#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registerwindow.h"
#include "interface.h"
#include <fstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->checkBox, &QCheckBox::stateChanged, [=](int state){
        if (state == Qt::Checked) {
            ui->textEditPassword->setEchoMode(QLineEdit::Normal);
        } else {
            ui->textEditPassword->setEchoMode(QLineEdit::Password);
        }
    });

//    hide();
//    Interface *mailInterface=new Interface;
//    mailInterface->setWindowIcon(QIcon(":Logo.png"));
//    mailInterface->setWindowTitle("ATMail");
//    mailInterface->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_LoginBtn_clicked()
{
    //database = QSqlDatabase::addDatabase("QODBC");
    //database.setDatabaseName("DRIVER={SQL Server};SERVER=2648-ATM-5603N;DATABASE=ProiectQt;UID=minulescu.daniel;PWD=;Trusted_Connection=Yes;");

    //QString username = ui->textEditUserName->text();
    //QString password = ui->textEditPassword->text();

    //if (database.open())
    //{
    //    int check=0;

    //    QMessageBox::information(this,"Autentificare reusita!","Conexiune la baza de date");
    //    QSqlQuery query(QSqlDatabase::database());

    //    query.prepare(QString("SELECT * FROM users WHERE username = :username AND password = :password"));
    //    query.bindValue(":username", username);
    //    query.bindValue(":password", password);

    //    if (!query.exec())
    //    {
    //        QMessageBox::information(this,"Ups!","Ceva nu a mers corect");
    //    }

    //    else
    //    {
    //        while(query.next())
    //        {
    //            QString usernameDB= query.value(1).toString();
    //            QString passwordDB= query.value(2).toString();
    //            QString LastName= query.value(3).toString();
    //            QString FirstName= query.value(4).toString();

    //            if (usernameDB == username && passwordDB == password)
    //            {
    //                //QMessageBox::information(this,"Succes", "Am trecut mai departe");
    //                check=1;
    //                fstream fis("fis.txt",ios::out);
    //                fis<<FirstName.toStdString()<<" "<<LastName.toStdString();
    //                hide();
    //                Interface *mailInterface=new Interface;
    //                mailInterface->setWindowIcon(QIcon(":Logo.png"));
    //                mailInterface->setWindowTitle("ATMail");
    //                mailInterface->show();
    //            }

    //        }
    //    }

    //    if (check==0)
    //    {
    //        QMessageBox::information(this,"Eroare","Email sau parola gresita!");

    //    }

    //}

    //else
    //{
    //     QMessageBox::information(this,"Conexiune esuata!","Baza de date nu este conectata!");

    //}

}


void MainWindow::on_RegisterBtn_clicked()
{
    hide();
    RegisterWindow registerWindow;
    registerWindow.setWindowIcon(QIcon(":Logo.png"));
    registerWindow.setWindowTitle("Register");
    registerWindow.setModal(true);
    registerWindow.exec();

}

