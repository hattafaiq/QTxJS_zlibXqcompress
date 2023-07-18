#include "tampil.h"
#include "ui_tampil.h"
#include "strc.h"
#include "QDateTime"

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
    }
    else{
        qDebug()<<"buka db"<<filename;
    }
    //////////////////////////
    box1 = new QVBoxLayout(this);
    QLabel *judul1;
    judul1 = new QLabel(this);
    QString aa;
    QString text1;
    //proses_q(query,"SELECT ALL id FROM parameter WHERE true");
    aa = QString("SELECT ALL id_database FROM info_db WHERE true");
    if(!buka.exec(aa)){qDebug()<<"tidak ada";}
    else{ while(buka.next()){
        text1 = "Daftar Semua Data Client ID:"+QString::number(buka.value("id_database").toInt());
        id_database = buka.value("id_database").toInt();
    }}
    judul1->setText(text1);
    ui->verticalLayout->addWidget(judul1);
    ui->verticalLayout->addLayout(box1);
    mulai_cari(&buka);
}

void Tampil::persiapan_server()
{
    box2 = new QVBoxLayout(this);
    QLabel *judul1;
    judul1 = new QLabel(this);
    QString aa;
    QString text1;
    text1 = "Daftar Semua Data Server";
    judul1->setText(text1);
    ui->verticalLayout_2->addWidget(judul1);
    ui->verticalLayout_2->addLayout(box2);
}


void Tampil::mulai_cari(QSqlQuery *query)
{
    //cari ada berapa rute

    QStringList rute;
    QString qu;
    QList<int> RuteList;
    qu = QString("SELECT ALL id, nama_rute, id_date FROM rute WHERE true");
    if(!query->exec(qu)) qDebug()<< __FUNCTION__ << __LINE__ << "ERROR : "<<query->lastError().text();
    else{
     while(query->next()){
        RuteList.push_back(query->value("id").toInt());
      //  info_rute[0].push_back(query->value("id").toInt());
        rute.push_back(query->value("nama_rute").toString());
        rute_.push_back(query->value("nama_rute").toString());
        //qDebug()<<"list rute"<<query->value("nama_rute").toString() << info_rute[0];
     }}
    //
    //
    //
    //temukan id_param by rute di tabel data_masuk
    //----------------------------------------------------------------------------------------------//
    QString qa;
    QStringList RChild;
    foreach ( int a, RuteList) {RChild.push_back(QString::number(a)); qDebug()<<a;}
//    query->clear();
    qa=QString("SELECT * FROM data_masuk WHERE id_rute IN (%1)").arg(RChild.join(","));
    if(!query->exec(qa)){}
    else{while(query->next()){
            qDebug()<<"-"
                    //  <<"rute"<<rute_[info_rute[0][i]]*/
                   <<"id_masuk"<<query->value("id").toInt()
                  <<"id_param"<<query->value("id_param").toInt()
                 <<"tipe_param"<<query->value("id_tipe_param").toInt()
                <<"id_rute"<<query->value("id_rute").toInt();
                info_tipe_data[0].push_back(query->value("id_rute").toInt());
               // info_tipe_data[1].push_back(query->value("id").toInt());
                info_tipe_data[2].push_back(query->value("id_param").toInt());
                info_tipe_data[3].push_back(query->value("id_tipe_param").toInt());
                info_tipe_data[4].push_back(query->value("id_date").toInt());
            }
        }
    //}
    //temukan timestamp data_tipe
    //
    //
    for(int i=0; i<info_tipe_data[0].size(); i++){
        QString tipe_data = get_table_name(info_tipe_data[3][i]);
        qu = QString("SELECT data,data_timestamp FROM %1 WHERE id_param=%2 AND id_date=%3").arg(tipe_data.toUtf8().data(),QString::number(info_tipe_data[2][i]),QString::number(info_tipe_data[4][i]));
        if(!query->exec(qu)) qDebug()<< __FUNCTION__ << __LINE__ << "ERROR : "<<query->lastError().text();
        else{while(query->next()){
             qDebug()<<id_database<<"timestamp"
                    <<query->value("data_timestamp").toInt()
                    <<"tipe     :" << info_tipe_data[3][i]
                    <<"id_param :" << info_tipe_data[2][i]
                    <<"id_date  :" << info_tipe_data[4][i];
             info_tipe_data[1].push_back(query->value("data_timestamp").toInt());
             QByteArray data = query->value("data").toByteArray();
             qDebug()<<"size data:"<<data.size();
             all_data.append(query->value("data").toByteArray());
             qDebug()<<"size data tampung:"<<all_data[i].size();
             qDebug()<<"data:"<<data.size();
             struct  t_kom_dat drute;
             memcpy( (char *) &drute.rute, data.data(), sizeof(drute.data));
             QString list_nama_asetku;
             list_nama_asetku+=QString::number(info_tipe_data[0][i]);//rute[info_tipe_data[0][i]];
             list_nama_asetku+="/";
             list_nama_asetku+=drute.rute.inisial;
             list1 = new QLabel(this);
             box1->addWidget(list1);
             list1->setText(list_nama_asetku);
         }}
    }
}

