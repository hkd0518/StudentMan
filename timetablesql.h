#ifndef TIMETABLESQL_H
#define TIMETABLESQL_H
class QString;
class TimetableSql
{
public:
    TimetableSql();
    ~TimetableSql();

    QString getTime(int c_id,int tea_id);
    bool changeTime(QString t,int c_id,int tea_id);
    QString getAddr(int c_id,int tea_id);
    bool changeAddr(QString t,int c_id,int tea_id);
};

#endif // TIMETABLESQL_H
