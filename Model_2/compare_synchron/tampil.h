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
    void cari_data(QSqlQuery *query);
    void cari_data_server(QSqlQuery *query);
    void masuk_tipe_data();
    void masuk_tipe_data_server();
    QVector<int> info_data[2];
    QVector<int> info_data_server[2];
    QString get_table_name(int tipe);
    void cari_induk_paramm(int parameter,int tipe,int id_data);
    void cari_induk_paramm_server(int parameter,int tipe,int id_data);
    void cari_induk(int p_id_param);
    void cari_induk_server(int p_id_param);
    QString initial_rute;
    QString initial_rute2;
    QLabel *labelku;
    QLabel *labelku2;
    QCheckBox *boxlabelku;
    QCheckBox *boxlabelku2;
    QVBoxLayout *box;
    QVBoxLayout *box2;
    QVBoxLayout *box3;
    QStringList cacah_data_name;
    QVector<int> id_param_target;
    QStringList cacah_data_synchronize;
    void compare();
    void synchronize();
    int id_database;

};

#endif // TAMPIL_H
