#ifndef DRAGDROPWINDOW_H
#define DRAGDROPWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class DragDropWindow; }
QT_END_NAMESPACE

class DragDropWindow : public QMainWindow
{
    Q_OBJECT

public:
    DragDropWindow(QWidget *parent = nullptr);
    ~DragDropWindow();

private:
    Ui::DragDropWindow *ui;
};
#endif // DRAGDROPWINDOW_H
