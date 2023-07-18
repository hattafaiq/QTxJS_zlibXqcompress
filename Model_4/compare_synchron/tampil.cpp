#include "tampil.h"
#include "ui_tampil.h"
#include "strc.h"

Tampil::Tampil(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tampil)
{
    ui->setupUi(this);

    dbx = QSqlDatabase::addDatabase("QMYSQL");
    dbx.setHostName("127.0.0.1");
    dbx.setDatabaseName("test");
    dbx.setUserName("root");
    dbx.setPassword("password");
    //int i=0;
    if (!dbx.open())
    {
      QMessageBox::critical(0, QObject::tr("Database Error"),dbx.lastError().text());

    }else{
      QMessageBox::information(this,"connected","database masuk");
      open_db();
      persiapan_server();
      this->show();
    }
}

Tampil::~Tampil()
{
    delete ui;
}

void Tampil::open_db()
{
    QString filename = "rotatinghal.dbb";
    QString con_name;
    con_name = QString("LOC_DB%1").arg(1);
    db =QSqlDatabase::addDatabase("QSQLITE",con_name);
    db.setDatabaseName(filename);
    QSqlQuery buka(db);
    if(!db.open())
    {
      qDebug()<<"db gak kebukak";
      //return;
    }
    else{
        qDebug()<<"buka db"<<filename;
    }

    //////////////////////////
    box = new QVBoxLayout(this);
    QLabel *judul1;
    judul1 = new QLabel(this);
    QString aa;
    QString text1;
    //proses_q(query,"SELECT ALL id FROM parameter WHERE true");
    aa = QString("SELECT ALL id_database FROM info_db WHERE true");
    if(!buka.exec(aa)){qDebug()<<"tidak ada";}
    else{
    while(buka.next()){
        text1 = "Daftar Semua Data Client ID:"+QString::number(buka.value("id_database").toInt());
        id_database = buka.value("id_database").toInt();
    }}
    judul1->setText(text1);
    ui->verticalLayout->addWidget(judul1);
    ui->verticalLayout->addLayout(box);
    cari_data(&buka);
}

void Tampil::persiapan_server()
{
    QSqlQuery querty(dbx);
    box2 = new QVBoxLayout(this);
    QLabel *judul1;
    judul1 = new QLabel(this);
    QString aa;
    QString text1;
    text1 = "Daftar Semua Data Server";
    judul1->setText(text1);
    ui->verticalLayout_2->addWidget(judul1);
    ui->verticalLayout_2->addLayout(box2);
    cari_data_server(&querty);
}

void Tampil::cari_data_server(QSqlQuery *query)
{
    QString aa;
    //proses_q(query,"SELECT ALL id FROM parameter WHERE true");
    aa = QString("SELECT ALL id,id_tipe_param,id_aset FROM parameter WHERE true");
    if(!query->exec(aa)){qDebug()<<"tidak ada";}
    else{
    //if(query->first()){qDebug()<<"ada=";}
    while(query->next()){
   // qDebug()<< query->value("id").toInt() << query->value("id_tipe_param").toInt();
    int id = query->value("id").toInt();
    int tipe = query->value("id_tipe_param").toInt();
    info_data_server[0].push_back(id);
    info_data_server[1].push_back(tipe);
    info_data_server[2].push_back(query->value("id_aset").toInt());
    //masuk_tipe_data(id,tipe);
    qDebug()<<"id:" <<id<<"|tipe:"<<tipe<<"|aset:"<<query->value("id_aset").toInt();
    }}
         qDebug()<<"sudah cari parameter";
//------------------stop dari param dulu karena hanya mengecek keberadaan param saja---//
     masuk_tipe_data_server(query);
}

void Tampil::cari_anak_aset(QSqlQuery *query,int aset){
    QString aa;
    aa = QString("SELECT id FROM aset WHERE id_parent=%1").arg(aset);
    if(!query->exec(aa)){qDebug()<<"tidak ada anak";}
    else{
    while(query->next()){
        qDebug()<<query->value("id").toInt();
        cari_param.push_back(query->value("id").toInt());
        cari_anak_aset(query,query->value("id").toInt());
    }}
}


