#include "spacedeleterwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpaceDeleterWindow w;
    w.resize(300,250);
    w.show();
    return a.exec();
}
