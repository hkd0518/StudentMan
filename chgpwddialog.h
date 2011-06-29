#ifndef CHGPWDDIALOG_H
#define CHGPWDDIALOG_H

#include <QDialog>

class QAbstractButton;

namespace Ui {
    class ChgPwdDialog;
}

class ChgPwdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChgPwdDialog(QWidget *parent = 0);
    ~ChgPwdDialog();

    QString getOldPwd();
    QString getNewPwd();

private slots:
    bool check(QAbstractButton*);

private:
    Ui::ChgPwdDialog *ui;
};

#endif // CHGPWDDIALOG_H
