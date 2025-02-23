QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addoutpatientdlg.cpp \
    addpatientdlg.cpp \
    appointinfotable.cpp \
    appointmentdlg.cpp \
    chospitaloutpatient.cpp \
    cpatient.cpp \
    creception.cpp \
    deleteoutpatientdlg.cpp \
    deletepatientdlg.cpp \
    deletereceptiondlg.cpp \
    failfindoutpatientdlg.cpp \
    failfindreceptiondlg.cpp \
    failoutpatientfulldlg.cpp \
    hospitalinfotable.cpp \
    inquirereceptiondlg.cpp \
    logwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    outpatientinfotable.cpp \
    passworddlg.cpp \
    receptioninfotable.cpp \
    searchbyoutpatientdlg.cpp \
    searchbypatientnamedlg.cpp \
    searchbypatientphonedlg.cpp \
    successaddappointmentdlg.cpp \
    successdeleteoutpatientdlg.cpp \
    successdeletepatientdlg.cpp \
    successdeletereeptiondlg.cpp \
    warningdlg.cpp

HEADERS += \
    addoutpatientdlg.h \
    addpatientdlg.h \
    appointinfotable.h \
    appointmentdlg.h \
    chospitaloutpatient.h \
    cpatient.h \
    creception.h \
    deleteoutpatientdlg.h \
    deletepatientdlg.h \
    deletereceptiondlg.h \
    failfindoutpatientdlg.h \
    failfindreceptiondlg.h \
    failoutpatientfulldlg.h \
    hospitalinfotable.h \
    inquirereceptiondlg.h \
    logwidget.h \
    mainwindow.h \
    outpatientinfotable.h \
    passworddlg.h \
    receptioninfotable.h \
    searchbyoutpatientdlg.h \
    searchbypatientnamedlg.h \
    searchbypatientphonedlg.h \
    successaddappointmentdlg.h \
    successdeleteoutpatientdlg.h \
    successdeletepatientdlg.h \
    successdeletereeptiondlg.h \
    warningdlg.h

FORMS += \
    addoutpatientdlg.ui \
    addpatientdlg.ui \
    appointmentdlg.ui \
    deleteoutpatientdlg.ui \
    deletepatientdlg.ui \
    deletereceptiondlg.ui \
    failfindoutpatientdlg.ui \
    failfindreceptiondlg.ui \
    failoutpatientfulldlg.ui \
    inquirereceptiondlg.ui \
    logwidget.ui \
    mainwindow.ui \
    passworddlg.ui \
    searchbyoutpatientdlg.ui \
    searchbypatientnamedlg.ui \
    searchbypatientphonedlg.ui \
    successaddappointmentdlg.ui \
    successdeleteoutpatientdlg.ui \
    successdeletepatientdlg.ui \
    successdeletereeptiondlg.ui \
    warningdlg.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    HospitalImage.qrc

DISTFILES +=
