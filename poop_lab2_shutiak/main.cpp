#include "ResizeObserver.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ResizeObserver ro;
    ro.resize(400,300);
    ro.show();
    return a.exec();
}
