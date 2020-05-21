#include "ResizeObserver.h"
#include "ui_mainwindow.h"

ResizeObserver::ResizeObserver(QWidget *parent)
    : QLabel(parent)
{
    setAlignment(Qt::AlignCenter);
}

ResizeObserver::~ResizeObserver()
{
}

void ResizeObserver::resizeEvent(QResizeEvent *event){
    showSize();
}

void ResizeObserver::showSize(){
    setText(QString::number(this->width())+"x"+QString::number(this->height()));
}


