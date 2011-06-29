#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QList>
#include <QStandardItem>
#include <QMessageBox>

#include "administrator.h"
#include "infowidget.h"
#include "utility.h"

Administrator::Administrator(DBInfo dbInfo)
{
    createList();

    sql = new studentsql(dbInfo);   //初始化实体类指针
    scSql = new studentCourseSql(dbInfo);
    cSql = new coursesql(dbInfo);
    tcSql = new teacherCourseSql(dbInfo);
    tSql = new teachersql(dbInfo);
}

Administrator::~Administrator()
{

}

void Administrator::initInfo()
{
//    userInfo.name = "Mr. X";
//    userInfo.number = "T87654321";
//    userInfo.role = "Administrator";
//    userInfo.portrait.load(":/resources/icon/administrator.png");
    tSql->connectToDB();

    userInfo.name = tSql->getName(userInfo.number);
    userInfo.role = "Administrator";
    userInfo.portrait.load(":/resources/icon/administrator.png");

    tSql->closeConnection();
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
    if (!tSql->connectToDB())
        return false;

    if (password == tSql->getPwd(loginNumber) && 0 != tSql->getLevel(loginNumber))
    {
        userInfo.number = loginNumber;
        initInfo();
        return true;
    }
    else
    {
        QMessageBox::warning(0, QObject::tr("ERROR"), QObject::tr("Wrong Login Infomation!"));
        return false;
    }

    tSql->closeConnection();
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

QList<QStandardItem*> Administrator::profileDetail()
{
    QList<QStandardItem*> list;

    tSql->connectToDB();

    list.append(new QStandardItem(userInfo.number));
    list.append(new QStandardItem(tSql->getName(userInfo.number)));
    list.append(new QStandardItem(tSql->getSex(userInfo.number)));
    list.append(new QStandardItem(tSql->getTitle(userInfo.number)));
    list.append(new QStandardItem(tSql->getNation(userInfo.number)));
    list.append(new QStandardItem(tSql->getProvince(userInfo.number)));
    list.append(new QStandardItem(tSql->getAddr(userInfo.number)));
    list.append(new QStandardItem(tSql->getCollege(userInfo.number)));
    list.append(new QStandardItem(tSql->getEmail(userInfo.number)));
    list.append(new QStandardItem(tSql->getTelephone(userInfo.number)));
    list.append(new QStandardItem(tSql->getRemark(userInfo.number)));

    tSql->closeConnection();

    return list;
}

void Administrator::saveProfileChange(QStandardItem* item)
{
    if (item->column() == 0)
        return;

    tSql->connectToDB();

    switch (item->row())
    {
    case 0:
        break;
    case 1:
        //sql->changeName(item->text(), userInfo.number);
        break;
    case 2:
        tSql->changeSex(item->text(), userInfo.number);
        break;
    case 3:
        tSql->changeTitle(item->text(), userInfo.number);
        break;
    case 4:
        tSql->changeNation(item->text(), userInfo.number);
        break;
    case 5:
        tSql->changeProvince(item->text(), userInfo.number);
        break;
    case 6:
        tSql->changeAddr(item->text(), userInfo.number);
        break;
    case 7:
        tSql->changeCollege(item->text(), userInfo.number);
        break;
    case 8:
        tSql->changeEmail(item->text(), userInfo.number);
        break;
    case 9:
        tSql->changeTelephone(item->text(), userInfo.number);
        break;
    case 10:
        tSql->changeRemark(item->text(), userInfo.number);
        break;
    }

    tSql->closeConnection();
}

void Administrator::loadScore(QTableView * tableView)
{

}


void Administrator::loadPlan()
{

}

void Administrator::chgPwd(QString oldPwd, QString newPwd)
{
    tSql->connectToDB();

    if (tSql->getPwd(userInfo.number) == oldPwd)
    {
        if (tSql->changePwd(newPwd, userInfo.number))
            QMessageBox::information(0, QObject::tr("Change Password"), QObject::tr("Change Password Successfully!"));
        else
            QMessageBox::warning(0, QObject::tr("Change Password"), QObject::tr("Error occurs while changing password!"));
    }
    else
    {
        QMessageBox::warning(0, QObject::tr("Wrong Password"), QObject::tr("Wrong Password!"));
    }

    tSql->closeConnection();
}
