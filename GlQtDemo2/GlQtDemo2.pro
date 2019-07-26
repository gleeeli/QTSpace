#-------------------------------------------------
#
# Project created by QtCreator 2019-07-02T14:59:40
#
#-------------------------------------------------

QT       += core gui \
            network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GlQtDemo2
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
        loginwidget.cpp \
    homewindow.cpp \
    colorselwindow.cpp \
    progresswindow.cpp \
    folderwindow.cpp \
    graphicswindow.cpp \
    imagewindow.cpp \
    systemwindow.cpp \
    coursewindow.cpp \
    safewindow.cpp \
    networkwindow.cpp \
    handdrawwindow.cpp

HEADERS += \
        loginwidget.h \
    homewindow.h \
    colorselwindow.h \
    progresswindow.h \
    folderwindow.h \
    graphicswindow.h \
    imagewindow.h \
    systemwindow.h \
    coursewindow.h \
    safewindow.h \
    networkwindow.h \
    handdrawwindow.h

FORMS += \
        loginwidget.ui \
    homewindow.ui \
    colorselwindow.ui \
    progresswindow.ui \
    folderwindow.ui \
    graphicswindow.ui \
    imagewindow.ui \
    mediawindow.ui \
    systemwindow.ui \
    coursewindow.ui \
    safewindow.ui \
    networkwindow.ui \
    handdrawwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
