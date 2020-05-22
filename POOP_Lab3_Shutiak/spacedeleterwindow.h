#ifndef SPACEDELETERWINDOW_H
#define SPACEDELETERWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SpaceDeleterWindow; }
QT_END_NAMESPACE

class SpaceDeleterWindow : public QMainWindow
{
    Q_OBJECT

public:
    SpaceDeleterWindow(QWidget *parent = nullptr);
    ~SpaceDeleterWindow();

private slots:
    void on_chooseB_clicked();

    void on_saveB_clicked();

    void on_processB_clicked();

private:
    Ui::SpaceDeleterWindow *ui;
};
#endif // SPACEDELETERWINDOW_H
