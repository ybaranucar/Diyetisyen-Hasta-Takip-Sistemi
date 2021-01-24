#ifndef DELETEPATIENT_H
#define DELETEPATIENT_H

#include <QDialog>
#include "login.h"
#include "mainwindow.h"

namespace Ui {
class Deletepatient;
}

class Deletepatient : public QDialog
{
    Q_OBJECT

public:
    explicit Deletepatient(QWidget *parent = nullptr);
    ~Deletepatient();

private slots:
    void on_sil_btn_clicked();

private:
    Ui::Deletepatient *ui;
};

#endif // DELETEPATIENT_H
