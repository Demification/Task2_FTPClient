QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    QtNetwork/ftp_client_ozzylogik.cpp \
    QtNetwork/socket_shell.cpp \
    QtNetwork/tcp_client.cpp \
    gui_client.cpp \
    main.cpp

HEADERS += \
    QtNetwork/ftp_client_ozzylogik.h \
    QtNetwork/socket_shell.h \
    QtNetwork/tcp_client.h \
    gui_client.h

FORMS += \
    gui_client.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
