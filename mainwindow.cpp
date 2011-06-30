#include "ui_mainwindow.h"
#include "mainwindow.h"

#include "dbinfodialog.h"
#include "chgpwddialog.h"
#include "logindialog.h"
#include "utility.h"

#include "student.h"
#include "teacher.h"
#include "administrator.h"
#include "MyTableView.h"

#include <QAction>
#include <QDebug>
#include <QTreeWidget>
#include <QMessageBox>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Init
    isSqlSetted = true;

    //status tips
    ui->actionDataBase_Info->setStatusTip(tr("Set Database Info."));
    ui->actionLogin->setStatusTip(tr("Get Login Dialog."));
    ui->actionExit->setStatusTip(tr("Exit the Window."));
    ui->actionLogout->setStatusTip(tr("Logout the account."));

    //signals and slots
    connect(ui->actionDataBase_Info, SIGNAL(triggered()), this, SLOT(getDBInfo()));
    connect(ui->actionLogin, SIGNAL(triggered()), this, SLOT(login()));
    connect(ui->actionLogout, SIGNAL(triggered()), this, SLOT(reset()));

    connect(ui->infoWidget, SIGNAL(loadProfile()), this, SLOT(loadProfile()));
    connect(ui->infoWidget, SIGNAL(loadScore()), this, SLOT(loadScore()));
    connect(ui->infoWidget, SIGNAL(loadCurriculumSchedule()), this, SLOT(loadCurriculumSchedule()));
    connect(ui->infoWidget, SIGNAL(loadElective()), this, SLOT(loadElective()));
    connect(ui->infoWidget, SIGNAL(loadPlan()), this, SLOT(loadPlan()));
    connect(ui->infoWidget, SIGNAL(chgPwd()), this, SLOT(changePwd()));

    dbInfo.hostName = "localhost";
    dbInfo.DBName = "Handin";
    dbInfo.userName = "hkd";
    dbInfo.password = "19900518";

    login();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getDBInfo()
{

    DBInfoDialog *dbInfoDlg = new DBInfoDialog(this);
    dbInfoDlg->setWindowIcon(QIcon(":/resources/icon/settings.png"));
    if (QDialog::Accepted == dbInfoDlg->exec())
    {
        dbInfoDlg->getInfo(dbInfo);
        isSqlSetted = true;
        dbInfoDlg->hide();
        login();
    }

    delete dbInfoDlg;

}

void MainWindow::login()
{
    if (isSqlSetted)
    {
        int status;

//        LoginDialog *loginDlg = new LoginDialog;
//        loginDlg->setWindowIcon(QIcon(":/resources/icon/login.png"));
//        status = loginDlg->exec();

        user = new Administrator(dbInfo);
//        if (loginDlg->isStuChecked())
//            user = new Student(dbInfo);
//        else if (loginDlg->isTeaChecked())
//                user = new Teacher(dbInfo);
//        else if (loginDlg->isAdmChecked())
//                user = new Administrator(dbInfo);
//        else
//        {
//            if (status == QDialog::Accepted)
//                QMessageBox::warning(this, tr("ERROR"), tr("ERROR occurs while creating user object!"));
//            return;
//        }

        user->login("T00000003", "123", dbInfo);
        initInfo();
//        if (user->login(loginDlg->getLoginNumber(), loginDlg->getPassword(), dbInfo))
//            initInfo(); //初始化界面

        //delete loginDlg;
    }
    else
    {
        QMessageBox::warning(this, tr("SQL"), tr("SQL not Setted!"));
        getDBInfo();
    }
}

void MainWindow::initInfo()
{
    user->loadInfoWidget(ui->infoWidget);
}

void MainWindow::reset()
{
    ui->infoWidget->reset();
    ui->tableView->reset();
}

void MainWindow::loadCurriculumSchedule()
{
    //QMessageBox::information(0, "User", "Schedule");
    ui->tableView->reset();

    QStandardItemModel *model = new QStandardItemModel();
    QStandardItem*** list = user->scheduleDetail();
    bool** matrix;

    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 15; j++)
            model->setItem(j, i, list[i][j]);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Monday"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Tuesday"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Wednesday"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Thursday"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Friday"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Saturday"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Sunday"));

    ui->tableView->setModel(model);

    for (int i = 0; i < 7; i++)
        ui->tableView->horizontalHeader()->setResizeMode(i, QHeaderView::Stretch);
    for (int i = 0; i < 15; i++)
        ui->tableView->verticalHeader()->setResizeMode(i, QHeaderView::Stretch);


    matrix = user->scheduleMatrix();
    for (int i = 0; i < 7; i++)
    {
        int st = 0, ed = 0;
        while (ed < 15)
        {
            while (!matrix[i][st] && st < 15) st++;
            ed = st;
            while (matrix[i][ed] && ed < 15) ed++;
            if (ed >= 15) ui->tableView->setSpan(st, i, 15 - st, 1);
            else ui->tableView->setSpan(st, i, ed - st, 1);
            qDebug() << ed;
            st++;
        }
    }
    ui->tableView->verticalHeader()->setVisible(true);
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);


}

