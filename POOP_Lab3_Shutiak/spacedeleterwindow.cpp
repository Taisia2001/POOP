#include "spacedeleterwindow.h"
#include "ui_spacedeleterwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QChar>
SpaceDeleterWindow::SpaceDeleterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SpaceDeleterWindow)
{
    ui->setupUi(this);
}

SpaceDeleterWindow::~SpaceDeleterWindow()
{
    delete ui;
}

void SpaceDeleterWindow::on_chooseB_clicked()
{
    ui->pathFileFrom->setText(QFileDialog::getOpenFileName(this, "Choose a file", QDir::homePath(), "*.txt"));
    if(ui->pathFileFrom->text()==ui->pathFileTo->text()&&ui->pathFileFrom->text()!=""){
        QMessageBox::warning(this,"Fail", "You can not choose one file for opening and saving!");
        ui->pathFileFrom->setText("");
        return;
    }
    ui->processB->setEnabled( ui->pathFileFrom->text().length()!=0&& ui->pathFileTo->text().length());
}

void SpaceDeleterWindow::on_saveB_clicked()
{
    ui->pathFileTo->setText(QFileDialog::getSaveFileName(this, "Save", QDir::homePath(), "*.txt" ));
    if(ui->pathFileFrom->text()==ui->pathFileTo->text()&&ui->pathFileFrom->text()!=""){
         QMessageBox::warning(this,"Fail", "You can not choose one file for opening and saving!");
         ui->pathFileTo->setText("");
        return;
    }
    ui->processB->setEnabled( ui->pathFileFrom->text().length()!=0&& ui->pathFileTo->text().length());
}

void SpaceDeleterWindow::on_processB_clicked()
{
     ui->processB->setEnabled(false);
    QFile fileFrom (ui->pathFileFrom->text());
    if (!fileFrom.open(QFile::ReadOnly| QFile::Text)){
        QMessageBox::warning(this,"Fail","File can not be read!");
        return;
    }
    QFile fileTo(ui->pathFileTo->text());
    if (!fileTo.open(QFile::WriteOnly)){
        QMessageBox::warning(this,"Fail","File can not be created!");
        return;
    }
    QByteArray a;
    while(!fileFrom.atEnd()){
       a = fileFrom.readLine();
       a.replace('\t'," ");
       a.replace('\n',"");
       fileTo.write(a);
    }

    fileTo.flush();
    fileFrom.flush();
    fileTo.close();
    fileFrom.close();
    QMessageBox::information(this,"Success","Result was saved!");
    ui->processB->setEnabled(true);

}