void Tampil::cari_data(QSqlQuery *query)
{
    QString aa;
    //proses_q(query,"SELECT ALL id FROM parameter WHERE true");
    aa = QString("SELECT ALL id,id_tipe_param,id_aset FROM parameter WHERE true");
    if(!query->exec(aa)){qDebug()<<"tidak ada";}
    else{
    //if(query->first()){qDebug()<<"ada=";}
    while(query->next()){
   // qDebug()<< query->value("id").toInt() << query->value("id_tipe_param").toInt();
    int id = query->value("id").toInt();
    int tipe = query->value("id_tipe_param").toInt();
    info_data[0].push_back(id);
    info_data[1].push_back(tipe);
    info_data[2].push_back(query->value("id_aset").toInt());
    //masuk_tipe_data(id,tipe);
    qDebug()<<"id:" <<id<<"|tipe:"<<tipe<<"|aset:"<<query->value("id_aset").toInt();
    }}
         qDebug()<<"sudah cari parameter";
//------------------stop dari param dulu karena hanya mengecek keberadaan param saja---//
     masuk_tipe_data(query);
}

QString Tampil::get_table_name(int tipe)
{
    QString nama_tabel = QString("data_%1_tipe").arg(tipe);
    return nama_tabel;
}

void Tampil::masuk_tipe_data(QSqlQuery *query)
{

    QString s;
    QString nama_rute;
    s = QString("SELECT ALL nama_rute FROM rute WHERE true");
    if(!query->exec(s)){qDebug()<< __FUNCTION__ << __LINE__ << "ERROR : "<<query->lastError().text();
    }
    else
    {
        while (query->next())
        {
            nama_rute = query->value("nama_rute").toString();
        }
    }
    qDebug()<<"-------------------------->client"<<info_data->size();
    for(int i=0; i<info_data->size(); i++){
    QString qu;
    qDebug()<<"cari tipe: "<<info_data[1][i]<<"|"<<"param:"<<info_data[0][i];
    qu = QString("SELECT id,id_param,data FROM %1 WHERE id_param=%2").arg(get_table_name(info_data[1][i]),QString::number(info_data[0][i]));
    if(!query->exec(qu)){qDebug()<< __FUNCTION__ << __LINE__ << "ERROR : "<<query->lastError().text()<<
                                    "tipe: "<<info_data[1][i]<<"|"<<"param:"<<info_data[0][i];
    }
    else
    {
        while (query->next())
        {
            QByteArray data = query->value("data").toByteArray();
            qDebug()<<"data:"<<data.size();
            if(info_data[1][i]==41 || info_data[1][i]==42 || info_data[1][i]==43){
                ///  | ..t_rute.. | ..t_info_rotat.. | ..data_sp.. | ..data_wf.. | dd_rotat |
                /// struct  t_kom_dat       drute;
                struct  t_kom_dat       drute;
                //char    *data_recip;
                memcpy( (char *) &drute.rute, data.data(), sizeof(drute.data));
                //cek
                qDebug()<<"hasil:"<<info_data[1][i]<<drute.rute.id_tipe_param<<drute.rute.inisial;
                QString list_nama_asetku;
                list_nama_asetku+=nama_rute;
                list_nama_asetku+="/";
                list_nama_asetku+=drute.rute.inisial;
               // info_name_aset_server.push_back(drute.rute.inisial);
                labelku = new QLabel(this);
                box->addWidget(labelku);
                labelku->setText(list_nama_asetku);
                cacah_data_name.push_back(list_nama_asetku);
                list_nama_asetku.clear();
      }}
   }}
}

