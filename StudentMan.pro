#-------------------------------------------------
#
# Project created by QtCreator 2011-05-23T18:40:45
#
#-------------------------------------------------

QT       += core gui sql

CONFIG += qwt

TARGET = StudentMan
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    student.cpp \
    teacher.cpp \
    administrator.cpp \
    dbinfodialog.cpp \
    infowidget.cpp \
    logindialog.cpp \
    user.cpp \
    chgpwddialog.cpp \
    sql/teachersql.cpp \
    sql/teachercoursesql.cpp \
    sql/studentsql.cpp \
    sql/studentcoursesql.cpp \
    sql/sql.cpp \
    sql/coursesql.cpp \
    MyTableView.cpp

HEADERS  += mainwindow.h \
    student.h \
    teacher.h \
    administrator.h \
    dbinfodialog.h \
    infowidget.h \
    logindialog.h \
    user.h \
    utility.h \
    chgpwddialog.h \
    sql/teachersql.h \
    sql/teachercoursesql.h \
    sql/studentsql.h \
    sql/studentcoursesql.h \
    sql/sql.h \
    sql/coursesql.h \
    MyTableView.h

FORMS    += mainwindow.ui \
    dbinfodialog.ui \
    infowidget.ui \
    logindialog.ui \
    chgpwddialog.ui

RESOURCES += \
    StudentMan.qrc
