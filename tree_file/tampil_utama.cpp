#include "tampil_utama.h"
#include "ui_tampil_utama.h"

tampil_utama::tampil_utama(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tampil_utama)
{
    ui->setupUi(this);
    QString mPath = "Home/";
    dirModel = new QFileSystemModel(this);

    // Set filter
    dirModel->setFilter(QDir::NoDotAndDotDot |
                        QDir::AllDirs);

    // QFileSystemModel requires root path
    dirModel->setRootPath(mPath);

    // Attach the model to the view
    ui->treeView->setModel(dirModel);
}

tampil_utama::~tampil_utama()
{
    delete ui;
}

