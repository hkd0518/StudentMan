#ifndef USER_H
#define USER_H

#include "utility.h"

#include <QList>

class InfoWidget;
class QString;
class QTableView;
class QStringList;
class QStandardItem;
class QStandardItemModel;

class User
{
public:
    User();
    ~User();
    virtual void initInfo();    //初始化个人信息

    virtual bool isExist(QString loginNumber, QString database);       //判断用户是否存在
    virtual bool login(QString loginNumber, QString password, DBInfo dbInfo);    //登录

    virtual void loadInfoWidget(InfoWidget*);   //包括个人信息和功能列表

    virtual void loadCurriculumSchedule(QTableView*);   //课程表
    virtual QStandardItem*** scheduleDetail();
    virtual bool** scheduleMatrix();

    virtual QList<QStandardItem *> courseList();
    virtual QList<QStandardItem *> courseIdList();
    virtual void savePlanChange(QStandardItem*, QStandardItemModel*);

    virtual QList<QStandardItem *> recordList();
    virtual QList<QStandardItem *> recordIdList();
    virtual void saveRecordChange(QStandardItem*, QStandardItemModel*);

    virtual void loadElective(QTableView*); //选课
    virtual QList< QList<QStandardItem *> > electiveDetail();
    virtual void saveElectiveChange(QStandardItem*, QStandardItemModel*);

    virtual void loadScore(QTableView*);    //成绩查询
    virtual QList< QList<QStandardItem *> > scoreDetail();

    virtual void loadProfile(QTableView*);  //个人信息

    virtual void createList();   //构造功能表

    virtual QList<QStandardItem *> profileHeader();    //个人信息属性列表
    virtual QList<QStandardItem *> profileDetail();

    virtual void chgPwd(QString,QString);

    virtual void saveProfileChange(QStandardItem*);

    UserInfo userInfo;
};

#endif // USER_H