void MainWindow::loadElective()
{
    //QMessageBox::information(0, "User", "Elective");
    ui->tableView->reset();

    QStandardItemModel *model = new QStandardItemModel();
    //MyStandardItemModel *model = new MyStandardItemModel();
    MyItemDelegate *delegate = new MyItemDelegate();

    connect(model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(saveElectiveChange(QStandardItem*)));

    QList< QList<QStandardItem *> > list = user->electiveDetail();

    for (int i = 0; i < list.count(); i++)
    {
        model->insertRow(i, list.at(i));
        qDebug() << list.at(i).at(1)->text();
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Status"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Course ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Course Name"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Teacher ID"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Teacher Name"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Course Addr."));

    ui->tableView->setModel(model);
    //ui->tableView->setItemDelegate(delegate);

    for (int i = 0; i < model->columnCount(); i++)
        ui->tableView->horizontalHeader()->setResizeMode(i, QHeaderView::Stretch);
    //ui->tableView->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
    ui->tableView->resizeColumnToContents(1);
    ui->tableView->resizeColumnToContents(2);
//    ui->tableView->setColumnWidth(2, 100);
//    ui->tableView->setColumnWidth(3, 100);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);
}

void MainWindow::saveElectiveChange(QStandardItem *item)
{
    user->saveElectiveChange(item, (QStandardItemModel*)ui->tableView->model());
}

void MainWindow::loadPlan()
{
    //QMessageBox::information(0, "User", "Schedule");
    ui->tableView->reset();

    QStandardItemModel *model = new QStandardItemModel();
    int  num = user->courseList().count();


    connect(model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(savePlanChange(QStandardItem*)));

    model->insertColumn(0, user->courseIdList());
    model->insertColumn(1, user->courseList());
    //model->insertColumn(1, user->profileDetail());
    for (int i = 0; i < num; i++)
        for (int j = 2; j < 5; j++)
            model->setItem(i, j, new QStandardItem());

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Course ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Course Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Teacher"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Time"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Address"));

    for (int i = 0; i < model->rowCount(); i++)
    {
        model->item(i, 0)->setEditable(false);
    }

    //ui->tableView->setRowHeight(0, 150);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView->setModel(model);
}

void MainWindow::savePlanChange(QStandardItem *item)
{
    user->savePlanChange(item, (QStandardItemModel*)ui->tableView->model());
}

void MainWindow::loadProfile()
{
    //ui->tableView->reset();
    ui->tableView->reset();

    QStandardItemModel *model = new QStandardItemModel();

    connect(model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(saveProfileChange(QStandardItem*)));

    model->insertColumn(0, user->profileHeader());
    model->insertColumn(1, user->profileDetail());

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Property"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Value"));
    for (int i = 0; i < model->rowCount(); i++)
    {
        model->item(i, 0)->setEditable(false);
    }
    model->item(0, 1)->setEditable(false);
    model->item(1, 1)->setEditable(false);

    //ui->tableView->setRowHeight(0, 150);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView->setModel(model);
}

void MainWindow::saveProfileChange(QStandardItem *item)
{
    user->saveProfileChange(item);
}

void MainWindow::loadRecord()
{

}

void MainWindow::loadScore()
{
    //QMessageBox::information(0, "wer", "wer");
    ui->tableView->reset();

    QStandardItemModel *model = new QStandardItemModel();

    QList< QList<QStandardItem *> > list = user->scoreDetail();

    for (int i = 0; i < list.count(); i++)
    {
        model->insertRow(i, list.at(i));
        qDebug() << list.at(i).at(1)->text();
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Course Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Middleterm Score"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Final Score"));

    for (int i = 0; i < model->rowCount(); i++)
        for (int j = 0; j < model->columnCount(); j++)
            model->item(i,j)->setEditable(false);

    ui->tableView->setModel(model);

    ui->tableView->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
    ui->tableView->resizeColumnToContents(1);
    ui->tableView->resizeColumnToContents(2);
//    ui->tableView->setColumnWidth(2, 100);
//    ui->tableView->setColumnWidth(3, 100);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);

}

void MainWindow::loadStatic()
{

}

void MainWindow::changePwd()
{
    ChgPwdDialog *chgPwd = new ChgPwdDialog(this);

    if (QDialog::Accepted == chgPwd->exec())
        user->chgPwd(chgPwd->getOldPwd(), chgPwd->getNewPwd());

    delete chgPwd;
}
