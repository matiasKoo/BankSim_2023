
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
    void getCardInfo();
    void getCustomerInfo();
    void getTransactions();
    void getSaldo();
    void nosta20();
    void nosta40();
    void nosta50();
    void nosta100();

private slots:
    void receiveCardNumber(QString);
    void receivePinNumber(QString);
    void loginSlot(QNetworkReply * reply);
    void getCardInfoSlot(QNetworkReply * reply);
    void getCustomerInfoSlot(QNetworkReply * reply);
    void getTransactionsSlot(QNetworkReply * reply);
    void getSaldoSlot(QNetworkReply * reply);
    void nostaSlot(QNetworkReply * reply);

signals:
    void sendSaldo(QString);
    void sendTransactions(QStringList);
    void sendLogin(QString);
    void sendNosto(QString);

private:
    QString cardNumber, pinNumber, idtili, idasiakas, saldo, fname, lname, henkilotunnus, luottoraja, tilitapahtumat;
    QNetworkAccessManager * accessManager;
    QNetworkReply * reply;
    QByteArray response_data;
    QByteArray token;
    QStringList list;
};


#endif // RESTAPIDLL_H
