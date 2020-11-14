#-------------------------------------------------
#
# Project created by QtCreator 2019-06-27T12:08:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyFinalProject
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
        add_building.cpp \
        classes.cpp \
        edit_building.cpp \
        main.cpp \
        mainpage.cpp \
        mainwindow.cpp \
        search_user.cpp \
        show_buildings_admin.cpp \
        sign_in_function.cpp \
        sign_up_function.cpp

HEADERS += \
        add_building.h \
        classes.h \
        edit_building.h \
        mainpage.h \
        mainwindow.h \
        search_user.h \
        show_buildings_admin.h \
        sign_in_function.h \
        sign_up_function.h
FORMS += \
        add_building.ui \
        edit_building.ui \
        mainpage.ui \
        mainwindow.ui \
        search_user.ui \
        show_buildings_admin.ui \
        sign_in_function.ui \
        sign_up_function.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
