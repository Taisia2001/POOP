#ifndef PAINTWINDOW_H
#define PAINTWINDOW_H

#include <helpwindow.h>
#include <QMainWindow>


#include "canvas.h"

class QGraphicsScene;
class QAction;
class QGraphicsScene;
class QGraphicsView;
class QToolButton;
class QWidget;
class QScrollArea;
class QVBoxLayout;
class PaintWindow : public QMainWindow
{
    Q_OBJECT

public:
    PaintWindow(QWidget *parent=nullptr);
    ~PaintWindow();
private slots:
    void pencil();
    void spray();
    void fill();
    void rubber();
    void rect();
    void circle();
    void pick();
    void select();
    void font();
    void text();
    void help();
    void line();
    void open();
    bool save();
    void color1();
    void color2();
    void width();
    void enablePaste();
    void enableCutCopy(bool);
    void hasColor1();
    void hasColor2();
    void colorPicked();
protected:
    virtual void closeEvent(QCloseEvent *event) override;

private:

    Canvas* _canvas;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *toolsMenu;
    QMenu *helpMenu;
    QToolBar *editToolBar;
    QToolButton* c1;
    QToolButton* c2;
    QAction *exitAction;
    QAction *circleAction;
    QAction *pickerAction;
    QAction *selectAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *fontAction;
    QAction *textAction;
    QAction *helpAction;
    QAction *fillAction;
    QAction *pencilAction;
    QAction *rectAction;
    QAction *undoAction;
    QAction *redoAction;
    QAction *rubberAction;
    QAction *lineAction;
    QAction *sprayAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *color1Action;
    QAction *color2Action;
    QAction *widthAction;
    QAction *clearAction;
    QAction *hasContourAction;
    QAction *hasFillAction;
    QScrollArea* area;
    HelpWindow helpW;

    void createActions();
    void createMenus();
    void createToolBars();
    bool requestSaving();


};
#endif // PAINTWINDOW_H
