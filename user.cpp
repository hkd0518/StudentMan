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

void User::loadElective(QTableView * tableView)
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

void User::saveProfileChange(QStandardItem *item)
{

}

void User::loadScore(QTableView * tableView)
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
