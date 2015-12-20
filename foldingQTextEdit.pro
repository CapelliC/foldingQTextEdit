#-------------------------------------------------
#
# Project created by QtCreator 2015-12-18T19:42:17
#
# author: CapelliC @2015
#
#-------------------------------------------------

CONFIG += c++11
QT     += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = foldingQTextEdit
TEMPLATE = app

# only for file2string
INCLUDEPATH += /home/carlo/develop/loqt/lqUty

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    foldingQTextEdit.cpp \
    framedTextAttr.cpp \
    foldedTextAttr.cpp

HEADERS += \
    mainwindow.h \
    foldingQTextEdit.h \
    framedTextAttr.h \
    foldedTextAttr.h

DISTFILES += \
    LICENSE \
    README.md
