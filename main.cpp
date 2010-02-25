#include <QtGui/QApplication>
#include "udialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UDialog w;
    w.show();
    return a.exec();
}
