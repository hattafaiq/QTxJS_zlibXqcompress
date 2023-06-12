#include <QCoreApplication>
#include <QApplication>
#include "tampil.h"

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    QApplication a(argc, argv);
    QApplication::setOrganizationName("buak folder aset");
    QApplication::setApplicationName("server");
    Tampil d;
    return a.exec();
}
