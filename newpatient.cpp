#include "newpatient.h"
#include "ui_newpatient.h"
#include <QMessageBox>

Newpatient::Newpatient(QWidget *parent, QString val) :
    QDialog(parent),
    ui(new Ui::Newpatient)
{
    ui->setupUi(this);
    doktor_id = val;
}

Newpatient::~Newpatient()
{
    delete ui;
}

void Newpatient::on_kaydet_btn_clicked()
{
    Login conn;
    QString name, surname, age, gender, birthday, telephone, mail;
    name = ui->ad_txt->text();
    surname = ui->soyad_txt->text();
    age = ui->yas_txt->text();
    birthday =ui->dogum_tarihi_txt->date().toString();
    telephone = ui->tel_no_txt->text();
    mail = ui->email_txt->text();
    if (ui->erkek_radio_btn->isChecked())
    {
        gender = ui->erkek_radio_btn->text();
    }
    if (ui->kadin_radio_btn->isChecked())
    {
        gender = ui->kadin_radio_btn->text();
    }


    if(!conn.connOpen())
    {
        qDebug() << "Veritabanına bağlanılamadı.";
        return;
    }

    conn.connOpen();
    QSqlQuery q;
    //doktor_id kısmını ayarla
    q.prepare("insert into hasta_tbl (hasta_id, doktor_id, hasta_adı, hasta_soyadı, hasta_yaşı, cinsiyet, dogum_tarihi, tel_no, email) values (NULL,'" + doktor_id + "','" + name + "','"+ surname + "','" + age + "','" + gender + "','" + birthday + "','" + telephone + "','" + mail + "')");

    if(q.exec())
    {
        QMessageBox::critical(this, tr("Kaydet"), tr("Kaydedildi"));
        conn.connClose();
        this->hide();
    }
    else
    {
        QMessageBox::critical(this, tr("error::"), q.lastError().text());
    }
}
