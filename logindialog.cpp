#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

bool LoginDialog::isStuChecked()
{
    return ui->stuRadio->isChecked();
}

bool LoginDialog::isTeaChecked()
{
    return ui->teaRadio->isChecked();
}

bool LoginDialog::isAdmChecked()
{
    return ui->admRadio->isChecked();
}

QString LoginDialog::getLoginNumber()
{
    return ui->loginNumber->text();
}

QString LoginDialog::getPassword()
{
    return ui->password->text();
}
