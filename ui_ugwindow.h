/********************************************************************************
** Form generated from reading ui file 'ugwindow.ui'
**
** Created: Fri 27. Mar 19:11:20 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_UGWINDOW_H
#define UI_UGWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UGWindowClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UGWindowClass)
    {
        if (UGWindowClass->objectName().isEmpty())
            UGWindowClass->setObjectName(QString::fromUtf8("UGWindowClass"));
        UGWindowClass->setObjectName("UGWindowClass");
        UGWindowClass->resize(600, 400);
        menuBar = new QMenuBar(UGWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        UGWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(UGWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        UGWindowClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(UGWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        UGWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(UGWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        UGWindowClass->setStatusBar(statusBar);

        retranslateUi(UGWindowClass);

        QMetaObject::connectSlotsByName(UGWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *UGWindowClass)
    {
        UGWindowClass->setWindowTitle(QApplication::translate("UGWindowClass", "UGWindow", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(UGWindowClass);
    } // retranslateUi

};

namespace Ui {
    class UGWindowClass: public Ui_UGWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UGWINDOW_H
