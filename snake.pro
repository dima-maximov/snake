#-------------------------------------------------
#
# Project created by QtCreator 2014-08-17T20:50:55
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = snake
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp
LIBS =  -lopencv_core -lopencv_imgproc -lopencv_highgui
