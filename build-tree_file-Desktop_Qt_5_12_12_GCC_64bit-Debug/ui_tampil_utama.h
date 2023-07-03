/********************************************************************************
** Form generated from reading UI file 'tampil_utama.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAMPIL_UTAMA_H
#define UI_TAMPIL_UTAMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tampil_utama
{
public:
    QWidget *centralwidget;
    QTreeView *treeView;
    QListView *listView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *tampil_utama)
    {
        if (tampil_utama->objectName().isEmpty())
            tampil_utama->setObjectName(QString::fromUtf8("tampil_utama"));
        tampil_utama->resize(800, 600);
        centralwidget = new QWidget(tampil_utama);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(9, 9, 256, 192));
        listView = new QListView(centralwidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(280, 10, 256, 192));
        tampil_utama->setCentralWidget(centralwidget);
        menubar = new QMenuBar(tampil_utama);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        tampil_utama->setMenuBar(menubar);
        statusbar = new QStatusBar(tampil_utama);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        tampil_utama->setStatusBar(statusbar);

        retranslateUi(tampil_utama);

        QMetaObject::connectSlotsByName(tampil_utama);
    } // setupUi

    void retranslateUi(QMainWindow *tampil_utama)
    {
        tampil_utama->setWindowTitle(QApplication::translate("tampil_utama", "tampil_utama", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tampil_utama: public Ui_tampil_utama {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAMPIL_UTAMA_H
