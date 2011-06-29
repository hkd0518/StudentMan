#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QList>
#include <QStandardItem>

#include "administrator.h"
#include "infowidget.h"
#include "utility.h"

Administrator::Administrator(DBInfo dbInfo)
{
    initInfo();
    createList();
}

Administrator::~Administrator()
{

}

void Administrator::initInfo()
{
    userInfo.name = "Mr. X";
    userInfo.number = "T87654321";
    userInfo.role = "Administrator";
    userInfo.portrait.load(":/resources/icon/administrator.png");
}

void Administrator::createList()
{
    featureList = new QTreeWidget();

    QTreeWidgetItem *studyItem = new QTreeWidgetItem(featureList, QStringList(QObject::tr("Study")));
    QTreeWidgetItem *profileItem = new QTreeWidgetItem(featureList, QStringList(QObject::tr("Profile")));

    featureList->addTopLevelItem(studyItem);
    featureList->addTopLevelItem(profileItem);

    QTreeWidgetItem *item1 = new QTreeWidgetItem(studyItem, QStringList(QObject::tr("Plan Class Schedule")));

    studyItem->addChild(item1);

    QTreeWidgetItem *item4 = new QTreeWidgetItem(profileItem, QStringList(QObject::tr("Personal Information")));
    QTreeWidgetItem *item5 = new QTreeWidgetItem(profileItem, QStringList(QObject::tr("Change Password")));

    profileItem->addChild(item4);
    profileItem->addChild(item5);
}



bool Administrator::isExist(QString loginNumber, QString database)
{
    return false;
}

bool Administrator::login(QString loginNumber, QString password, DBInfo dbInfo)
{
    return false;
}

void Administrator::loadCurriculumSchedule(QTableView * tableView)
{
}

void Administrator::loadElective(QTableView * tableView)
{

}

void Administrator::loadInfoWidget(InfoWidget* infoWidget)
{
    //infoWidget->loadUserInfo(new QImage(":/resources/icon/administrator.png"), new QStringList("administrator"));
    infoWidget->loadUserInfo(&userInfo);
    infoWidget->loadFeatureList(featureList);
}

void Administrator::loadProfile(QTableView * tableView)
{

}

QList<QStandardItem*> Administrator::profileHeader()
{
    QList<QStandardItem*> list;

    list.append(new QStandardItem(QObject::tr("ID")));
    list.append(new QStandardItem(QObject::tr("Name")));
    list.append(new QStandardItem(QObject::tr("Sex")));
    list.append(new QStandardItem(QObject::tr("Title")));
    list.append(new QStandardItem(QObject::tr("Nation")));
    list.append(new QStandardItem(QObject::tr("Province")));
    list.append(new QStandardItem(QObject::tr("Address")));
    list.append(new QStandardItem(QObject::tr("College")));
    list.append(new QStandardItem(QObject::tr("Email")));
    list.append(new QStandardItem(QObject::tr("Telephone")));
    list.append(new QStandardItem(QObject::tr("Remark")));

    return list;
}

void Administrator::loadScore(QTableView * tableView)
{

}


void Administrator::loadPlan()
{

}
