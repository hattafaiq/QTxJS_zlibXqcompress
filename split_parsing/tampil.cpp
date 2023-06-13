#include "tampil.h"
#include "ui_tampil.h"
#include <QTreeView>
#include <QObject>

Tampil::Tampil(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tampil)
{
    ui->setupUi(this);
    menu_tgl = new QMenu( ui->tableView_2 );
    ui->tableView_2->setContextMenuPolicy(Qt::ActionsContextMenu);
    this->setWindowTitle("Simulasi Upload Data");
    this->setMaximumSize(600,600);
    hapus = new QAction(tr("hapus data"), menu_tgl);
    ui->tableView_2->addAction( hapus );
    QObject::connect( hapus, SIGNAL(triggered()), this, SLOT(hapus_data()));
    setup_tampil_hirarki_server();
    tree1 = new QStandardItemModel();

    QString filename = "cp_data.dbb";
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
        qDebug()<<"buka db";
    }

   this->load_aset(0, 0, 0);

    connect(ui->treeView,&TreeSub::emitEmulateDataByClick,this,&Tampil::on_treeView_clicked);
    ui->treeView->setModel( tree1 );

    this->ui->treeView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->ui->treeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    QModelIndex index = ui->treeView->model()->index(0,0);
    this->ui->treeView->setCurrentIndex(index);

    setup_tampil_hirarki_sofhaliza();
    setup_tampil_hirarki_haliza();
//    qwerty  "LOC_DB1"
//    lok  "/home/fh/SoftHaliza_series/db_test/rotating haliza.dbb"
    //load_aset(0,0,0);
    show();
}

void Tampil::setup_tampil_hirarki_server()
{
    QStandardItemModel *r_model = new QStandardItemModel(this);
    r_model->setHorizontalHeaderItem(0, new QStandardItem(QString("folder")));

    QFile file("modules.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))qDebug()<<"!File";
        //           return 1;

       QTextStream in(&file);
       QString line= in.readLine();
       while (!line.isNull()) {
           line = in.readLine();
           qDebug()<<line;
           int row = r_model->rowCount();
           row++;
           r_model->setItem( row-1, 0, new QStandardItem(line));
       }

       ui->tableView->setModel( r_model );
}

void Tampil::setup_tampil_hirarki_sofhaliza()
{
    QStandardItemModel *r_model = new QStandardItemModel(this);
    r_model->setHorizontalHeaderItem(0, new QStandardItem(QString("folder")));

    QFile file("modules.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))qDebug()<<"!File";
        //           return 1;

       QTextStream in(&file);
       QString line= in.readLine();
       while (!line.isNull()) {
           line = in.readLine();
           qDebug()<<line;
           int row = r_model->rowCount();
           row++;
           r_model->setItem( row-1, 0, new QStandardItem(line));
       }

       ui->tableView_3->setModel( r_model );
}

void Tampil::setup_tampil_hirarki_haliza()
{
    QStandardItemModel *r_model = new QStandardItemModel(this);
    r_model->setHorizontalHeaderItem(0, new QStandardItem(QString("folder")));

    QFile file("modules.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))qDebug()<<"!File";
        //           return 1;

       QTextStream in(&file);
       QString line= in.readLine();
       while (!line.isNull()) {
           line = in.readLine();
           qDebug()<<line;
           int row = r_model->rowCount();
           row++;
           r_model->setItem( row-1, 0, new QStandardItem(line));
       }

       ui->tableView_5->setModel( r_model );
}

Tampil::~Tampil()
{
    delete ui;
}

void Tampil::on_tableView_clicked(const QModelIndex &index)
{
    int n_row = index.row();
    last_select_view_data = n_row;
    QString kota = ui->tableView->model()->data(ui->tableView->model()->index(n_row,0)).toString();

    qDebug()<<n_row<< kota;
    QString a = "Isi_hirarki/"+kota+"/"+kota+"_config.txt";
    last_kota = a;
    qDebug()<< a;
    QFile file(a);
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))qDebug()<<"!File"+a;

       QStandardItemModel *r_model = new QStandardItemModel(this);
       r_model->setHorizontalHeaderItem(0, new QStandardItem(QString("data")));
       QTextStream in(&file);
       QString line= in.readLine();
       while (!line.isNull()) {
           line = in.readLine();
           tampung_data.push_back(line);
           qDebug()<<line;
           int row = r_model->rowCount();
           row++;
           r_model->setItem( row-1, 0, new QStandardItem(line));
       }
       ui->tableView_2->setModel( r_model );
       file.close();
}

void Tampil::hapus_data()
{
    tampung_data.removeAt(index_data_hapus);
    qDebug()<<" hapus data: "<<index_data_hapus;
    qDebug()<<"datanya sekarang ini: "<<tampung_data;
    re_write();
    refresh_data(last_kota);
    //tampung_data.clear();
}


void Tampil::on_tableView_2_pressed(const QModelIndex &index)
{
    int n_row = index.row();
    index_data_hapus = n_row;
}

void Tampil::refresh_data(QString a)
{
    tampung_data.clear();
    qDebug()<<"(refresh) data";
    QFile file(last_kota);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))qDebug()<<"!File"+a;

    QStandardItemModel *r_model = new QStandardItemModel(this);
    r_model->setHorizontalHeaderItem(0, new QStandardItem(QString("data")));
    QTextStream in(&file);
    QString line= in.readLine();
    while (!line.isNull()) {
        line = in.readLine();
        tampung_data.push_back(line);
        qDebug()<<line;
        int row = r_model->rowCount();
        row++;
        r_model->setItem( row-1, 0, new QStandardItem(line));
    }
    ui->tableView_2->setModel( r_model );
}

void Tampil::on_treeView_clicked(QModelIndex index)
{

}

void Tampil::on_treeView_expanded(QModelIndex index)
{

}

void Tampil::on_treeView_activated(QModelIndex index)
{

}

void Tampil::re_write()
{
    QFile file(last_kota);
    file.open(QIODevice::WriteOnly);
    for (int i=0; i<tampung_data.size(); i++) {
    QString str = tampung_data[i];
    if(!file.isOpen())
    {
        //alert that file did not open
    }
    QTextStream outStream(&file);
    outStream << "\n";
    outStream << str;
    }

    file.close();
}

void Tampil::on_pushButton_clicked()
{
    //nama data soft haliza upload
    QString data = ui->lineEdit->text().toUtf8();
    qDebug()<<"softhaliza upload="<<data;
}

void Tampil::on_pushButton_2_clicked()
{
    QString data = ui->lineEdit_2->text().toUtf8();
    qDebug()<<"softhaliza hirarki="<<data;
    //tambah hirarki baru di server
    //atau tambah posisi aset
}


void Tampil::on_pushButton_4_clicked()
{
    //upload haliza
    QString data = ui->lineEdit_3->text().toUtf8();
    qDebug()<<"haliza upload data="<<data;
}


void Tampil::on_pushButton_3_clicked()
{
    //upload haliza hirarki baru
    QString data = ui->lineEdit_4->text().toUtf8();
    qDebug()<<"haliza hirarki="<<data;
}


void Tampil::on_pushButton_5_clicked()
{
    //ambil alamat hirarki untuk pengukuran
    QString data = ui->lineEdit_5->text().toUtf8();
    qDebug()<<"haliza get alamat="<<data;
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
//    QString filename = "cp_data.dbb";
//    con_name = "LOC_DB1";
//   // db = QSqlDatabase::database( con_name );
//    db =QSqlDatabase::addDatabase("QSQLITE",con_name);
//    db.setDatabaseName(filename);
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
