
#include "studentsql.h"
#include "utility.h"

#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QString>
#include <QPixmap>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlDatabase>

studentsql::studentsql(DBInfo dbInfo){

    this->dbInfo = dbInfo;
}

bool studentsql::connectToDB()
{

    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName(dbInfo.hostName);
    db.setDatabaseName(dbInfo.DBName);
    db.setUserName(dbInfo.userName);
    db.setPassword(dbInfo.password);
//    qDebug() << "ODBC driver valid?" << db.isValid();

//        qDebug() << db.hostName();
//        qDebug() << db.databaseName();
//        qDebug() << db.userName();
//        qDebug() << db.password();
//        qDebug() << db.driverName();

    if (db.open())
    {
        qDebug() << "Connect to DB Successfully!";
        return true;
    }
    else
    {
        QMessageBox::warning(0, QObject::tr("Database"), db.lastError().text()+" studentsql");
        return false;
    }
}

void studentsql::closeConnection()
{
    db.close();
}

QString studentsql::getAddr(QString id){
    QSqlQuery query;
    query.exec("SELECT addr FROM student WHERE student_id = '"+id+"'");
    QString addr = "";
    if (query.next())
        addr = query.value(0).toString();
    return addr;
}

bool studentsql::changeAddr(QString addr, QString id){
    QSqlQuery query;
    return query.exec("UPDATE student SET addr = '"+addr+"' WHERE student_id = '"+id+"'");
}

QString studentsql::getClass(QString id){
    QSqlQuery query;
    query.exec("SELECT class FROM student WHERE student_id = '"+id+"'");
    QString cla = "";
    if (query.next())
        cla = query.value(0).toString();
    return cla;
}

bool studentsql::changeClass(QString cla, QString id){
    QSqlQuery query;
    return query.exec("UPDATE student SET class = '"+cla+"' WHERE student_id = '"+id+"'");
}

QString studentsql::getCollege(QString id){
    QSqlQuery query;
    query.exec("SELECT college FROM student WHERE student_id = '"+id+"'");
    QString college = "";
    if (query.next())
        college = query.value(0).toString();
    return college;
}

bool studentsql::changeCollege(QString college, QString id){
    QSqlQuery query;
    return query.exec("UPDATE student SET college = '"+college+"' WHERE student_id = '"+id+"'");
}

QString studentsql::getEmail(QString id){
    QSqlQuery query;
    query.exec("SELECT email FROM student WHERE student_id = '"+id+"'");
    QString email = "";
    if (query.next())
        email = query.value(0).toString();
    return email;
}

bool studentsql::changeEmail(QString email, QString id){
    QSqlQuery query;
    return query.exec("UPDATE student SET email = '"+email+"' WHERE student_id = '"+id+"'");
}

QString studentsql::getName(QString id){
    QSqlQuery query;
    query.exec("SELECT student_name FROM student WHERE student_id = '"+id+"'");
    QString name="";
    if (query.next())
        name = query.value(0).toString();
    return name;
}

bool studentsql::changeName(QString name, QString id){
    QSqlQuery query;
    return query.exec("UPDATE student SET student_name = '"+name+"' WHERE student_id = '"+id+"'");
}

QString studentsql::getNation(QString id){
    QSqlQuery query;
    query.exec("SELECT nation FROM student WHERE student_id = '"+id+"'");
    QString nation="";
    if (query.next())
        nation = query.value(0).toString();
    return nation;
}

bool studentsql::changeNation(QString nation, QString id){
    QSqlQuery query;
    return query.exec("UPDATE student SET nation = '"+nation+"' WHERE student_id = '"+id+"'");
}

QString studentsql::getProfession(QString id){
    QSqlQuery query;
    query.exec("SELECT profession FROM student WHERE student_id = '"+id+"'");
    QString pro="";
    if (query.next())
        pro = query.value(0).toString();
    return pro;
}

bool studentsql::changeProfession(QString pro, QString id){
    QSqlQuery query;
    return query.exec("UPDATE student SET profession = '"+pro+"' WHERE student_id = '"+id+"'");
}

QString studentsql::getProvince(QString id){
    QSqlQuery query;
    query.exec("SELECT province FROM student WHERE student_id = '"+id+"'");
    QString province="";
    if (query.next())
        province = query.value(0).toString();
    return province;
}

