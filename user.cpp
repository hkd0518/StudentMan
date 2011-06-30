#include "user.h"
#include "infowidget.h"

User::User()
{
}

User::~User()
{
}

bool User::isExist(QString loginNumber, QString database)
{
    return false;
}

bool User::login(QString loginNumber, QString password, DBInfo dbInfo)
{
    return false;
}

void User::loadCurriculumSchedule(QTableView * tableView)
{
}

QStandardItem*** User::scheduleDetail()
{
}

bool** User::scheduleMatrix()
{

}

void User::loadElective(QTableView * tableView)
{

}

QList< QList<QStandardItem *> > User::electiveDetail()
{

}

void User::saveElectiveChange(QStandardItem* item , QStandardItemModel *model)
{

}

void User::loadInfoWidget(InfoWidget * infoWidget)
{

}

void User::loadProfile(QTableView * tableView)
{

}

QList<QStandardItem*> User::profileHeader()
{

}

QList<QStandardItem*> User::profileDetail()
{

}

QList<QStandardItem *> User::courseList()
{

}

QList<QStandardItem *> User::courseIdList()
{

}

void User::savePlanChange(QStandardItem*, QStandardItemModel*)
{

}

void User::saveProfileChange(QStandardItem *item)
{

}

void User::loadScore(QTableView * tableView)
{

}

QList< QList<QStandardItem *> > User::scoreDetail()
{

}

void User::createList()
{

}

void User::initInfo()
{

}

void User::chgPwd(QString oldPwd, QString newPwd)
{

}
