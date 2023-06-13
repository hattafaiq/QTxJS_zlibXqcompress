#ifndef TAMPIL_H
#define TAMPIL_H
#include "pars.h"
#include <QMainWindow>
#include <QStandardItem>
#include "treesub.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>

namespace Ui {
class Tampil;
}

class Tampil : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tampil(QWidget *parent = nullptr);
    ~Tampil();
    pars a;
    QStandardItem* assign_icon_x( QString name, int id_kind);
    QStandardItem* assign_icon(QStandardItemModel *tree, QString name, int id_kind, int id);
    QStandardItem* assign_icon_item(QStandardItem *tree, QString name, int id_kind, int id);
    void set_assign_icon_item(QStandardItem *tree, QString name, int id_kind, int id);
    void load_aset(QStandardItem *si, int id, int siapa);
    void load_param(QStandardItem *si, int id_aset, int siapa);


public slots:
    void on_treeView_clicked(QModelIndex index);
    void on_treeView_expanded(QModelIndex index);
    void on_treeView_activated(QModelIndex index);

private slots:
    void on_tableView_clicked(const QModelIndex &index);
    void hapus_data();
    void on_tableView_2_pressed(const QModelIndex &index);
    void refresh_data(QString a);


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Tampil *ui;
    QAction *hapus;
    QMenu *menu_tgl;
    QStringList tampung_data;
    int index_data_hapus;
    int last_select_view_data;
    QString last_kota;
    void re_write();
    void setup_tampil_hirarki_server();
    void setup_tampil_hirarki_sofhaliza();
    void setup_tampil_hirarki_haliza();
     QStandardItemModel *tree1;
     int sudah_ada_aset;
     QSqlDatabase db;
     QString con_name;
     QSqlQuery *pQ;
     QSqlRelationalTableModel *r_model;

};

#endif // TAMPIL_H
