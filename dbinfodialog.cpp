#include "dbinfodialog.h"
#include "ui_dbinfodialog.h"
#include "utility.h"

DBInfoDialog::DBInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DBInfoDialog)
{
    ui->setupUi(this);
}

DBInfoDialog::~DBInfoDialog()
{
    delete ui;
}

void DBInfoDialog::getInfo(DBInfo &dbinfo)
{
    dbinfo.hostName = ui->hostEdit->text();
    dbinfo.DBName = ui->dbEdit->text();
    dbinfo.userName = ui->userEdit->text();
    dbinfo.password = ui->pwdEdit->text();
}
