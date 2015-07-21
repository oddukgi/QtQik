TARGET = bodydata

QT += network xml widgets serialport
#QT -= gui

CONFIG += debug

INCLUDEPATH += ../../src
LIBS += -L../../lib

win32 {
    debug: LIBS += -lqhttpserverd
    else: LIBS += -lqhttpserver
} else {
    LIBS += -lqhttpserver
}

SOURCES = \
    console.cpp \
    mainwindow.cpp \
    settingsdialog.cpp \
    responder.cpp \
    main.cpp \
    httpcomm.cpp
HEADERS = \
    console.h \
    mainwindow.h \
    settingsdialog.h \
    responder.h \
    httpcomm.h

FORMS += \
    mainwindow.ui \
    settingsdialog.ui

RESOURCES += \
    mainwindow.qrc
