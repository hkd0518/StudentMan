#include "teachersql.h"
#include <QSqlQuery>
#include <QVariant>
#include <QString>
#include <QPixmap>


teachersql::teachersql(){

}

QString teachersql::getAddr(QString id){
    QSqlQuery query;
    query.exec("SELECT addr FROM teacher WHERE teacher_id = '"+id+"'");
    QString addr = "";
    if (query.next())
        addr = query.value(0).toString();
    return addr;
}

bool teachersql::changeAddr(QString addr, QString id){
    QSqlQuery query;
    return query.exec("UPDATE teacher SET addr = '"+addr+"' WHERE teacher_id = '"+id+"'");
}

QString teachersql::getCollege(QString id){
    QSqlQuery query;
    query.exec("SELECT college FROM teacher WHERE teacher_id = '"+id+"'");
    QString college = "";
    if (query.next())
        college = query.value(0).toString();
    return college;
}

bool teachersql::changeCollege(QString college, QString id){
    QSqlQuery query;
    return query.exec("UPDATE teacher SET college = '"+college+"' WHERE teacher_id = '"+id+"'");
}

QString teachersql::getEmail(QString id){
    QSqlQuery query;
    query.exec("SELECT email FROM teacher WHERE teacher_id = '"+id+"'");
    QString email = "";
    if (query.next())
        email = query.value(0).toString();
    return email;
}

bool teachersql::changeEmail(QString email, QString id){
    QSqlQuery query;
    return query.exec("UPDATE teacher SET email = '"+email+"' WHERE teacher_id = '"+id+"'");
}

int teachersql::getLevel(QString id){
    QSqlQuery query;
    query.exec("SELECT teacher_level FROM teacher WHERE teacher_id = '"+id+"'");
    int level = 0;
    if (query.next())
        level = query.value(0).toInt();
    return level;
}

bool teachersql::changeLevel(int level, QString id){
    QSqlQuery query;
    QString s=QString::number(level);
    return query.exec("UPDATE teacher SET teacher_level = "+ s +" WHERE teacher_id = '"+id+"'");
}

QString teachersql::getName(QString id){
    QSqlQuery query;
    query.exec("SELECT teacher_name FROM teacher WHERE teacher_id = '"+id+"'");
    QString name = "";
    if (query.next())
        name = query.value(0).toString();
    return name;
}

bool teachersql::changeName(QString name, QString id){
    QSqlQuery query;
    return query.exec("UPDATE teacher SET teacher_name = '"+name+"' WHERE teacher_id = '"+id+"'");
}

QString teachersql::getNation(QString id){
    QSqlQuery query;
    query.exec("SELECT nation FROM teacher WHERE teacher_id = '"+id+"'");
    QString nation = "";
    if (query.next())
        nation = query.value(0).toString();
    return nation;
}

bool teachersql::changeNation(QString nation, QString id){
    QSqlQuery query;
    return query.exec("UPDATE teacher SET nation = '"+nation+"' WHERE teacher_id = '"+id+"'");
}

QString teachersql::getProvince(QString id){
    QSqlQuery query;
    query.exec("SELECT province FROM teacher WHERE teacher_id = '"+id+"'");
    QString province = "";
    if (query.next())
        province = query.value(0).toString();
    return province;
}

bool teachersql::changeProvince(QString province, QString id){
    QSqlQuery query;
    return query.exec("UPDATE teacher SET province = '"+province+"' WHERE teacher_id = '"+id+"'");
}

QString teachersql::getPwd(QString id){
    QSqlQuery query;
    query.exec("SELECT pwd FROM teacher WHERE teacher_id = '"+id+"'");
    QString pwd = "";
    if (query.next())
        pwd = query.value(0).toString();
    return pwd;
}

bool teachersql::changePwd(QString pwd, QString id){
    QSqlQuery query;
    return query.exec("UPDATE teacher SET pwd = '"+pwd+"' WHERE teacher_id = '"+id+"'");
}

QString teachersql::getRemark(QString id){
    QSqlQuery query;
    query.exec("SELECT remark FROM teacher WHERE teacher_id = '"+id+"'");
    QString remark = "";
    if (query.next())
        remark = query.value(0).toString();
    return remark;
}

bool teachersql::changeRemark(QString remark, QString id){
    QSqlQuery query;
    return query.exec("UPDATE teacher SET remark = '"+remark+"' WHERE teacher_id = '"+id+"'");
}

QString teachersql::getSex(QString id){
    QSqlQuery query;
    query.exec("SELECT sex FROM teacher WHERE teacher_id = '"+id+"'");
    QString sex = "";
    if (query.next())
        sex = query.value(0).toString();
    return sex;
}

bool teachersql::changeSex(QString sex, QString id){
    QSqlQuery query;
    return query.exec("UPDATE teacher SET sex = '"+sex+"' WHERE teacher_id = '"+id+"'");
}

QString teachersql::getTelephone(QString id){
    QSqlQuery query;
    query.exec("SELECT telephone FROM teacher WHERE teacher_id = '"+id+"'");
    QString tel = "";
    if (query.next())
        tel = query.value(0).toString();
    return tel;
}

bool teachersql::changeTelephone(QString tel, QString id){
    QSqlQuery query;
    return query.exec("UPDATE teacher SET telephone = '"+tel+"' WHERE teacher_id = '"+id+"'");
}

QString teachersql::getTitle(QString id){
    QSqlQuery query;
    query.exec("SELECT title FROM teacher WHERE teacher_id = '"+id+"'");
    QString title = "";
    if (query.next())
        title = query.value(0).toString();
    return title;
}

bool teachersql::changeTitle(QString title, QString id){
    QSqlQuery query;
    return query.exec("UPDATE teacher SET title = '"+title+"' WHERE teacher_id = '"+id+"'");
}

bool teachersql::addTeacher(QString id, QString pwd, QString name){
    QSqlQuery query;
    return query.exec("INSERT INTO teacher(teacher_id , pwd, teacher_name) VALUES ('"+id +"' , '"+ pwd+"' , '"+name+"')");
}

bool teachersql::delTeacher(QString id){
    QSqlQuery query;
    return query.exec("DELETE FROM teacher WHERE teacher_id = '"+id+"'");
}

QString teachersql::getPicture(QString id){
    QSqlQuery query;
    query.exec("SELECT picture FROM teacher WHERE teacher_id = '"+id+"'");
    QString photo="";
    if (query.next())
        photo =query.value(0).toString();
    return photo;
}

bool teachersql::changePicture(QString photolink, QString id){
    QSqlQuery query;
    return query.exec("UPDATE teacher SET picture = '"+photolink+"' WHERE teacher_id ='"+id+"'");
}


int teachersql::getTeacherNum(){
    QSqlQuery query;
    query.exec("SELECT count(*) FROM teacher");
    int num=0;
    if (query.next())
        num = query.value(0).toInt();
    return num;
}

QString teachersql::getIdFromNum(int num){
    QSqlQuery query;
    query.exec("SELECT teacher_id FROM teacher order by teacher_id");
    QString s= "";
    for (int i=0;i<num && query.next();i++);
       s =query.value(0).toString();
    return s;
}
