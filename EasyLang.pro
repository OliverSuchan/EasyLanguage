#-------------------------------------------------
#
# Project created by QtCreator 2013-12-09T14:28:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EasyLang
TEMPLATE = app
CONFIG += c++11
INCLUDEPATH += "include"

SOURCES +=\
    src/conjugation.cpp \
    src/conjugator.cpp \
    src/language.cpp \
    src/languagemanager.cpp \
    src/lection.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/parser.cpp \
    src/verb.cpp \
    src/voc.cpp

HEADERS  += \
    src/conjugation.h \
    src/conjugator.h \
    src/Globals.h \
    src/language.h \
    src/languagemanager.h \
    src/lection.h \
    src/mainwindow.h \
    src/parser.h \
    src/verb.h \
    src/voc.h \
    src/IHashable.h

FORMS    += \
    forms/mainwindow.ui
