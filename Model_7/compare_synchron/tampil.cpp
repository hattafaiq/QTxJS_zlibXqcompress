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
    box3 = new QVBoxLayout(this);
    QLabel *judul1;
    judul1 = new QLabel(this);
    QLabel *judul2;
    judul2 = new QLabel(this);
    QString text1;
    text1 = "List Belum Ada Di Server";
    judul1->setText(text1);
    QString text2;
    text2 = "List masuk ke Server";
    judul1->setText(text1);
    judul2->setText(text2);
    ui->verticalLayout_2->addWidget(judul1);
    ui->verticalLayout_4->addWidget(judul2);
    ui->verticalLayout_2->addLayout(box2);
    ui->verticalLayout_4->addLayout(box3);
}

void Tampil::mulai_cari(QSqlQuery *query)
{
    QVector<int> datax[4];
    QVector<int> data_[4];
    //mengecek keseluruhan data yang ada di data masuk
    QString qu;
            qu = QString("SELECT id,id_param,id_tipe_param,id_rute "
                 "FROM data_masuk"
                 " WHERE true");
    if(!query->exec(qu)) qDebug()<< __FUNCTION__ << __LINE__ << "ERROR : "<<query->lastError().text();
    else{while(query->next()){
        qDebug()<<query->value("id").toInt()
                <<query->value("id_param").toInt()
                <<query->value("id_tipe_param").toInt()
                <<query->value("id_rute").toInt();
        datax[0].push_back(query->value("id").toInt());
        datax[1].push_back(query->value("id_param").toInt());
        datax[2].push_back(query->value("id_tipe_param").toInt());
        datax[3].push_back(query->value("id_rute").toInt());
     }}

    //validasi ulang dari info rute apakah benar data masuk sesuai rute yang ada
    qu.clear();
    for(int i=0; i<datax[0].size(); i++){
        qu = QString("SELECT id_date "
             "FROM rute"
             " WHERE id=%1").arg(QString::number(datax[3][i]));
        if(!query->exec(qu)) qDebug()<< __FUNCTION__ << __LINE__ << "ERROR : "<<query->lastError().text();
        else{while(query->next()){
            data_[0].push_back(datax[0][i]);
            data_[1].push_back(datax[1][i]);
            data_[2].push_back(datax[2][i]);
            data_[3].push_back(datax[3][i]);
         }}
    }

    //mulai cari data berdasarkan time stamp nya
    for(int i=0; i<data_[0].size(); i++){
        qu = QString("SELECT data,data_timestamp "
                    "FROM %1"
                    " WHERE id_param=%2 AND id_data_masuk=%3").arg(get_table_name(data_[2][i]),QString::number(data_[1][i]),QString::number(data_[0][i]));
     if(data_[2][i]==3 || data_[2][i]==28){
     qu = QString("SELECT data,data_timestamp, siklus "
                 "FROM %1"
                 " WHERE id_param=%2 AND id_data_masuk=%3").arg(get_table_name(data_[2][i]),QString::number(data_[1][i]),QString::number(data_[0][i]));
        }
    if(!query->exec(qu)) qDebug()<< __FUNCTION__ << __LINE__ << "ERROR : "<<query->lastError().text();
    else{while(query->next()){
         all_data.append(query->value("data").toByteArray());
        qDebug()<<"tiem:"<<query->value("data_timestamp").toInt();
        data_n[0].push_back(data_[0][i]);//id_rute lama
        data_n[1].push_back(data_[1][i]);//id_param
        data_n[2].push_back(data_[2][i]);//id_tipe_param
        data_n[3].push_back(data_[3][i]);//id_rute
        data_n[4].push_back(query->value("data_timestamp").toInt());
        data_n[5].push_back(query->value("siklus").toInt());
     }}}

    for(int i=0; i<data_n[0].size(); i++){
    qu = QString("SELECT nama_rute "
                "FROM rute"
                " WHERE id=%1").arg(QString::number(data_n[3][i]));
   if(!query->exec(qu)) qDebug()<< __FUNCTION__ << __LINE__ << "ERROR : "<<query->lastError().text();
   else{while(query->next()){
        rute_baru.push_back(query->value("nama_rute").toString());
        qDebug()<<"rute:"<<query->value("nama_rute").toString();
//        QString list_nama_asetku;
//         list_nama_asetku+=query->value("nama_rute").toString();//rute[info_tipe_data[0][i]];
//         list_nama_asetku+="/";
//         list_nama_asetku+= QString::number(data_n[1][i]);
//         list1 = new QLabel(this);
//         box1->addWidget(list1);
//         list1->setText(list_nama_asetku);
    }}}

//--------------------mode cari aset start-----------------------------------------------//
for(int i=0; i<data_n[0].size(); i++){
    cari_induk_paramm(data_n[1][i], data_n[2][i]);
}
//--------------------mode cari aset end-----------------------------------------------//


    //cari data rute_isi yang mau dipindahkan berdasarkan data yang exist
    //tujuannya untuk efisiensi jumlah data yang mau ditambahkan ke rute_isi
    //sehingga tidak semua isi rute dipindahkan langsung.

    for(int i=0; i<data_n[0].size(); i++){
        qu = QString("SELECT param_setting "
                    "FROM rute_isi"
                    " WHERE id_rute=%1 AND id_param=%2").arg(QString::number(data_n[3][i]),QString::number(data_n[1][i]));
           if(!query->exec(qu)) qDebug()<< __FUNCTION__ << __LINE__ << "ERROR : "<<query->lastError().text();
           else{while(query->next()){
                qDebug()<<"list rute_isi"<<data_n[3][i]<<data_n[1][i]<<query->value("param_setting").toByteArray().size();
                all_rute_param.append(query->value("param_setting").toByteArray());
            }}
    }
}

