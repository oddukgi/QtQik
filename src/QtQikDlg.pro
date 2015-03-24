
QT += widgets
TEMPLATE = app
TARGET = styles

SOURCES += \
    main.cpp \
    configure.cpp \
    pages.cpp \
    homeform.cpp
RESOURCES += styles.qrc
FORMS += \
    configure.ui \
    homeform.ui

HEADERS += \
    configure.h \
    testtabbar.h \
    pages.h \
    homeform.h
