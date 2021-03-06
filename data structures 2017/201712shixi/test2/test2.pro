#-------------------------------------------------
#
# Project created by QtCreator 2017-12-26T16:40:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dialogchaxunlianxiren.cpp \
    dialogchaxunlianxi.cpp \
    dialogxiugailianxiren.cpp \
    dialogxiugailianxi.cpp \
    mapsrc/IO.cpp \
    showallrelation.cpp

HEADERS += \
        mainwindow.h \
    dialogchaxunlianxiren.h \
    dialogchaxunlianxi.h \
    dialogxiugailianxiren.h \
    dialogxiugailianxi.h \
    mapsrc/IO.h \
    mapsrc/LinkedList.h \
    mapsrc/Map.h \
    mapsrc/Person.h \
    mapsrc/Relation.h \
    showallrelation.h

FORMS += \
    dialogchaxunlianxiren.ui \
    dialogchaxunlianxi.ui \
    dialogxiugailianxiren.ui \
    dialogxiugailianxi.ui \
    showallrelation.ui


DISTFILES +=

