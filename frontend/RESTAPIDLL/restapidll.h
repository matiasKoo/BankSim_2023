
#ifndef RESTAPIDLL_H
#define RESTAPIDLL_H

#include "RESTAPIDLL_global.h"
#include <QObject>
#include <QDebug>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


class RESTAPIDLL_EXPORT RESTAPIDLL: public QObject
{
    Q_OBJECT
public:
    RESTAPIDLL(QObject * parent = nullptr);
    void Login();
    void GetCardInfo();
    void getSaldo();
    void nosta20();
    void nosta40();
    void nosta50();
    void nosta100();

private slots:
    void receiveCardNumber(QString);
    void receivePinNumber(QString);
    void loginSlot(QNetworkReply * reply);
    void getByCardInfoSlot(QNetworkReply * reply);
    void getSaldoSlot(QNetworkReply * reply);
    void nostaSlot(QNetworkReply * reply);

private:
    QString cardNumber, pinNumber, idtili, idasiakas, saldo;
    QNetworkAccessManager * accessManager;
    QNetworkReply * reply;
    QByteArray response_data;
    QByteArray token;
};


#endif // RESTAPIDLL_H
