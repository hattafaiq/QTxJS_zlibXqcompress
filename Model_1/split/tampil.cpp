#include "tampil.h"
#include "ui_tampil.h"
#include <QTreeView>
#include <QObject>

Tampil::Tampil(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tampil)
{
    ui->setupUi(this);
    this->setWindowTitle("Simulasi Upload Data");
    this->setMaximumSize(600,600);
    setup_tampil_hirarki_server();
//    setup_tampil_hirarki_sofhaliza();
//    setup_tampil_hirarki_haliza();
    flag_kirim =0;
    show();
}

void Tampil::setup_tampil_hirarki_server()
{
    tree1 = new QStandardItemModel();
    QString filename = "cp.dbb";
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
    this->load_aset(0, 0, 0);
    connect(ui->treeView,&TreeSubwin::emitEmulateDataByClick,this,&Tampil::on_treeView_clicked);
    ui->treeView->setModel( tree1 );
    this->ui->treeView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->ui->treeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    QModelIndex index = ui->treeView->model()->index(0,0);
    this->ui->treeView->setCurrentIndex(index);
}

void Tampil::setup_tampil_hirarki_sofhaliza()
{

}

void Tampil::setup_tampil_hirarki_haliza()
{

}

Tampil::~Tampil()
{
    delete ui;
}

void Tampil::on_tableView_clicked(const QModelIndex &index)
{

}


void Tampil::on_tableView_2_pressed(const QModelIndex &index)
{
    int n_row = index.row();
    index_data_hapus = n_row;
}


void Tampil::on_treeView_clicked(QModelIndex index)
{
    qDebug() <<__PRETTY_FUNCTION__
            << "qmodelindex: "<< index.row()
            << "parent id:"<<index.parent().data(ROLE_TREE_ASET_ID).toInt()
            << "tree view anak ke1 diklik dengan index = " << index.row();
    index_tree_selected(index);

}

void Tampil::on_treeView_expanded(QModelIndex index)
{
    int n_row = index.row();
    index_data_hapus = n_row;
    qDebug()<<"index="<<index;

}

void Tampil::on_treeView_activated(QModelIndex index)
{
    int n_row = index.row();
    index_data_hapus = n_row;
    qDebug()<<"index="<<index;
    //ui->lineEdit->clear();
}


QStandardItem* Tampil::assign_icon_x( QString name, int id_kind)
{
    QStandardItem* item;

    if (id_kind == ID_KIND_COMPANY)
        item = new QStandardItem( QIcon( ICON_COMPANY ), name);
    else if (id_kind == ID_KIND_DEPARTMENT)
        item = new QStandardItem( QIcon( ICON_DEPT ), name);
    else if (id_kind == ID_KIND_LOCATION)
        item = new QStandardItem( QIcon( ICON_LOCATION ), name);
    else if (id_kind == ID_KIND_GROUP)
        item = new QStandardItem( QIcon( ICON_GROUP ), name);
    else if (id_kind == ID_OFF_RUTE_ASET){
        item = new QStandardItem( QIcon( ICON_OFF_ROUTE_ASET), name);
        qDebug() << "(debug 16) aset merupakan off rute 2";
    }
    else if (id_kind == ID_KIND_RECIP_ENGINE)
        item = new QStandardItem( QIcon( ICON_RECIP_ENGINE ), name);
    else if (id_kind == ID_KIND_RECIP_COMPRESSOR)
        item = new QStandardItem( QIcon( ICON_RECIP_COMPRESSOR ), name);
    else if (id_kind == ID_KIND_ROTATING_MACHINE || id_kind == ID_KIND_ROTATING_EQUIP_V)
        item = new QStandardItem( QIcon( ICON_ROTATING_MACHINE ), name);
    else if (id_kind == ID_KIND_STRUCTURE)
        item = new QStandardItem( QIcon( ICON_STRUCTURE ), name);
    else if (id_kind == ID_KIND_PIPE)
        item = new QStandardItem( QIcon( ICON_PIPE ), name);
    else if (id_kind == ID_KIND_TANK)
        item = new QStandardItem( QIcon( ICON_TANK ), name);
    else if (id_kind == ID_KIND_ENGINE_CYL)
        item = new QStandardItem( QIcon( ICON_ENGINE_CYL ), name);
    else if (id_kind == ID_KIND_COMP_THROW)
        item = new QStandardItem( QIcon( ICON_COMP_THROW ), name);
    else if (id_kind == ID_KIND_COMP_VALVE)
        item = new QStandardItem( QIcon( ICON_COMP_VALVE ), name);
    else if (id_kind == ID_KIND_ROTATING_POINT)
        item = new QStandardItem( QIcon( ICON_ROTATING_POINT ), name);
    else if (id_kind == ID_KIND_STRUCTURE_POINT)
        item = new QStandardItem( QIcon( ICON_STRUCTURE_POINT ), name);
    else if (id_kind == ID_KIND_PIPE_POINT )
        item = new QStandardItem( QIcon( ICON_PIPE_POINT ), name);
    else if (id_kind == ID_KIND_EQUIPMENT_OTHER)
        item = new QStandardItem( QIcon( ICON_EQUIPMENT_OTHER ), name);
    else if (id_kind == ID_KIND_COMPONENT_OTHER )
        item = new QStandardItem( QIcon( ICON_COMPONENT_OTHER ), name);
    else
        item = new QStandardItem( QIcon( ICON_OTHER ), name);

    return item;
}


