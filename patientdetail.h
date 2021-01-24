#ifndef PATIENTDETAIL_H
#define PATIENTDETAIL_H

#include <QDialog>
#include "login.h"
#include "newpatient.h"
#include "mainwindow.h"

namespace Ui {
class Patientdetail;
}

class Patientdetail : public QDialog
{
    Q_OBJECT

public:
    QString hasta_id;
    explicit Patientdetail(QWidget *parent = nullptr, QString val="");
    ~Patientdetail();
    void get_table();
private slots:
    void on_yeni_kayit_btn_clicked();

    void on_pushButton_clicked();

private:
    Ui::Patientdetail *ui;
};

#endif // PATIENTDETAIL_H
