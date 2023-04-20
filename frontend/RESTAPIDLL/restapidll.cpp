
#include "restapidll.h"
#include "environment.h"


RESTAPIDLL::RESTAPIDLL(QObject *parent): QObject(parent)
{
    qDebug()<<"RESTAPI DLL created";
}

void RESTAPIDLL::receiveCardNumber(QString n)
{
    cardNumber = n;
    qDebug()<<"Card number received. The number is "<<cardNumber;
}

void RESTAPIDLL::receivePinNumber(QString n)
{
    pinNumber = n;
    qDebug()<<"Pin number received. The number is "<<pinNumber;
}

void RESTAPIDLL::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    if(QString::compare(response_data, "false")!=0)
    {
        qDebug()<<"Login OK";
        token = "Bearer "+response_data;
        qDebug()<<token;

        reply->deleteLater();
        accessManager->deleteLater();
        getCardInfo();

    }
    else
    {
        qDebug()<<"Login FAILED";
        emit sendError("false");

        reply->deleteLater();
        accessManager->deleteLater();
    }
}

void RESTAPIDLL::getCardInfoSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        idtili=QString::number(json_obj["tili_idtili"].toInt());
        idasiakas=QString::number(json_obj["asiakas_idasiakas"].toInt());
        luottoraja=QString::number(json_obj["luottoraja"].toInt());
    }

    qDebug()<<"idtili = "<<idtili;
    qDebug()<<"idasiakas = "<<idasiakas;
    qDebug()<<"luottoraja = "<<luottoraja;

    reply->deleteLater();
    accessManager->deleteLater();
    getCustomerInfo();
}

void RESTAPIDLL::getCustomerInfoSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    fname=json_obj["fname"].toString();
    lname=json_obj["lname"].toString();
    henkilotunnus=json_obj["henkilotunnus"].toString();

    qDebug()<<"fname = "<<fname;
    qDebug()<<"lname = "<<lname;
    qDebug()<<"henkilotunnus = "<<henkilotunnus;
    reply->deleteLater();
    accessManager->deleteLater();
}

void RESTAPIDLL::getTransactionsSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        QString aika = json_obj["aika"].toString();
        QString maara = QString::number(json_obj["maara"].toInt());
        tilitapahtumat = "Aika: "+aika+" | Määrä: "+maara;
        list<<tilitapahtumat;
        qDebug()<<list;
        emit sendTransactions(list);

    }

    reply->deleteLater();
    accessManager->deleteLater();
}

void RESTAPIDLL::getSaldoSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    saldo=QString::number(json_obj["saldo"].toInt());
    qDebug()<<"saldo = "<<saldo;
    emit sendSaldo(saldo);
    reply->deleteLater();
    accessManager->deleteLater();
}

void RESTAPIDLL::nostaSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    if(QString::compare(response_data, "0")!=0 && QString::compare(response_data, "Unauthorized")!=0)
    {
        qDebug()<<"Nosto successful";

        reply->deleteLater();
        accessManager->deleteLater();
    }
    else
    {
        qDebug()<<"Nosto failed";
        emit sendError("0");

        reply->deleteLater();
        accessManager->deleteLater();
    }

}

void RESTAPIDLL::Login()
{
    qDebug()<<"Sending login request to server";
    QJsonObject jsonObj;
    jsonObj.insert("korttinumero",cardNumber);
    jsonObj.insert("PIN",pinNumber);
    QString site_url = Environment::getBaseUrl()+"/login/";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    accessManager = new QNetworkAccessManager(this);
    connect(accessManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(loginSlot(QNetworkReply*)));

    reply = accessManager->post(request, QJsonDocument(jsonObj).toJson());
}

void RESTAPIDLL::getCardInfo()
{
    QString site_url = Environment::getBaseUrl()+"/kortti/1/"+cardNumber;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU

    accessManager = new QNetworkAccessManager(this);

    connect(accessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getCardInfoSlot(QNetworkReply*)));

    reply = accessManager->get(request);
}

void RESTAPIDLL::getCustomerInfo()
{
    QString site_url = Environment::getBaseUrl()+"/asiakas/"+idasiakas;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU

    accessManager = new QNetworkAccessManager(this);

    connect(accessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getCustomerInfoSlot(QNetworkReply*)));

    reply = accessManager->get(request);
}

void RESTAPIDLL::getTransactions()
{
    QString site_url = Environment::getBaseUrl()+"/tilitapahtumat/1/"+idtili;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU

    accessManager = new QNetworkAccessManager(this);

    connect(accessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getTransactionsSlot(QNetworkReply*)));

    reply = accessManager->get(request);
}

void RESTAPIDLL::getSaldo()
{
    QString site_url = Environment::getBaseUrl()+"/tili/"+idtili+"/saldo";
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU

    accessManager = new QNetworkAccessManager(this);

    connect(accessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getSaldoSlot(QNetworkReply*)));

    reply = accessManager->get(request);
}

void RESTAPIDLL::nosta20()
{
    QJsonObject jsonObj;
    jsonObj.insert("idtili", idtili);

    QString site_url = Environment::getBaseUrl()+"/tili/"+idtili+"/20";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU

    accessManager = new QNetworkAccessManager(this);

    connect(accessManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(nostaSlot(QNetworkReply*)));

    reply = accessManager->put(request, QJsonDocument(jsonObj).toJson());
}

void RESTAPIDLL::nosta40()
{
    QJsonObject jsonObj;
    jsonObj.insert("idtili", idtili);

    QString site_url = Environment::getBaseUrl()+"/tili/"+idtili+"/40";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU

    accessManager = new QNetworkAccessManager(this);

    connect(accessManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(nostaSlot(QNetworkReply*)));

    reply = accessManager->put(request, QJsonDocument(jsonObj).toJson());
}

void RESTAPIDLL::nosta50()
{
    QJsonObject jsonObj;
    jsonObj.insert("idtili", idtili);

    QString site_url = Environment::getBaseUrl()+"/tili/"+idtili+"/50";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU

    accessManager = new QNetworkAccessManager(this);

    connect(accessManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(nostaSlot(QNetworkReply*)));

    reply = accessManager->put(request, QJsonDocument(jsonObj).toJson());
}

void RESTAPIDLL::nosta100()
{
    QJsonObject jsonObj;
    jsonObj.insert("idtili", idtili);

    QString site_url = Environment::getBaseUrl()+"/tili/"+idtili+"/100";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU

    accessManager = new QNetworkAccessManager(this);

    connect(accessManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(nostaSlot(QNetworkReply*)));

    reply = accessManager->put(request, QJsonDocument(jsonObj).toJson());
}
