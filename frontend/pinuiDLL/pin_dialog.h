#ifndef PIN_DIALOG_H
#define PIN_DIALOG_H

#include <QDialog>
#include "pinuiDLL_global.h"
#include <QDebug>

namespace Ui {
class pin_dialog;
}

class PINUIDLL_EXPORT pin_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit pin_dialog(QWidget *parent = nullptr);
    ~pin_dialog();
    void displayText(QString);

signals:
    void sendPin(short);

private slots:
    void clickNumberHandler();
    void clickSubmitHandler();
    void clickEraseHandler();

private:
    Ui::pin_dialog *ui;
    QString pin;
};

#endif // PIN_DIALOG_H
