#-------------------------------------------------
#
# Project created by QtCreator 2014-10-10T15:43:39
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Modbus
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    switchbutton.cpp \
    form.cpp

HEADERS  += dialog.h \
    switchbutton.h \
    form.h

FORMS    += \
    form.ui

RESOURCES += \
    Resource.qrc
