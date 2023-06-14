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

    menu_tgl = new QMenu( ui->tableView_2 );
    ui->tableView_2->setContextMenuPolicy(Qt::ActionsContextMenu);
    hapus = new QAction(tr("hapus data"), menu_tgl);
    ui->tableView_2->addAction( hapus );
    QObject::connect( hapus, SIGNAL(triggered()), this, SLOT(hapus_data()));
    setup_tampil_hirarki_server();

    tree1 = new QStandardItemModel();
    //tree2 = new QStandardItemModel();
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

//   QStandardItem * item0;
//   item0 = assign_icon(this->tree1," ss", 100, 0);
   this->load_aset(0, 0, 0);

    connect(ui->treeView,&TreeSub::emitEmulateDataByClick,this,&Tampil::on_treeView_clicked);
    ui->treeView->setModel( tree1 );

//    connect(ui->treeView_2,&TreeSub::emitEmulateDataByClick,this,&Tampil::on_treeView_clicked);
//    ui->treeView->setModel( tree2 );

    this->ui->treeView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->ui->treeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    QModelIndex index = ui->treeView->model()->index(0,0);
    this->ui->treeView->setCurrentIndex(index);

//    QModelIndex index2 = ui->treeView_2->model()->index(0,0);
//    this->ui->treeView_2->setCurrentIndex(index2);

    //setup_tampil_hirarki_sofhaliza();
    //setup_tampil_hirarki_haliza();

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
qDebug()<<" -- tree click --";
}

void Tampil::on_treeView_expanded(QModelIndex index)
{
    qDebug()<<" -- expand --";
}

