#include "newpatientdetail.h"
#include "ui_newpatientdetail.h"
#include <QMessageBox>

Newpatientdetail::Newpatientdetail(QWidget *parent, QString val) :
    QDialog(parent),
    ui(new Ui::Newpatientdetail)
{
    ui->setupUi(this);
    hasta_id = val;
}

Newpatientdetail::~Newpatientdetail()
{
    delete ui;
}

void Newpatientdetail::on_kaydet_btn_clicked()
{
    Login conn;
    QString date, next_date, height, weight, hip_size, leg_size, waist_size,
            calorie, fat_percentage, water_percentage, muscle_percentage, notes;

    date = ui->tarih_txt->date().toString();
    next_date = ui->sonraki_tarih_txt->dateTime().toString();
    height = ui->boy_txt->cleanText();
    weight = ui->kilo_txt->cleanText();
    hip_size = ui->kalca_txt->cleanText();
    leg_size = ui->bacak_txt->cleanText();
    waist_size = ui->bel_txt->cleanText();
    calorie = ui->kalori_txt->cleanText();
    fat_percentage = ui->yag_oran_txt->cleanText();
    water_percentage = ui->su_oran_txt->cleanText();
    muscle_percentage = ui->kas_oran_txt->cleanText();
    notes = ui->gorusme_notu_txt->toPlainText();

    if(!conn.connOpen())
    {
        qDebug() << "Veritabanına bağlanılamadı.";
        return;
    }

    conn.connOpen();
    QSqlQuery q;

    q.prepare("insert into hasta_detay_tbl (id, hasta_id, tarih, sonraki_randevu_tarihi, boy_cm, kilo_kg, kalca_cm, bacak_cm, bel_cm, kalori, yağ_orani, su_orani, kas_orani, gorusme_notu) values (NULL,'" + hasta_id + "', '" + date + "', '" + next_date + "', '" + height + "', '" + weight + "', '" + hip_size + "', '" + leg_size + "', '" + waist_size + "', '" + calorie + "', '" + fat_percentage + "', '" + water_percentage + "', '" + muscle_percentage + "', '" + notes + "' )");

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
