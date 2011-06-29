#include "chgpwddialog.h"
#include "ui_chgpwddialog.h"

#include <QMessageBox>
#include <QAbstractButton>

ChgPwdDialog::ChgPwdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChgPwdDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(clicked(QAbstractButton*)), this, SLOT(check(QAbstractButton*)));
}

ChgPwdDialog::~ChgPwdDialog()
{
    delete ui;
}

QString ChgPwdDialog::getOldPwd()
{
    return ui->oldPwd->text();
}

QString ChgPwdDialog::getNewPwd()
{
    return ui->newPwd->text();
}

bool ChgPwdDialog::check(QAbstractButton* btn)
{
    if (btn->text() != "OK")
        return true;

    if (ui->newPwd->text() == ui->confirmPwd->text())
        this->accept();
    else
        QMessageBox::warning(0, QObject::tr("Error"), QObject::tr("Confirm Password is not Confirmed!"));
}
