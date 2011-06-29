#include <QObject>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QStringList>
#include <QTableView>
#include <QHeaderView>
#include <QList>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QDebug>

#include "student.h"
#include "infowidget.h"
#include "utility.h"

Student::Student(DBInfo dbInfo)
{
    createList();

    sql = new studentsql(dbInfo);   //初始化实体类指针
    scSql = new studentCourseSql(dbInfo);
    cSql = new coursesql(dbInfo);
}

Student::~Student()
{
    delete featureList;
}

void Student::initInfo()
{
//    userInfo.name = "Titi";
//    userInfo.number = "08382000";
//    userInfo.role = "Student";
//    userInfo.portrait.load(":/resources/icon/student.png");
    sql->connectToDB();

    userInfo.name = sql->getName(userInfo.number);
    userInfo.role = "Student";
    userInfo.portrait.load(":/resources/icon/student.png");

    sql->closeConnection();
}

void Student::createList()
{
    featureList = new QTreeWidget();

    QTreeWidgetItem *studyItem = new QTreeWidgetItem(featureList, QStringList(QObject::tr("Study")));
    QTreeWidgetItem *profileItem = new QTreeWidgetItem(featureList, QStringList(QObject::tr("Profile")));

    featureList->addTopLevelItem(studyItem);
    featureList->addTopLevelItem(profileItem);

    QTreeWidgetItem *item1 = new QTreeWidgetItem(studyItem, QStringList(QObject::tr("Elective")));
    QTreeWidgetItem *item2 = new QTreeWidgetItem(studyItem, QStringList(QObject::tr("View Class Schedule")));
    QTreeWidgetItem *item3 = new QTreeWidgetItem(studyItem, QStringList(QObject::tr("View Results")));

    studyItem->addChild(item1);
    studyItem->addChild(item2);
    studyItem->addChild(item3);

    QTreeWidgetItem *item4 = new QTreeWidgetItem(profileItem, QStringList(QObject::tr("Personal Information")));
    QTreeWidgetItem *item5 = new QTreeWidgetItem(profileItem, QStringList(QObject::tr("Change Password")));

    profileItem->addChild(item4);
    profileItem->addChild(item5);
}



bool Student::isExist(QString loginNumber, QString database)
{

    return false;
}

bool Student::login(QString loginNumber, QString password, DBInfo dbInfo)
{

    if (!sql->connectToDB())
        return false;

    if (password == sql->getPwd(loginNumber))
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

    sql->closeConnection();
}

void Student::loadCurriculumSchedule(QTableView * tableView)
{
}

void Student::loadElective(QTableView * tableView)
{

}

void Student::loadInfoWidget(InfoWidget* infoWidget)
{

    //infoWidget->loadUserInfo(new QImage(":/resources/icon/student.png"), new QStringList("student"));
    infoWidget->loadUserInfo(&userInfo);
    infoWidget->loadFeatureList(featureList);
}

void Student::loadProfile(QTableView * tableView)
{
//无用，待删
}

QList<QStandardItem *> Student::profileHeader()
{
    QList<QStandardItem*> list;

    list.append(new QStandardItem(QObject::tr("ID")));
    list.append(new QStandardItem(QObject::tr("Name")));
    list.append(new QStandardItem(QObject::tr("Sex")));
    list.append(new QStandardItem(QObject::tr("Nation")));
    list.append(new QStandardItem(QObject::tr("Province")));
    list.append(new QStandardItem(QObject::tr("Address")));
    list.append(new QStandardItem(QObject::tr("College")));
    list.append(new QStandardItem(QObject::tr("Series")));
    list.append(new QStandardItem(QObject::tr("Major")));
    list.append(new QStandardItem(QObject::tr("Enter Time")));
    list.append(new QStandardItem(QObject::tr("Class")));
    list.append(new QStandardItem(QObject::tr("Email")));
    list.append(new QStandardItem(QObject::tr("Telephone")));
    list.append(new QStandardItem(QObject::tr("Remark")));

    return list;
}

