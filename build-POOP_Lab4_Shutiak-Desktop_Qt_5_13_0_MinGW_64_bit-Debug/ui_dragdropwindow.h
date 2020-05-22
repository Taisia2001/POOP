/********************************************************************************
** Form generated from reading UI file 'dragdropwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAGDROPWINDOW_H
#define UI_DRAGDROPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <dragdroplistwidget.h>

QT_BEGIN_NAMESPACE

class Ui_DragDropWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    DragDropListWidget *listW1;
    DragDropListWidget *listW2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DragDropWindow)
    {
        if (DragDropWindow->objectName().isEmpty())
            DragDropWindow->setObjectName(QString::fromUtf8("DragDropWindow"));
        DragDropWindow->resize(800, 600);
        centralwidget = new QWidget(DragDropWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listW1 = new DragDropListWidget(centralwidget);
        listW1->setObjectName(QString::fromUtf8("listW1"));
        listW1->setAcceptDrops(true);

        horizontalLayout->addWidget(listW1);

        listW2 = new DragDropListWidget(centralwidget);
        listW2->setObjectName(QString::fromUtf8("listW2"));

        horizontalLayout->addWidget(listW2);

        DragDropWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DragDropWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        DragDropWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DragDropWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DragDropWindow->setStatusBar(statusbar);

        retranslateUi(DragDropWindow);

        QMetaObject::connectSlotsByName(DragDropWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DragDropWindow)
    {
        DragDropWindow->setWindowTitle(QCoreApplication::translate("DragDropWindow", "DragDropWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DragDropWindow: public Ui_DragDropWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAGDROPWINDOW_H
