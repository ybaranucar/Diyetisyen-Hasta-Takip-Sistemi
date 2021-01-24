#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "newpatient.h"
#include "patientdetail.h"
#include "newpatientdetail.h"
#include "deletepatient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Mainwindow; }
QT_END_NAMESPACE

class Mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    QString doktor_id;
    Mainwindow(QWidget *parent = nullptr, QString val="");
    ~Mainwindow();
    void get_table();

private slots:
    void on_sil_btn_clicked();

    void on_hasta_tbl_activated(const QModelIndex &index);

    void on_yeni_kayit_btn_clicked();

    void on_guncelle_btn_clicked();

private:
    Ui::Mainwindow *ui;
};

#endif // MAINWINDOW_H