QStandardItem* Tampil::assign_icon(QStandardItemModel *tree, QString name, int id_kind, int id)
{
    QStandardItem* item;

    item = assign_icon_x( name, id_kind );

    tree->appendRow(item);
    QVariant v(id), L(id_kind);

    item->setData( v, ROLE_TREE_ASET_ID );
    item->setData( L, ROLE_TREE_ASET_KIND );

    item->setEditable( false );

    return item;
}

/* hanya merubah icon & text */
void Tampil::set_assign_icon_item(QStandardItem *tree, QString name, int id_kind, int id)
{
    qDebug("id = %d",id);
    tree->setText( name );

    if (id_kind == ID_KIND_COMPANY)
        tree->setIcon( QIcon( ICON_COMPANY ) );
    else if (id_kind == ID_KIND_DEPARTMENT)
        tree->setIcon( QIcon( ICON_DEPT ));
    else if (id_kind == ID_KIND_LOCATION)
        tree->setIcon( QIcon( ICON_LOCATION ));
    else if (id_kind == ID_KIND_GROUP)
        tree->setIcon( QIcon( ICON_GROUP ));
    else if (id_kind == ID_OFF_RUTE_ASET){
        tree->setIcon( QIcon( ICON_OFF_ROUTE_ASET ));
        qDebug() << "(debug 16) aset merupakan off rute 3";
    }
    else if (id_kind == ID_KIND_RECIP_ENGINE)
        tree->setIcon( QIcon( ICON_RECIP_ENGINE ));
    else if (id_kind == ID_KIND_RECIP_COMPRESSOR)
        tree->setIcon( QIcon( ICON_RECIP_COMPRESSOR ));
    else if (id_kind == ID_KIND_ROTATING_MACHINE)
        tree->setIcon( QIcon( ICON_ROTATING_MACHINE ));
    else if (id_kind == ID_KIND_STRUCTURE)
        tree->setIcon( QIcon( ICON_STRUCTURE ));
    else if (id_kind == ID_KIND_PIPE)
        tree->setIcon( QIcon( ICON_PIPE ));
    else if (id_kind == ID_KIND_TANK)
        tree->setIcon( QIcon( ICON_TANK ));
    else if (id_kind == ID_KIND_ENGINE_CYL)
        tree->setIcon( QIcon( ICON_ENGINE_CYL ));
    else if (id_kind == ID_KIND_COMP_THROW)
        tree->setIcon( QIcon( ICON_COMP_THROW ));
    else if (id_kind == ID_KIND_COMP_VALVE)
        tree->setIcon( QIcon( ICON_COMP_VALVE ));
    else if (id_kind == ID_KIND_ROTATING_POINT)
        tree->setIcon( QIcon( ICON_ROTATING_POINT ));
    else if (id_kind == ID_KIND_STRUCTURE_POINT)
        tree->setIcon( QIcon( ICON_STRUCTURE_POINT ));
    else if (id_kind == ID_KIND_PIPE_POINT )
        tree->setIcon( QIcon( ICON_PIPE_POINT ));
    else if (id_kind == ID_KIND_EQUIPMENT_OTHER)
        tree->setIcon( QIcon( ICON_EQUIPMENT_OTHER ));
    else if (id_kind == ID_KIND_COMPONENT_OTHER )
        tree->setIcon( QIcon( ICON_COMPONENT_OTHER ));
    else
        tree->setIcon( QIcon( ICON_OTHER ));
}

