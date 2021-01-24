#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "mainwindow.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    QSqlDatabase db;
    void connClose();
    bool connOpen();

private slots:
    void on_login_btn_clicked();

private:
    Ui::Login *ui;
};
#endif // LOGIN_H
