#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QStringList>
#include <QList>
#include <QStandardItem>

#include "teacher.h"
#include "infowidget.h"
#include "utility.h"

Teacher::Teacher(DBInfo dbInfo)
{
    initInfo();
    createList();
}

Teacher::~Teacher()
{

}

void Teacher::initInfo()
{
    userInfo.name = "Mr. Hu";
    userInfo.number = "T12345678";
    userInfo.role = "Teacher";
    userInfo.portrait.load(":/resources/icon/teacher.png");
}

void Teacher::createList()
{
    featureList = new QTreeWidget();

    QTreeWidgetItem *studyItem = new QTreeWidgetItem(featureList, QStringList(QObject::tr("Study")));
    QTreeWidgetItem *profileItem = new QTreeWidgetItem(featureList, QStringList(QObject::tr("Profile")));

    featureList->addTopLevelItem(studyItem);
    featureList->addTopLevelItem(profileItem);

    QTreeWidgetItem *item1 = new QTreeWidgetItem(studyItem, QStringList(QObject::tr("View Class Schedule")));
    QTreeWidgetItem *item2 = new QTreeWidgetItem(studyItem, QStringList(QObject::tr("Record Scores")));
    QTreeWidgetItem *item3 = new QTreeWidgetItem(studyItem, QStringList(QObject::tr("Scores Statics")));

    studyItem->addChild(item1);
    studyItem->addChild(item2);
    studyItem->addChild(item3);

    QTreeWidgetItem *item4 = new QTreeWidgetItem(profileItem, QStringList(QObject::tr("Personal Information")));
    QTreeWidgetItem *item5 = new QTreeWidgetItem(profileItem, QStringList(QObject::tr("Change Password")));

    profileItem->addChild(item4);
    profileItem->addChild(item5);
}

bool Teacher::isExist(QString loginNumber, QString database)
{
    return false;
}

bool Teacher::login(QString loginNumber, QString password, DBInfo dbInfo)
{
    return false;
}

void Teacher::loadCurriculumSchedule(QTableView * tableView)
{
}

void Teacher::loadElective(QTableView * tableView)
{

}

void Teacher::loadInfoWidget(InfoWidget *infoWidget)
{
    //infoWidget->loadUserInfo(new QImage(":/resources/icon/teacher.png"), new QStringList("teacher"));
    infoWidget->loadUserInfo(&userInfo);
    infoWidget->loadFeatureList(featureList);
}

void Teacher::loadProfile(QTableView * tableView)
{

}

QList<QStandardItem*> Teacher::profileHeader()
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

void Teacher::loadScore(QTableView * tableView)
{

}

void Teacher::loadRecord()
{

}

void Teacher::loadStatic()
{

}
