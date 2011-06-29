#ifndef UTILITY_H
#define UTILITY_H

#include <QString>
#include <QImage>

struct UserInfo
{
    QString name;
    QString number;
    QString role;
    QImage portrait;
};

struct DBInfo
{
    QString hostName;
    QString DBName;
    QString userName;
    QString password;
};

#endif // UTILITY_H
