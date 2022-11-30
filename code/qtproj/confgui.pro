QT       += core gui

TARGET = app

OBJECTS_DIR = ../outfile

DESTDIR = ./

MOC_DIR = ../tmp

UI_DIR = ../tmp

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../src/codediff.cpp \
    ../src/confgui.cpp \
    ../src/fileshow.cpp \
    ../src/main.cpp \
    ../src/readoutput.cpp \
    ../src/recommend.cpp

HEADERS += \
    ../h/codediff.h \
    ../h/confgui.h \
    ../h/fileshow.h \
    ../h/readoutput.h \
    ../h/recommend.h

FORMS += \
    ../qtui/confgui.ui \
    ../qtui/fileshow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
