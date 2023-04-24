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


    connect(this,SIGNAL(pinNum(QString)),
            RestDLL,SLOT(receivePinNumber(QString)));

    connect(this,SIGNAL(cardNum(QString)),
            RestDLL,SLOT(receiveCardNumber(QString)));

    connect(ui->pushButton,SIGNAL(clicked(bool)),
            this,SLOT(clickhandler()));

    connect(pinUI,SIGNAL(sendPin(short)),
            this,SLOT(pinSgnalHandler(short)));

    connect(ui->testi,SIGNAL(clicked(bool)),
            this,SLOT(testi()));

    connect(ui->goToNostaPage,SIGNAL(clicked(bool)),
            this,SLOT(nostaPageHandler()));

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
    state = 1;
    ui->stackedWidget->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickhandler()
{
    emit cardNum(ui->cardNumLineEdit->text());
    pinUI->displayText("Syötä PIN");
    state = 2;
    pinUI->show();
}

void MainWindow::pinSgnalHandler(short pin)
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
    RestDLL->getSaldo();
}


void MainWindow::testi()
{
    //RestDLL->GetCardInfo();
    RestDLL->getSaldo();
}

void MainWindow::cardReceiver(QString response)
{
    if(state == 1 && response == "1"){
        emit cardNum(response);         // response may need modification
        state = 2;
        pinUI->displayText("Syötä PIN");
        pinUI->show();
    }
}


void MainWindow::loginReceiver(QString response)
{
    if(response == "true"){
        ui->stackedWidget->setCurrentIndex(1);
    }else{
        pinUI->displayText(QString::number(3 - pinAttempts) + " yritystä jäljellä");
        pinUI->show();
    }


}

void MainWindow::nostoReceiver(QString responce)
{
    qDebug()<<"get saldo";
    RestDLL->getSaldo();
}

void MainWindow::saldoReceiver(QString saldo)
{
    ui->saldoLine->setText(saldo);
}

