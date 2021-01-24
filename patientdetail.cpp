#include "patientdetail.h"
#include "ui_patientdetail.h"
#include <QMessageBox>

Patientdetail::Patientdetail(QWidget *parent, QString val) :
    QDialog(parent),
    ui(new Ui::Patientdetail)
{
    ui->setupUi(this);
    hasta_id = val;
    get_table();
}

Patientdetail::~Patientdetail()
{
    delete ui;
}

void Patientdetail::get_table()
{
    Login conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* q = new QSqlQuery(conn.db);
    q->prepare("select * from hasta_detay_tbl where hasta_id='" + hasta_id + "'");
    //q->prepare("select h.hasta_id AS 'Hasta İd', h.hasta_adı AS 'Ad', h.hasta_soyadı AS 'Soyad', h.email AS 'E-Mail', h.tel_no AS 'GSM', u.ad_soyad as 'Diyetisyen' from hasta_tbl h, user_tbl u");
    q->exec();
    modal->setQuery(*q);
    ui->hasta_detay_tbl->resizeColumnsToContents();
    ui->hasta_detay_tbl->setModel(modal);

    conn.close();
}


void Patientdetail::on_yeni_kayit_btn_clicked()
{
    Newpatientdetail *deneme;
    deneme = new Newpatientdetail(this, hasta_id);
    deneme->show();
}

void Patientdetail::on_pushButton_clicked()
{
    get_table();
    QMessageBox::critical(this, tr("Mesaj"), "Tablo Güncellendi");
}