QStandardItem* Tampil::assign_icon_item(QStandardItem *tree, QString name, int id_kind, int id)
{
    QStandardItem* item;

    item = assign_icon_x( name, id_kind );

    tree->appendRow(item);
    QVariant v(id), L(id_kind);

    item->setData( v, ROLE_TREE_ASET_ID );
    item->setData( L, ROLE_TREE_ASET_KIND );

    item->setEditable( false );

    return item;
}
void Tampil::load_param(QStandardItem *si, int id_aset, int siapa)
{
    qDebug() << __FUNCTION__ << "id_aset "<< id_aset<< "siapa"<<siapa;
    QString nama_param, qq;
    QSqlQuery Q( db );
    int id_s, id_tipe_param, urut;

    qq = QString("SELECT p.id, p.id_tipe_param, p.urut, tp.nama_param FROM parameter p JOIN tipe_param tp ON tp.id = p.id_tipe_param WHERE %1=%2").arg( (siapa)?"id_aset":"id").arg(id_aset);
    if(!Q.exec(qq)) qDebug() << __FUNCTION__ << __LINE__ << "ERROR : "<< Q.lastError().text();
    else {
        while(Q.next())
        {
            id_s = Q.value("id").toInt();
            id_tipe_param = Q.value("id_tipe_param").toInt();
            urut = Q.value("urut").toInt();
            nama_param = Q.value("nama_param").toString();

            if(urut>1) nama_param = QString("%1_%2").arg(nama_param).arg(urut);

            QVariant v(id_s), L( ID_KIND_PARAM );
            QStandardItem* item1;
            item1 = new QStandardItem(QIcon(":/images/param2.png"), nama_param );

            item1->setData( v, ROLE_TREE_ASET_ID );
            item1->setData( L, ROLE_TREE_ASET_KIND );
            item1->setData(id_tipe_param, ROLE_TREE_ASET_ID_TIPE_PARAM);
            item1->setData(id_s, ROLE_TREE_ASET_ID_PARAM);
            item1->setEditable( false );

            si->appendRow( item1 );
            QApplication::processEvents();

        }
    }
}

void Tampil::load_aset(QStandardItem *si, int id, int siapa)
{
    qDebug("%s() <== id=%d, siapa = %d",__FUNCTION__,id,siapa);// << "(debug 10) masuk ke void load_aset";
    QSqlQuery Q2( db );
    QString nama;
    int id_kind;
    int id_aset;
    int id_parent;
    int jum_aset = 0;

    QString qu;

    qu = QString("SELECT * FROM aset WHERE id_parent=%1").arg(id);
    if(!Q2.exec(qu)) qDebug()<< __FUNCTION__ << __LINE__ << "ERROR : "<<Q2.lastError().text();
    else
    {
        while (Q2.next())
        {
            jum_aset++;
            nama = Q2.value("name").toString();
            id_aset = Q2.value("id").toInt();
            id_kind = Q2.value("id_kind").toInt();
            id_parent = Q2.value("id_parent").toInt();
            qDebug("id_aset : %d, id_kind : %d, id_parent : %d",id_aset,id_kind, id_parent);
            QStandardItem* item0;

            item0 = (id==0)? assign_icon(this->tree1, nama, id_kind, id_aset) :assign_icon_item( si, nama, id_kind, id_aset);

            load_aset(item0, id_aset, 1);
            load_param(item0, id_aset,1);

        }
        /// sorting dibuat hanya untuk id_kind == 5200 || 5300  RECIP_COMPRESSOR

        if(id_kind == ID_KIND_RECIP_COMPRESSOR)/*|| id_kind == ID_KIND_COMP_VALVE*/// )
            tree1->sort(0, Qt::AscendingOrder);

        if(id==0)
            this->sudah_ada_aset++;
    }
    if((siapa==0)&& (jum_aset==0))
        this->sudah_ada_aset=0;

}