bool studentsql::changeProvince(QString province, QString id){
    QSqlQuery query;
    return query.exec("UPDATE student SET province = '"+province+"' WHERE student_id = '"+id+"'");
}

QString studentsql::getRemark(QString id){
    QSqlQuery query;
    query.exec("SELECT remark FROM student WHERE student_id = '"+id+"'");
    QString remark="";
    if (query.next())
        remark = query.value(0).toString();
    return remark;
}

bool studentsql::changeRemark(QString remark, QString id){
    QSqlQuery query;
    return query.exec("UPDATE student SET remark = '"+remark+"' WHERE student_id = '"+id+"'");
}

QString studentsql::getSeries(QString id){
    QSqlQuery query;
    query.exec("SELECT series FROM student WHERE student_id = '"+id+"'");
    QString series="";
    if (query.next())
        series = query.value(0).toString();
    return series;
}

bool studentsql::changeSeries(QString series, QString id){
    QSqlQuery query;
    return query.exec("UPDATE student SET series = '"+series+"' WHERE student_id = '"+id+"'");
}

QString studentsql::getSex(QString id){
    QSqlQuery query;
    query.exec("SELECT sex FROM student WHERE student_id = '"+id+"'");
    QString sex="";
    if (query.next())
        sex = query.value(0).toString();
    return sex;
}

bool studentsql::changeSex(QString sex, QString id){
    QSqlQuery query;
    return query.exec("UPDATE student SET sex = '"+sex+"' WHERE student_id = '"+id+"'");
}

QString studentsql::getTelephone(QString id){
    QSqlQuery query;
    query.exec("SELECT telephone FROM student WHERE student_id = '"+id+"'");
    QString tel="";
    if (query.next())
        tel = query.value(0).toString();
    return tel;
}

bool studentsql::changeTelephone(QString tel, QString id){
    QSqlQuery query;
    return query.exec("UPDATE student SET telephone = '"+tel+"' WHERE student_id = '"+id+"'");
}

QString studentsql::getPwd(QString id){
    QSqlQuery query;
    query.exec("SELECT pwd FROM student WHERE student_id = '"+id+"'");
    QString pwd="";
    if (query.next())
        pwd = query.value(0).toString();
    return pwd;
}

bool studentsql::changePwd(QString pwd, QString id){
    QSqlQuery query;
    return query.exec("UPDATE student SET pwd = '"+pwd+"' WHERE student_id = '"+id+"'");
}

bool studentsql::addStudent(QString id, QString pwd, QString name){
    QSqlQuery query;
    return query.exec("INSERT INTO student(student_id, pwd, student_name) VALUES ('"+id +"' , '"+ pwd +"' , '"+ name+"')");
}

bool studentsql::delStudent(QString id){
    QSqlQuery query;
    return query.exec("DELETE FROM student WHERE student_id = '"+id+"'");
}

QString studentsql::getEnterTime(QString id){
    QSqlQuery query;
    query.exec("SELECT enter_time FROM student WHERE student_id = '"+id+"'");
    QString time="";
    if (query.next())
        time = query.value(0).toString();
    return time;
}

bool studentsql::changeEnterTime(QString time, QString id){
    QSqlQuery query;
    return query.exec("UPDATE student SET enter_time = '"+time+"' WHERE student_id = '"+id+"'");
}

QString studentsql::getPicture(QString id){
    QSqlQuery query;
    query.exec("SELECT picture FROM student WHERE student_id = '"+id+"'");
    QString photo;
    if (query.next())
        photo =query.value(0).toString();
    return photo;
}

bool studentsql::changePicture(QString photolink, QString id){
    QSqlQuery query;
    return query.exec("UPDATE student SET picture = '"+photolink+"' WHERE student_id ='"+id+"'");
}

int studentsql::getStudentNum(){
    QSqlQuery query;
    query.exec("SELECT count(*) FROM student");
    int num=0;
    if (query.next())
        num = query.value(0).toInt();
    return num;
}

QString studentsql::getIdFromNum(int num){
    QSqlQuery query;
    query.exec("SELECT student_id FROM student order by student_id");
    QString s= "";
    for (int i=0;i<num && query.next();i++);
       s = query.value(0).toString();
    return s;
}