void Tampil::masuk_tipe_data_server(QSqlQuery *query)
{
    //    cari_data_param[0].push_back(query->value("id").toInt());
    //    cari_data_param[1].push_back(query->value("id_tipe_param").toInt());
    //    cari_data_param[2].push_back(query->value("id_aset").toInt());
        qDebug()<<"-------------------------->server"<<info_data_server->size();
        for(int i=0; i<info_data_server->size(); i++){
        QString qu;
        qDebug()<<"cari tipe: "<<info_data_server[1][i]<<"|"<<"param:"<<info_data_server[0][i];
        qu = QString("SELECT id,id_param,data FROM %1 WHERE id_param=%2").arg(get_table_name(info_data_server[1][i]),QString::number(info_data_server[0][i]));
        if(!query->exec(qu)){qDebug()<< __FUNCTION__ << __LINE__ << "ERROR : "<<query->lastError().text()<<
                                        "tipe: "<<info_data_server[1][i]<<"|"<<"param:"<<info_data_server[0][i];
        }
        else
        {
            while (query->next())
            {
                QByteArray data = query->value("data").toByteArray();
                qDebug()<<"data:"<<data.size();
                if(info_data_server[1][i]==41 || info_data_server[1][i]==42 || info_data_server[1][i]==43){
                    ///  | ..t_rute.. | ..t_info_rotat.. | ..data_sp.. | ..data_wf.. | dd_rotat |
                    /// struct  t_kom_dat       drute;
                    struct  t_kom_dat       drute;
                    //char    *data_recip;
                    memcpy( (char *) &drute.rute, data.data(), sizeof(drute.data));
                    //cek
                    qDebug()<<"hasil:"<<info_data_server[1][i]<<drute.rute.id_tipe_param<<drute.rute.inisial;
//                    QString list_nama_asetku;
//                    list_nama_asetku+="DBE";
//                    list_nama_asetku+="/";
//                    list_nama_asetku+=drute.rute.inisial;
//                    info_name_aset_server.push_back(list_nama_asetku);

//                    labelku2 = new QLabel(this);
//                    box2->addWidget(labelku2);
//                    labelku2->setText(list_nama_asetku);
//                    cacah_data_name.push_back(list_nama_asetku);
//                    //cacah_data_name.push_back(initial_rute);
//                    list_nama_asetku.clear();
                    cari_induk_paramm_server(info_data_server[0][i],info_data_server[1][i],query->value("id").toInt());
          }}
       }}
}

void Tampil::cari_induk_paramm(int parameter, int tipe, int id_data)
{
    QSqlQuery Q2( db );
    int id_aset_induk;
    int id_parent_ku;
    QString qu;
    qu = QString("SELECT id_aset FROM parameter WHERE id=%1").arg(parameter);
    if(!Q2.exec(qu)) qDebug()<< __FUNCTION__ << __LINE__ << "ERROR : "<<Q2.lastError().text();
    else
    {
        while (Q2.next())
        {
         id_aset_induk = Q2.value("id_aset").toInt();
         qDebug()<<"parent1:"<<id_aset_induk;
         cari_induk(id_aset_induk);
      }
   }
}

void Tampil::cari_induk_paramm_server(int parameter, int tipe, int id_data)
{
    qDebug()<<"cari param server";
    QSqlQuery Q2( dbx );
    int id_aset_induk;
    int id_parent_ku;
    QString qu;
    qu = QString("SELECT id_aset FROM parameter WHERE id=%1").arg(parameter);
    if(!Q2.exec(qu)) qDebug()<< __FUNCTION__ << __LINE__ << "ERROR : "<<Q2.lastError().text();
    else
    {
        while (Q2.next())
        {
         id_aset_induk = Q2.value("id_aset").toInt();
         qDebug()<<"parent1:"<<id_aset_induk;
         cari_induk_server(id_aset_induk);
      }
   }
}

void Tampil::cari_induk(int p_id_aset){

    QSqlQuery Q3( db );
    QString nama;
    int id_aset_induk;
    int id_parent_ku;
    QString qu;
    qu = QString("SELECT * FROM aset WHERE id=%1").arg(p_id_aset);
    if(!Q3.exec(qu)) qDebug()<< __FUNCTION__ << __LINE__ << "ERROR : "<<Q3.lastError().text();
    else{
     while(Q3.next()){
        id_parent_ku = Q3.value("id_parent").toInt();
        nama = Q3.value("name").toString();
        qDebug()<<"parent:"<<id_parent_ku << "|nama:"<<nama;
        nama+="/";
        initial_rute.prepend(nama);
        if(id_parent_ku!=0){
            cari_induk(id_parent_ku);
        }
        else{
            labelku = new QLabel(this);
            //boxlabelku = new QCheckBox(this);
            box->addWidget(labelku);
            labelku->setText(initial_rute);
            //boxlabelku->setText(initial_rute);
            //boxlabelku->setChecked(true);
            //cacah_data_name.push_back(initial_rute);
            initial_rute.clear();
            qDebug()<<"emit";
        }
     }
   }
}