void Tampil::index_tree_selected(QModelIndex index){


    qDebug(">> masuk fungsi %s()",__PRETTY_FUNCTION__);
    int p_id_aset;
    int p_id_kind;
    int p_id_tipe_param;
    int idParentSelect;
    idParentSelect=index.parent().data(ROLE_TREE_ASET_ID).toInt();

    QStandardItem *sd = tree1->itemFromIndex(index);

    //mencari semua anak dari tree yang dipilih
    QModelIndexList llist;
    getAllChildren(index, llist);
    onRouteChildTree.clear();
    for(int i=0; i< llist.size(); i++)
    {
        int idKind =llist.value(i).data(ROLE_TREE_ASET_KIND).toInt();
        if(idKind!= ID_KIND_PARAM ){
            int idAset = llist.value(i).data(ROLE_TREE_ASET_ID).toInt();
            onRouteChildTree.push_back(idAset);
        }
    }

    p_id_aset = sd->data( ROLE_TREE_ASET_ID ).toInt();
    p_id_kind = sd->data( ROLE_TREE_ASET_KIND ).toInt();
    p_id_tipe_param= sd->data(ROLE_TREE_ASET_ID_TIPE_PARAM).toInt();

    if (sd->hasChildren())
    {
        qDebug("Punya Anak %d", sd->rowCount());
    }
    qDebug()<<"anaknya:"<<onRouteChildTree;
    qDebug()<<"param:"<<p_id_aset;
    qDebug()<<"tipe data:"<<p_id_tipe_param;
    ui->lineEdit->clear();
    initial_rute.clear();
    cari_induk_param(p_id_aset);
    qDebug()<<initial_rute.split('/');
    QStringList dataList = initial_rute.split('/');
    data_ini = dataList;
//    QDataStream dataStreamWrite(&data_utama, QIODevice::WriteOnly);
//    dataStreamWrite << data_ini;
//   // QStringList appNameList = appName.split("U");

//   //qDebug()<<"size nama=>"<<sizeof(data_ini)
//   // susun_data(p_id_aset,p_id_tipe_param);
//    data_utama.clear();
}

QString Tampil::get_table_name(int tipe)
{
    QString nama_tabel = QString("data_%1_tipe").arg(tipe);
//    nama_tabel.sprintf("data_%d_tipe", tipe);
    return nama_tabel;
}

void Tampil::tambah_aset(int parent, QString aset){
//    QString filename = "test_paste.dbb";
//    QString con_name;
//    con_name = QString("LOC_DB%1").arg(2);
//    QSqlDatabase dbs =QSqlDatabase::addDatabase("QSQLITE",con_name);
//    dbs.setDatabaseName(filename);
//    QSqlQuery query( dbs );
//    if(!dbs.open())
//    {
//      qDebug()<<"db gak kebukak";
//      //return;
//    }
//    else{
//        qDebug()<<"buka db";
//    }
//    qDebug()<<"aset:"<<aset;
//    query.prepare("INSERT INTO aset (name, tag_number, note, id_kind ,id_parent) VALUES(:name, :tag_number, :note, :id_kind, :id_parent)");
//    query.bindValue(":name", "");//aset.toUtf8().data());
//    query.bindValue(":tag_number", "");
//    query.bindValue(":note", "");
//    query.bindValue(":id_kind", 0);
//    query.bindValue(":id_parent", parent);
//    if(!query.exec())qDebug()<<"lapo?" << "ERROR : "<<query.lastError();
}

