#-------------------------------------------------
#
# Project created by QtCreator 2023-04-08T12:13:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = textedit
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h \
    ../build-textedit-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/ui_mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    image/103.bmp \
    image/120.bmp \
    image/430.bmp \
    image/BLD.BMP \
    image/cut.bmp \
    image/DBLUNDR.BMP \
    image/exit.bmp \
    image/ITL.BMP \
    image/new2.bmp \
    image/open3.bmp \
    image/paste.bmp \
    image/UNDRLN.BMP \
    image/WORDUNDR.BMP
RC_ICONS = AppIcon.ico