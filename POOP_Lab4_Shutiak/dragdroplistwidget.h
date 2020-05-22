#ifndef LISTBOX_H
#define LISTBOX_H

#include <QtGui>
#include <QListWidget>

class DragDropListWidget : public QListWidget
{
    Q_OBJECT
public:
    DragDropListWidget(QWidget* parent);
protected:
    virtual void dragEnterEvent(QDragEnterEvent* event);
    virtual void dropEvent(QDropEvent* event);

    virtual void dragMoveEvent(QDragMoveEvent* e);
    virtual void startDrag(Qt::DropActions supportedActions);

signals:
    void itemDroped();
};

#endif // LISTBOX_H
