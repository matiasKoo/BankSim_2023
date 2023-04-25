#include "rfidinterface.h"
#include <engine.h>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

rfidInterface::rfidInterface(QObject * parent) : QObject(parent)
{
    qDebug()<<"rfidInterface() konstruktori";

    pEngine = new engine(this);

    connect(pEngine, SIGNAL(cardNumberToInterface(QString)),
             this, SLOT(readyReadHandler(QString)));

    pEngine->openSerialPort();

}

rfidInterface::~rfidInterface()
{

}

void rfidInterface::readyReadHandler(QString s)
{
    qDebug()<<"Interfacen readHandler: "<<s;
    emit cardNumToExe(s);
}
