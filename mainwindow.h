#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include <QTreeWidget>
#include <QWidget>

#include "utility.h"

class QSqlDatabase;
class Student;
class User;
class QStandardItem;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void getDBInfo();
    void login();
    void reset();

    void loadCurriculumSchedule();
    void loadElective();
    void loadScore();
    void loadProfile();

    void loadRecord();
    void loadStatic();

    void loadPlan();

    void changePwd();

    void saveProfileChange(QStandardItem*);
    void saveElectiveChange(QStandardItem*);
    void savePlanChange(QStandardItem*);

private:
    void loadUserInfo();
    void initInfo();

private:
    Ui::MainWindow *ui;
    QSqlDatabase *sql;

    User *user;
    bool isSqlSetted;

    DBInfo dbInfo;

};

#endif // MAINWINDOW_H
