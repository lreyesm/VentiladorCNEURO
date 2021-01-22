/********************************************************************************
** Form generated from reading UI file 'widget_options.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_OPTIONS_H
#define UI_WIDGET_OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>
#include <mythreestateslabelanimated.h>

QT_BEGIN_NAMESPACE

class Ui_Widget_Options
{
public:
    QLabel *label;
    MyLabelAnimated *l_hide_menu;
    QWidget *widget_buttons;
    MyThreeStatesLabelAnimated *l_config_alarms;
    MyThreeStatesLabelAnimated *l_config_fecha_hora;
    MyThreeStatesLabelAnimated *l_download_data;
    MyThreeStatesLabelAnimated *l_pacient_data;
    MyThreeStatesLabelAnimated *l_log_information;
    MyThreeStatesLabelAnimated *l_otros_ajustes;
    MyThreeStatesLabelAnimated *l_calibracion_oxigeno;
    QPushButton *pb_power_off;

    void setupUi(QWidget *Widget_Options)
    {
        if (Widget_Options->objectName().isEmpty())
            Widget_Options->setObjectName(QStringLiteral("Widget_Options"));
        Widget_Options->resize(585, 415);
        label = new QLabel(Widget_Options);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 1, 585, 408));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/menu_on.png")));
        label->setScaledContents(false);
        l_hide_menu = new MyLabelAnimated(Widget_Options);
        l_hide_menu->setObjectName(QStringLiteral("l_hide_menu"));
        l_hide_menu->setGeometry(QRect(0, 0, 50, 50));
        l_hide_menu->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_izq.png")));
        l_hide_menu->setScaledContents(true);
        widget_buttons = new QWidget(Widget_Options);
        widget_buttons->setObjectName(QStringLiteral("widget_buttons"));
        widget_buttons->setGeometry(QRect(30, 40, 241, 341));
        l_config_alarms = new MyThreeStatesLabelAnimated(widget_buttons);
        l_config_alarms->setObjectName(QStringLiteral("l_config_alarms"));
        l_config_alarms->setGeometry(QRect(10, 10, 178, 24));
        l_config_alarms->setPixmap(QPixmap(QString::fromUtf8(":/icons/config_alarms_off.png")));
        l_config_alarms->setScaledContents(true);
        l_config_fecha_hora = new MyThreeStatesLabelAnimated(widget_buttons);
        l_config_fecha_hora->setObjectName(QStringLiteral("l_config_fecha_hora"));
        l_config_fecha_hora->setGeometry(QRect(10, 110, 209, 23));
        l_config_fecha_hora->setPixmap(QPixmap(QString::fromUtf8(":/icons/config_fecha_hora_off.png")));
        l_config_fecha_hora->setScaledContents(true);
        l_download_data = new MyThreeStatesLabelAnimated(widget_buttons);
        l_download_data->setObjectName(QStringLiteral("l_download_data"));
        l_download_data->setGeometry(QRect(10, 210, 174, 30));
        l_download_data->setPixmap(QPixmap(QString::fromUtf8(":/icons/download_data_off.png")));
        l_download_data->setScaledContents(true);
        l_pacient_data = new MyThreeStatesLabelAnimated(widget_buttons);
        l_pacient_data->setObjectName(QStringLiteral("l_pacient_data"));
        l_pacient_data->setGeometry(QRect(10, 160, 167, 23));
        l_pacient_data->setPixmap(QPixmap(QString::fromUtf8(":/icons/pacient_data_off.png")));
        l_pacient_data->setScaledContents(true);
        l_log_information = new MyThreeStatesLabelAnimated(widget_buttons);
        l_log_information->setObjectName(QStringLiteral("l_log_information"));
        l_log_information->setGeometry(QRect(7, 260, 197, 30));
        l_log_information->setPixmap(QPixmap(QString::fromUtf8(":/icons/log_information_off.png")));
        l_log_information->setScaledContents(true);
        l_otros_ajustes = new MyThreeStatesLabelAnimated(widget_buttons);
        l_otros_ajustes->setObjectName(QStringLiteral("l_otros_ajustes"));
        l_otros_ajustes->setGeometry(QRect(10, 60, 139, 27));
        l_otros_ajustes->setPixmap(QPixmap(QString::fromUtf8(":/icons/otros_ajustes_off.png")));
        l_otros_ajustes->setScaledContents(true);
        l_calibracion_oxigeno = new MyThreeStatesLabelAnimated(widget_buttons);
        l_calibracion_oxigeno->setObjectName(QStringLiteral("l_calibracion_oxigeno"));
        l_calibracion_oxigeno->setGeometry(QRect(7, 310, 226, 31));
        l_calibracion_oxigeno->setPixmap(QPixmap(QString::fromUtf8(":/icons/calibracion_oxigeno_off.png")));
        l_calibracion_oxigeno->setScaledContents(true);
        pb_power_off = new QPushButton(Widget_Options);
        pb_power_off->setObjectName(QStringLiteral("pb_power_off"));
        pb_power_off->setGeometry(QRect(170, 500, 80, 23));
        label->raise();
        widget_buttons->raise();
        l_hide_menu->raise();
        pb_power_off->raise();

        retranslateUi(Widget_Options);

        QMetaObject::connectSlotsByName(Widget_Options);
    } // setupUi

    void retranslateUi(QWidget *Widget_Options)
    {
        Widget_Options->setWindowTitle(QApplication::translate("Widget_Options", "Form", nullptr));
        label->setText(QString());
        l_hide_menu->setText(QString());
        l_config_alarms->setText(QString());
        l_config_fecha_hora->setText(QString());
        l_download_data->setText(QString());
        l_pacient_data->setText(QString());
        l_log_information->setText(QString());
        l_otros_ajustes->setText(QString());
        l_calibracion_oxigeno->setText(QString());
        pb_power_off->setText(QApplication::translate("Widget_Options", "Power off", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_Options: public Ui_Widget_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_OPTIONS_H