void Tampil::kirim_data(int id_param, int tipe_data, QByteArray data){
//    qDebug()<<"mulai kirim data:";
//    QString filename = "test_paste.dbb";
//    QString con_name;
//    con_name = QString("LOC_DB%1").arg(2);
//    QSqlDatabase dbs =QSqlDatabase::addDatabase("QSQLITE",con_name);
//    dbs.setDatabaseName(filename);
//    if(!dbs.open())
//    {
//      qDebug()<<"db gak kebukak";
//      //return;
//    }
//    else{
//        qDebug()<<"buka db";
//    }

//    qDebug()<<initial_rute.split('/');
//    QStringList dataList = initial_rute.split('/');
//  //  qDebug()<<dataList;
//    QSqlQuery Q3( dbs );
//    QSqlQuery query( dbs );
//    int id_parent=0;
//    QString qu;
//    QString qur;
//    data_ini = dataList;
//    for(int i=0; i<dataList.size()-1; i++){
//        QString aset_ku = (QString) dataList[i];
//        qu = QString("SELECT * FROM aset WHERE name=%1").arg(aset_ku.toUtf8().data());
//        if(!Q3.exec(qu)) {
//          qDebug()<< __FUNCTION__ << __LINE__ << "ERROR : "<<Q3.lastError().text() <<dataList[i];

//         // QString nama_kus = (QString) dataList[i];
//          //tambah_aset(id_parent, aset_ku);
//          qDebug()<<"aset:"<<aset_ku;

//        }
//        else{
//        while(Q3.next()){
//         id_parent = Q3.value("id_parent").toInt();
//         qDebug()<<"ada"<<id_parent;
//         }
//       }
//    }
//    proses_q(&query, "insert into aset (name, tag_number, note, id_kind, id_parent) values('%s', '%s', '%s', %d, %d)","x","x", "x", 0, 0);
//    if(!query.exec())qDebug()<<"kenapa?"<<query.lastError().text();
}



void Tampil::susun_data(int id_param, int tipe_data){
    qDebug()<<"mulai susun data:";
    QSqlQuery Q3( db );
    QString nama_tipe_data = get_table_name(tipe_data);
    qDebug() << nama_tipe_data;
    QString qu;
    qu = QString("SELECT * FROM %1 WHERE id_param=%2").arg(nama_tipe_data.toUtf8().data()).arg(id_param);
    if(!Q3.exec(qu)) qDebug()<< __FUNCTION__ << __LINE__ << "ERROR : "<<Q3.lastError().text();
    else{
     while(Q3.next()){
        QByteArray data = Q3.value("data").toByteArray();
        qDebug()<<"size:"<<data.size();
        kirim_data(id_param, tipe_data, data);
     }
   }
}

void Tampil::cari_induk_param(int p_id_aset){

    QSqlQuery Q2( db );
    QSqlQuery Q3( db );
    QString nama;
    int id_aset_induk;
    int id_parent_ku;

    QString qu;

    qu = QString("SELECT id_aset FROM parameter WHERE id=%1").arg(p_id_aset);
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
            ui->lineEdit->backspace();
            ui->lineEdit->setText(initial_rute);
            qDebug()<<"emit";
        }
     }
   }
}

void Tampil::getAllChildren(QModelIndex idx, QModelIndexList &list)
{
    list.push_back(idx);
    for (int i=0; i!= tree1->rowCount(idx);i++)
    {
        getAllChildren(idx.child(i,0), list);
    }
}


void Tampil::kirim1_kedatabase()
{
    qDebug()<<"kirim trigger";
    QSqlQuery query1(dbx);
    QSqlQuery query2(dbx);
    int i;
    int id_parent=0;
    QStringList kantong_ada;
    QStringList kantong_tidak;
    QString aa;
    int id_aset=0;
    for(i=0; i<data_ini.size()-1; i++){
        QString aset_ku = (QString) data_ini[i];

        aa = QString("SELECT id FROM aset WHERE name='%1'AND id_parent=%2").arg(aset_ku,QString::number(id_parent));
        if(!query1.exec(aa)){qDebug()<<"tidak ada1="<<aset_ku;}
        if(query1.first()){qDebug()<<"ada="<<aset_ku;
        id_parent = query1.value("id").toInt();
        }
        else {
          qDebug()<<"tidak ada2="<<aset_ku;
          flag_masukkan_param=1;

          //id_parent = query1.lastInsertId().toInt();
          aa = QString("INSERT INTO aset ( name, id_kind, id_parent, id_database, id_user) VALUES('%1',%2,%3,%4,%5)").arg(aset_ku,QString::number(0),QString::number(id_parent),QString::number(0),QString::number(0));
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
}


void Tampil::on_PB_connect_clicked()
{
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
      ui->PB_connect->setText("--connected--");
    }
}


void Tampil::on_PB_kirim_clicked()
{
    kirim1_kedatabase();//simulasi mengirim data satuan
}


void Tampil::on_PB_compare_clicked()
{

}


void Tampil::on_PB_synchron_clicked()
{

}

