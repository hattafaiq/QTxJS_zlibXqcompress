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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "treesub.h"

QT_BEGIN_NAMESPACE

class Ui_Tampil
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    TreeSub *treeView;
    QFrame *line_2;
    QLabel *label_4;
    QLabel *label;
    QPushButton *pushButton;
    QFrame *line;
    QLabel *label_5;
    QLabel *label_3;
    QFrame *line_3;
    QFrame *line_4;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Tampil)
    {
        if (Tampil->objectName().isEmpty())
            Tampil->setObjectName(QString::fromUtf8("Tampil"));
        Tampil->resize(800, 600);
        centralwidget = new QWidget(Tampil);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 11, 0, 1, 1);

        treeView = new TreeSub(centralwidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        gridLayout->addWidget(treeView, 5, 0, 1, 2);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 0, 0, 1, 2);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 14, 0, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 0, 1, 2);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 17, 2, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 5, 2, 1, 1);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 10, 0, 1, 2);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 17, 0, 1, 2);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 16, 0, 1, 1);

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
        pushButton_2->setText(QApplication::translate("Tampil", "Connect", nullptr));
        label_4->setText(QApplication::translate("Tampil", "Server", nullptr));
        label->setText(QApplication::translate("Tampil", "Status", nullptr));
        pushButton->setText(QApplication::translate("Tampil", "Kirim", nullptr));
        label_5->setText(QApplication::translate("Tampil", "Haliza", nullptr));
        label_3->setText(QApplication::translate("Tampil", "Sofhaliza", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tampil: public Ui_Tampil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAMPIL_H
