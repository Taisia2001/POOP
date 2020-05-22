/********************************************************************************
** Form generated from reading UI file 'spacedeleterwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPACEDELETERWINDOW_H
#define UI_SPACEDELETERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpaceDeleterWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QPushButton *chooseB;
    QLabel *pathFileFrom;
    QPushButton *saveB;
    QLabel *pathFileTo;
    QPushButton *processB;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SpaceDeleterWindow)
    {
        if (SpaceDeleterWindow->objectName().isEmpty())
            SpaceDeleterWindow->setObjectName(QString::fromUtf8("SpaceDeleterWindow"));
        SpaceDeleterWindow->resize(800, 600);
        centralwidget = new QWidget(SpaceDeleterWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        chooseB = new QPushButton(centralwidget);
        chooseB->setObjectName(QString::fromUtf8("chooseB"));

        verticalLayout->addWidget(chooseB);

        pathFileFrom = new QLabel(centralwidget);
        pathFileFrom->setObjectName(QString::fromUtf8("pathFileFrom"));

        verticalLayout->addWidget(pathFileFrom);

        saveB = new QPushButton(centralwidget);
        saveB->setObjectName(QString::fromUtf8("saveB"));

        verticalLayout->addWidget(saveB);

        pathFileTo = new QLabel(centralwidget);
        pathFileTo->setObjectName(QString::fromUtf8("pathFileTo"));

        verticalLayout->addWidget(pathFileTo);

        processB = new QPushButton(centralwidget);
        processB->setObjectName(QString::fromUtf8("processB"));
        processB->setEnabled(false);

        verticalLayout->addWidget(processB);

        SpaceDeleterWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SpaceDeleterWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        SpaceDeleterWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SpaceDeleterWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SpaceDeleterWindow->setStatusBar(statusbar);

        retranslateUi(SpaceDeleterWindow);

        QMetaObject::connectSlotsByName(SpaceDeleterWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SpaceDeleterWindow)
    {
        SpaceDeleterWindow->setWindowTitle(QCoreApplication::translate("SpaceDeleterWindow", "SpaceDeleterWindow", nullptr));
        chooseB->setText(QCoreApplication::translate("SpaceDeleterWindow", "Choose File", nullptr));
        pathFileFrom->setText(QString());
        saveB->setText(QCoreApplication::translate("SpaceDeleterWindow", "Save To", nullptr));
        pathFileTo->setText(QString());
        processB->setText(QCoreApplication::translate("SpaceDeleterWindow", "Process", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpaceDeleterWindow: public Ui_SpaceDeleterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPACEDELETERWINDOW_H
