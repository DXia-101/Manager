#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>

int main(int argc, char *argv[])
{
    //链接数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("Mysql");
    db.setUserName("root");
    db.setPassword("k916025328");
    bool ok = db.open();
    if (ok){
        qDebug()<<"sql open success";
    }
    else {
        qDebug()<<"error open database because"<<db.lastError().text();
    }
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
