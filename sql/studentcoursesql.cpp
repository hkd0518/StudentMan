#include "studentcoursesql.h"
#include "utility.h"

#include <QSqlQuery>
#include <QVariant>
#include <QString>
#include <QPixmap>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlDatabase>

studentCourseSql::studentCourseSql(DBInfo dbInfo){

    this->dbInfo = dbInfo;

}

bool studentCourseSql::connectToDB()
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
        QMessageBox::warning(0, QObject::tr("Database"), db.lastError().text()+"studentscoursesql");
        return false;
    }
}

void studentCourseSql::closeConnection()
{
    db.close();
}

int studentCourseSql::getMidScore(QString studentId, QString teacherId, QString courseId){
    QSqlQuery query;
    query.exec("SELECT mid_score FROM student_course WHERE teacher_id = '"+teacherId+"'AND course_id = '"+courseId+"'AND student_id = '"+studentId+"'");
    int minScore = 0;
    if (query.next())
        minScore = query.value(0).toInt();
    return minScore;
}

int studentCourseSql::getFinalScore(QString studentId, QString teacherId, QString courseId){
    QSqlQuery query;
    query.exec("SELECT final_score FROM student_course WHERE teacher_id = '"+teacherId+"'AND course_id = '"+courseId+"'AND student_id = '"+studentId+"'");
    int finalScore = 0;
    if (query.next())
        finalScore = query.value(0).toInt();
    return finalScore;
}

bool studentCourseSql::changeMidScore(int midScore, QString studentId, QString teacherId, QString courseId){
    QSqlQuery query;
    QString temp = QString::number(midScore);
    return query.exec("UPDATE student_course SET mid_score ="+ temp +"WHERE teacher_id = '"+teacherId+"'AND course_id = '"+courseId+"'AND student_id = '"+studentId+"'");
}

bool studentCourseSql::changeFinalScore(int finalScore, QString studentId, QString teacherId, QString courseId){
    QSqlQuery query;
    QString temp = QString::number(finalScore);
    return query.exec("UPDATE student_course SET final_score ="+ temp +"WHERE teacher_id = '"+teacherId+"'AND course_id = '"+courseId+"'AND student_id = '"+studentId+"'");
}

bool studentCourseSql::addStudentCourse(QString studentId, QString teacherId, QString courseId){
    QSqlQuery query;
    return query.exec("INSERT INTO student_course(student_id,teacher_id,course_id) VALUES('"+studentId+"','"+teacherId+"','"+courseId+"')");
}

bool studentCourseSql::delStudentCourse(QString studentId, QString teacherId, QString courseId){
    QSqlQuery query;
    return query.exec("DELETE FROM student_course WHERE teacher_id = '"+teacherId+"'AND course_id = '"+courseId+"'AND student_id = '"+studentId+"'");
}




int studentCourseSql::getTableNum(QString studentId){
    QSqlQuery query;
    query.exec("SELECT count(*)FROM student_course WHERE student_id ='"+studentId+"'");
    int num=0;
    if (query.next())
        num = query.value(0).toInt();
    return num;
}

QString studentCourseSql::getTeacherIdFromTable(int num, QString studentId){
    QSqlQuery query;
    query.exec("SELECT teacher_id FROM student_course WHERE student_id ='"+studentId+"'");
    QString s= "";
    for (int i=0;i<num && query.next();i++);
       s =query.value(0).toString();
    return s;
}

QString studentCourseSql::getCourseIdFromTable(int num, QString studentId){
    QSqlQuery query;
    query.exec("SELECT course_id FROM student_course WHERE student_id ='"+studentId+"'");
    QString s= "";
    for (int i=0;i<num && query.next();i++);
       s =query.value(0).toString();
    return s;
}

int studentCourseSql::getMidScoreFromTable(int num, QString studentId){
    QSqlQuery query;
    query.exec("SELECT mid_score FROM student_course WHERE student_id ='"+studentId+"'");
    int temp= 0;
    for (int i=0;i<num && query.next();i++);
       temp= query.value(0).toInt();
    return temp;
}

int studentCourseSql::getFinalScoreFromTable(int num, QString studentId){
    QSqlQuery query;
    query.exec("SELECT final_score FROM student_course WHERE student_id ='"+studentId+"'");
    int temp= 0;
    for (int i=0;i<num && query.next();i++);
       temp= query.value(0).toInt();
    return temp;
}

int studentCourseSql::getAvailCourseNum(QString studentId){
    QSqlQuery query;
    query.exec("SELECT count(*) FROM teacher_course WHERE course_id NOT IN (SELECT course_id FROM student_course WHERE student_id ='"+studentId+"')");
    int num=0;
    if (query.next())
        num = query.value(0).toInt();
    return num;
}

QString studentCourseSql::getAvailCourseId(int num, QString studentId){
    QSqlQuery query;
    query.exec("SELECT course_id FROM teacher_course WHERE course_id NOT IN (SELECT course_id FROM student_course WHERE student_id ='"+studentId+"')");
    QString s= "";
    for (int i=0;i<num && query.next();i++);
       s =query.value(0).toString();
    return s;
}

QString studentCourseSql::getAvailTeacherId(int num, QString studentId){
    QSqlQuery query;
    query.exec("SELECT teacher_id FROM teacher_course WHERE course_id NOT IN (SELECT course_id FROM student_course WHERE student_id ='"+studentId+"')");
    QString s= "";
    for (int i=0;i<num && query.next();i++);
       s =query.value(0).toString();
    return s;
}

int studentCourseSql::getTeachingStudentNum(QString teacherId, QString courseId){
    QSqlQuery query;
    query.exec("SELECT count(*) FROM student_course WHERE teacher_id = '"+teacherId+"'AND course_id = '"+courseId+"'");
    int num=0;
    if (query.next())
        num = query.value(0).toInt();
    return num;
}

QString studentCourseSql::getTeachingStudentId(int num, QString teacherId, QString courseId){
    QSqlQuery query;
    query.exec("SELECT student_id FROM student_course WHERE teacher_id = '"+teacherId+"'AND course_id = '"+courseId+"'");
    QString s= "";
    for (int i=0;i<num && query.next();i++);
       s =query.value(0).toString();
    return s;
}
