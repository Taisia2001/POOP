#include "canvas.h"
#include <QPainter>
#include<QPalette>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QRandomGenerator>
#include <QStack>

Canvas::Canvas(QWidget *parent):QWidget(parent),
    _penWidth(5), _current(0), _allSaves(0),  _changed(false), _hasCountur(true), _hasFill(true),
    _penColor(Qt::black), _fillColor(Qt::white),_tool(PENCIL), _selectionMode(NONE),_text(nullptr),
    _selectionRect(nullptr),_bufferedRect(nullptr),_bufferedImage(nullptr), _copiedRect(nullptr),_copiedImage(nullptr)
{
    resize(1890,920);
    _image.fill(qRgb(255,255,255));
    _saves.append(_image);
    setFocusPolicy(Qt::StrongFocus);
}
Canvas::~Canvas(){
    if(_text){
        delete _text;
        _text= nullptr;
    }
    if(_selectionRect){
        delete _selectionRect;
        _selectionRect= nullptr;
    }
    if(_bufferedRect){
        delete _bufferedRect;
        _bufferedRect= nullptr;
    }
    if(_bufferedImage){
        delete _bufferedImage;
        _bufferedImage= nullptr;
    }
    if(_copiedRect){
        delete _copiedRect;
        _copiedRect= nullptr;
    }
    if(_copiedImage){
        delete _copiedImage;
        _copiedImage= nullptr;
    }
}

QFont Canvas::font()const{
    return _font;
}
void Canvas::setFont(const QFont& f){
    _font=f;
    if(_text){
        delete _text;
        _text = nullptr;
    }
}
bool Canvas::open(const QString& file){
    QImage loadedImage;

    if (!loadedImage.load(file))
        return false;
    loadedImage.convertTo(QImage::Format_RGB32);
    QSize newSize = loadedImage.size();
    resize(newSize);
    _image = loadedImage;
    _changed = true;
    saveState();
    update();
    return true;
}

void Canvas::clear(){
    _image.fill(qRgb(255,255,255));
    resize(1890,920);
    _changed = true;
    saveState();
    update();
}
void Canvas::saveState()
{
    ++_current;
    if(_current == _saves.size())
        _saves.append(_image);
    else _saves[_current] = _image;
    _allSaves = _current;
    _changed = true;
    emit undoSignal(true);
    emit redoSignal(false);

}

void Canvas::cut(){
    if(_selectionRect){
        setCopied();
        QPainter painter(&_image);
        painter.fillRect(*_selectionRect, Qt::white);

        resetSelection();
        update();
        saveState();
        emit pasteSignal();
    }
}
void Canvas::copy(){
    if(_selectionRect){
        setCopied();
        emit pasteSignal();
    }
}
void Canvas::paste(){
    setTool(PASTE);
}
void Canvas::setTool(const Tool& t){
    _tool=t;
    if(_tool != SELECT){
       resetSelection();
        update();
    }
}
QColor Canvas::penColor() const{
    return _penColor;
}
int  Canvas::penWidth() const{
    return _penWidth;
}

void Canvas::setPenWidth(const int width){
    _penWidth=qMax(1,width);
}
QColor Canvas::fillColor() const{
    return  _fillColor;
}
void Canvas::setPenColor(const QColor& c){
    _penColor=c;
}
void Canvas::setFillColor(const QColor& c){
    _fillColor=c;
}
void Canvas::undo(){
    _image=_saves[--_current];
    update();
    emit undoSignal( _current);
    emit redoSignal(true);
   resetSelection();
}
void Canvas::redo(){
    if(_current<_allSaves){
        _image=_saves[++_current];
        update();}
    emit redoSignal(_current<_allSaves);
    emit undoSignal(true);
    resetSelection();
}


