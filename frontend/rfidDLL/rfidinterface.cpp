#include "rfidinterface.h"
#include <engine.h>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

rfidInterface::rfidInterface(QObject * parent) : QObject(parent)
{
    qDebug()<<"rfidInterface() konstruktori";

    pEngine = new engine(this);

    connect(pEngine, SIGNAL(cardNumberToInterface()),
             this, SLOT(readyReadHandler()));

}

rfidInterface::~rfidInterface()
{

}

void rfidInterface::readyReadHandler()
{
    qDebug()<<"Interfacen readHandler";
    qDebug()<<pEngine->fetchCardNumber();
}
