#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "user.h"
#include "utility.h"
#include "sql/studentsql.h"
#include "sql/studentcoursesql.h"
#include "sql/coursesql.h"
#include "sql/teachercoursesql.h"
#include "sql/teachersql.h"
#include <QList>

class QTreeWidget;
class QStringList;

class Administrator : public User
{
public:
    Administrator(DBInfo);
    ~Administrator();

    virtual void initInfo();    //初始化个人信息

    virtual bool isExist(QString loginNumber, QString database);       //判断用户是否存在
    virtual bool login(QString loginNumber, QString password, DBInfo dbInfo);    //登录

    virtual void loadInfoWidget(InfoWidget*);   //包括个人信息和功能列表

    virtual void loadCurriculumSchedule(QTableView*);   //课程表
    virtual void loadElective(QTableView*); //选课
    virtual void loadScore(QTableView*);    //成绩查询

    virtual void loadProfile(QTableView*);  //个人信息
    virtual QList<QStandardItem *> profileHeader();    //个人信息属性列表
    virtual QList<QStandardItem *> profileDetail();
    virtual void saveProfileChange(QStandardItem*);

    virtual void chgPwd(QString,QString);


protected:
    void loadPlan();    //排课
    virtual void createList();

private:
    QTreeWidget *featureList;
    UserInfo userInfo;
    studentsql *sql;
    studentCourseSql *scSql;
    coursesql *cSql;
    teacherCourseSql *tcSql;
    teachersql *tSql;
};

#endif // ADMINISTRATOR_H
