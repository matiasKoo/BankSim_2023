#ifndef RFIDINTERFACE_H
#define RFIDINTERFACE_H

#include "rfidInterface_global.h"
#include <QString>
#include "engine.h"
#include <QObject>

class RFIDINTERFACE_EXPORT rfidInterface : public QObject
{
    Q_OBJECT

public:
    rfidInterface(QObject * parent = nullptr);
    ~rfidInterface();

private:
    engine *pEngine;
signals:
    void cardNumToExe(QString s);

public slots:
    void readyReadHandler(QString s);
};

#endif // RFIDINTERFACE_H
