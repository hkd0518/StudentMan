#include "coursesql.h"
#include <QSqlQuery>
#include <QVariant>
#include <QString>
#include <qDebug>

coursesql::coursesql(){

}

QString coursesql::getId(QString name){
    QSqlQuery query;
    query.exec("SELECT course_id FROM course WHERE course_name='"+name+"'");
    QString id="";
    if (query.next())
        id = query.value(0).toString();
    return id;
}

QString coursesql::getName(QString id){
    QSqlQuery query;
    query.exec("SELECT course_name FROM course WHERE course_id='"+id+"'");
    QString name="";
    if (query.next())
        name = query.value(0).toString();
    return name;
}

bool coursesql::changeName(QString name,QString id){
    QSqlQuery query;
    return query.exec("UPDATE course SET course_name = '" + name +"' WHERE course_id = '"+id+"'");
}

QString coursesql::getRemark(QString id){
    QSqlQuery query;
    query.exec("SELECT remark FROM course WHERE course_id='"+id+"'");
    QString remark="";
    if (query.next())
        remark = query.value(0).toString();
    return remark;
}

bool coursesql::changeRemark(QString remark,QString id){
    QSqlQuery query;    
    return query.exec("UPDATE course SET remark = '" + remark +"' WHERE course_id = '"+id+"'");
}

bool coursesql::addCourse(QString id,QString name,QString remark){
    QSqlQuery query;
    return query.exec("INSERT INTO course(course_id,course_name,remark) VALUES ('"+id+"','"+name+"','"+remark+"')");
}

bool coursesql::delCourse(QString id){
    QSqlQuery query;
    return query.exec("DELETE FROM course WHERE course_id = '"+id+"'");
}

int coursesql::getCourseNum(){
    QSqlQuery query;
    query.exec("SELECT count(*) FROM course");
    int num=0;
    if (query.next())
        num = query.value(0).toInt();
    return num;
}

QString coursesql::getIdFromNum(int num){
    QSqlQuery query;
    query.exec("SELECT course_id FROM course order by course_name");
    QString s= "";
    for (int i=0;i<num && query.next();i++);
       s =query.value(0).toString();
    return s;
}

QString coursesql::getNameFromNum(int num){
    QSqlQuery query;
    query.exec("SELECT course_name FROM course order by course_name");
    QString s= "";
    for (int i=0;i<num && query.next();i++);
       s =query.value(0).toString();
    return s;
}

QString coursesql::getRemarkFromNum(int num){
    QSqlQuery query;
    query.exec("SELECT remark FROM course order by course_name");
    QString s= "";
    for (int i=0;i<num && query.next();i++);
       s =query.value(0).toString();
    return s;
}
