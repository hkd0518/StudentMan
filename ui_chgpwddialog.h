/********************************************************************************
** Form generated from reading UI file 'chgpwddialog.ui'
**
** Created: Thu Jun 30 06:45:10 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHGPWDDIALOG_H
#define UI_CHGPWDDIALOG_H

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

class Ui_ChgPwdDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLineEdit *oldPwd;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *newPwd;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *confirmPwd;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ChgPwdDialog)
    {
        if (ChgPwdDialog->objectName().isEmpty())
            ChgPwdDialog->setObjectName(QString::fromUtf8("ChgPwdDialog"));
        ChgPwdDialog->resize(287, 130);
        verticalLayout = new QVBoxLayout(ChgPwdDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ChgPwdDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        oldPwd = new QLineEdit(ChgPwdDialog);
        oldPwd->setObjectName(QString::fromUtf8("oldPwd"));
        oldPwd->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(oldPwd);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(ChgPwdDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        newPwd = new QLineEdit(ChgPwdDialog);
        newPwd->setObjectName(QString::fromUtf8("newPwd"));
        newPwd->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(newPwd);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(ChgPwdDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        confirmPwd = new QLineEdit(ChgPwdDialog);
        confirmPwd->setObjectName(QString::fromUtf8("confirmPwd"));
        confirmPwd->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(confirmPwd);


        verticalLayout->addLayout(horizontalLayout_3);

        buttonBox = new QDialogButtonBox(ChgPwdDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ChgPwdDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), ChgPwdDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ChgPwdDialog);
    } // setupUi

    void retranslateUi(QDialog *ChgPwdDialog)
    {
        ChgPwdDialog->setWindowTitle(QApplication::translate("ChgPwdDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ChgPwdDialog", "Old Password:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ChgPwdDialog", "New Password:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ChgPwdDialog", "Confirm Password:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChgPwdDialog: public Ui_ChgPwdDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHGPWDDIALOG_H
