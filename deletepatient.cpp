#include "deletepatient.h"
#include "ui_deletepatient.h"

#include <QMessageBox>

Deletepatient::Deletepatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Deletepatient)
{
    ui->setupUi(this);
}

Deletepatient::~Deletepatient()
{
    delete ui;
}

void Deletepatient::on_sil_btn_clicked()
{
    Login conn;
    QString id;
    id = ui->id_txt->text();

    if (id != "")
    {
        if(!conn.connOpen())
        {
            qDebug() << "Veritabanına bağlanılamadı.";
            return;
        }

        conn.connOpen();
        QSqlQuery q;
        q.prepare("select hasta_id from hasta_tbl where hasta_id='" + id + "'");
        if (q.exec())
        {
            q.prepare("delete from hasta_tbl where hasta_id='" + id + "'");
            if(q.exec())
            {
                QMessageBox::critical(this, tr("Mesaj"), tr("Silindi"));
                conn.connClose();
                this->hide();
            }
            else
            {
                QMessageBox::critical(this, tr("error::"), q.lastError().text());
            }
        }
        else
        {
            QMessageBox::critical(this, tr("Uyarı"), "Bu id numarasına sahip bir hasta bulunamadı.");
        }
    }
    else
    {
        QMessageBox::critical(this, tr("Uyarı"), "Lütfen silinecek hastanın id'sini giriniz.");
    }
}
