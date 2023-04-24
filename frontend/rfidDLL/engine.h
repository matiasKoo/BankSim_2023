#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QIODevice>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>

class engine : public QObject
{
    Q_OBJECT

public:
    engine(QObject * parent = nullptr);

    void openSerialPort();

public slots:
    void readyReadHandler();
signals:
    void cardNumberToInterface(QString s);
private:
    QSerialPort *serialPort;
    QList<QSerialPortInfo> serialPortInfo;
    QString cardString;
};

#endif // ENGINE_H
