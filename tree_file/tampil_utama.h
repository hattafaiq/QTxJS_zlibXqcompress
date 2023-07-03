#ifndef TAMPIL_UTAMA_H
#define TAMPIL_UTAMA_H

#include <QMainWindow>
#include <QFileSystemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class tampil_utama; }
QT_END_NAMESPACE

class tampil_utama : public QMainWindow
{
    Q_OBJECT

public:
    tampil_utama(QWidget *parent = nullptr);
    ~tampil_utama();

private:
    Ui::tampil_utama *ui;
    QFileSystemModel *dirModel;
    QFileSystemModel *fileModel;
};
#endif // TAMPIL_UTAMA_H
