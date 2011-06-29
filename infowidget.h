#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QWidget>
#include "utility.h"

namespace Ui {
    class InfoWidget;
}

class QTreeWidget;
class QTreeWidgetItem;
struct UserInfo;

class InfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InfoWidget(QWidget *parent = 0);
    ~InfoWidget();

public slots:
    void dispatchView(QTreeWidgetItem*,int);

signals:
    void loadCurriculumSchedule();
    void loadElective();
    void loadScore();
    void loadProfile();

    void loadRecord();
    void loadStatic();

    void loadPlan();

    void chgPwd();

public:
//    void loadUserInfo(QImage*, QStringList*);
    void loadUserInfo(UserInfo*);
    void loadFeatureList(QTreeWidget*);
    void addChildItem(QTreeWidgetItem*, QTreeWidgetItem*);

    void reset();

private:
    Ui::InfoWidget *ui;
    UserInfo userInfo;
};

#endif // INFOWIDGET_H
