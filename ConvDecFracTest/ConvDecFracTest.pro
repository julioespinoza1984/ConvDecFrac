QT += testlib
QT -= gui

TARGET = ConvDecFracTest
TEMPLATE = app

CONFIG += c++11
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

INCLUDEPATH += source \
    ../ConvDecFracCore/source

SOURCES +=  source/testsuite.cpp \
    source/main.cpp \
    source/model/decimalfractiontest.cpp

HEADERS += \
    source/testsuite.h \
    source/model/decimalfractiontest.h

LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lConvDecFracCore

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

