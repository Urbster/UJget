/********************************************************************************
** Form generated from reading ui file 'udialog.ui'
**
** Created: Fri 27. Mar 22:49:20 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_UDIALOG_H
#define UI_UDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UDialogClass
{
public:
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *CurrentFolder;
    QLabel *label;
    QLabel *CurrentFile;
    QProgressBar *progressBar;
    QPushButton *CancelBtn;
    QGroupBox *groupBox_2;
    QLineEdit *MangaEdit;
    QLabel *label_3;
    QPushButton *GetBtn;
    QLabel *label_5;
    QLineEdit *NumberEdit;
    QLineEdit *UrlEdit;
    QLabel *label_4;
    QGroupBox *groupBox_3;
    QLineEdit *DirEdit;
    QLabel *label_6;
    QPushButton *FindBtn;
    QLabel *label_7;

    void setupUi(QDialog *UDialogClass)
    {
        if (UDialogClass->objectName().isEmpty())
            UDialogClass->setObjectName(QString::fromUtf8("UDialogClass"));
        UDialogClass->resize(508, 399);
        groupBox = new QGroupBox(UDialogClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 290, 471, 80));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 20, 31, 21));
        CurrentFolder = new QLabel(groupBox);
        CurrentFolder->setObjectName(QString::fromUtf8("CurrentFolder"));
        CurrentFolder->setGeometry(QRect(10, 35, 81, 21));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 46, 21));
        CurrentFile = new QLabel(groupBox);
        CurrentFile->setObjectName(QString::fromUtf8("CurrentFile"));
        CurrentFile->setGeometry(QRect(90, 35, 71, 21));
        progressBar = new QProgressBar(groupBox);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(160, 35, 211, 23));
        progressBar->setValue(24);
        progressBar->setAlignment(Qt::AlignCenter);
        CancelBtn = new QPushButton(groupBox);
        CancelBtn->setObjectName(QString::fromUtf8("CancelBtn"));
        CancelBtn->setGeometry(QRect(380, 30, 75, 30));
        groupBox_2 = new QGroupBox(UDialogClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 20, 471, 131));
        MangaEdit = new QLineEdit(groupBox_2);
        MangaEdit->setObjectName(QString::fromUtf8("MangaEdit"));
        MangaEdit->setGeometry(QRect(160, 95, 81, 20));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 25, 101, 16));
        GetBtn = new QPushButton(groupBox_2);
        GetBtn->setObjectName(QString::fromUtf8("GetBtn"));
        GetBtn->setGeometry(QRect(390, 40, 75, 30));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(160, 75, 101, 16));
        NumberEdit = new QLineEdit(groupBox_2);
        NumberEdit->setObjectName(QString::fromUtf8("NumberEdit"));
        NumberEdit->setGeometry(QRect(30, 95, 81, 20));
        UrlEdit = new QLineEdit(groupBox_2);
        UrlEdit->setObjectName(QString::fromUtf8("UrlEdit"));
        UrlEdit->setGeometry(QRect(10, 45, 361, 20));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 75, 101, 16));
        groupBox_3 = new QGroupBox(UDialogClass);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 160, 471, 111));
        DirEdit = new QLineEdit(groupBox_3);
        DirEdit->setObjectName(QString::fromUtf8("DirEdit"));
        DirEdit->setGeometry(QRect(10, 40, 361, 20));
        DirEdit->setReadOnly(false);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 20, 111, 16));
        FindBtn = new QPushButton(groupBox_3);
        FindBtn->setObjectName(QString::fromUtf8("FindBtn"));
        FindBtn->setGeometry(QRect(390, 35, 75, 30));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 80, 201, 16));

        retranslateUi(UDialogClass);

        QMetaObject::connectSlotsByName(UDialogClass);
    } // setupUi

    void retranslateUi(QDialog *UDialogClass)
    {
        UDialogClass->setWindowTitle(QApplication::translate("UDialogClass", "UrbGet - Get What You Want, Man", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("UDialogClass", "Download", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("UDialogClass", "Page:", 0, QApplication::UnicodeUTF8));
        CurrentFolder->setText(QApplication::translate("UDialogClass", "<CurrentFolder>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("UDialogClass", "Manga:", 0, QApplication::UnicodeUTF8));
        CurrentFile->setText(QApplication::translate("UDialogClass", "<CurrentFile>", 0, QApplication::UnicodeUTF8));
        CancelBtn->setText(QApplication::translate("UDialogClass", "Cancel", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("UDialogClass", "Manga", 0, QApplication::UnicodeUTF8));
        MangaEdit->setText(QApplication::translate("UDialogClass", "OnePiece", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("UDialogClass", "Url of the first page:", 0, QApplication::UnicodeUTF8));
        GetBtn->setText(QApplication::translate("UDialogClass", "Get", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("UDialogClass", "Name of the Manga:", 0, QApplication::UnicodeUTF8));
        NumberEdit->setText(QApplication::translate("UDialogClass", "5", 0, QApplication::UnicodeUTF8));
        UrlEdit->setText(QApplication::translate("UDialogClass", "http://img55.onemanga.com/mangas/00000004/000100772/01.jpg", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("UDialogClass", "Number of Mangas:", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("UDialogClass", "Output Settings", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("UDialogClass", "Destination Directory:", 0, QApplication::UnicodeUTF8));
        FindBtn->setText(QApplication::translate("UDialogClass", "Find", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("UDialogClass", "Warning: it is not checked if dir is valid!", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(UDialogClass);
    } // retranslateUi

};

namespace Ui {
    class UDialogClass: public Ui_UDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDIALOG_H
