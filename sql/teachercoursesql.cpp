#include "teachercoursesql.h"
#include <QSqlQuery>
#include <QVariant>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>

teacherCourseSql::teacherCourseSql(DBInfo dbInfo){

    this->dbInfo = dbInfo;
}

bool teacherCourseSql::connectToDB()
{

    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName(dbInfo.hostName);
    db.setDatabaseName(dbInfo.DBName);
    db.setUserName(dbInfo.userName);
    db.setPassword(dbInfo.password);

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

void teacherCourseSql::closeConnection()
{
    db.close();
}

QString teacherCourseSql::getCourseAddr(QString teacherId, QString courseId){
    QSqlQuery query;
    query.exec("SELECT addr FROM teacher_course WHERE teacher_id = '"+teacherId+"'AND course_id = '"+courseId+"'");
    QString addr = "";
    if (query.next())
        addr = query.value(0).toString();
    return addr;
}

QString teacherCourseSql::getTimetable(QString teacherId, QString courseId){
    QSqlQuery query;
    query.exec("SELECT ttime FROM teacher_course WHERE teacher_id = '"+teacherId+"'AND course_id = '"+courseId+"'");
    QString ttime = "";
    if (query.next())
        ttime = query.value(0).toString();
    return ttime;
}

int teacherCourseSql::getNum(QString teacherId, QString courseId){
    QSqlQuery query;
    query.exec("SELECT num FROM teacher_course WHERE teacher_id = '"+teacherId+"'AND course_id = '"+courseId+"'");
    int num = 0;
    if (query.next())
        num = query.value(0).toInt();
    return num;
}

bool teacherCourseSql::changeTeacherCourse(QString timetable, QString courseAddr, int courseNum, QString teacherId, QString courseId){
    QSqlQuery query;
    QString temp = QString::number(courseNum);
    if (query.exec("UPDATE teacher_course SET ttime = '"+timetable+"' WHERE teacher_id = '"+teacherId+"'AND course_id = '"+courseId+"'"))
       if (query.exec("UPDATE teacher_course SET addr = '"+courseAddr+"' WHERE teacher_id = '"+teacherId+"'AND course_id = '"+courseId+"'"))
          if (query.exec("UPDATE teacher_course SET num = "+temp+" WHERE teacher_id = '"+teacherId+"'AND course_id = '"+courseId+"'"))
              return true;
    return false;
}

bool teacherCourseSql::addTeacherCourse(QString teacherId, QString courseId){
    QSqlQuery query;
    return query.exec("INSERT INTO teacher_course(teacher_id,course_id) VALUES( '"+teacherId+"' , '"+courseId+"')");
}

bool teacherCourseSql::delTeacherCourse(QString teacherId, QString courseId){
    QSqlQuery query;
    return query.exec("DELETE FROM teacher_course WHERE teacher_id = '"+teacherId+"'AND course_id = '"+courseId+"'");
}



int teacherCourseSql::getTableNum(QString teacherId){
    QSqlQuery query;
    query.exec("SELECT count(*) FROM teacher_course WHERE teacher_id ='"+teacherId+"'");
    int num=0;
    if (query.next())
        num = query.value(0).toInt();
    return num;
}

QString teacherCourseSql::getCourseIdFronTable(int num, QString teacherId){
    QSqlQuery query;
    query.exec("SELECT course_id FROM teacher_course WHERE teacher_id ='"+teacherId+"'");
    QString s= "";
    for (int i=0;i<num && query.next();i++);
       s =query.value(0).toString();
    return s;
}

QString teacherCourseSql::getTimeFromTable(int num, QString teacherId){
    QSqlQuery query;
    query.exec("SELECT ttime FROM teacher_course WHERE teacher_id ='"+teacherId+"'");
    QString s= "";
    for (int i=0;i<num && query.next();i++);
       s =query.value(0).toString();
    return s;
}

QString teacherCourseSql::getAddrFromTable(int num, QString teacherId){
    QSqlQuery query;
    query.exec("SELECT addr FROM teacher_course WHERE teacher_id ='"+teacherId+"'");
    QString s= "";
    for (int i=0;i<num && query.next();i++);
       s =query.value(0).toString();
    return s;
}

int teacherCourseSql::getNumFromTable(int num, QString teacherId){
    QSqlQuery query;
    query.exec("SELECT num FROM teacher_course WHERE teacher_id ='"+teacherId+"'");
    int temp= 0;
    for (int i=0;i<num && query.next();i++);
       temp= query.value(0).toInt();
    return temp;
}

int teacherCourseSql::getAvailCourseNum(QString teacherId){
    QSqlQuery query;
    query.exec("SELECT count(*) FROM course WHERE course_id NOT IN (SELECT course_id FROM teacher_course WHERE teacher_id ='"+teacherId+"')");
    int num=0;
    if (query.next())
        num = query.value(0).toInt();
    return num;
}

QString teacherCourseSql::getAvailCourseId(int num,QString teacherId){
    QSqlQuery query;
    query.exec("SELECT course_id FROM course WHERE course_id NOT IN (SELECT course_id FROM teacher_course WHERE teacher_id ='"+teacherId+"')");
    QString s= "";
    for (int i=0;i<num && query.next();i++);
       s =query.value(0).toString();
    return s;
}
