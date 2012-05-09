#-------------------------------------------------
#
# Project created by QtCreator 2012-05-02T12:11:41
#
#-------------------------------------------------

QT       += core gui rt

TARGET = PruebasSisOp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        receptormensajes.cpp

HEADERS  += mainwindow.h\
            receptormensajes.h\
            mq/comun.h

FORMS    += mainwindow.ui
 
LIBS     += -lrt
