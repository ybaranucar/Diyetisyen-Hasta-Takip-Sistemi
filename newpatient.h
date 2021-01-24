#ifndef NEWPATIENT_H
#define NEWPATIENT_H

#include <QDialog>
#include "login.h"
#include "mainwindow.h"

namespace Ui {
class Newpatient;
}

class Newpatient : public QDialog
{
    Q_OBJECT

public:
    QString doktor_id;
    explicit Newpatient(QWidget *parent = nullptr, QString val="");
    ~Newpatient();

private slots:
    void on_kaydet_btn_clicked();

private:
    Ui::Newpatient *ui;
};

#endif // NEWPATIENT_H
