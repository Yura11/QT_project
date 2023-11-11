QT       += core gui
QT       +=sql
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog1.cpp \
    dialog2.cpp \
    dialog3.cpp \
    dialog4.cpp \
    main.cpp \
    mainwindow.cpp \
    registry.cpp \
    secondwindow.cpp \
    trainer1.cpp \
    trainer2.cpp \
    trainer3.cpp \
    trainer4.cpp

HEADERS += \
    dialog1.h \
    dialog2.h \
    dialog3.h \
    dialog4.h \
    mainwindow.h \
    registry.h \
    secondwindow.h \
    trainer1.h \
    trainer2.h \
    trainer3.h \
    trainer4.h

FORMS += \
    dialog1.ui \
    dialog2.ui \
    dialog3.ui \
    dialog4.ui \
    mainwindow.ui \
    registry.ui \
    secondwindow.ui \
    trainer1.ui \
    trainer2.ui \
    trainer3.ui \
    trainer4.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
    win32:RC_FILE = file.rc
