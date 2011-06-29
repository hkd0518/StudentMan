/********************************************************************************
** Form generated from reading UI file 'dbinfodialog.ui'
**
** Created: Wed Jun 29 21:39:51 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBINFODIALOG_H
#define UI_DBINFODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DBInfoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *hostEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *dbEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *userEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *pwdEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DBInfoDialog)
    {
        if (DBInfoDialog->objectName().isEmpty())
            DBInfoDialog->setObjectName(QString::fromUtf8("DBInfoDialog"));
        DBInfoDialog->resize(268, 202);
        verticalLayout = new QVBoxLayout(DBInfoDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DBInfoDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        hostEdit = new QLineEdit(DBInfoDialog);
        hostEdit->setObjectName(QString::fromUtf8("hostEdit"));
        hostEdit->setDragEnabled(true);

        horizontalLayout->addWidget(hostEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(DBInfoDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        dbEdit = new QLineEdit(DBInfoDialog);
        dbEdit->setObjectName(QString::fromUtf8("dbEdit"));
        dbEdit->setDragEnabled(true);

        horizontalLayout_2->addWidget(dbEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(DBInfoDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        userEdit = new QLineEdit(DBInfoDialog);
        userEdit->setObjectName(QString::fromUtf8("userEdit"));
        userEdit->setDragEnabled(true);

        horizontalLayout_3->addWidget(userEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(DBInfoDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        pwdEdit = new QLineEdit(DBInfoDialog);
        pwdEdit->setObjectName(QString::fromUtf8("pwdEdit"));
        pwdEdit->setEchoMode(QLineEdit::Password);
        pwdEdit->setDragEnabled(true);

        horizontalLayout_4->addWidget(pwdEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        buttonBox = new QDialogButtonBox(DBInfoDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DBInfoDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DBInfoDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DBInfoDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DBInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *DBInfoDialog)
    {
        DBInfoDialog->setWindowTitle(QApplication::translate("DBInfoDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DBInfoDialog", "HostName:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DBInfoDialog", "Database Name:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DBInfoDialog", "UserName:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DBInfoDialog", "Password:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DBInfoDialog: public Ui_DBInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBINFODIALOG_H
