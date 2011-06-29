#ifndef TEACHERCOURSESQL_H
#define TEACHERCOURSESQL_H

#include "utility.h"
#include <QSqlDatabase>

class QString;

class teacherCourseSql
{
public:
    teacherCourseSql(DBInfo);

    int getNum(QString teacherId ,QString courseId);
    QString getTimetable (QString teacherId ,QString courseId);
    QString getCourseAddr(QString teacherId ,QString courseId);

    bool changeTeacherCourse(QString timetable,QString courseAddr,int courseNum,QString teacherId ,QString courseId);
    bool addTeacherCourse(QString teacherId ,QString courseId);
    bool delTeacherCourse(QString teacherId ,QString courseId);

    int getTableNum(QString teacherId);
    QString getCourseIdFronTable(int num,QString teacherId);
    QString getTimeFromTable(int num,QString teacherId);
    QString getAddrFromTable(int num,QString teacherId);
    int getNumFromTable(int num,QString teacherId);

    int getAvailCourseNum(QString teacherId);
    QString getAvailCourseId(int num,QString teacherId);

    bool connectToDB();
    void closeConnection();

private:
    DBInfo dbInfo;
    QSqlDatabase db;
};

#endif // TEACHERCOURSESQL_H
