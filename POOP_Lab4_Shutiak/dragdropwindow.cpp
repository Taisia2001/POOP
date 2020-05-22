#include "dragdropwindow.h"
#include "ui_dragdropwindow.h"

DragDropWindow::DragDropWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DragDropWindow)
{
    ui->setupUi(this);
    ui->listW1->addItem("Alice");
    ui->listW1->addItem("Ann");
    ui->listW1->addItem("Bob");
    ui->listW1->addItem("Alex");
    ui->listW1->addItem("Emma");
    ui->listW2->addItem("John");
    ui->listW2->addItem("Jake");
    ui->listW2->addItem("Tom");
    ui->listW2->addItem("Lina");
    ui->listW2->addItem("Grace");
}

DragDropWindow::~DragDropWindow()
{
    delete ui;
}

