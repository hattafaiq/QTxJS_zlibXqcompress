#include "tampil_utama.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tampil_utama w;
    w.show();
    return a.exec();
}
