#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("SQL cek");
    this->setMaximumSize(300,300);
    counter=1;
    show();
}

static char buf_command[4096];
int MainWindow::proses_q( QSqlQuery *q, const char *s, ...)
{
    QSqlError er;
    va_list args;

    va_start (args, s);

       /* For this to work, printbuffer must be larger than
        * anything we ever want to print.
        */
    vsprintf (buf_command, s, args);
    va_end (args);

    if (!q->exec( buf_command ))
    {
        er = q->lastError();
        qDebug() << "(debug 58) Querry Error : Data not Found! 1";
        qDebug("%s(): ERR : %s", __FUNCTION__, er.text().toUtf8().data());
        return -1;
    }
    else
    {
        if(!q->first()){
            qDebug() << "(debug 58) Querry Error : Data not Found! 2" << q->lastQuery();
        }
        else{
           qDebug() << "(debug 58) Data Found!";
        }
    }
    return 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("password");
    if (!db.open())
    {
      QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
    }else{
      QMessageBox::information(this,"connected","database masuk");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    QSqlQuery query(db);
    proses_q(&query, "insert into aset ( name, id_kind, id_parent) values( '%s', %d, %d)", "x", 0, 0);
    if(!query.exec())qDebug()<<"kenapa?"<<query.lastError().text();
}

