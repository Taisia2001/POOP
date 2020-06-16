#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QList>
#include <QImage>
#include <QLabel>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QString>
class Canvas:public QWidget
{
    Q_OBJECT
public:
    Canvas(QWidget *parent=nullptr);
    ~Canvas();
    enum SelectionMode{ LEFT, RIGHT, TOP, BOTTOM, MOVE,NONE };
    enum Tool{PENCIL, SPRAY, FILL,CIRCLE, RECT, LINE, TEXT, PICKER, ERASER, SELECT, PASTE};
    void setTool(const Tool&);

    QColor penColor() const;
    QColor fillColor() const;
    void setPenColor(const QColor&);
    void setFillColor(const QColor&);
    int  penWidth() const;
    void setPenWidth(const int width);
    QFont font()const;
    void setFont(const QFont&);
    void setHasCountur(const bool&);
    void setHasFill(const bool&);
    bool open(const QString&);
    bool saveImage(const QString& file);
    bool isChanged();

public slots:
    void clear();
    void redo();
    void undo();
    void cut();
    void copy();
    void paste();



signals:
    void undoSignal(bool);
    void redoSignal(bool);
    void pasteSignal();
    void selectSignal(bool);
    void colorPickedSignal();


protected:

    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

private:
    void resizeImage(QImage* image, const QSize &newSize);
    void saveState();

    void drawPoint(const QPoint& p);
    void fill(QPoint pos);
    void drawSpray(QPoint pos);

    bool hasSelectedArea();
    bool hasBufferedArea();
    bool hasCopiedArea();
    void drawSelectionSquareTo(const QPoint& p);
    void resetSelection();

    void setCopied();

    int _penWidth;
    int _current;
    int _allSaves;

    bool _changed;
    bool _hasCountur;
    bool _hasFill;

    QPoint _lastPoint;
    QColor _penColor;
    QColor _fillColor;
    QFont _font;
    QImage _image;
    Tool _tool;
    SelectionMode _selectionMode;

    QString* _text;
    QRect* _selectionRect;
    QRect* _bufferedRect;
    QImage* _bufferedImage;
    QRect* _copiedRect;
    QImage* _copiedImage;

    QList<QImage> _saves;
};

#endif // CANVAS_H
