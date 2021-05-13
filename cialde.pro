#-------------------------------------------------
#
# Project created by QtCreator 2021-04-13T12:17:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cialde
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


SOURCES +=\
        main.cpp \
    model/covered.cpp \
    model/wafflebox.cpp \
    model/circlebox.cpp \
    model/heightproviderbox.cpp \
    model/conebox.cpp \
    model/ventagliobox.cpp \
    model/cannolobox.cpp \
    model/branded.cpp \
    model/xmlmanagement.cpp \
    model/tablemodel.cpp \
    model/model.cpp \
    view/menubar.cpp \
    view/catalog.cpp \
    view/addproduct.cpp \
    view/modifyproduct.cpp \
    view/searchinventory.cpp \
    view/table.cpp \
    view/tablezone.cpp \
    view/mainwindow.cpp \
    controller.cpp

HEADERS +=\
    model/covered.h \
    model/wafflebox.h \
    model/circlebox.h \
    model/heightproviderbox.h \
    model/conebox.h \
    model/ventagliobox.h \
    model/cannolobox.h \
    model/branded.h \
    model/container.h \
    model/xmlmanagement.h \
    model/tablemodel.h \
    model/model.h \
    model/deepptr.h \
    view/menubar.h \
    view/catalog.h \
    view/addproduct.h \
    view/modifyproduct.h \
    view/searchinventory.h \
    view/table.h \
    view/tablezone.h \
    view/mainwindow.h \
    controller.h

RESOURCES += \
    Data/res.qrc
