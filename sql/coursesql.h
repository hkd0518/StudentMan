#ifndef COURSESQL_H
#define COURSESQL_H

#include "utility.h"
#include <QSqlDatabase>

class QString;
class coursesql
{
public:
    coursesql(DBInfo);
    QString getId(QString name);
   // bool changeId(QString,QString);    
    QString getName(QString id);
    bool changeName(QString name,QString id);
    QString getRemark(QString id);
    bool changeRemark(QString remark,QString id);
    bool addCourse(QString id,QString name,QString remark);
    bool delCourse(QString id);


    int getCourseNum();
    QString getIdFromNum(int num);
    QString getNameFromNum(int num);
    QString getRemarkFromNum(int num);

    bool connectToDB();
    void closeConnection();
private:
    DBInfo dbInfo;
    QSqlDatabase db;

};

#endif // COURSESQL_H
