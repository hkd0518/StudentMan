#ifndef COURSESQL_H
#define COURSESQL_H
class QString;
class coursesql
{
public:
    coursesql();
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

};

#endif // COURSESQL_H
