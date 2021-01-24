#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

Mainwindow::Mainwindow(QWidget *parent, QString val) :
    QMainWindow(parent),
    ui(new Ui::Mainwindow)
{
    ui->setupUi(this);
    doktor_id = val;
    Login conn;
    if (!conn.connOpen())
    {
        ui->label->setText("Veritabanı bağlantısı başarısız");
    }
    else
    {
        get_table();
        ui->label->setText("Veritabanı bağlantısı başarılı");
    }
}

Mainwindow::~Mainwindow()
{
    delete ui;
}

void Mainwindow::on_yeni_kayit_btn_clicked()
{
    /*Newpatient new_patient;
    new_patient.setModal(true);
    new_patient.exec();*/
    //qDebug() << doktor_id;
    Newpatient *deneme;
    deneme = new Newpatient(this, doktor_id);
    deneme->show();
}

void Mainwindow::on_sil_btn_clicked()
{
    qDebug() << doktor_id;
    Deletepatient *page;
    page = new Deletepatient(this);
    page->show();
}

void Mainwindow::get_table()
{
    Login conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* q = new QSqlQuery(conn.db);
    q->prepare("select h.hasta_id AS 'Hasta İd', h.hasta_adı AS 'Ad', h.hasta_soyadı AS 'Soyad', h.cinsiyet as 'Cinsiyet', h.email AS 'E-Mail', h.tel_no AS 'GSM', h.hasta_yaşı as 'Yaş', h.dogum_tarihi as 'Doğum Tarihi' from hasta_tbl h");
    //q->prepare("select h.hasta_id AS 'Hasta İd', h.hasta_adı AS 'Ad', h.hasta_soyadı AS 'Soyad', h.email AS 'E-Mail', h.tel_no AS 'GSM', u.ad_soyad as 'Diyetisyen' from hasta_tbl h, user_tbl u");
    q->exec();
    modal->setQuery(*q);
    ui->hasta_tbl->resizeColumnsToContents();
    ui->hasta_tbl->setModel(modal);

    conn.close();
}

void Mainwindow::on_hasta_tbl_activated(const QModelIndex &index)
{
    QString val2 = ui->hasta_tbl->selectionModel()->currentIndex().data().toString();
    qDebug() << val2;
    QString val = ui->hasta_tbl->model()->data(index).toString();

    Login conn;
    if(!conn.connOpen())
    {
        qDebug() << "Veritabanına bağlanılamadı.";
        return;
    }

    conn.connOpen();
    QSqlQuery q;
    q.prepare("select * from hasta_tbl where hasta_id='" + val + "'");

    if(q.exec())
    {
        QString hasta_id; // hasta_id ye değer ata
        Patientdetail *detail;
        detail = new Patientdetail(this, val);
        detail->show();
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this, tr("error::"), q.lastError().text());
    }
}



void Mainwindow::on_guncelle_btn_clicked()
{
    get_table();
    QMessageBox::critical(this, tr("Mesaj"), "Tablo Güncellendi");
}
