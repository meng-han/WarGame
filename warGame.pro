#-------------------------------------------------
#
# Project created by QtCreator 2015-03-29T20:38:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = warGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    agent.cpp \
    boardstate.cpp \
    minimaxagent.cpp \
    alphabetaagent.cpp

HEADERS  += mainwindow.h \
    agent.h \
    boardstate.h \
    minimaxagent.h \
    alphabetaagent.h

FORMS    += mainwindow.ui
