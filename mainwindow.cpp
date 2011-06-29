#include "ui_mainwindow.h"
#include "mainwindow.h"

#include "dbinfodialog.h"
#include "chgpwddialog.h"
#include "logindialog.h"
#include "utility.h"

#include "student.h"
#include "teacher.h"
#include "administrator.h"

#include <QAction>
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
    connect(ui->infoWidget, SIGNAL(chgPwd()), this, SLOT(changePwd()));

    dbInfo.hostName = "localhost";
    dbInfo.DBName = "Handin";
    dbInfo.userName = "hkd";
    dbInfo.password = "19900518";

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

        LoginDialog *loginDlg = new LoginDialog;
        loginDlg->setWindowIcon(QIcon(":/resources/icon/login.png"));
        status = loginDlg->exec();

        if (loginDlg->isStuChecked())
            user = new Student(dbInfo);
        else if (loginDlg->isTeaChecked())
                user = new Teacher(dbInfo);
        else if (loginDlg->isAdmChecked())
                user = new Administrator(dbInfo);
        else
        {
            if (status == QDialog::Accepted)
                QMessageBox::warning(this, tr("ERROR"), tr("ERROR occurs while creating user object!"));
            return;
        }

        if (user->login(loginDlg->getLoginNumber(), loginDlg->getPassword(), dbInfo))
            initInfo(); //初始化界面

        delete loginDlg;
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

}

void MainWindow::loadElective()
{

}

void MainWindow::loadPlan()
{

}

void MainWindow::loadProfile()
{
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

    ui->tableView->setRowHeight(0, 150);
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
