#include "pars.h"

pars::pars()
{

}
static void process_line(const QString &)
{

}

int pars::buka_list_file(QString line)
{
    QFile file("modules.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           return 1;

       QTextStream in(&file);
        line= in.readLine();
       while (!line.isNull()) {
           process_line(line);
           line = in.readLine();
           qDebug()<<line;
       }
}

void pars::parsing()
{
    struct t_m masuk;
    struct t_info info;
    struct t_c *masuk2;
    struct t_info* info2;
    info.kind[0]=100;
    info.kind[1]=200;
    info.kind[2]=300;
    info.kind[3]=800;
    masuk.gol =900;

    char buffTemp[sizeof(t_m)];
    memcpy(buffTemp, &masuk, sizeof(t_m));
    QByteArray data1 = QByteArray::fromRawData(buffTemp,sizeof(t_m));
    char buffTempa[sizeof(t_info)];
    memcpy(buffTempa, &info, sizeof(t_info));
    QByteArray infor = QByteArray::fromRawData(buffTempa,sizeof(t_info));
    //pemindahan aset dari split .
    QByteArray hirarki = "comp.pab.DBE.Engine1.=";
        // || aset----- || info kind dll || setting ||
        data1.push_back(infor);
        QByteArray data = data1.prepend(hirarki);

        qDebug()<<"size hirar="<<hirarki.size();

        QByteArray bb = data.mid(hirarki.size(),sizeof (t_m));
            masuk2 =(struct t_c *)bb.data();
            qDebug() <<"setting:"<< masuk2->gol;
        QByteArray bs = data.mid(hirarki.size()+sizeof (t_c),sizeof (t_info));
            info2 =(struct t_info *)bs.data();

        qDebug()<<"data yang nanti dikirim="<<data;
        QString olah = (QString )data;
        QStringList cacah = olah.split(".");
        qDebug() << cacah;
        QString aset;
        for(int i=0; i<cacah.size()-1; i++){
            aset = cacah[i];
            qDebug() <<"| nama aset " <<cacah[i]<<"|" << info2->kind[i]<<"|";
            qDebug()<<"+--------------------------+";
        }
        //pemindahan data dari string list ke struct
}

void pars::buat_file(QString path){
    QDir dir;
    // We create the directory if needed
    if (!dir.exists(path))
        dir.mkpath(path); // You can check the success if needed
    QFile file(path + "NewFile.txt");
    file.open(QIODevice::WriteOnly); // Or QIODevice::ReadWrite
    //setiap nambah atau kurangi file harus dicatat di log/config
    struct t_m masuk;
    struct t_info info;
    struct t_c *masuk2;
    struct t_info* info2;
    info.kind[0]=100;
    info.kind[1]=200;
    info.kind[2]=300;
    info.kind[3]=800;
    masuk.gol =900;

    char buffTemp[sizeof(t_m)];
    memcpy(buffTemp, &masuk, sizeof(t_m));
    QByteArray data1 = QByteArray::fromRawData(buffTemp,sizeof(t_m));
    char buffTempa[sizeof(t_info)];
    memcpy(buffTempa, &info, sizeof(t_info));
    QByteArray infor = QByteArray::fromRawData(buffTempa,sizeof(t_info));
    QByteArray hirarki = "comp.pab.DBE.Engine1.=";
    // || aset----- || info kind dll || setting ||
    data1.push_back(infor);
    QByteArray data = data1.prepend(hirarki);//datanya
    if(!file.isOpen())
    {
        //alert that file did not open
    }
    QTextStream outStream(&file);
   // outStream << "\n";
    outStream << data;

    file.close();
}

void pars::delete_file(QString path){
    QFile file (path);
    if(!file.exists())qDebug()<<"data salah";
    else file.remove();
    //setiap nambah atau kurangi file harus dicatat di log/config
}


