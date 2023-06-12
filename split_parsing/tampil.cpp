#include "tampil.h"
#include "ui_tampil.h"

Tampil::Tampil(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tampil)
{
    ui->setupUi(this);
    menu_tgl = new QMenu( ui->tableView_2 );
    ui->tableView_2->setContextMenuPolicy(Qt::ActionsContextMenu);
    this->setWindowTitle("Simulasi Upload Data");
    this->setMaximumSize(600,520);
    hapus = new QAction(tr("hapus data"), menu_tgl);
    ui->tableView_2->addAction( hapus );
    QObject::connect( hapus, SIGNAL(triggered()), this, SLOT(hapus_data()));

    QStandardItemModel *r_model = new QStandardItemModel(this);
    r_model->setHorizontalHeaderItem(0, new QStandardItem(QString("folder")));
    //r_model->setHorizontalHeaderItem(1, new QStandardItem(QString("data")));
//    r_model->setHorizontalHeaderItem(2, new QStandardItem(QString("id_tipe_param")));

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
    show();
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

