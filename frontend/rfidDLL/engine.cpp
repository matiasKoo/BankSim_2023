#include "engine.h"
#include <QDebug>
#include "qobject.h"

engine::engine(QObject * parent) : QObject(parent)
{
    qDebug()<<"Enginen konstruktori";

    serialPort = new QSerialPort(this);

    serialPortInfo = QSerialPortInfo::availablePorts();
}

void engine::openSerialPort()
{
    connect(serialPort, SIGNAL(readyRead()),
            this, SLOT(readyReadHandler()));

    foreach(const auto tempSerialInfo, serialPortInfo){

        //haetaan sarjanumero "OL4E78E0053ECC3" ja sen portin nimi
        //jos jostain syystä com portti eläisi, ei älyttömän oleellinen
        QString serialNumber = "OL4E78E0053ECC3";

        if (tempSerialInfo.serialNumber() == serialNumber){
            qDebug()<<"Laite löydetty";

            serialPort->close();
            serialPort->setPortName(tempSerialInfo.portName());
            serialPort->setBaudRate(QSerialPort::Baud9600);
            serialPort->setDataBits(QSerialPort::Data8);
            serialPort->setParity(QSerialPort::NoParity);
            serialPort->setStopBits(QSerialPort::OneStop);
            serialPort->setFlowControl(QSerialPort::NoFlowControl);

            qDebug()<<serialPort->portName();

            if(serialPort->open(QIODevice::ReadWrite)) {
                qDebug() << "SERIAL: OK!";
            } else {
                qDebug() << "SERIAL: ERROR!";
            }
        }
    }
}

void engine::readyReadHandler()
{
    cardString = "";
    QByteArray data = serialPort->readAll();
    cardString = QString(data);
    qDebug()<<cardString;
    cardString.remove(0,2);
    cardString.remove(11,15);
    qDebug()<<cardString;
    emit cardNumberToInterface(cardString);
}
