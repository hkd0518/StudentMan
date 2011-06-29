#ifndef SCORESQL_H
#define SCORESQL_H
class QString;
class ScoreSql
{
public:
    ScoreSql();
    ~ScoreSql();

    int getScoreId(QString stu_id,QString tea_id,int c_id);
    //void changeScoreId(QString stu_id,int tea_id,int c_id);
    int getMidScore(int sc_id);
    int getMidScore(QString stu_id,QString tea_id,int c_id);
    bool changeMidScore(int score,int sc_id);
    bool changeMidScore(int score,QString stu_id,QString tea_id,int c_id);
    int getFinScore(int sc_id);
    int getFinScore(QString stu_id,QString tea_id,int c_id);
    bool changeFinScore(int score,int sc_id);
    bool changeFinScore(int score,QString stu_id,QString tea_id,int c_id);
};

#endif // SCORESQL_H
