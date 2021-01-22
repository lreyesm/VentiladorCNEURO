#-------------------------------------------------
#
# Project created by QtCreator 2020-05-12T00:31:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport printsupport network

TARGET = Ventilador
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    mylabelalarmanimated.cpp \
    mylabelanimated.cpp \
    mylabelstateanimated.cpp \
    mylabelstatetextanimated.cpp \
    mylineedit.cpp \
    myplaintextedit.cpp \
    mypointanimated.cpp \
    myradiobuttonanimated.cpp \
    mytextanimated.cpp \
    mywidgetalarmanimated.cpp \
    mywidgetanimated.cpp \
    pacient_data_in_menu.cpp \
    pacientclass.cpp \
    plot.cpp \
    processesclass.cpp \
    qcustomplot.cpp \
    qlabel_button.cpp \
    screen_apagado_sistema.cpp \
    screen_calibration_error.cpp \
    screen_calibration.cpp \
    screen_logo.cpp \
    screen_modo_at.cpp \
    screen_pacient_data.cpp \
    serialport.cpp \
    settingcenterparameters.cpp \
    settingieratio.cpp \
    settingmodes.cpp \
    settingparameter.cpp \
    messagedialog.cpp \
    butterworthlowpassfilter.cpp \
    checkserialmessage.cpp \
    datetimewidget.cpp \
    ieee_754_class.cpp \
    keyboard.cpp \
    widget_options.cpp \
    readtempds18b20class.cpp \
    updater.cpp \
    screen_datetime.cpp \
    mythreestateslabelanimated.cpp \
    log_information.cpp \
    download_data.cpp \
    tcp_server_controller.cpp \
    dialog.cpp \
    dialog_question.cpp \
    mylabellongpressanimated.cpp \
    mylabelalarmphotoanimated.cpp \
    mylabelstatetextalarmanimated.cpp \
    mylabelalarmphototextanimated.cpp \
    settingotherparameters.cpp \
    myfourstateslabelanimated.cpp \
    loadinganimation.cpp \
    QProgressIndicator.cpp \
    vt_communication_interface_wrapper.cpp \
    screenflukecontroller.cpp \
    optionsselector.cpp \
    passwordrequest.cpp

HEADERS  += mainwindow.h \
    mylabelalarmanimated.h \
    mylabelanimated.h \
    mylabelstateanimated.h \
    mylabelstatetextanimated.h \
    mylineedit.h \
    myplaintextedit.h \
    mypointanimated.h \
    myradiobuttonanimated.h \
    mytextanimated.h \
    mywidgetalarmanimated.h \
    mywidgetanimated.h \
    pacient_data_in_menu.h \
    pacientclass.h \
    plot.h \
    processesclass.h \
    qcustomplot.h \
    qlabel_button.h \
    screen_apagado_sistema.h \
    screen_calibration_error.h \
    screen_calibration.h \
    screen_logo.h \
    screen_modo_at.h \
    screen_pacient_data.h \
    serialport.h \
    settingcenterparameters.h \
    settingieratio.h \
    settingmodes.h \
    settingparameter.h \
    messagedialog.h \
    butterworthlowpassfilter.h \
    checkserialmessage.h \
    datetimewidget.h \
    globals_settings.h \
    ieee_754_class.h \
    keyboard.h \
    widget_options.h \
    readtempds18b20class.h \
    readtempds18b20class.h \
    updater.h \
    screen_datetime.h \
    mythreestateslabelanimated.h \
    log_information.h \
    download_data.h \
    tcp_server_controller.h \
    dialog.h \
    dialog_question.h \
    mylabellongpressanimated.h \
    mylabelalarmphotoanimated.h \
    mylabelstatetextalarmanimated.h \
    mylabelalarmphototextanimated.h \
    settingotherparameters.h \
    myfourstateslabelanimated.h \
    loadinganimation.h \
    QProgressIndicator.h \
    vt_communication_interface_wrapper.h \
    screenflukecontroller.h \
    optionsselector.h \
    passwordrequest.h

FORMS    += mainwindow.ui \
    pacient_data_in_menu.ui \
    screen_apagado_sistema.ui \
    screen_calibration_error.ui \
    screen_calibration.ui \
    screen_logo.ui \
    screen_modo_at.ui \
    screen_pacient_data.ui \
    settingcenterparameters.ui \
    settingieratio.ui \
    settingmodes.ui \
    settingparameter.ui \
    messagedialog.ui \
    datetimewidget.ui \
    keyboard.ui \
    widget_options.ui \
    screen_logo.ui \
    updater.ui \
    screen_datetime.ui \
    log_information.ui \
    download_data.ui \
    dialog.ui \
    dialog_question.ui \
    settingotherparameters.ui \
    loadinganimation.ui \
    screenflukecontroller.ui \
    optionsselector.ui \
    passwordrequest.ui

RESOURCES += \
    assets.qrc \
    Assets.qrc


DISTFILES +=
