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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tampil
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QTableView *tableView_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QFrame *line;
    QLabel *label_3;
    QLabel *label_4;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *label_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Tampil)
    {
        if (Tampil->objectName().isEmpty())
            Tampil->setObjectName(QString::fromUtf8("Tampil"));
        Tampil->resize(800, 600);
        centralwidget = new QWidget(Tampil);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(30, 31, 211, 171));
        tableView_2 = new QTableView(centralwidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(280, 31, 191, 171));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 240, 181, 25));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 220, 91, 17));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(30, 290, 181, 25));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 270, 111, 17));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 240, 89, 25));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 290, 89, 25));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(30, 210, 451, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(480, 210, 67, 17));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(480, 10, 67, 17));
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(30, 10, 451, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(30, 330, 451, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(480, 330, 67, 17));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(240, 410, 89, 25));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(240, 360, 89, 25));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 340, 91, 17));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(30, 360, 181, 25));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(30, 410, 181, 25));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 390, 111, 17));
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
        label->setText(QApplication::translate("Tampil", "nama data", nullptr));
        label_2->setText(QApplication::translate("Tampil", "hirarki tertinggi", nullptr));
        pushButton->setText(QApplication::translate("Tampil", "Upload", nullptr));
        pushButton_2->setText(QApplication::translate("Tampil", "ReqBaru", nullptr));
        label_3->setText(QApplication::translate("Tampil", "Sofhaliza", nullptr));
        label_4->setText(QApplication::translate("Tampil", "Server", nullptr));
        label_5->setText(QApplication::translate("Tampil", "Haliza", nullptr));
        pushButton_3->setText(QApplication::translate("Tampil", "ReqBaru", nullptr));
        pushButton_4->setText(QApplication::translate("Tampil", "Upload", nullptr));
        label_6->setText(QApplication::translate("Tampil", "nama data", nullptr));
        label_7->setText(QApplication::translate("Tampil", "hirarki tertinggi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tampil: public Ui_Tampil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAMPIL_H
