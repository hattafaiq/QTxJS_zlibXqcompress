#include "pars.h"


pars::pars()
{
    struct t_m masuk;
    struct t_m *masuk2;
    masuk.gol =900;
    char buffTemp[sizeof(t_m)];
    memcpy(buffTemp, &masuk, sizeof(t_m));
    QByteArray data1 = QByteArray::fromRawData(buffTemp,sizeof(t_m));
    //pemindahan aset dari split .
    QByteArray hirarki = "comp.pab.DBE.Engine1.=";
    QByteArray data = data1.prepend(hirarki);
    qDebug()<<data;
    QString olah = (QString )data;
    QStringList cacah = olah.split(".");
    qDebug() << cacah;
    QString aset;
    for(int i=0; i<cacah.size()-1; i++){
        aset = cacah[i];
        qDebug() <<"aset="<< cacah[i];
        qDebug()<<"----------------------";
    }
    //pemindahan data dari string list ke struct
    QStringList mulai = olah.split("=");
    qDebug()<<"data:"<<mulai[1];
    QByteArray data_struct;
    data_struct+=mulai[1];
    qDebug()<<"data2:"<<data_struct;
    QByteArray bb = data_struct.left(sizeof (t_m));
    masuk2 =(struct t_m *)bb.data();
    qDebug() << masuk2->gol;
}
