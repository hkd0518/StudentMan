#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QStringList>
#include <QList>
#include <QStandardItem>
#include <QMessageBox>
#include <QDebug>

#include "teacher.h"
#include "infowidget.h"
#include "utility.h"

Teacher::Teacher(DBInfo dbInfo)
{
    createList();

    sql = new studentsql(dbInfo);   //初始化实体类指针
    scSql = new studentCourseSql(dbInfo);
    cSql = new coursesql(dbInfo);
    tcSql = new teacherCourseSql(dbInfo);
    tSql = new teachersql(dbInfo);
}

Teacher::~Teacher()
{

}

void Teacher::initInfo()
{
//    userInfo.name = "Mr. Hu";
//    userInfo.number = "T12345678";
//    userInfo.role = "Teacher";
//    userInfo.portrait.load(":/resources/icon/teacher.png");
    tSql->connectToDB();

    userInfo.name = tSql->getName(userInfo.number);
    userInfo.role = "Teacher";
    userInfo.portrait.load(":/resources/icon/teacher.png");

    tSql->closeConnection();
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

    studyItem->addChild(item1);
    studyItem->addChild(item2);

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
    if (!tSql->connectToDB())
        return false;

    if (password == tSql->getPwd(loginNumber) && 0 == tSql->getLevel(loginNumber))
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

void Teacher::loadCurriculumSchedule(QTableView * tableView)
{
}

QStandardItem*** Teacher::scheduleDetail()
{
    tcSql->connectToDB();

    QStandardItem*** list;
    list = new QStandardItem**[7];
    for (int i = 0; i < 7; i++)
        list[i] = new QStandardItem*[15];

    int num = tcSql->getTableNum(userInfo.number);
    QString name,time,addr;
    QStringList timeDetail;

    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 15; j++)
            list[i][j] = new QStandardItem();

    for (int i = 1; i <= num; i++)
    {
        name = cSql->getName(tcSql->getCourseIdFromTable(i, userInfo.number));
        time = tcSql->getTimetable(userInfo.number,
                                   tcSql->getCourseIdFromTable(i, userInfo.number));
        addr = tcSql->getCourseAddr(userInfo.number,
                                    tcSql->getCourseIdFromTable(i, userInfo.number));

        //qDebug() << name+" "+addr+" "+time;

        timeDetail = time.split(';');
        for (int j = 0; j < timeDetail.count() - 1; j++)
        {
            list[timeDetail.at(j).split(',').at(0).toInt() - 1]
                    [timeDetail.at(j).split(',').at(1).toInt() - 1]->setText(name+" "+addr.split(';').at(j));
            qDebug() << name+" "+addr.split(';').at(j);
        }
    }

    tcSql->closeConnection();

    return list;
}

bool** Teacher::scheduleMatrix()
{
    tcSql->connectToDB();

    bool **list;
    list = new bool*[7];
    for (int i = 0; i < 7; i++)
        list[i] = new bool[15];

    int num = tcSql->getTableNum(userInfo.number);
    QString time;
    QStringList timeDetail, courseDetail;

    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 15; j++)
            list[i][j] = false;

    for (int i = 1; i <= num; i++)
    {

        time = tcSql->getTimetable(userInfo.number,
                                   tcSql->getCourseIdFromTable(i, userInfo.number));

        timeDetail = time.split(';');
        for (int j = 0; j < timeDetail.count() - 1; j++)
        {
            courseDetail = timeDetail.at(j).split(',');
            for (int k = courseDetail.at(1).toInt(); k <= courseDetail.at(2).toInt(); k++)
                list[courseDetail.at(0).toInt() - 1][k - 1] = true;
        }
    }

    tcSql->closeConnection();

    return list;
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

QList<QStandardItem*> Teacher::profileDetail()
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

void Teacher::saveProfileChange(QStandardItem* item)
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

void Teacher::loadScore(QTableView * tableView)
{

}

void Teacher::loadRecord()
{

}

QList<QStandardItem *> Teacher::recordList()
{
    QList<QStandardItem*> list;

    scSql->connectToDB();

    QString cId = tcSql->getCourseIdFromTable(1, userInfo.number);
    int num = scSql->getTeachingStudentNum(userInfo.number, cId);

    for (int i = 1; i <= num; i++)
    {
        list.append(new QStandardItem(sql->getName(scSql->getTeachingStudentId(i, userInfo.number, cId))));
    }

    scSql->closeConnection();

    return list;
}

QList<QStandardItem *> Teacher::recordIdList()
{
    QList<QStandardItem*> list;

    scSql->connectToDB();

    QString cId = tcSql->getCourseIdFromTable(1, userInfo.number);
    int num = scSql->getTeachingStudentNum(userInfo.number, cId);

    for (int i = 1; i <= num; i++)
    {
        list.append(new QStandardItem(scSql->getTeachingStudentId(i, userInfo.number, cId)));
    }

    scSql->closeConnection();

    return list;
}

void Teacher::saveRecordChange(QStandardItem* item , QStandardItemModel *model)
{
    if (item->column() == 0 || item->column() == 1)
        return;

    tcSql->connectToDB();

    QString cId(tcSql->getCourseIdFromTable(1, userInfo.number));

    switch (item->column())
    {
    case 2://mid
        scSql->changeMidScore(item->text().toInt(), model->item(item->row(), 0)->text(), userInfo.number, cId);
        qDebug() << item->text();
        break;
    case 3://final
        scSql->changeFinalScore(item->text().toInt(), model->item(item->row(), 0)->text(), userInfo.number, cId);
        break;
    }

    tcSql->closeConnection();
}

void Teacher::loadStatic()
{

}

void Teacher::chgPwd(QString oldPwd, QString newPwd)
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
