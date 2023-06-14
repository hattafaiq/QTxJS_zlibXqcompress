#include "tiago.h"
#include <QDebug>
tiago::tiago()
{
   buat_bongkar();
}

void tiago::buat_bongkar()
{
    QJsonDocument dok;
    QJsonObject obj;
    QJsonObject obj2;

    obj.insert("name","DBE");
    dok.setObject(obj);
    obj.insert("name1","marsal");
    dok.setObject(obj);
    obj.insert("name2","marsal2");
    dok.setObject(obj);
    obj.insert("name2","marsal3");
    dok.setObject(obj);

    //for(int i=0; i<dok.object().count(); i++){
        //qDebug()<<obj.;
    //}
}
