#include "pin_dialog.h"
#include "ui_pin_dialog.h"

pin_dialog::pin_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pin_dialog)
{
    ui->setupUi(this);
    qDebug()<<"create dialog";

    connect(ui->N0,SIGNAL(clicked(bool)),
            this,SLOT(clickNumberHandler()));

    connect(ui->N1,SIGNAL(clicked(bool)),
            this,SLOT(clickNumberHandler()));

    connect(ui->N2,SIGNAL(clicked(bool)),
            this,SLOT(clickNumberHandler()));

    connect(ui->N3,SIGNAL(clicked(bool)),
            this,SLOT(clickNumberHandler()));

    connect(ui->N4,SIGNAL(clicked(bool)),
            this,SLOT(clickNumberHandler()));

    connect(ui->N5,SIGNAL(clicked(bool)),
            this,SLOT(clickNumberHandler()));

    connect(ui->N6,SIGNAL(clicked(bool)),
            this,SLOT(clickNumberHandler()));

    connect(ui->N7,SIGNAL(clicked(bool)),
            this,SLOT(clickNumberHandler()));

    connect(ui->N8,SIGNAL(clicked(bool)),
            this,SLOT(clickNumberHandler()));

    connect(ui->N9,SIGNAL(clicked(bool)),
            this,SLOT(clickNumberHandler()));

    connect(ui->eraseButton,SIGNAL(clicked(bool)),
            this,SLOT(clickEraseHandler()));

    connect(ui->submitButton,SIGNAL(clicked(bool)),
            this,SLOT(clickSubmitHandler()));
}

pin_dialog::~pin_dialog()
{
    qDebug()<<"delete dialog";
    delete ui;
}

void pin_dialog::displayText(QString s)
{
    ui->lineEdit->setPlaceholderText(s);
}

void pin_dialog::clickNumberHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString num = button->objectName();
    num =  num.remove(0,1);
    pin += num;
    qDebug()<<"Qstring pin = "<<pin;
    ui->lineEdit->insert("*");
    qDebug()<<"number pressed: "<<num;
}

void pin_dialog::clickSubmitHandler()
{
    qDebug()<<"pressed ok";
    ui->lineEdit->clear();
    emit sendPin(pin.toShort());
    pin.clear();
    this->done(1);
}

void pin_dialog::clickEraseHandler()
{
    qDebug()<<"pressed <-";
    ui->lineEdit->backspace();
    pin.remove(pin.length()-1,1);
}
