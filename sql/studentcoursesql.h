#ifndef STUDENTCOURSESQL_H
#define STUDENTCOURSESQL_H

#include "utility.h"
#include <QSqlDatabase>

class QString;

class studentCourseSql
{
public:
    studentCourseSql(DBInfo);

    int getMidScore(QString studentId, QString teacherId, QString courseId);
    bool changeMidScore(int midScore,QString studentId, QString teacherId, QString courseId);

    int getFinalScore(QString studentId, QString teacherId, QString courseId);
    bool changeFinalScore(int finalScore,QString studentId, QString teacherId, QString courseId);

    bool addStudentCourse(QString studentId, QString teacherId, QString courseId);
    bool delStudentCourse(QString studentId, QString teacherId, QString courseId);



    int getTableNum(QString studentId);
    QString getTeacherIdFromTable(int num,QString studentId);
    QString getCourseIdFromTable(int num,QString studentId);
    int getMidScoreFromTable(int num,QString studentId);
    int getFinalScoreFromTable(int num,QString studentId);

    int getAvailCourseNum(QString studentId);
    QString getAvailCourseId(int num,QString studentId);
    QString getAvailTeacherId(int num,QString studentId);

    int getTeachingStudentNum(QString teacherId, QString courseId);
    QString getTeachingStudentId(int num, QString teacherId, QString courseId);


    bool connectToDB();
    void closeConnection();
private:
    DBInfo dbInfo;
    QSqlDatabase db;
};

#endif // STUDENTCOURSESQL_H
