QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    date.cpp \
    loginwindow.cpp \
    main.cpp \
    person.cpp \
    professor.cpp \
    professormain.cpp \
    queryfunctions.cpp \
    student.cpp \
    studentmain.cpp

HEADERS += \
    date.h \
    loginwindow.h \
    person.h \
    professor.h \
    professormain.h \
    queryfunctions.h \
    student.h \
    studentmain.h

FORMS += \
    loginwindow.ui \
    professormain.ui \
    studentmain.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
