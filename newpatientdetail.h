#ifndef NEWPATIENTDETAIL_H
#define NEWPATIENTDETAIL_H

#include <QDialog>
#include "login.h"
#include "mainwindow.h"

namespace Ui {
class Newpatientdetail;
}

class Newpatientdetail : public QDialog
{
    Q_OBJECT

public:
    QString hasta_id;
    explicit Newpatientdetail(QWidget *parent = nullptr, QString val="");
    ~Newpatientdetail();

private slots:
    void on_kaydet_btn_clicked();

private:
    Ui::Newpatientdetail *ui;
};

#endif // NEWPATIENTDETAIL_H
