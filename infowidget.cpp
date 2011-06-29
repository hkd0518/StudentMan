#include <QTreeWidget>
#include <QImage>

#include "infowidget.h"
#include "ui_infowidget.h"

InfoWidget::InfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfoWidget)
{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(1);
    ui->treeWidget->setColumnWidth(0, 200);

    connect(ui->treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),
            this, SLOT(dispatchView(QTreeWidgetItem*,int)));
}

InfoWidget::~InfoWidget()
{
    delete ui;
}

//void InfoWidget::loadUserInfo(QImage * image, QStringList *stringList)
//{
//    ui->label->setPixmap(QPixmap::fromImage(image->scaled(150, 150)));
//    ui->textBrowser->setPlainText(stringList->at(0));
//}

void InfoWidget::loadUserInfo(UserInfo *userInfo)
{
    QString str = "<table>"
                  "<tr>"
                  "<td><h3>Name:</h3></td>"
                  "<td valign='bottom'>";
    str += userInfo->name;
    str +=        "</td>"
                  "</tr>"
                  "<tr>"
                  "<td><h3>Number:</h3></td>"
                  "<td valign='bottom'>";
    str += userInfo->number;
    str +=        "</td>"
                  "</tr>"
                  "<tr>"
                  "<td><h3>Role:</h3></td>"
                  "<td valign='bottom'>";
    str += userInfo->role;
    str +=        "</td>"
                  "</tr>"
                  "</table>";

    ui->label->setPixmap(QPixmap::fromImage(userInfo->portrait.scaled(150, 150)));
    ui->textBrowser->setHtml(str);
}

void InfoWidget::loadFeatureList(QTreeWidget *featureList)
{
    ui->treeWidget->clear();
    for (int i = 0; i < featureList->topLevelItemCount(); i++)
    {
        //ui->treeWidget->addTopLevelItem(new QTreeWidgetItem(*(featureList->topLevelItem(i))));
        //addChildItem(featureList->topLevelItem(i), ui->treeWidget->topLevelItem(i));
        ui->treeWidget->addTopLevelItem(featureList->topLevelItem(i)->clone());
    }
}

void InfoWidget::addChildItem(QTreeWidgetItem *src, QTreeWidgetItem *des)
{
    for (int i = 0; i < src->childCount(); i++)
    {
        //des->addChild(new QTreeWidgetItem(*(src->child(i))));
        des->addChild(src->child(i)->clone());
        //addChildItem(src->child(i), des->child(i));
    }
}

void InfoWidget::reset()
{
    ui->label->clear();
    ui->textBrowser->clear();
    ui->treeWidget->clear();
}

void InfoWidget::dispatchView(QTreeWidgetItem *item, int index)
{
    if (item->text(0) == tr("Personal Information"))
        emit loadProfile();
    else if (item->text(0) == tr("Change Password"))
        emit chgPwd();
    else if (item->text(0) == tr("View Results"))
        emit loadScore();
}