QList<QStandardItem *> Student::profileDetail()
{
    QList<QStandardItem*> list;

    sql->connectToDB();

    list.append(new QStandardItem(userInfo.number));
    list.append(new QStandardItem(sql->getName(userInfo.number)));
    list.append(new QStandardItem(sql->getSex(userInfo.number)));
    list.append(new QStandardItem(sql->getNation(userInfo.number)));
    list.append(new QStandardItem(sql->getProvince(userInfo.number)));
    list.append(new QStandardItem(sql->getAddr(userInfo.number)));
    list.append(new QStandardItem(sql->getCollege(userInfo.number)));
    list.append(new QStandardItem(sql->getSeries(userInfo.number)));
    list.append(new QStandardItem(sql->getProfession(userInfo.number)));
    list.append(new QStandardItem(sql->getEnterTime(userInfo.number)));
    list.append(new QStandardItem(sql->getClass(userInfo.number)));
    list.append(new QStandardItem(sql->getEmail(userInfo.number)));
    list.append(new QStandardItem(sql->getTelephone(userInfo.number)));
    list.append(new QStandardItem(sql->getRemark(userInfo.number)));

    sql->closeConnection();

    return list;
}

void Student::saveProfileChange(QStandardItem* item)
{
    if (item->column() == 0)
        return;

    sql->connectToDB();

    switch (item->row())
    {
    case 0:
        break;
    case 1:
        //sql->changeName(item->text(), userInfo.number);
        break;
    case 2:
        sql->changeSex(item->text(), userInfo.number);
        break;
    case 3:
        sql->changeNation(item->text(), userInfo.number);
        break;
    case 4:
        sql->changeProvince(item->text(), userInfo.number);
        break;
    case 5:
        sql->changeAddr(item->text(), userInfo.number);
        break;
    case 6:
        sql->changeCollege(item->text(), userInfo.number);
        break;
    case 7:
        sql->changeSeries(item->text(), userInfo.number);
        break;
    case 8:
        sql->changeProfession(item->text(), userInfo.number);
        break;
    case 9:
        sql->changeEnterTime(item->text(), userInfo.number);
        break;
    case 10:
        sql->changeClass(item->text(), userInfo.number);
        break;
    case 11:
        sql->changeEmail(item->text(), userInfo.number);
        break;
    case 12:
        sql->changeTelephone(item->text(), userInfo.number);
        break;
    case 13:
        sql->changeRemark(item->text(), userInfo.number);
        break;
    }

    sql->closeConnection();
}

void Student::loadScore(QTableView * tableView)
{

}

QList< QList<QStandardItem *> > Student::scoreDetail()
{
    qDebug() << "scoreDetail";

    scSql->connectToDB();
    cSql->connectToDB();

    QList< QList<QStandardItem *> > list;
    int num = scSql->getTableNum(userInfo.number);
    //qDebug() << num;

    for (int i = 1; i <= num; i++)
    {
        QList<QStandardItem *> tmp;

        tmp.append(new QStandardItem(cSql->getName(scSql->getCourseIdFromTable(i, userInfo.number))));
        //qDebug() << cSql->getName(scSql->getCourseIdFromTable(i, userInfo.number));
        tmp.append(new QStandardItem(QString().setNum(scSql->getMidScoreFromTable(i, userInfo.number))));
        //qDebug() << scSql->getMidScoreFromTable(i, userInfo.number);
        //qDebug() << tmp.at(1)->text();
        tmp.append(new QStandardItem(QString().setNum(scSql->getFinalScoreFromTable(i, userInfo.number))));
        //qDebug() << scSql->getFinalScoreFromTable(i, userInfo.number);

        list.append(tmp);
    }

    cSql->closeConnection();
    scSql->closeConnection();

    return list;
}

void Student::chgPwd(QString oldPwd, QString newPwd)
{
    sql->connectToDB();

    if (sql->getPwd(userInfo.number) == oldPwd)
    {
        if (sql->changePwd(newPwd, userInfo.number))
            QMessageBox::information(0, QObject::tr("Change Password"), QObject::tr("Change Password Successfully!"));
        else
            QMessageBox::warning(0, QObject::tr("Change Password"), QObject::tr("Error occurs while changing password!"));
    }
    else
    {
        QMessageBox::warning(0, QObject::tr("Wrong Password"), QObject::tr("Wrong Password!"));
    }

    sql->closeConnection();
}
