#ifndef TAMPIL_H
#define TAMPIL_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>
#include <QDebug>
#include <QLabel>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QMessageBox>

namespace Ui {
class Tampil;
}

class Tampil : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tampil(QWidget *parent = nullptr);
    ~Tampil();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Tampil *ui;
    void open_db();
    void persiapan_server();
    QSqlDatabase db;
    QSqlDatabase dbx;
    QVBoxLayout *box1;
    QLabel *list1;
    QVBoxLayout *box2;
    QLabel *list2;
    //--cari data berdasarkan urutan --//client
    void mulai_cari(QSqlQuery *query);
    void mulai_cari2(QSqlQuery *query);
    int id_database;
    QStringList jumlah_rute;
    QStringList nama_tidakada;
    //--cari data berdasarkan urutan --//server
    void mulai_cari_server(QSqlQuery *query);
    void mulai_cari_server2(QSqlQuery *query);
    void compare();
    void synchronize();
    QString get_table_name(int tipe);
    QStringList rute_;
    QVector<int> info_tipe_data[5];
    QVector<int> update_info[4];
    QVector<int> update_isi_rute[4];
    QByteArrayList all_data;
    QStringList rute_baru;
     QVector<int> data_[5];
     QVector<int> data_new[6];
};

#endif // TAMPIL_H
