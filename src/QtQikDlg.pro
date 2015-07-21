QT += core widgets serialport network xml
TEMPLATE = app
TARGET = 0_main_gui

SOURCES += \
    main.cpp \
    configure.cpp \
    homeform.cpp \
    mynofocusstyle.cpp \
    listviewdelegate.cpp \
    scheduleform.cpp \
    serialform.cpp \
    responder.cpp \
    httpform.cpp \
    qhttprequest.cpp \
    qhttpresponse.cpp \
    qhttpserver.cpp \
    qhttpconnection.cpp \
    http_parser.c \
    graph1form.cpp \
    graph2form.cpp \
    valuetableform.cpp \
    rawdataform.cpp

HEADERS += \
    configure.h \
    testtabbar.h \
    homeform.h \
    mynofocusstyle.h \
    listviewdelegate.h \
    scheduleform.h \
    header.h \
    define.h \
    serialform.h \
    responder.h \
    httpform.h \
    qhttpconnection.h \
    qhttprequest.h \
    qhttpresponse.h \
    qhttpserver.h \
    qhttpserverapi.h \
    qhttpserverfwd.h \
    http_parser.h \
    graph1form.h \
    graph2form.h \
    valuetableform.h \
    rawdataform.h

FORMS += \
    configure.ui \
    homeform.ui \
    scheduleform.ui \
    serialform.ui \
    httpform.ui \
    graph1form.ui \
    graph2form.ui \
    valuetableform.ui \
    rawdataform.ui

RESOURCES += \
    ess.qrc

DISTFILES +=
