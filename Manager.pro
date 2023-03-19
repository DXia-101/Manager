QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dlg_ingredient.cpp \
    dlg_wares.cpp \
    ingredient.cpp \
    ingredienttable.cpp \
    ingredientwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    wares.cpp \
    warestable.cpp \
    wareswidget.cpp

HEADERS += \
    dlg_ingredient.h \
    dlg_wares.h \
    ingredient.h \
    ingredienttable.h \
    ingredientwidget.h \
    mainwindow.h \
    wares.h \
    warestable.h \
    wareswidget.h

FORMS += \
    dlg_ingredient.ui \
    dlg_wares.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