void Tampil::on_treeView_activated(QModelIndex index)
{

qDebug()<<" -- tree active --";
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

//    while(counter<=4){
//        counter++;
//    QStandardItem* item0;
//    item0 = assign_icon(this->tree1, "cacah[i]", 100,counter);
//    item0 = assign_icon(this->tree1, "cacah[i]", 800, counter);
//    item0 = assign_icon(this->tree1, "cacah[0]", 5400, counter);
//    item0 = assign_icon(this->tree1, "cacah[0]", 5400, counter);
//    load_aset(item0,counter,1);
//    }
   // load_aset(item0,1,1);
//    QString nama;
//    int id_kind;
//    int id_aset;
//    int id_parent;
//    int jum_aset = 0;
//    QString aset;
//    qDebug("%s() <== id=%d, siapa = %d",__FUNCTION__,id,siapa);// << "(debug 10) masuk ke void load_aset";
//    QString qu;
//    QStandardItemModel *r_model = new QStandardItemModel(this);
//    r_model->setHorizontalHeaderItem(0, new QStandardItem(QString("folder")));

//    QFile file("new/data/NewFile.txt");
//       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))qDebug()<<"!File";
//        //           return 1;

//       QTextStream in(&file);
//       QString line = in.readLine();
//       QByteArray data;
//       data+=line;
////       while (!line.isNull()) {
////           jum_aset++;
////           line = in.readLine();
////           qDebug()<<line;
////           int row = r_model->rowCount();
////           row++;
////           r_model->setItem( row-1, 0, new QStandardItem(line));
////           int id_kind =100;
////           QStandardItem* item0;
////           item0 = (id==0)? assign_icon(this->tree1, line, id_kind, jum_aset) :assign_icon_item( si, line, id_kind, jum_aset);
////           //load_aset(item0, id_aset, 1);
////       }
//       struct t_m masuk;
//       struct t_info info;
//       struct t_c *masuk2;
//       struct t_info* info2;
//       QVector<int> kind={100,810,5400,5400};
//       QByteArray hirarki = "comp.pab.DBE.Engine1.=";

//       QByteArray bb = data.mid(hirarki.size(),sizeof (t_m));
//           masuk2 =(struct t_c *)bb.data();
//           qDebug() <<"setting:"<< masuk2->gol;
//       QByteArray bs = data.mid(hirarki.size()+sizeof (t_c),sizeof (t_info));
//           info2 =(struct t_info *)bs.data();

//       qDebug()<<"data yang nanti dikirim="<<data;
//       QString olah = (QString )data;
//       QStringList cacah = olah.split(".");
//       qDebug() << cacah;

//       for(int i=0; i<cacah.size()-1; i++){
//           aset = cacah[i];
//           qDebug() <<"| nama aset " <<cacah[i]<<"|" << kind[i]<<"|";
//           qDebug()<<"+--------------------------+";
//           QStandardItem* item0;
//        //  for(int k=0; k<2; k++){
//          item0 = assign_icon(this->tree1, cacah[i], kind[i], i);// :assign_icon_item( si, line, kind[i], k);
//          //}

//           if(i==1)break;
//          load_aset(item0,i,1);

//       }

//    QSqlQuery Q2( db );
//    QString nama;
//    int id_kind;
//    int id_aset;
//    int id_parent;
//    int jum_aset = 0;

//    QString qu;

//    qu = QString("SELECT * FROM aset WHERE id_parent=%1").arg(id);
//    if(!Q2.exec(qu)) qDebug()<< __FUNCTION__ << __LINE__ << "ERROR : "<<Q2.lastError().text();
//    else
//    {
//        while (Q2.next())
//        {
//            jum_aset++;
//            nama = Q2.value("name").toString();
//            id_aset = Q2.value("id").toInt();
//            id_kind = Q2.value("id_kind").toInt();
//            id_parent = Q2.value("id_parent").toInt();
//            qDebug()<<nama;
//            qDebug("id_aset : %d, id_kind : %d, id_parent : %d , id : %d",id_aset,id_kind, id_parent,id);
//            QStandardItem* item0;

//            item0 = (id==0)? assign_icon(this->tree1, nama, id_kind, id_aset) :assign_icon_item( si, nama, id_kind, id_aset);

//            load_aset(item0, id_aset, 1);
//            load_param(item0, id_aset,1);

//        }


        // sorting dibuat hanya untuk id_kind == 5200 || 5300  RECIP_COMPRESSOR

//        if(id_kind == ID_KIND_RECIP_COMPRESSOR)/*|| id_kind == ID_KIND_COMP_VALVE*/// )
//            tree1->sort(0, Qt::AscendingOrder);

//        if(id==0)
//            this->sudah_ada_aset++;
  // }
    //QTreeView *tree = new QTreeView;
//    QVector<int> kind = {100,800,5300};
//    QVector<int> kind2 = {100,800,5300,5300};
//    QVector<QString> nama = {"hai","hallo","bay"};
//    QVector<QString> nama2 = {"hai","hallo","bay","blade"};
//    int kind_last=0;
//    QStandardItemModel model(3, 3);
//    QStandardItem *items;
//    for (int i = 0; i < kind.size()-1; i++)
//    {
//        if(counter ==0)items = new QStandardItem(nama[i]);
//        counter+=1;
//        items->appendRow(new QStandardItem(nama[i+1]));
//        tree1->setItem(0,0,items);
//     }
    QTreeView *view   = new QTreeView;
    QJsonModel *model = new QJsonModel;

    view->setModel(model);

    std::string json = R"({
                      "firstName": "John",
                      "lastName": "Smith",
                      "age": 25,
                      "far-sighted": true,
                      "address":
                      {
                          "streetAddress": "21 2nd Street",
                          "city": "New York",
                          "state": "NY",
                          "postalCode": "10021"
                      },
                      "phoneNumber":
                      [
                          {
                            "type": "home",
                            "number": "212 555-1234"
                          },
                          {
                            "type": "fax",
                            "number": "646 555-4567"
                          }
                      ],
                      "DBE":{"dbs":"hallo"}
                  })";

       model->loadJson(QByteArray::fromStdString(json));
       view->show();

       QByteArray mjson = model->json();
       qDebug() << mjson;
}

void Tampil::on_pushButton_6_clicked()
{
    //buat folder/file baru
    QString data = ui->lineEdit_6->text().toUtf8();
    qDebug()<<"alamat file="<<data;
    a.buat_file(data);
}


void Tampil::on_pushButton_7_clicked()
{
    QString data = ui->lineEdit_7->text().toUtf8();
    qDebug()<<"alamat file="<<data;
    a.delete_file(data);
}

