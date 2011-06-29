#ifndef STUDENTSQL_H
#define STUDENTSQL_H

#include "utility.h"
#include <QSqlDatabase>

class QString;
class QPixmap;

class studentsql
{
public:    
    studentsql(DBInfo);

    QString getPwd(QString id);
    bool changePwd(QString pwd,QString id);
    //QString getId();
    //bool changeId();
    QString getName(QString id);
    bool changeName(QString name,QString id);
    QString getSex(QString id);
    bool changeSex(QString sex,QString id);
    QString getNation(QString id);
    bool changeNation(QString nation,QString id);
    QString getProvince(QString id);
    bool changeProvince(QString province,QString id);
    QString getAddr(QString id);
    bool changeAddr(QString addr,QString id);

    QString getPicture(QString id);
    bool changePicture(QString photolink,QString id);

    QString getCollege(QString id);
    bool changeCollege(QString college,QString id);
    QString getSeries(QString id);
    bool changeSeries(QString series,QString id);
    QString getProfession(QString id);
    bool changeProfession(QString pro,QString id);

    QString getEnterTime(QString id);
    bool changeEnterTime(QString pro,QString id);

    QString getClass(QString id);
    bool changeClass(QString cla,QString id);
    QString getEmail(QString id);
    bool changeEmail(QString email,QString id);
    QString getTelephone(QString id);
    bool changeTelephone(QString tel,QString id);
    QString getRemark(QString id);
    bool changeRemark(QString remark,QString id);

    bool addStudent(QString id,QString pwd,QString name);
    bool delStudent(QString id);


    int getStudentNum();
    QString getIdFromNum(int num);


    bool connectToDB();
    void closeConnection();
private:
    DBInfo dbInfo;
    QSqlDatabase db;
};

#endif // STUDENTSQL_H
