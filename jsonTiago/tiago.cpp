#include "tiago.h"
#include <iostream>
#include <QPointF>
#include <qjsonmodel.h>


tiago::tiago()
{
   //buat_bongkar();
    bikin_array();
}

void tiago::bikin_array()
{
    QFile inFile("child1.json");
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    if (doc.isNull()) {
        qDebug() << "Parse failed";
    }
    qDebug()<<data;
    inFile.close();
}

void tiago::buat_bongkar()
{

    QFile inFile("faiq2.json");
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    if (doc.isNull()) {
        qDebug() << "Parse failed";
    }
    qDebug()<<doc.object();
    qDebug()<<doc.object().keys();
    QStringList datab= doc.object().keys();
    QStringList cari = {"DBE","marsal","prodev","motor2"};
    QStringList back_up[cari.size()];
    QString masukin_VibAcc = "Vib.acc";
    QString masukin_Motor = "Motor3";
    QJsonObject cari_yuk = doc.object();
    QJsonObject tambah;
    QJsonObject masuk_baru;
    QString sementara;
    QJsonValue nilainya[cari.size()];
    QJsonObject nilaiku[cari.size()];
    int flag_masukin_apa=0;
    //buka datanya
//         contents = jsonContents.toVariantMap();
    for(int i=0; i<cari.size(); i++){
        qDebug()<<cari_yuk.find(cari[i]).value();
        nilainya[i] = cari_yuk.find(cari[i]).value();//outputnya value
        nilaiku[i] = cari_yuk.find(cari[i]).value().toObject();//outputnya object
        cari_yuk = cari_yuk.find(cari[i]).value().toObject();//outputnya cari object
        if(i==cari.size()-2)tambah =cari_yuk.find(cari[i]).value().toObject();
    }
    //insert
    for(int i=(cari.size()-1); i>=0; --i){
        if(i==(cari.size()-1)){
        if(flag_masukin_apa==0)tambah.insert(masukin_VibAcc,"Nulls");
        else if(flag_masukin_apa==1)tambah.insert(masukin_Motor,"");

        }
        QByteArray suntik;
        if(cari[i]=="marsal"){
            qDebug()<<nilaiku[i].toVariantMap();
            QVariantMap map =nilaiku[i].toVariantMap();

            QVariantList l = qvariant_cast<QVariantList>(map["prodev"]);

        }
    }
    //qDebug()<<"B:"<<tambah;

    inFile.close();
}
