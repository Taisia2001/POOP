#include "paintwindow.h"

#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include <QColorDialog>
#include <QVBoxLayout>
#include <QToolButton>
#include <QInputDialog>
#include <QFontDialog>
#include <QFileDialog>
#include <QMessageBox>


PaintWindow::PaintWindow(QWidget *parent):
    QMainWindow(parent),
    _canvas(nullptr),
    helpW("../POOP_Lab5_Shutiak/doc", "index.htm")
{
    setWindowIcon(QIcon(":/images/icon.png"));
    QWidget* container = new QWidget;
    _canvas = new Canvas(this);
    container->setLayout(new QVBoxLayout);
    setCentralWidget(container);
    area = new QScrollArea(container);

    area->setWidget(_canvas);
    area->setBackgroundRole(QPalette::Dark);

    setCentralWidget(area);
    createActions();
    createMenus();
    createToolBars();

    setWindowTitle(tr("Paint"));
}
PaintWindow::~PaintWindow(){
    delete fileMenu;
    delete editMenu;
    delete toolsMenu;
    delete helpMenu;
    delete editToolBar;

    delete exitAction;
    delete circleAction;
    delete pickerAction;
    delete selectAction;
    delete cutAction;
    delete copyAction;
    delete pasteAction;
    delete fontAction;
    delete textAction;
    delete helpAction;
    delete fillAction;
    delete pencilAction;
    delete rectAction;
    delete undoAction;
    delete redoAction;
    delete rubberAction;
    delete lineAction;
    delete sprayAction;
    delete openAction;
    delete saveAction;
    delete color1Action;
    delete color2Action;
    delete widthAction;
    delete clearAction;
    delete hasContourAction;
    delete hasFillAction;
    delete _canvas;
    delete area;

}
void PaintWindow::createActions()
{
    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    cutAction = new QAction(tr("Cu&t"), this);
    cutAction->setIcon(QIcon(":/images/cut.png"));
    cutAction->setShortcut(tr("Ctrl+X"));
    cutAction->setEnabled(false);
    connect(cutAction, SIGNAL(triggered()), _canvas, SLOT(cut()));



    copyAction = new QAction(tr("&Copy"), this);
    copyAction->setIcon(QIcon(":/images/copy.png"));
    copyAction->setShortcut(tr("Ctrl+C"));
    copyAction->setEnabled(false);
    connect(copyAction, SIGNAL(triggered()), _canvas, SLOT(copy()));

    pasteAction = new QAction(tr("&Paste"), this);
    pasteAction->setIcon(QIcon(":/images/paste.png"));
    pasteAction->setShortcut(tr("Ctrl+V"));
    pasteAction->setEnabled(false);
    connect(pasteAction, SIGNAL(triggered()), _canvas, SLOT(paste()));

    pencilAction = new QAction(tr("&Pencil"), this);
    pencilAction->setIcon(QIcon(":/images/pencil.png"));
    pencilAction->setShortcut(tr("Ctrl+L"));
    connect(pencilAction, SIGNAL(triggered()), this, SLOT(pencil()));

    sprayAction = new QAction(tr("&Spray"), this);
    sprayAction->setIcon(QIcon(":/images/spray.png"));
    sprayAction->setShortcut(tr("Ctrl+P"));
    connect(sprayAction, SIGNAL(triggered()), this, SLOT(spray()));

    undoAction = new QAction(tr("&Undo"), this);
    undoAction->setIcon(QIcon(":/images/undo.png"));
    undoAction->setShortcut(tr("Ctrl+Z"));
    undoAction->setEnabled(false);
    connect(undoAction, SIGNAL(triggered()), _canvas, SLOT(undo()));

    redoAction = new QAction(tr("&Redo"), this);
    redoAction->setIcon(QIcon(":/images/redo.png"));
    redoAction->setShortcut(tr("Ctrl+Y"));
    redoAction->setEnabled(false);
    connect(redoAction, SIGNAL(triggered()), _canvas, SLOT(redo()));

    rectAction = new QAction(tr("&Rect"), this);
    rectAction->setIcon(QIcon(":/images/rectangle.png"));
    rectAction->setShortcut(tr("Ctrl+R"));
    connect(rectAction, SIGNAL(triggered()), this, SLOT(rect()));

    circleAction = new QAction(tr("&Circle"), this);
    circleAction->setIcon(QIcon(":/images/circle.png"));
    circleAction->setShortcut(tr("Ctrl+I"));
    connect(circleAction, SIGNAL(triggered()), this, SLOT(circle()));

    lineAction = new QAction(tr("&Line"), this);
    lineAction->setIcon(QIcon(":/images/slash.png"));
    lineAction->setShortcut(tr("Ctrl+E"));
    connect(lineAction, SIGNAL(triggered()), this, SLOT(line()));

    openAction = new QAction(tr("&Open"), this);
    openAction->setIcon(QIcon(":/images/file.png"));
    openAction->setShortcut(tr("Ctrl+O"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

    saveAction = new QAction(tr("&Save"), this);
    saveAction->setIcon(QIcon(":/images/save.png"));
    saveAction->setShortcut(tr("Ctrl+S"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

    pickerAction = new QAction(tr("&Pick"), this);
    pickerAction->setIcon(QIcon(":/images/color-picker.png"));
    pickerAction->setShortcut(tr("Ctrl+K"));
    connect(pickerAction, SIGNAL(triggered()), this, SLOT(pick()));

    selectAction = new QAction(tr("&Select"), this);
    selectAction->setIcon(QIcon(":/images/crop.png"));
    selectAction->setShortcut(tr("Ctrl+A"));
    connect(selectAction, SIGNAL(triggered()), this, SLOT(select()));

    fontAction = new QAction(tr("&Font"), this);
    fontAction->setIcon(QIcon(":/images/font.png"));
    fontAction->setShortcut(tr("Ctrl+F"));
    connect(fontAction, SIGNAL(triggered()), this, SLOT(font()));

    textAction = new QAction(tr("&Text"), this);
    textAction->setIcon(QIcon(":/images/text.png"));
    textAction->setShortcut(tr("Ctrl+T"));
    connect(textAction, SIGNAL(triggered()), this, SLOT(text()));

    helpAction = new QAction(tr("&Help"), this);
    helpAction->setIcon(QIcon(":/images/help.png"));
    helpAction->setShortcut(tr("F1"));
    connect(helpAction, SIGNAL(triggered()), this, SLOT(help()));

    color1Action = new QAction(tr("&Color"), this);
    color1Action->setShortcut(tr("Alt+1"));
    connect(color1Action, SIGNAL(triggered()), this, SLOT(color1()));

    color2Action = new QAction(tr("&FillColor"), this);
    color2Action->setShortcut(tr("Alt+2"));
    connect(color2Action, SIGNAL(triggered()), this, SLOT(color2()));

    hasContourAction = new QAction(tr("&Contour"), this);
    hasContourAction->setShortcut(tr("Alt+C"));
    hasContourAction->setCheckable(true);
    hasContourAction->setChecked(true);
    connect(hasContourAction, SIGNAL(triggered()),this,  SLOT(hasColor1()));

    hasFillAction = new QAction(tr("&Filled"), this);
    hasFillAction->setShortcut(tr("Alt+L"));
    hasFillAction->setCheckable(true);
    hasFillAction->setChecked(true);
    connect(hasFillAction, SIGNAL(triggered()),this,  SLOT(hasColor2()));


    fillAction = new QAction(tr("&Fill"), this);
    fillAction->setIcon(QIcon(":/images/paint.png"));
    fillAction->setShortcut(tr("Alt+F"));
    connect(fillAction, SIGNAL(triggered()), this, SLOT(fill()));

    rubberAction = new QAction(tr("&Erase"), this);
    rubberAction->setIcon(QIcon(":/images/rubber.png"));
    rubberAction->setShortcut(tr("Alt+E"));
    connect(rubberAction, SIGNAL(triggered()), this, SLOT(rubber()));

    widthAction = new QAction(tr("&Width"), this);
    widthAction->setShortcut(tr("Ctrl+W"));
    connect(widthAction, SIGNAL(triggered()), this, SLOT(width()));

    clearAction = new QAction(tr("&Clear"), this);
    clearAction->setShortcut(tr("Ctrl+D"));
    connect(clearAction, SIGNAL(triggered()), _canvas, SLOT(clear()));


    connect(_canvas, SIGNAL(undoSignal(bool)), undoAction, SLOT(setEnabled(bool)));
    connect(_canvas, SIGNAL(redoSignal(bool)), redoAction, SLOT(setEnabled(bool)));

    connect(_canvas, SIGNAL(pasteSignal()),  SLOT(enablePaste()));
    connect(_canvas, SIGNAL(selectSignal(bool)),  SLOT(enableCutCopy(bool)));
    connect(_canvas, SIGNAL(colorPickedSignal()),  SLOT(colorPicked()));



}


void PaintWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(undoAction);
    editMenu->addAction(redoAction);
    editMenu->addSeparator();
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);

    toolsMenu = menuBar()->addMenu(tr("&Tools"));
    toolsMenu->addAction(color1Action);
    toolsMenu->addAction(color2Action);
    toolsMenu->addAction(widthAction);
    toolsMenu->addAction(hasContourAction);
    toolsMenu->addAction(hasFillAction);
    toolsMenu->addSeparator();
    toolsMenu->addAction(fontAction);
    toolsMenu->addSeparator();
    toolsMenu->addAction(clearAction);
    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(helpAction);
}

void PaintWindow::createToolBars()
{
    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(undoAction);
    editToolBar->addAction(redoAction);
    editToolBar->addSeparator();
    editToolBar->addAction(cutAction);
    editToolBar->addAction(copyAction);
    editToolBar->addAction(pasteAction);
    editToolBar->addAction(selectAction);
    editToolBar->addSeparator();
    editToolBar->addAction(pencilAction);
    editToolBar->addAction(sprayAction);
    editToolBar->addAction(fillAction);
    editToolBar->addSeparator();
    editToolBar->addAction(circleAction);
    editToolBar->addAction(rectAction);
    editToolBar->addAction(lineAction);
    editToolBar->addAction(textAction);
    editToolBar->addSeparator();

    editToolBar->addAction(pickerAction);
    editToolBar->addAction(color1Action);
    c1=qobject_cast<QToolButton*>(editToolBar->widgetForAction(color1Action));
    c1->setStyleSheet("QToolButton { background-color: #"+_canvas->penColor().name().mid(1,6)+"}");
    editToolBar->addAction(color2Action);
    c2=qobject_cast<QToolButton*>(editToolBar->widgetForAction(color2Action));
    c2->setStyleSheet("QToolButton { background-color: #"+_canvas->fillColor().name().mid(1,6)+"}");
    editToolBar->addSeparator();
    editToolBar->addAction(rubberAction);
    editToolBar->addSeparator();

}

void PaintWindow::pencil(){
    _canvas->setTool(Canvas::PENCIL);
}
void PaintWindow::spray(){
    _canvas->setTool(Canvas::SPRAY);
}
void PaintWindow::fill(){
    _canvas->setTool(Canvas::FILL);
}
void PaintWindow::rubber(){
    _canvas->setTool(Canvas::ERASER);
}
void PaintWindow::rect(){
    _canvas->setTool(Canvas::RECT);
}
void PaintWindow::circle(){
    _canvas->setTool(Canvas::CIRCLE);
}
void PaintWindow::pick(){
    _canvas->setTool(Canvas::PICKER);
}

void PaintWindow::select(){
    _canvas->setTool(Canvas::SELECT);
}
void PaintWindow::font(){
    bool ok;
    QFont newFont = QFontDialog::getFont(&ok);
    if(ok) _canvas->setFont(newFont);

}
void PaintWindow::text(){
    _canvas->setTool(Canvas::TEXT);
}
void PaintWindow::help(){
    helpW.resize(600, 500);
    helpW.show();
}

void PaintWindow::line(){
    _canvas->setTool(Canvas::LINE);
}
void PaintWindow::open(){
    if(requestSaving()){
        QString fileName = QFileDialog::getOpenFileName(this, "Open file", QDir::homePath());
        if(!fileName.isEmpty())
            if(!_canvas->open(fileName))
                QMessageBox::warning(this,"Opening failed","You should choose an image!");

    }
}

bool PaintWindow::save(){
    QString fileName = QFileDialog::getSaveFileName(this, "Save As",
                                                    QDir::homePath(),
                                                    "*.png");

    if (fileName.isEmpty())
        return false;

    return _canvas->saveImage(fileName);



}
void PaintWindow::color1(){
    _canvas->setPenColor(QColorDialog::getColor(_canvas->penColor()));
    colorPicked();


}
void PaintWindow::color2(){
    _canvas->setFillColor(QColorDialog::getColor(_canvas->fillColor()));
    c2->setStyleSheet("QToolButton { background-color: #"+_canvas->fillColor().name().mid(1,6)+"}");
}
void PaintWindow::colorPicked(){
    c1->setStyleSheet("QToolButton { background-color: #"+_canvas->penColor().name().mid(1,6)+"}");
}

void PaintWindow::width(){
    bool ok;
    int newWidth = QInputDialog::getInt(this, "Width",
                                        "Select width:",
                                        _canvas->penWidth(),
                                        1, 50, 2, &ok);

    if(ok) _canvas->setPenWidth(newWidth);

}
void PaintWindow::enablePaste(){
    pasteAction->setEnabled(true);
}
void PaintWindow::enableCutCopy(bool b){
    copyAction->setEnabled(b);
    cutAction->setEnabled(b);
}
void PaintWindow::hasColor1(){
    _canvas->setHasCountur(hasContourAction->isChecked());
}
void PaintWindow::hasColor2(){
    _canvas->setHasFill(hasFillAction->isChecked());
}
bool PaintWindow::requestSaving()
{
    if(_canvas->isChanged()){
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this,
                                   "Saving...",
                                   "Do you want to save progress?",
                                   QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if(ret == QMessageBox::Save) return save();
        else if(ret == QMessageBox::Cancel) return false;

    }
    return true;
}
void PaintWindow::closeEvent(QCloseEvent *event)
{
    if(requestSaving()) event->accept();
    else event->ignore();
}




