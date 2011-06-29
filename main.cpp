#include <QtGui/QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QStringList>
#include <QDebug>
#include "mainwindow.h"

#include "utility.h"
#include "sql/studentsql.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    DBInfo dbInfo;
//    dbInfo.hostName = "localhost";
//    dbInfo.DBName = "Handin";
//    dbInfo.userName = "hkd";
//    dbInfo.password = "19900518";

//    studentsql sql(dbInfo);
//    sql.connectToDB();
//    sql.closeConnection();


//    QSqlDatabase db;
//    db = QSqlDatabase::addDatabase("QODBC");
//    qDebug() << "ODBC driver valid?" << db.isValid();
//    db.setHostName(QString("localhost"));
//    db.setDatabaseName(QString("Handin"));
//    db.setUserName(QString("hkd"));
//    db.setPassword(QString("19900518"));

//    if (db.open())
//        qDebug() << "Database Opened!";
//    else
//        qDebug() << db.lastError().text();

    return a.exec();
}
