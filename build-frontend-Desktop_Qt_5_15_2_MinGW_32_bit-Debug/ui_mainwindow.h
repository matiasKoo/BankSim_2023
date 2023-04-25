/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *startPage;
    QPushButton *pushButton;
    QLineEdit *cardNumLineEdit;
    QWidget *menuPage;
    QPushButton *goToNostaPage;
    QPushButton *goToTiliTapahtumatPage;
    QWidget *nostoPage;
    QPushButton *nosta20;
    QPushButton *nosta40;
    QPushButton *nosta50;
    QPushButton *nosta100;
    QLineEdit *saldoLine;
    QLabel *label;
    QPushButton *testi;
    QPushButton *menuButton1;
    QLabel *label_3;
    QWidget *tiliTapahtumatPage;
    QListWidget *listWidget;
    QLabel *label_2;
    QPushButton *menuButton2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(524, 381);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 521, 341));
        startPage = new QWidget();
        startPage->setObjectName(QString::fromUtf8("startPage"));
        pushButton = new QPushButton(startPage);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 40, 80, 24));
        cardNumLineEdit = new QLineEdit(startPage);
        cardNumLineEdit->setObjectName(QString::fromUtf8("cardNumLineEdit"));
        cardNumLineEdit->setGeometry(QRect(250, 50, 113, 24));
        stackedWidget->addWidget(startPage);
        menuPage = new QWidget();
        menuPage->setObjectName(QString::fromUtf8("menuPage"));
        goToNostaPage = new QPushButton(menuPage);
        goToNostaPage->setObjectName(QString::fromUtf8("goToNostaPage"));
        goToNostaPage->setGeometry(QRect(320, 100, 80, 24));
        goToTiliTapahtumatPage = new QPushButton(menuPage);
        goToTiliTapahtumatPage->setObjectName(QString::fromUtf8("goToTiliTapahtumatPage"));
        goToTiliTapahtumatPage->setGeometry(QRect(89, 100, 101, 24));
        stackedWidget->addWidget(menuPage);
        nostoPage = new QWidget();
        nostoPage->setObjectName(QString::fromUtf8("nostoPage"));
        nosta20 = new QPushButton(nostoPage);
        nosta20->setObjectName(QString::fromUtf8("nosta20"));
        nosta20->setGeometry(QRect(90, 130, 80, 24));
        nosta40 = new QPushButton(nostoPage);
        nosta40->setObjectName(QString::fromUtf8("nosta40"));
        nosta40->setGeometry(QRect(90, 170, 80, 24));
        nosta50 = new QPushButton(nostoPage);
        nosta50->setObjectName(QString::fromUtf8("nosta50"));
        nosta50->setGeometry(QRect(260, 130, 80, 24));
        nosta100 = new QPushButton(nostoPage);
        nosta100->setObjectName(QString::fromUtf8("nosta100"));
        nosta100->setGeometry(QRect(260, 170, 80, 24));
        saldoLine = new QLineEdit(nostoPage);
        saldoLine->setObjectName(QString::fromUtf8("saldoLine"));
        saldoLine->setGeometry(QRect(340, 40, 113, 24));
        QFont font;
        font.setPointSize(15);
        saldoLine->setFont(font);
        saldoLine->setReadOnly(true);
        saldoLine->setClearButtonEnabled(false);
        label = new QLabel(nostoPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 40, 61, 21));
        label->setFont(font);
        testi = new QPushButton(nostoPage);
        testi->setObjectName(QString::fromUtf8("testi"));
        testi->setGeometry(QRect(90, 270, 121, 24));
        menuButton1 = new QPushButton(nostoPage);
        menuButton1->setObjectName(QString::fromUtf8("menuButton1"));
        menuButton1->setGeometry(QRect(320, 270, 80, 24));
        label_3 = new QLabel(nostoPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(190, 100, 49, 16));
        stackedWidget->addWidget(nostoPage);
        tiliTapahtumatPage = new QWidget();
        tiliTapahtumatPage->setObjectName(QString::fromUtf8("tiliTapahtumatPage"));
        listWidget = new QListWidget(tiliTapahtumatPage);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(115, 91, 261, 201));
        label_2 = new QLabel(tiliTapahtumatPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 40, 151, 20));
        menuButton2 = new QPushButton(tiliTapahtumatPage);
        menuButton2->setObjectName(QString::fromUtf8("menuButton2"));
        menuButton2->setGeometry(QRect(400, 310, 80, 24));
        stackedWidget->addWidget(tiliTapahtumatPage);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 524, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "enter pin", nullptr));
        goToNostaPage->setText(QCoreApplication::translate("MainWindow", "nosta rahaa", nullptr));
        goToTiliTapahtumatPage->setText(QCoreApplication::translate("MainWindow", "tili tapahtumat", nullptr));
        nosta20->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        nosta40->setText(QCoreApplication::translate("MainWindow", "40", nullptr));
        nosta50->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        nosta100->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "saldo", nullptr));
        testi->setText(QCoreApplication::translate("MainWindow", "testi p\303\244ivit\303\244 saldo", nullptr));
        menuButton1->setText(QCoreApplication::translate("MainWindow", "takaisin", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "nosto", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "tilitapahtumat", nullptr));
        menuButton2->setText(QCoreApplication::translate("MainWindow", "takaisin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
