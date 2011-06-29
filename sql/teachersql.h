#ifndef TEACHERSQL_H
#define TEACHERSQL_H

class QString;
class QPixmap;

class teachersql
{
public:
    teachersql(); 
    QString getPwd(QString id);
    bool changePwd(QString pwd,QString id);
    //QString getId();
    //bool changeId(QString id);
    QString getName(QString id);
    bool changeName(QString name,QString id);
    int getLevel(QString id);
    bool changeLevel(int level,QString id);
    QString getSex(QString id);
    bool changeSex(QString sex,QString id);
    QString getNation(QString id);
    bool changeNation(QString nation,QString id);
    QString getProvince(QString id);
    bool changeProvince(QString province,QString id);
    QString getAddr(QString id);
    bool changeAddr(QString addr,QString id);

    QString getPicture(QString id);
    bool changePicture(QString photolink,QString id);

    QString getCollege(QString id);
    bool changeCollege(QString college,QString id);
    QString getTitle(QString id);
    bool changeTitle(QString title,QString id);
    QString getEmail(QString id);
    bool changeEmail(QString email,QString id);
    QString getTelephone(QString id);
    bool changeTelephone(QString tel,QString id);
    QString getRemark(QString id);
    bool changeRemark(QString remark,QString id);
    bool addTeacher(QString id,QString pwd ,QString name);
    bool delTeacher(QString id);


    int getTeacherNum();
    QString getIdFromNum(int num);
};

#endif // TEACHERSQL_H
