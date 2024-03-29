#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pinUI = new pin_dialog(this);
    RestDLL = new RESTAPIDLL(this);
    rfid = new rfidInterface(this);

    // rest login tiedot lähetys
    connect(this,SIGNAL(pinNum(QString)),
            RestDLL,SLOT(receivePinNumber(QString)));

    connect(this,SIGNAL(cardNum(QString)),
            RestDLL,SLOT(receiveCardNumber(QString)));

    // pinnin vastaanotto
    connect(pinUI,SIGNAL(sendPin(short)),
            this,SLOT(pinSignalHandler(short)));


    // navigation

    connect(ui->goToNostaPage,SIGNAL(clicked(bool)),
            this,SLOT(nostaPageHandler()));
    connect(ui->goToTiliTapahtumatPage,SIGNAL(clicked(bool)),
            this,SLOT(tiliTapahtumatPageHandler()));
    connect(ui->menuButton1,SIGNAL(clicked(bool)),
            this,SLOT(menuPageHandler()));
    connect(ui->menuButton2,SIGNAL(clicked(bool)),
            this,SLOT(menuPageHandler()));

    connect(ui->logoutButton,SIGNAL(clicked(bool)),
            this,SLOT(logoutHandler()));


    //nosto connections
    connect(ui->nosta20,SIGNAL(clicked(bool)),
            this,SLOT(nosta20Handler()));
    connect(ui->nosta40,SIGNAL(clicked(bool)),
            this,SLOT(nosta40Handler()));
    connect(ui->nosta50,SIGNAL(clicked(bool)),
            this,SLOT(nosta50Handler()));
    connect(ui->nosta100,SIGNAL(clicked(bool)),
            this,SLOT(nosta100Handler()));

    //receiver connections
    connect(RestDLL,SIGNAL(sendLogin(QString)),
            this,SLOT(loginReceiver(QString)));

    connect(RestDLL,SIGNAL(sendSaldo(QString)),
            this,SLOT(saldoReceiver(QString)));

    connect(RestDLL,SIGNAL(sendNosto(QString)),
            this,SLOT(nostoReceiver(QString)));

    connect(RestDLL,SIGNAL(sendTransactions(QStringList)),
            this,SLOT(transactionsReceiver(QStringList)));

    //connection korttinumeron vastaan otolle
    connect(rfid,SIGNAL(cardNumToExe(QString)),
            this,SLOT(cardNumReceiver(QString)));

    state = 1;
    ui->stackedWidget->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pinSignalHandler(short pin)
{
    if(state == 2 && pinAttempts < 3){
        emit pinNum(QString::number(pin));
        RestDLL->Login();
        pinAttempts ++;

    }else if(state == 2 && pinAttempts >= 3){
        state = 1;
        pinAttempts = 0;
        qDebug()<<"reset login";
        ui->stackedWidget->setCurrentIndex(0);
    }



}

void MainWindow::nosta20Handler()
{
    RestDLL->nosta20();
}
void MainWindow::nosta40Handler()
{
    RestDLL->nosta40();
}
void MainWindow::nosta50Handler()
{
    RestDLL->nosta50();
}
void MainWindow::nosta100Handler()
{
    RestDLL->nosta100();
}

void MainWindow::nostaPageHandler()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->nostoMessage->setText("");
    RestDLL->getSaldo();
}

void MainWindow::tiliTapahtumatPageHandler()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->nostoMessage->setText("");
    //hae tapahtumat listaan
    RestDLL->getTransactions();

}

void MainWindow::menuPageHandler()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::logoutHandler()
{
    delete RestDLL;
    delete rfid;
    RestDLL = new RESTAPIDLL(this);
    rfid = new rfidInterface(this);

    // rest login tiedot lähetys
    connect(this,SIGNAL(pinNum(QString)),
            RestDLL,SLOT(receivePinNumber(QString)));

    connect(this,SIGNAL(cardNum(QString)),
            RestDLL,SLOT(receiveCardNumber(QString)));

    //receiver connections
    connect(RestDLL,SIGNAL(sendLogin(QString)),
            this,SLOT(loginReceiver(QString)));

    connect(RestDLL,SIGNAL(sendSaldo(QString)),
            this,SLOT(saldoReceiver(QString)));

    connect(RestDLL,SIGNAL(sendNosto(QString)),
            this,SLOT(nostoReceiver(QString)));

    connect(RestDLL,SIGNAL(sendTransactions(QStringList)),
            this,SLOT(transactionsReceiver(QStringList)));

    //connection korttinumeron vastaan otolle
    connect(rfid,SIGNAL(cardNumToExe(QString)),
            this,SLOT(cardNumReceiver(QString)));

    qDebug()<<"EXE: logout";
    ui->nostoMessage->setText("");
    state = 1;
    pinAttempts = 0;
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::cardNumReceiver(QString responce)
{
    if(state == 1){
        qDebug()<<"EXE: rfid korttinumero saatu: "<<responce;
        emit cardNum(responce);
        state = 2;
        pinUI->displayText("Syötä PIN");
        pinUI->exec();
    }
}


void MainWindow::loginReceiver(QString response)
{
    if(response == "true"){
        ui->stackedWidget->setCurrentIndex(1);
    }else{
        pinUI->displayText(QString::number(3 - pinAttempts) + " yritystä jäljellä");
        pinUI->exec();
    }


}

void MainWindow::nostoReceiver(QString responce)
{
    if(responce == "1"){
        qDebug()<<"EXE: nosto onistui";
        ui->nostoMessage->setText("nosto onistui");
        ui->stackedWidget->setCurrentIndex(1);
    }else{
        qDebug()<<"EXE: nosto epäonistui";
        ui->nostoMessage->setText("nosto epäonistui");
        ui->stackedWidget->setCurrentIndex(1);
    }

}

void MainWindow::saldoReceiver(QString saldo)
{
    qDebug()<<"got saldo"<<saldo;
    ui->saldoLine->setText(saldo);
}

void MainWindow::transactionsReceiver(QStringList n)
{
    QStringListModel * model;
    model = new QStringListModel(this);

    QStringList transactionsList = n;
    qDebug()<<n;
    model->setStringList(transactionsList);
    ui->listView->setModel(model);
}