void Tampil::mulai_cari_server(QSqlQuery *query)
{
    QString qu;
    QVector<int> id_rute;
    int last_id_rute=0;
   // QDateTime waktu;
    qint64 date_1;
    date_1 = QDateTime::currentMSecsSinceEpoch() ;
    qDebug()<<"1start"<<date_1;
   //------------------------------------------------------------------------------------------------------------------//
    //masukkan rute terlebih dahulu sejumlah rute
    //
    //
    for(int i=0; i<rute_.size(); i++){
        QString rute = (QString)rute_[i];
        qu = QString("INSERT INTO rute (nama_rute,id_database)"
                     " SELECT '%1',%2 WHERE NOT EXISTS (SELECT nama_rute,id_database FROM rute WHERE nama_rute='%3' AND id_database=%4)").
                arg(rute,QString::number(id_database),
                rute,QString::number(id_database));
        if(!query->exec(qu)) {qDebug()<< "ERROR:: " <<query->lastError().text();}
        else{
            while(query->next()){
                id_rute.push_back(query->lastInsertId().toInt());
            }
        }

    }
   // QDateTime waktu2;
    qint64 date_2;
    date_2 = QDateTime::currentMSecsSinceEpoch() ;
    qDebug()<<"2time="<<date_2-date_1 <<" ms"<<"->memasukkan semua info rute";
    //------------------------------------------------------------------------------------------------------------------//
    //ketika rute sudah masuk mulai memasukkan isi rute sejumlah data yang existing
    //
    //mengurutkan id sesuai dengan nama id // mengecek ulang data
    for(int i=0; i<info_tipe_data[0].size(); i++){
        qDebug()<<"rute:"<<info_tipe_data[0][i] <<"|tiemstamp:"<< info_tipe_data[1][i] <<"|param:"<< info_tipe_data[2][i]
                <<"|tipe:"<<info_tipe_data[3][i]<<"id_date  :" << info_tipe_data[4][i];
       QString list_nama_asetku;
        list_nama_asetku+=QString::number(info_tipe_data[0][i]);//rute[info_tipe_data[0][i]];
        list_nama_asetku+="/";
        list_nama_asetku+= QString::number(info_tipe_data[1][i]);
        list2 = new QLabel(this);
        box2->addWidget(list2);
        list2->setText(list_nama_asetku);

    }

    //QDateTime waktu3;
    qint64 date_3;
    date_3 = QDateTime::currentMSecsSinceEpoch() ;
    qDebug()<<"3time="<<date_3-date_2 <<" ms"<<"->menata ulang data isi_rute";
 //------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------__coba masukin isi_rute oke better karena datanya bisa masuk>>
    QByteArray datax;
    datax.resize(500);
    for(int i=0; i<info_tipe_data[0].size(); i++){
        QString qa;
                qa.sprintf("INSERT INTO rute_isi (id_rute,id_tipe_param,id_last_param,kanal,param_setting,setting_rute)"
                           " SELECT :id_rute,:id_tipe_param,:id_last_param,:kanal,:param_setting,:setting_rute "
                           "WHERE NOT EXISTS (SELECT id_rute,id_last_param FROM rute_isi "
                           "WHERE id_rute=:id_rute AND id_last_param=:id_last_param)");
                query->exec("pragma synchronous = off;");
                query->prepare(qa);
                query->bindValue(":id_rute",info_tipe_data[0][i]);
                query->bindValue(":id_tipe_param",info_tipe_data[3][i]);
                query->bindValue(":id_last_param",info_tipe_data[2][i]);
                query->bindValue(":kanal",1);
                query->bindValue(":param_setting",datax);
                query->bindValue(":setting_rute",datax);
                query->exec();
    }
//------------------------------------------------------__>>
//------------------------------------bisa masukin data----->>
    qint64 date_4;
    date_4 = QDateTime::currentMSecsSinceEpoch() ;
    qDebug()<<"4time="<<date_4-date_3<<" ms" <<"->memasukkan data isi_rute";
    for(int i=0; i<info_tipe_data[0].size(); i++){
         QString tipe_data = get_table_name(info_tipe_data[3][i]);

        QString qa;
        qa.sprintf("INSERT INTO %s (id_rute,data,flag_set_param,data_timestamp)"
                     " SELECT :id_rute,:data,:flag_set_param,:data_timestamp "
                     "WHERE NOT EXISTS (SELECT id_rute,data_timestamp FROM %s "
                     "WHERE id_rute=:id_rute AND data_timestamp=:data_timestamp)",
                      tipe_data.toUtf8().data(),tipe_data.toUtf8().data());
                        query->exec("pragma synchronous = off;");
                        query->prepare(qa);
                        query->bindValue(":id_rute",info_tipe_data[0][i]);
                        query->bindValue(":data",all_data[i]);
                        query->bindValue(":flag_set_param",0);
                        query->bindValue(":data_timestamp",info_tipe_data[1][i]);
                        query->exec();
    }
//------------------------------------------------------------------------------------------------------------------//
//to do
    //-data apa saja yang digunakan untuk informasi
    //-protokolnya seperti apa
    //-model datanya seperti apa
    //-dan sistem validasinya seperti apa
    //-------------compare----------------------------//
    //1. (client)info dari data tiap rute client semua dikirim sebagai info keserver? misalnya banyak? (kirim ke server)
    //2. (server) server melakukan validasi siapa saja yang data tiap rute yang dikirim tadi tidak ada di database (kirim ke client)
    //poin 2 bagaimana metode yang tepat untuk membandingkan dari data client ke data server?
    //selanjutnya bagaimana proses lanjutannya setelah sudah dibandingkan dan tinggal beberapa data saja sisa yang harus masuk?
    //-------------synchronize----------------------------//
    //3. (client) client menjawab list datanya (kirim ke server)
    //4. (server) ketika client sudah menjawab siapa saja yang harus dipindahkan baru beraksi todo insert rute,rute_isi,data%
    qint64 date_5;
    date_5 = QDateTime::currentMSecsSinceEpoch() ;
    qDebug()<<"5 time="<<date_5-date_4 << " ms"<<"->memasukkan semua data";
    qDebug()<<"5 end="<<date_5;
    qDebug()<<"ovrall time="<<date_5-date_1<<" ms";
}

QString Tampil::get_table_name(int tipe)
{
    QString nama_tabel = QString("data_%1_tipe").arg(tipe);
    return nama_tabel;
}

void Tampil::on_pushButton_clicked()
{
    compare();
}

void Tampil::compare()
{
    QSqlQuery querty(dbx);
    mulai_cari_server(&querty);
}

void Tampil::synchronize()
{

}


void Tampil::on_pushButton_2_clicked()
{
    synchronize();
}

