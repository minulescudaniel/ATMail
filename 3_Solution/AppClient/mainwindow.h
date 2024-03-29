#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QtSql>
//#include <QSql>
//#include <QSqlQuery>
//#include <QSqlDatabase>
#include <qmessagebox.h>
#include "app_credentials.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_LoginBtn_clicked();

    void on_RegisterBtn_clicked();

    void loadNextInterface();

private:
    Ui::MainWindow *ui;
    app::credentials credentials;
    //QSqlDatabase database;
};
#endif // MAINWINDOW_H