void Tampil::cari_induk_server(int p_id_aset){
    qDebug()<<"cari induk server";
    QSqlQuery Q3( dbx );
    QString nama;
    int id_aset_induk;
    int id_parent_ku;
    QString qu;
    qu = QString("SELECT * FROM aset WHERE id=%1").arg(p_id_aset);
    if(!Q3.exec(qu)) qDebug()<< __FUNCTION__ << __LINE__ << "ERROR : "<<Q3.lastError().text();
    else{
     while(Q3.next()){
        id_parent_ku = Q3.value("id_parent").toInt();
        nama = Q3.value("name").toString();
        qDebug()<<"parent:"<<id_parent_ku << "|nama:"<<nama;
        nama+="/";
        initial_rute2.prepend(nama);
        if(id_parent_ku!=0){
            cari_induk_server(id_parent_ku);
        }
        else{
            labelku2 = new QLabel(this);
            //boxlabelku2 = new QCheckBox(this);
            box2->addWidget(labelku2);
            //box2->addWidget(boxlabelku2);
            labelku2->setText(initial_rute2);
            //boxlabelku2->setText(initial_rute2);
            //boxlabelku2->setChecked(true);
            //cacah_data_name.push_back(initial_rute2);
            initial_rute2.clear();
            qDebug()<<"emit";
        }
     }
   }
}

void Tampil::on_pushButton_clicked()
{
    box3 = new QVBoxLayout(this);
    QLabel *judul1;
    judul1 = new QLabel(this);
    QString text1;
    text1 = "Daftar Semua Data Compired";
    judul1->setText(text1);
    ui->verticalLayout_4->addWidget(judul1);
    ui->verticalLayout_4->addLayout(box3);
    compare();
}

void Tampil::compare()
{
    qDebug()<<"compare"<<cacah_data_name.size()<<cacah_data_name;
    int flag_masukkan_param=0;
    QSqlQuery Q3( dbx );
    QSqlQuery Q4( dbx );
    int id_parent=0;
    //buat rute nya dulu dari aset
    for(int i=0; i<cacah_data_name.size(); i++){
        QString nama_aset = cacah_data_name[i];
        QStringList data_satuan_cacah = nama_aset.split('/');
        for(int k=0; k<data_satuan_cacah.size(); k++){
        QString nama_rute = (QString)data_satuan_cacah[k];
        QString qu;
        qu = QString("SELECT id FROM aset WHERE name='%1'").arg(nama_rute);
        if(!Q3.exec(qu)) {qDebug()<< "tidak ada: "<<nama_rute;
        }
        if(Q3.first()){qDebug()<< "ada rute: "<<nama_rute;
        id_parent = Q3.value("id").toInt();
        }
        else{
            qDebug()<< "tidak ada rute: "<<nama_rute;
            qu.clear();
            qu = QString("INSERT INTO aset ( name, id_kind, id_parent, id_database, id_user) VALUES('%1',%2,%3,%4,%5)").arg(nama_rute,QString::number(0),QString::number(id_parent),QString::number(id_database),QString::number(0));
            if(!Q3.exec(qu)) {qDebug()<< "tidak ada: "<<nama_rute;}
            else{qDebug()<<"masuk rutenya";}

            qu.clear();
            qu = QString("INSERT INTO rute ( nama_rute, id_aset, id_date) VALUES('%1',%2,%3)").arg(nama_rute,QString::number(Q3.lastInsertId().toInt()),QString::number(0));
            if(!Q3.exec(qu)) {qDebug()<< "tidak ada: "<<nama_rute;}
            else{qDebug()<<"masuk rutenya";}
          }
    }}
    //cacah data pertama sebanyak urutan datanya
    qDebug()<<"info list server:"<<info_name_aset_server.size();
    for(int i=0; i<info_name_aset_server.size(); i++){
        //bongkar 1 persatu name
        QString satuan_name = info_name_aset_server[i];
        qDebug()<<"Paket data:"<<satuan_name;
        QStringList data_satuan_cacah = satuan_name.split('/');
            for(int k=0; k<data_satuan_cacah.size(); k++){
            QString nama = (QString) data_satuan_cacah[k];
            qDebug()<<"Satuan name:"<<nama;
            QString qu;
            qu = QString("SELECT id FROM aset WHERE name='%1'AND id_parent=%2").arg(satuan_name,QString::number(id_parent));
            if(!Q3.exec(qu)) {qDebug()<< "tidak ada: "<<satuan_name;}
            if(Q3.first()){qDebug()<<"ada="<<satuan_name;
            id_parent = Q3.value("id").toInt();
            }
            else {
              qDebug()<<"tidak ada2="<<satuan_name <<id_parent;
             // id_parent=0;
              flag_masukkan_param=1;
            }
            }
            int counter;
            counter+=flag_masukkan_param;
            qDebug()<<"counter"<<counter;
            if(flag_masukkan_param){
                labelku2 = new QLabel(this);
                boxlabelku2 = new QCheckBox(this);
                box3->addWidget(boxlabelku2);
                boxlabelku2->setText(satuan_name);
                boxlabelku2->setChecked(true);
                cacah_data_synchronize.push_back(satuan_name);
                flag_masukkan_param=0;
            }
    }
}

