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
    timetablesql.cpp \
    teachersql.cpp \
    studentsql.cpp \
    scoresql.cpp \
    coursesql.cpp \
    chgpwddialog.cpp \
    teachercoursesql.cpp \
    studentcoursesql.cpp

HEADERS  += mainwindow.h \
    student.h \
    teacher.h \
    administrator.h \
    dbinfodialog.h \
    infowidget.h \
    logindialog.h \
    user.h \
    utility.h \
    timetablesql.h \
    teachersql.h \
    studentsql.h \
    scoresql.h \
    coursesql.h \
    chgpwddialog.h \
    teachercoursesql.h \
    studentcoursesql.h

FORMS    += mainwindow.ui \
    dbinfodialog.ui \
    infowidget.ui \
    logindialog.ui \
    chgpwddialog.ui

RESOURCES += \
    StudentMan.qrc
