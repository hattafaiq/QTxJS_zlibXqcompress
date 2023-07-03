#include <QCoreApplication>
#include <QApplication>
#include "tampil.h"

static char buf_command[4096];
int proses_q( QSqlQuery *q, const char *s, ...)
{
    QSqlError er;
    va_list args;

    va_start (args, s);

       /* For this to work, printbuffer must be larger than
        * anything we ever want to print.
        */
    vsprintf (buf_command, s, args);
    va_end (args);

//    qDebug() << __PRETTY_FUNCTION__ << buf_command;
    //debug("%s(): %s",__FUNCTION__, buf_command );

    if (!q->exec( buf_command ))
    {
        er = q->lastError();
        qDebug() << "(debug 58) Querry Error : Data not Found! 1";
        qDebug("%s(): ERR : %s", __FUNCTION__, er.text().toUtf8().data());
        return -1;
    }
    else
    {
        /* untuk SQLITE harus manual ditunjukkan ke first sebelum bisa dipakai */
//        q->first();

        if(!q->first()){
            /* handler if query doesn't exist */
            qDebug() << "(debug 58) Querry Error : Data not Found! 2" << q->lastQuery();
           // setting.dat_avb = 0;
        }
        else{
//            qDebug() << "(debug 58) Data Found!";
           // setting.dat_avb = 1;
        }

        /* SQLITE size juga pasti akan -1 */
        //debug("%s(): OK, %d row", __FUNCTION__, q->size());
    }
    return 0;
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    QApplication a(argc, argv);
    QApplication::setOrganizationName("buak folder aset");
    QApplication::setApplicationName("server");
    Tampil d;
    return a.exec();
}