void Tampil::synchronize()
{
    qDebug()<<"kirim trigger";
    int flag_masukkan_param;
    QSqlQuery query1(dbx);
    QSqlQuery query2(dbx);
    int i;
    int id_parent=0;
    QStringList kantong_ada;
    QStringList kantong_tidak;
    QString aa;
    int id_aset=0;
    for(int z=0; z<cacah_data_synchronize.size(); z++){
        QStringList data_ini;
        QString urai = cacah_data_synchronize[z];
        data_ini = urai.split('/');
        for(i=0; i<data_ini.size()-1; i++){
            QString aset_ku = (QString) data_ini[i];

            aa = QString("SELECT id FROM aset WHERE name='%1'AND id_parent=%2 AND id_database=%3").arg(aset_ku,QString::number(id_parent),QString::number(id_database));
            if(!query1.exec(aa)){qDebug()<<"tidak ada1="<<aset_ku;}
            if(query1.first()){qDebug()<<"ada="<<aset_ku;
            id_parent = query1.value("id").toInt();
            }
            else {
              qDebug()<<"tidak ada2="<<aset_ku;
              flag_masukkan_param=1;

              //id_parent = query1.lastInsertId().toInt();
              aa = QString("INSERT INTO aset ( name, id_kind, id_parent, id_database, id_user) VALUES('%1',%2,%3,%4,%5)").arg(aset_ku,QString::number(0),QString::number(id_parent),QString::number(id_database),QString::number(0));
              if(!query1.exec(aa)){qDebug()<<"1gagal simpen"<<aset_ku;}
              else{while(query1.next())qDebug()<<"1sukses="<<aset_ku;}

              if(query1.first()){qDebug()<<"2sukses="<<aset_ku;}
              else{qDebug()<<"mulai simpen"<<aset_ku;
              id_parent = query1.lastInsertId().toInt();}

            }
            id_aset=query1.lastInsertId().toInt();
        }
        if(flag_masukkan_param==0){
            aa = QString("INSERT INTO parameter ( id_tipe_param, id_aset, urut) VALUES('%1',%2,%3)").arg(QString::number(410),QString::number(id_parent),QString::number(1));
            if(!query2.exec(aa)){qDebug()<<"1gagal simpen"<<id_aset;}
            else{while(query2.next())qDebug()<<"1sukses="<<id_aset;}

            if(query2.first()){qDebug()<<"2sukses="<<id_aset;}
            else{qDebug()<<"mulai simpen0"<<id_aset;}
        }
        else{
        aa = QString("INSERT INTO parameter ( id_tipe_param, id_aset, urut) VALUES('%1',%2,%3)").arg(QString::number(410),QString::number(id_aset),QString::number(1));
        if(!query2.exec(aa)){qDebug()<<"1gagal simpen"<<id_aset;}
        else{while(query2.next())qDebug()<<"1sukses="<<id_aset;}

        if(query2.first()){qDebug()<<"2sukses="<<id_aset;}
        else{qDebug()<<"mulai simpen1"<<id_aset;}
        flag_masukkan_param=0;
        }
    id_parent=0;
 }
}


void Tampil::on_pushButton_2_clicked()
{
    synchronize();
}

