#include "dragdroplistwidget.h"

DragDropListWidget::DragDropListWidget(QWidget* parent)
    : QListWidget(parent)
{
    this->setAcceptDrops(true);
    this->setSelectionMode(QAbstractItemView::SingleSelection);
    this->setDragEnabled(true);
}


void DragDropListWidget::dragEnterEvent(QDragEnterEvent* event)
{
    if (event->mimeData()->hasFormat("application/x-item"))
        event->accept();
    else
        event->ignore();
}

void DragDropListWidget::dropEvent(QDropEvent* event)
{
    if (event->mimeData()->hasFormat("application/x-item")) {
        event->accept();
        insertItem(event->pos().y()/this->sizeHintForRow(0),event->mimeData()->data("application/x-item"));
    } else
        event->ignore();
}


void DragDropListWidget::dragMoveEvent(QDragMoveEvent* e)
{
    if (e->mimeData()->hasFormat("application/x-item") /*&& e->source() != this*/) {
        e->accept();
        this->setCurrentRow( e->pos().y()/this->sizeHintForRow(0));
    } else
        e->ignore();
}

void DragDropListWidget::startDrag(Qt::DropActions supportedActions)
{
    QListWidgetItem* item = currentItem();
    QMimeData* mimeData = new QMimeData;
    mimeData->setData("application/x-item", item->text().toLatin1().data());
    QDrag* drag = new QDrag(this);
    drag->setMimeData(mimeData);
    if (drag->exec(Qt::MoveAction) == Qt::MoveAction) {
        delete takeItem(row(item));
        emit itemDroped();
    }

}


