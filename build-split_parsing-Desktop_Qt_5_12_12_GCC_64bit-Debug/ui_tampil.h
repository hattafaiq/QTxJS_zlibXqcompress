/********************************************************************************
** Form generated from reading UI file 'tampil.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAMPIL_H
#define UI_TAMPIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>
#include "treesub.h"

QT_BEGIN_NAMESPACE

class Ui_Tampil
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_6;
    QTableView *tableView_3;
    QLineEdit *lineEdit_3;
    TreeSub *treeView;
    QLineEdit *lineEdit_2;
    QLabel *label_7;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_2;
    QTableView *tableView_5;
    QTableView *tableView_4;
    QFrame *line_2;
    QLabel *label_3;
    QFrame *line;
    QPushButton *pushButton_3;
    QLabel *label_9;
    QLabel *label_8;
    QTableView *tableView;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QTableView *tableView_6;
    QPushButton *pushButton;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QFrame *line_3;
    QLineEdit *lineEdit_4;
    QTableView *tableView_2;
    QLabel *label_5;
    QLabel *label_10;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Tampil)
    {
        if (Tampil->objectName().isEmpty())
            Tampil->setObjectName(QString::fromUtf8("Tampil"));
        Tampil->resize(800, 618);
        centralwidget = new QWidget(Tampil);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 24, 1, 1, 1);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 13, 2, 1, 1);

        tableView_3 = new QTableView(centralwidget);
        tableView_3->setObjectName(QString::fromUtf8("tableView_3"));

        gridLayout->addWidget(tableView_3, 6, 0, 1, 1);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 20, 1, 1, 1);

        treeView = new TreeSub(centralwidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        gridLayout->addWidget(treeView, 5, 0, 1, 3);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 12, 1, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 23, 0, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 12, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 12, 3, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 10, 0, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 20, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 12, 0, 1, 1);

        tableView_5 = new QTableView(centralwidget);
        tableView_5->setObjectName(QString::fromUtf8("tableView_5"));

        gridLayout->addWidget(tableView_5, 18, 0, 1, 1);

        tableView_4 = new QTableView(centralwidget);
        tableView_4->setObjectName(QString::fromUtf8("tableView_4"));

        gridLayout->addWidget(tableView_4, 6, 1, 1, 2);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 0, 0, 1, 3);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 5, 3, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 0, 1, 3);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 23, 2, 1, 1);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 13, 0, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 24, 0, 1, 1);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 2, 0, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 10, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 3, 1, 1);

        tableView_6 = new QTableView(centralwidget);
        tableView_6->setObjectName(QString::fromUtf8("tableView_6"));

        gridLayout->addWidget(tableView_6, 18, 1, 1, 2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 10, 2, 1, 1);

        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 13, 1, 1, 1);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 24, 2, 1, 1);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 20, 2, 1, 1);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 16, 0, 1, 3);

        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 23, 1, 1, 1);

        tableView_2 = new QTableView(centralwidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));

        gridLayout->addWidget(tableView_2, 2, 1, 1, 2);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 18, 3, 1, 1);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 14, 0, 1, 1);

        lineEdit_7 = new QLineEdit(centralwidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        gridLayout->addWidget(lineEdit_7, 14, 1, 1, 1);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 14, 2, 1, 1);

        Tampil->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Tampil);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        Tampil->setMenuBar(menubar);
        statusbar = new QStatusBar(Tampil);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Tampil->setStatusBar(statusbar);

        retranslateUi(Tampil);

        QMetaObject::connectSlotsByName(Tampil);
    } // setupUi

    void retranslateUi(QMainWindow *Tampil)
    {
        Tampil->setWindowTitle(QApplication::translate("Tampil", "MainWindow", nullptr));
        pushButton_6->setText(QApplication::translate("Tampil", "New", nullptr));
        label_7->setText(QApplication::translate("Tampil", "hirarki tertinggi", nullptr));
        pushButton_2->setText(QApplication::translate("Tampil", "ReqBaru", nullptr));
        label->setText(QApplication::translate("Tampil", "nama data", nullptr));
        label_6->setText(QApplication::translate("Tampil", "nama data", nullptr));
        label_2->setText(QApplication::translate("Tampil", "hirarki tertinggi", nullptr));
        label_3->setText(QApplication::translate("Tampil", "Sofhaliza", nullptr));
        pushButton_3->setText(QApplication::translate("Tampil", "ReqBaru", nullptr));
        label_9->setText(QApplication::translate("Tampil", "Buat file baru", nullptr));
        label_8->setText(QApplication::translate("Tampil", "Ambil st untuk pengukuran baru", nullptr));
        label_4->setText(QApplication::translate("Tampil", "Server", nullptr));
        pushButton->setText(QApplication::translate("Tampil", "Upload", nullptr));
        pushButton_5->setText(QApplication::translate("Tampil", "ReqBaru", nullptr));
        pushButton_4->setText(QApplication::translate("Tampil", "Upload", nullptr));
        label_5->setText(QApplication::translate("Tampil", "Haliza", nullptr));
        label_10->setText(QApplication::translate("Tampil", "delete file", nullptr));
        pushButton_7->setText(QApplication::translate("Tampil", "delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tampil: public Ui_Tampil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAMPIL_H
