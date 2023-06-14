#ifndef PARS_H
#define PARS_H
#include <QDebug>
#include <QByteArray>
#include "strc.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QFile>
#include <QDir>

class pars
{
public:
    pars();
    void parsing();
    int buka_list_file(QString line);
    void buat_file(QString path);
    void delete_file(QString path);
};

#endif // PARS_H
