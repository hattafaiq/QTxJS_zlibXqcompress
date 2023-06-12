#ifndef TAMPIL_H
#define TAMPIL_H
#include "pars.h"
#include <QMainWindow>
#include <QStandardItem>

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

private slots:
    void on_tableView_clicked(const QModelIndex &index);
    void hapus_data();
    void on_tableView_2_pressed(const QModelIndex &index);
    void refresh_data(QString a);

private:
    Ui::Tampil *ui;
    QAction *hapus;
    QMenu *menu_tgl;
    QStringList tampung_data;
    int index_data_hapus;
    int last_select_view_data;
    QString last_kota;
    void re_write();


};

#endif // TAMPIL_H