void Tampil::cari_induk_paramm(int parameter, int tipe)
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

void Tampil::cari_induk(int p_id_aset){

    QSqlQuery Q3( db );
    QString nama;
    int id_aset_induk;
    int id_parent_ku;
    QString qu;
    qu = QString("SELECT * FROM aset WHERE id=%1").arg(QString::number(p_id_aset));
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
            cacah_data_name.push_back(initial_rute);
            QString list_nama_asetku;
             list1 = new QLabel(this);
             box1->addWidget(list1);
             list1->setText(initial_rute);
            initial_rute.clear();
            qDebug()<<"emit";
        }
     }
   }
}

void Tampil::mulai_cari_server(QSqlQuery *query)
{
    qDebug()<<"mulai server2"<<rute_baru;
    //qint64 total_waktu;
    for(int i=0; i<data_n[0].size(); i++){
        data_new[0].push_back(data_n[0][i]);//id_rute lama
        data_new[1].push_back(data_n[1][i]);//id_param
        data_new[2].push_back(data_n[2][i]);//id_tipe_param
        data_new[3].push_back(data_n[3][i]);//id_rute
        data_new[4].push_back(data_n[4][i]);//timestamp
        data_new[5].push_back(data_n[5][i]);//siklus
    }

    qDebug()<<data_new[0].size() <<data_n[0].size()
            <<data_new[1].size() <<data_n[1].size()
            <<data_new[2].size() <<data_n[2].size()
            <<data_new[3].size() <<data_n[3].size()
            <<data_new[4].size() <<data_n[4].size()
            <<data_new[5].size() <<data_n[5].size()
            <<rute_baru.size()<<
            all_data.size();
//ini array yang dikirim menggunakan GRPC ke array data yang nanti digunakan sebagai variable isi
    int konter=0;
    int flag_count=0;
    for(int i=0; i<data_n[0].size(); i++){
        //qDebug()<<"tipe data-"<<data_n[2][i]<<data_n[4][i];
        QString qu;
        qu = QString("SELECT id FROM %1 WHERE data_timestamp=%2").arg(get_table_name(data_n[2][i]),QString::number(data_n[4][i]));
        if(data_n[2][i]==3 || data_n[2][i]==28){
         qu = QString("SELECT id FROM %1 WHERE data_timestamp=%2 AND siklus=%3").arg(get_table_name(data_n[2][i]),QString::number(data_n[4][i]),QString::number(data_n[5][i]));
        }
        if(!query->exec(qu)) {qDebug()<< "ERROR:: " <<query->lastError().text();}
        else{while(query->next()){
             qDebug()<<"remove >> id--------"<<query->value("id").toInt();
            if(flag_count==0){
                data_new[0].erase(data_new[0].begin()+i);
                data_new[1].erase(data_new[1].begin()+i);
                data_new[2].erase(data_new[2].begin()+i);
                data_new[3].erase(data_new[3].begin()+i);
                data_new[4].erase(data_new[4].begin()+i);
                data_new[5].erase(data_new[5].begin()+i);

                rute_baru.erase(rute_baru.begin()+i);
                all_data.erase(all_data.begin()+i);
                cacah_data_name.erase(cacah_data_name.begin()+i);
                flag_count+=1;
            }
            else{
                konter+=1;
                data_new[0].erase(data_new[0].begin()+i-konter);
                data_new[1].erase(data_new[1].begin()+i-konter);
                data_new[2].erase(data_new[2].begin()+i-konter);
                data_new[3].erase(data_new[3].begin()+i-konter);
                data_new[4].erase(data_new[4].begin()+i-konter);
                data_new[5].erase(data_new[5].begin()+i-konter);
                rute_baru.erase(rute_baru.begin()+i-konter);
                all_data.erase(all_data.begin()+i-konter);
                cacah_data_name.erase(cacah_data_name.begin()+i-konter);
            }}}
    }

    qDebug()<<"sampai?";
    if(data_new[0].size()!=0){
         for(int i=0; i<data_new[0].size(); i++){
            QString list_nama_asetku;
            QString nama_rute = cacah_data_name[i];//rute_baru[i];
//             list_nama_asetku+=nama_rute;
//             list_nama_asetku+="/";
//             list_nama_asetku+= QString::number(data_new[1][i]);
             check_bok.push_back(nama_rute/*list_nama_asetku*/);
        }
    }
    else{
        QMessageBox::information(this,"informasi","tidak ada data update");
    }

    list_check = new QListWidget;
    list_check->addItems(check_bok);
    QListWidgetItem* list_item = 0;
    for(int i=0; i<list_check->count(); i++){
        list_item = list_check->item(i);
        list_item->setFlags(list_item->flags() | Qt::ItemIsUserCheckable);
        list_item->setCheckState(Qt::Checked);
    }
    box2->addWidget(list_check);
    QObject::connect(list_check, SIGNAL(itemChanged(QListWidgetItem*)),
                     this, SLOT(highlightChecked(QListWidgetItem*)));

    //qDebug()<<"total waktu simpan"<<total_waktu;
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

void Tampil::synchronize(QSqlQuery *query)
{
    if(data_new[0].size()!=0){
        QListWidgetItem* list_item = 0;
        int konter=0;
        int flag_count=0;
        for(int i=0; i<list_check->count(); i++){
            list_item = list_check->item(i);
            qDebug()<<"status "<<i<<list_item->checkState();
            if(list_item->checkState()==false){
                if(flag_count==0){
                    data_new[0].erase(data_new[0].begin()+i);
                    data_new[1].erase(data_new[1].begin()+i);
                    data_new[2].erase(data_new[2].begin()+i);
                    data_new[3].erase(data_new[3].begin()+i);
                    data_new[4].erase(data_new[4].begin()+i);
                    data_new[5].erase(data_new[5].begin()+i);
                    rute_baru.erase(rute_baru.begin()+i);
                    all_data.erase(all_data.begin()+i);
                    cacah_data_name.erase(cacah_data_name.begin()+i);
                    flag_count+=1;
                }
                else{
                    konter+=1;
                    data_new[0].erase(data_new[0].begin()+i-konter);
                    data_new[1].erase(data_new[1].begin()+i-konter);
                    data_new[2].erase(data_new[2].begin()+i-konter);
                    data_new[3].erase(data_new[3].begin()+i-konter);
                    data_new[4].erase(data_new[4].begin()+i-konter);
                    data_new[5].erase(data_new[5].begin()+i-konter);
                    rute_baru.erase(rute_baru.begin()+i-konter);
                    all_data.erase(all_data.begin()+i-konter);
                    cacah_data_name.erase(cacah_data_name.begin()+i-konter);
                }
            }
        }
        qDebug()<<"jumlah datanya jadi="<<data_new[0].size()<<rute_baru.size();



        //
        //masukkan tabel parameter
        //

        for(int i=0; i<data_new[0].size(); i++){
            qDebug()<<data_new[1][i]<<rute_baru[i];

            list3 = new QLabel(this);
            box3->addWidget(list3);
            QString list_nama_asetku;
            QString nama_rute = cacah_data_name[i];//rute_baru[i];
//             list_nama_asetku+=nama_rute;
//             list_nama_asetku+="/";
//             list_nama_asetku+= QString::number(data_new[1][i]);
            qDebug()<<nama_rute;
             list3->setText(nama_rute/*list_nama_asetku*/);
        }

      //  qDebug()<<"status check box"<<this->list_masuk->checkState();
        //masukkan rute yang belum ada
            if(rute_baru.size()!=0){
                for(int i=0; i<rute_baru.size(); i++){//hapusnya dari rute_baru
                    QString qu;
                    int id_rute_baru;
                    QString rute = (QString)rute_baru[i];
                    qu = QString("INSERT INTO rute (nama_rute,id_database)"
                                 " SELECT '%1',%2 WHERE NOT EXISTS (SELECT nama_rute,id_database FROM rute WHERE nama_rute='%3' AND id_database=%4)").
                            arg(rute,QString::number(id_database),
                            rute,QString::number(id_database));
                    if(!query->exec(qu)) {qDebug()<< "ERROR:: " <<query->lastError().text();}
                    else{while(query->next()){
                            id_rute_baru=query->lastInsertId().toInt();
                           // data_new[5].push_back(id_rute_baru);//new id rute
                            qDebug()<<"id_rute baru tambah:"<<id_rute_baru<<rute;
                    }}}
                            qDebug()<<data_new[0].size()<<data_new[1].size()
                                    <<data_new[2].size()<<data_new[3].size()
                                    <<data_new[4].size()<<data_new[5].size();
            //masukkan isi_rute dulu
                for(int i=0; i<rute_baru.size(); i++){
                    qint64 mulai;
                    mulai = QDateTime::currentMSecsSinceEpoch() ;
                    QString qu;
                    int id_rute_baru;
                    QString rute = (QString)rute_baru[i];
                    qu = QString("SELECT id FROM rute WHERE nama_rute='%1'").
                            arg(rute);
                    if(!query->exec(qu)) {qDebug()<< "ERROR:: " <<query->lastError().text();}
                    else{while(query->next()){
                             id_rute_baru=query->value("id").toInt();
                             data_new[5].push_back(id_rute_baru);//new id rute
                             qDebug()<<"id_rute:"<<id_rute_baru <<rute;
                             QByteArray datax;
                             datax.resize(100);
                             QString qa;
                                     qa.sprintf("INSERT INTO rute_isi (id_rute,id_tipe_param,id_last_param,kanal,param_setting,setting_rute)"
                                                " SELECT :id_rute,:id_tipe_param,:id_last_param,:kanal,:param_setting,:setting_rute "
                                                "WHERE NOT EXISTS (SELECT id_rute,id_last_param FROM rute_isi "
                                                "WHERE id_rute=:id_rute AND id_last_param=:id_last_param)");
                                     query->exec("pragma synchronous = off;");
                                     query->prepare(qa);
                                     query->bindValue(":id_rute",id_rute_baru);
                                     query->bindValue(":id_tipe_param",data_new[2][i]);
                                     query->bindValue(":id_last_param",data_new[1][i]);
                                     query->bindValue(":kanal",1);
                                     query->bindValue(":param_setting",all_rute_param[i]);
                                     query->bindValue(":setting_rute",datax);
                                     query->exec();
              //tampil
                              qint64 end;
                              end = QDateTime::currentMSecsSinceEpoch();
                              qint64 waktu = end-mulai;
                              qDebug()<<"time save rute_isi: "<<waktu<< " ms";
                             // qDebug()<<"size:"<<data_new[0].size();
                        }
                    }
                }
//----------------------------------------------------------------------------------------------------//

            //masukkan masukkan data
                for(int i=0; i<rute_baru.size(); i++){
                    qint64 mulai;
                    mulai = QDateTime::currentMSecsSinceEpoch() ;
                    QString qu;
                    int id_rute_baru;
                    QString rute = (QString)rute_baru[i];
                    qu = QString("SELECT id FROM rute WHERE nama_rute='%1'").
                            arg(rute);
                    if(!query->exec(qu)) {qDebug()<< "ERROR:: " <<query->lastError().text();}
                    else{while(query->next()){
                         id_rute_baru=query->value("id").toInt();
                         data_new[5].push_back(id_rute_baru);//new id rute
                         qDebug()<<"tipe_data:"<<data_new[2][i];
                         if(data_new[2][i]==410 || data_new[2][i]==420 || data_new[2][i]==430){
                             //tambahin id_isi_rute?
                             //
                             //
                             //
                             //

                              QString tipe_data = get_table_name(data_new[2][i]);
                              QString qa;
                              qa.sprintf("INSERT INTO %s (id_rute,data,flag_set_param,data_timestamp)"
                                           " SELECT :id_rute,:data,:flag_set_param,:data_timestamp "
                                           "WHERE NOT EXISTS (SELECT id_rute,data_timestamp FROM %s "
                                           "WHERE id_rute=:id_rute AND data_timestamp=:data_timestamp)",
                                            tipe_data.toUtf8().data(),tipe_data.toUtf8().data());
                                              query->exec("pragma synchronous = off;");
                                              query->prepare(qa);
                                              query->bindValue(":id_rute",id_rute_baru);
                                              query->bindValue(":data",all_data[i]);
                                              query->bindValue(":flag_set_param",0);
                                              query->bindValue(":data_timestamp",data_new[4][i]);
                                              query->exec();
                                              if(query->exec())qDebug()<<"nggak mmasuk:";
                             //---------------------------------------------------------------//
                              qint64 end;
                              end = QDateTime::currentMSecsSinceEpoch();
                              qint64 waktu;
                              waktu = end-mulai;
                              qDebug()<<"time save data tipe: "<<waktu<< " ms";
                        }
                        else if(data_new[2][i]==28 || data_new[2][i]==3){
                             //tambahin siklus dan id_isi_rute?
                             //
                             //
                             //
                             //
                             qDebug()<<"id_rute:"<<id_rute_baru <<rute;
                             QString tipe_data = get_table_name(data_new[2][i]);
                             QString qStr;
                             qStr.sprintf("insert into %s (id_rute, data, flag_set_param, data_timestamp, siklus) "
                                          "values (:id_rute, :data, :flag_set_param, :data_timestamp, :siklus)",tipe_data.toUtf8().data());
                             query->exec("pragma synchronous = off;");
                             query->prepare(qStr);
                             query->bindValue(":id_rute", id_rute_baru);
                             query->bindValue(":data", all_data[i]);
                             query->bindValue(":flag_set_param", 0);
                             query->bindValue(":data_timestamp", data_new[4][i]);
                             query->bindValue(":siklus", data_new[5][i]);
                             query->exec();
                             query->clear();
                             }
                         }

                    }
                }
            }
    }
    else{
        QMessageBox::information(this,"informasi","tidak ada data yang dikirim");
    }
}

void Tampil::on_pushButton_2_clicked()
{
    QSqlQuery query(dbx);
    synchronize(&query);
}

void Tampil::highlightChecked(QListWidgetItem *item)
{
    if(item->checkState() == Qt::Checked)
            item->setBackgroundColor(QColor("#ffffb2"));
        else
            item->setBackgroundColor(QColor("#ffffff"));
}

