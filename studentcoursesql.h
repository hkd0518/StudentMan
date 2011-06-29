#ifndef STUDENTCOURSESQL_H
#define STUDENTCOURSESQL_H

class QString;

class studentCourseSql
{
public:
    studentCourseSql();

    int getMidScore(QString studentId, QString teacherId, QString courseId);
    bool changeMidScore(int midScore,QString studentId, QString teacherId, QString courseId);

    int getFinalScore(QString studentId, QString teacherId, QString courseId);
    bool changeFinalScore(int finalScore,QString studentId, QString teacherId, QString courseId);

    bool addStudentCourse(QString studentId, QString teacherId, QString courseId);
    bool delStudentCourse(QString studentId, QString teacherId, QString courseId);



    int getTableNum(QString studentId);
    QString getTeacherIdFronTable(int num,QString studentId);
    QString getCourseIdFromTable(int num,QString studentId);
    int getMidScoreFromTable(int num,QString studentId);
    int getFinalScoreFromTable(int num,QString studentId);

    int getAvailCourseNum(QString studentId);
    QString getAvailCourseId(int num,QString studentId);
    QString getAvailTeacherId(int num,QString studentId);

    int getTeachingStudentNum(QString teacherId, QString courseId);
    QString getTeachingStudentId(int num, QString teacherId, QString courseId);
};

#endif // STUDENTCOURSESQL_H
