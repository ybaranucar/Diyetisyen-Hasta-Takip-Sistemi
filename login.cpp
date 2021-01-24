#include "login.h"
#include "ui_login.h"
#include <QMessageBox>


Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    if (!connOpen())
    {
        QMessageBox::critical(this, tr("Uyarı"), tr("Veritabanı bağlantısı başarısız."));
    }
}

Login::~Login()
{
    delete ui;
}

bool Login::connOpen()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./Diyetisyen/db_diyetisyen.db");

    if (!db.open())
    {
        qDebug()<<"Veritabanı bağlantısı başarısız";
        return false;
    }
    else
    {
        qDebug()<<"Veritabanı bağlantısı başarılı";
        return true;
    }
}

void Login::connClose()
{
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
}

void Login::on_login_btn_clicked()
{
    QString username = ui->username_text->text();
    QString password = ui->password_text->text();

    if(!connOpen())
    {
        qDebug() << "Veritabanına bağlanılamadı.";
        return;
    }

    connOpen();
    QSqlQuery q;
    q.prepare("select * from user_tbl where username='"+ username + "' and password='" + password + "'");
    QString doktor_id;
    if(q.exec())
    {
        int count=0;
        while (q.next())
        {
            count++;
            doktor_id = q.value(0).toString();
        }
        if (count==1)
        {
            connClose();
            this->hide();
            //this->close();
            Mainwindow *main_page;
            main_page = new Mainwindow(this, doktor_id);
            //deneme->setModal(true);
            main_page->show();
            /*Mainwindow main_window;
            main_window.show();
            main_window.setModal(true);
            main_window.exec();*/
        }
        if (count<1)
        {
            QMessageBox::critical(this, tr("Giriş Yapılamadı"), tr("Kullanıcı adı ve şifrenizi kontrol ederek tekrar deneyiniz."));
        }
    }
}
