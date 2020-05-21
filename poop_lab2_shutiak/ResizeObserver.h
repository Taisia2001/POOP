#ifndef _RESIZEOBSERVER_H
#define _RESIZEOBSERVER_H

#include <QLabel>

class ResizeObserver : public QLabel
{
    Q_OBJECT

public:
    ResizeObserver(QWidget *parent = nullptr);
    ~ResizeObserver();

protected:
    virtual void	resizeEvent(QResizeEvent *event);
    void showSize();

};
#endif // _RESIZEOBSERVER_H
