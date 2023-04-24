#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pin_dialog.h"
#include "restapidll.h"
#include "rfidinterface.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void clickhandler();
    void pinSgnalHandler(short);
    void nosta20Handler();
    void nosta40Handler();
    void nosta50Handler();
    void nosta100Handler();
    void nostaPageHandler();
    void testi();
    void cardReceiver(QString);
    void loginReceiver(QString);
    void nostoReceiver(QString);
    void saldoReceiver(QString);


signals:
    void pinNum(QString);
    void cardNum(QString);

private:
    Ui::MainWindow *ui;
    pin_dialog * pinUI;
    RESTAPIDLL * RestDLL;
    rfidInterface * rfid;


    void jsonToObj(QString);
    int pinAttempts = 0;
    int state = 0;
    /* 0 initializing
     * 1 wating for card number
     * 2 waiting for pin
     * 3 logged in
    */
};
#endif // MAINWINDOW_H