void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if(_tool == PENCIL || _tool == ERASER ) drawPoint(event->pos());
    else if(_tool == SPRAY) drawSpray(event->pos());
    else if(_tool == SELECT || _tool == PASTE || _tool == RECT || _tool == CIRCLE || _tool == LINE) {

        if( _selectionMode == NONE) { drawSelectionSquareTo(event->pos()); return; }
        else if(_selectionMode == MOVE){
            _selectionRect->moveTo(event->pos().x()+_bufferedRect->left() - _lastPoint.x(), event->pos().y()+ _bufferedRect->top()  - _lastPoint.y());
        }
        else if(_selectionMode == RIGHT) {
            if(event->pos().x()<=_bufferedRect->left() ) return;
            _selectionRect->setRight(event->pos().x());
        }
        else if(_selectionMode == LEFT) {
            if(event->pos().x()>=_bufferedRect->right() ) return;
            _selectionRect->setLeft(event->pos().x());
        }
        else if(_selectionMode == TOP) {
            if(event->pos().y()>=_bufferedRect->bottom() ) return;
            _selectionRect->setTop(event->pos().y());
        }
        else if(_selectionMode == BOTTOM) {
            if(event->pos().y()<=_bufferedRect->top() ) return;
            _selectionRect->setBottom(event->pos().y());

        }

        _image = *_bufferedImage;
        QPainter painter(&_image);
        painter.fillRect(*_bufferedRect,Qt::white);
        painter.drawImage(*_selectionRect, *_bufferedImage, *_bufferedRect);
        update();

    }


}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    if(_tool == TEXT){
        _lastPoint = event->pos();
        if(_text){
            delete _text;
            _text = nullptr;
        }
        _text = new QString;
    }else if(_tool == PENCIL || _tool == ERASER ) _lastPoint = event->pos();
    else if(_tool == SPRAY) drawSpray(event->pos());
    else if(_tool == FILL) fill(event->pos());
    else if(_tool == PASTE){
        if(!hasCopiedArea()) return ;
        QPainter painter(&_image);
        QRect updateRect = QRect(event->pos(),_copiedRect->size());
        painter.drawImage(updateRect, *_copiedImage, *_copiedRect);
        _selectionRect = new QRect(updateRect.topLeft(), updateRect.size());
        emit selectSignal(_selectionRect);
        _tool = SELECT;
    }
    if(_tool == SELECT || _tool == RECT || _tool == CIRCLE || _tool == LINE) {
        if(hasSelectedArea()){
            if(qAbs(event->pos().x()-_selectionRect->right()) <5){
                setCursor(Qt::SizeHorCursor);
                _selectionMode = RIGHT;
                return;
            }
            else if(qAbs(event->pos().x()-_selectionRect->left()) <5){
                setCursor(Qt::SizeHorCursor);
                _selectionMode = LEFT;
                return ;
            }
            else if(qAbs(event->pos().y()-_selectionRect->bottom()) <5){
                setCursor(Qt::SizeVerCursor);
                _selectionMode = BOTTOM;
                return ;
            }
            else if(qAbs(event->pos().y()-_selectionRect->top()) <5){
                setCursor(Qt::SizeVerCursor);
                _selectionMode = TOP;
                return ;
            }
            else if(_selectionRect->contains(event->pos())){
                setCursor(Qt::SizeAllCursor);
                _selectionMode = MOVE;
                _lastPoint = event->pos();
                return;
            }
            else {
                _selectionMode = NONE;
                resetSelection();
                update();
            }
        }
        _selectionRect = new QRect(event->pos(), QSize(1,1));
        emit selectSignal(_selectionRect && _tool == SELECT);
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event) {
    if(_tool == PICKER){
        _penColor = _image.pixelColor(event->pos());
        emit colorPickedSignal();
        return;
    }else if(_tool == SELECT){
        setCursor(Qt::ArrowCursor);
        _selectionMode = NONE;
        if(hasBufferedArea()) {
            delete _bufferedRect;
            delete _bufferedImage;
        }
        _bufferedRect = new QRect(_selectionRect->topLeft(), _selectionRect->size());
        _bufferedImage = new QImage(_image);
        update();
    }
    else if(_tool == RECT || _tool == CIRCLE || _tool == LINE){
        QPainter painter(&_image);
        painter.setPen(QPen(_penColor,_penWidth));
        if(_tool == LINE) painter.drawLine(_selectionRect->topLeft(), _selectionRect->bottomRight());
        else if(_hasFill||_hasCountur){
            if(_tool == RECT){
                if(_hasFill){
                    painter.setBrush(QBrush(_fillColor));
                    if(!_hasCountur){
                        painter.setPen(QPen(_fillColor,1));
                    }
                }
                painter.drawRect(*_selectionRect);


            }
            else{
                if(_hasFill){
                    painter.setBrush(QBrush(_fillColor));
                    if(!_hasCountur){
                        painter.setPen(QPen(_fillColor,1));
                    }
                }
                painter.drawEllipse(*_selectionRect);

            }
        }
        update(_selectionRect->adjusted(-3,-3,3,3));
       resetSelection();
    }
    saveState();

}

