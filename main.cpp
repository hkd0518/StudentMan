#include <QtGui/QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QStringList>
#include <QDebug>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


//    QSqlDatabase db;
//    db = QSqlDatabase::addDatabase("QODBC");
//    qDebug() << "ODBC driver valid?" << db.isValid();
//    db.setHostName(QString("hu-pc\sqlexpress"));
//    db.setDatabaseName(QString("Handin"));
//    db.setUserName(QString("hkd"));
//    db.setPassword(QString("19900518"));

//    if (db.open())
//        qDebug() << "Database Opened!";
//    else
//        qDebug() << db.lastError().text();

    return a.exec();
}
