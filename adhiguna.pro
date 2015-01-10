#KBS AGP
QT       += network core webkitwidgets sql

TARGET = adhiguna
TEMPLATE = app
CONFIG += embed_manifest_dll \
          embed_manifest_exe

macx{
ICON += icon/icons.icns
}

win32{
ICON += icon/desktop.ico
}


OTHER_FILES += \
    bar-descriptor.xml \
    LICENSE.BSD \
    css/ign.css \
    js/adhiguna.js \
    js/builtin.js \
    js/include.js \
    js/jquery.js \
    js/skulpt.js

SOURCES += \
    main.cpp \
    adhiguna.cpp \
    adhigunadownload.cpp \
    adhigunamovedrag.cpp \
    adhigunanetwork.cpp \
    adhigunasql.cpp \
    adhigunasystem.cpp \
    fs.cpp \
    traynotificationwidget.cpp \
    traynotificationmanager.cpp

RESOURCES += \
    adg.qrc

HEADERS += \
    adhiguna.h \
    adhigunadownload.h \
    adhigunamovedrag.h \
    adhigunanetwork.h \
    adhigunasql.h \
    adhigunasystem.h \
    fs.h \
    traynotificationwidget.h \
    traynotificationmanager.h
