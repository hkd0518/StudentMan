#ifndef DBINFODIALOG_H
#define DBINFODIALOG_H

#include <QDialog>

struct DBInfo;

namespace Ui {
    class DBInfoDialog;
}

class DBInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DBInfoDialog(QWidget *parent = 0);
    ~DBInfoDialog();

    void getInfo(DBInfo&);

private:
    Ui::DBInfoDialog *ui;
};

#endif // DBINFODIALOG_H