void Canvas::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QRect drawingArea = event->rect();
    resizeImage(&_image,size());
    painter.drawImage(drawingArea, _image, drawingArea);
    if(hasSelectedArea()){
        if( _tool == LINE) painter.setPen(QPen(_penColor,_penWidth));
        else if((_tool == RECT || _tool == CIRCLE)&&(_hasFill||_hasCountur) ){
            if(_hasFill){
                painter.setBrush(QBrush(_fillColor));
                if(!_hasCountur){
                    painter.setPen(QPen(_fillColor,1));
                }
            }
            if(_hasCountur){
                painter.setPen(QPen(_penColor,_penWidth));
            }
        }
        if(_tool==SELECT) painter.setPen(QPen(Qt::blue,1,Qt::DashLine));
        if(_tool == LINE)painter.drawLine(_selectionRect->topLeft(), _selectionRect->bottomRight());
        else if(_tool ==CIRCLE) painter.drawEllipse(*_selectionRect);
        else painter.drawRect(*_selectionRect);
    }
}
void  Canvas::keyReleaseEvent(QKeyEvent *event){
    if ((_tool = TEXT) && _text)
    {
        if(event->key()== Qt::Key_Backspace){
            if(_text->length()==0)return;
            _text->chop(1);
            undo();
        }
        else{
            _text->append(event->text());
            QPainter p(&_image);
            p.setPen(_penColor);
            p.setFont(_font);

            p.drawText(_lastPoint,*_text);
            saveState();
        }
        update();
    }


}
void Canvas::resizeImage(QImage *image, const QSize &newSize)
{
    if(image->size() == newSize) return;
    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255,255,255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0,0), _image);
    _image = newImage;
}
bool Canvas::isChanged(){
    return _changed;
}

bool Canvas::saveImage(const QString &fileName)
{
    return _image.save(fileName, "png");
}
void Canvas::setHasCountur(const bool& h){
    _hasCountur=h;
}
void Canvas::setHasFill(const bool& h){
    _hasFill=h;
}

void Canvas::drawPoint(const QPoint& nextPoint){
    QPainter painter(&_image);
    if(_tool==ERASER)
        painter.setPen(QPen(Qt::white,_penWidth));
    else
        painter.setPen(QPen(_penColor,_penWidth));
    painter.drawLine(_lastPoint,nextPoint);
    update();

    _lastPoint = nextPoint;
}
void Canvas::fill(QPoint pos){
    QColor color = _image.pixelColor(pos);
    if(color==_penColor)
        return;
    QStack<QPoint> stack;
    stack.push(pos);
    int width = _image.width();
    int height = _image.height();
    while(!stack.empty()){
        QPoint p = stack.pop();
        _image.setPixelColor(p,_penColor);
        if(p.x() > 0 && _image.pixelColor(p.x()-1,p.y()) == color) stack.push(QPoint(p.x()-1,p.y()));
        if(p.y() > 0 && _image.pixelColor(p.x(),p.y()-1) == color) stack.push(QPoint(p.x(),p.y()-1));
        if(p.x() < width-1 && _image.pixelColor(p.x()+1,p.y()) == color) stack.push(QPoint(p.x()+1,p.y()));
        if(p.y() < height-1 && _image.pixelColor(p.x(),p.y()+1) == color) stack.push(QPoint(p.x(),p.y()+1));
    }
    update();
}
void Canvas::drawSpray(QPoint pos){
    QPainter p(&_image);
    p.setPen(QPen(_penColor,_penWidth/4));
    int x = pos.x(), y = pos.y();
    for(int i=0; i<10; ++i){
        p.drawPoint(x+QRandomGenerator::global()->bounded(-_penWidth *2, _penWidth *2),y+QRandomGenerator::global()->bounded(-_penWidth *2, _penWidth *2));
    }
    update();
}

bool Canvas::hasSelectedArea()
{
    return _selectionRect;
}

bool Canvas::hasBufferedArea()
{
    return _bufferedRect;
}
bool  Canvas::hasCopiedArea(){
    return _copiedRect;
}
void Canvas::drawSelectionSquareTo(const QPoint &p)
{
    _selectionRect->setBottomRight(p);
    update();

}
void Canvas::setCopied(){

    if(hasCopiedArea()) {
        delete _copiedRect;
        _copiedRect=nullptr;
        delete _copiedImage;
        _copiedImage=nullptr;
    }
    _copiedRect = new QRect(_selectionRect->topLeft(), _selectionRect->size());
    _copiedImage = new QImage(_image);
}

void Canvas::resetSelection(){
    delete _selectionRect;
    _selectionRect = nullptr;
    emit selectSignal(_selectionRect);
    update();
}
