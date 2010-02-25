#ifndef UDIALOG_H
#define UDIALOG_H

#include <QtGui/QDialog>
#include <QHttp>
#include <QFile>
#include <QEventLoop>
#include <QDir>
#include <QFileDialog>

namespace Ui
{
    class UDialogClass;
}

class UDialog : public QDialog
{
    Q_OBJECT

public:
    UDialog(QWidget *parent = 0);
    ~UDialog();

private:
    Ui::UDialogClass *ui;
    QHttp* http;
    QFile* file;
    QEventLoop loop;
    QDir* dir;
    QFileDialog* dialog;
    bool cancel;
    bool next;

private slots:
    void onGetBtnClicked();
    void downloadFinished(bool);
    void downloadProgress(int,int);
    void onCancelBtnClicked();
    void onFindBtnClicked();
};

#endif // UDIALOG_H
