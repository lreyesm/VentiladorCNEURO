/********************************************************************************
** Form generated from reading UI file 'settingparameter.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGPARAMETER_H
#define UI_SETTINGPARAMETER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>
#include <mylabellongpressanimated.h>

QT_BEGIN_NAMESPACE

class Ui_SettingParameter
{
public:
    QLabel *l_value;
    QLabel *l_title;
    MyLabelLongPressAnimated *l_up;
    MyLabelLongPressAnimated *l_down;
    QLabel *l_value_min;
    MyLabelLongPressAnimated *l_up_min;
    MyLabelLongPressAnimated *l_down_min;
    QLabel *l_value_2;
    QLabel *l_value_3;
    MyLabelAnimated *l_ok;
    QLabel *l_value_4;
    QLabel *l_value_5;
    QLabel *l_value_6;
    MyLabelLongPressAnimated *l_up_fio2;
    QLabel *l_value_fio2;
    MyLabelLongPressAnimated *l_down_fio2;
    QLabel *l_value_7;
    QLabel *l_value_8;
    QWidget *widget_capnography;
    MyLabelLongPressAnimated *l_down_etco2;
    QLabel *l_value_9;
    QLabel *l_value_10;
    MyLabelLongPressAnimated *l_up_etco2;
    QLabel *l_value_etco2;

    void setupUi(QWidget *SettingParameter)
    {
        if (SettingParameter->objectName().isEmpty())
            SettingParameter->setObjectName(QStringLiteral("SettingParameter"));
        SettingParameter->resize(300, 384);
        SettingParameter->setStyleSheet(QStringLiteral(""));
        l_value = new QLabel(SettingParameter);
        l_value->setObjectName(QStringLiteral("l_value"));
        l_value->setGeometry(QRect(140, 39, 45, 41));
        QFont font;
        font.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font.setPointSize(26);
        font.setBold(true);
        font.setWeight(75);
        l_value->setFont(font);
        l_value->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_value->setAlignment(Qt::AlignCenter);
        l_title = new QLabel(SettingParameter);
        l_title->setObjectName(QStringLiteral("l_title"));
        l_title->setGeometry(QRect(0, -30, 131, 31));
        QFont font1;
        font1.setPointSize(24);
        l_title->setFont(font1);
        l_title->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_title->setAlignment(Qt::AlignCenter);
        l_up = new MyLabelLongPressAnimated(SettingParameter);
        l_up->setObjectName(QStringLiteral("l_up"));
        l_up->setGeometry(QRect(180, 37, 45, 45));
        l_up->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_der.png")));
        l_up->setScaledContents(true);
        l_down = new MyLabelLongPressAnimated(SettingParameter);
        l_down->setObjectName(QStringLiteral("l_down"));
        l_down->setGeometry(QRect(100, 37, 45, 45));
        l_down->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_izq.png")));
        l_down->setScaledContents(true);
        l_value_min = new QLabel(SettingParameter);
        l_value_min->setObjectName(QStringLiteral("l_value_min"));
        l_value_min->setGeometry(QRect(140, 117, 45, 41));
        l_value_min->setFont(font);
        l_value_min->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_value_min->setAlignment(Qt::AlignCenter);
        l_up_min = new MyLabelLongPressAnimated(SettingParameter);
        l_up_min->setObjectName(QStringLiteral("l_up_min"));
        l_up_min->setGeometry(QRect(180, 117, 45, 45));
        l_up_min->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_der.png")));
        l_up_min->setScaledContents(true);
        l_down_min = new MyLabelLongPressAnimated(SettingParameter);
        l_down_min->setObjectName(QStringLiteral("l_down_min"));
        l_down_min->setGeometry(QRect(100, 117, 45, 45));
        l_down_min->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_izq.png")));
        l_down_min->setScaledContents(true);
        l_value_2 = new QLabel(SettingParameter);
        l_value_2->setObjectName(QStringLiteral("l_value_2"));
        l_value_2->setGeometry(QRect(30, 122, 64, 40));
        QFont font2;
        font2.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font2.setPointSize(25);
        font2.setBold(true);
        font2.setWeight(75);
        l_value_2->setFont(font2);
        l_value_2->setStyleSheet(QStringLiteral("color: rgb(255, 222, 99);"));
        l_value_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/peep_label.png")));
        l_value_2->setScaledContents(true);
        l_value_2->setAlignment(Qt::AlignCenter);
        l_value_3 = new QLabel(SettingParameter);
        l_value_3->setObjectName(QStringLiteral("l_value_3"));
        l_value_3->setGeometry(QRect(30, 42, 64, 40));
        l_value_3->setFont(font2);
        l_value_3->setStyleSheet(QStringLiteral("color: rgb(255, 222, 99);"));
        l_value_3->setPixmap(QPixmap(QString::fromUtf8(":/icons/pmax_label_2.png")));
        l_value_3->setScaledContents(true);
        l_value_3->setAlignment(Qt::AlignCenter);
        l_ok = new MyLabelAnimated(SettingParameter);
        l_ok->setObjectName(QStringLiteral("l_ok"));
        l_ok->setGeometry(QRect(90, 327, 141, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font3.setPointSize(15);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        l_ok->setFont(font3);
        l_ok->setStyleSheet(QLatin1String("QLabel {\n"
"     border: 2px solid #E3E3E3;\n"
"     border-radius: 5px;\n"
"     color: #E3E3E3\n"
" }"));
        l_ok->setScaledContents(true);
        l_ok->setAlignment(Qt::AlignCenter);
        l_value_4 = new QLabel(SettingParameter);
        l_value_4->setObjectName(QStringLiteral("l_value_4"));
        l_value_4->setGeometry(QRect(0, 20, 3, 360));
        l_value_4->setFont(font2);
        l_value_4->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        l_value_4->setAlignment(Qt::AlignCenter);
        l_value_5 = new QLabel(SettingParameter);
        l_value_5->setObjectName(QStringLiteral("l_value_5"));
        l_value_5->setGeometry(QRect(220, 130, 75, 25));
        QFont font4;
        font4.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font4.setPointSize(18);
        font4.setBold(true);
        font4.setWeight(75);
        l_value_5->setFont(font4);
        l_value_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_value_5->setPixmap(QPixmap(QString::fromUtf8(":/icons/cmH2O.png")));
        l_value_5->setScaledContents(true);
        l_value_5->setAlignment(Qt::AlignCenter);
        l_value_6 = new QLabel(SettingParameter);
        l_value_6->setObjectName(QStringLiteral("l_value_6"));
        l_value_6->setGeometry(QRect(220, 50, 75, 25));
        l_value_6->setFont(font4);
        l_value_6->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_value_6->setPixmap(QPixmap(QString::fromUtf8(":/icons/cmH2O.png")));
        l_value_6->setScaledContents(true);
        l_value_6->setAlignment(Qt::AlignCenter);
        l_up_fio2 = new MyLabelLongPressAnimated(SettingParameter);
        l_up_fio2->setObjectName(QStringLiteral("l_up_fio2"));
        l_up_fio2->setGeometry(QRect(180, 190, 45, 45));
        l_up_fio2->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_der.png")));
        l_up_fio2->setScaledContents(true);
        l_value_fio2 = new QLabel(SettingParameter);
        l_value_fio2->setObjectName(QStringLiteral("l_value_fio2"));
        l_value_fio2->setGeometry(QRect(140, 190, 45, 41));
        l_value_fio2->setFont(font);
        l_value_fio2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_value_fio2->setAlignment(Qt::AlignCenter);
        l_down_fio2 = new MyLabelLongPressAnimated(SettingParameter);
        l_down_fio2->setObjectName(QStringLiteral("l_down_fio2"));
        l_down_fio2->setGeometry(QRect(100, 190, 45, 45));
        l_down_fio2->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_izq.png")));
        l_down_fio2->setScaledContents(true);
        l_value_7 = new QLabel(SettingParameter);
        l_value_7->setObjectName(QStringLiteral("l_value_7"));
        l_value_7->setGeometry(QRect(220, 201, 61, 23));
        l_value_7->setFont(font4);
        l_value_7->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_value_7->setPixmap(QPixmap(QString::fromUtf8(":/icons/porciento.png")));
        l_value_7->setScaledContents(false);
        l_value_7->setAlignment(Qt::AlignCenter);
        l_value_8 = new QLabel(SettingParameter);
        l_value_8->setObjectName(QStringLiteral("l_value_8"));
        l_value_8->setGeometry(QRect(30, 199, 64, 31));
        QFont font5;
        font5.setFamily(QStringLiteral("DIN Pro"));
        font5.setPointSize(22);
        font5.setBold(true);
        font5.setWeight(75);
        l_value_8->setFont(font5);
        l_value_8->setStyleSheet(QStringLiteral("color: rgb(255, 222, 99);"));
        l_value_8->setPixmap(QPixmap(QString::fromUtf8(":/icons/FiO2.png")));
        l_value_8->setScaledContents(false);
        l_value_8->setAlignment(Qt::AlignCenter);
        widget_capnography = new QWidget(SettingParameter);
        widget_capnography->setObjectName(QStringLiteral("widget_capnography"));
        widget_capnography->setGeometry(QRect(20, 260, 271, 51));
        l_down_etco2 = new MyLabelLongPressAnimated(widget_capnography);
        l_down_etco2->setObjectName(QStringLiteral("l_down_etco2"));
        l_down_etco2->setGeometry(QRect(80, 0, 45, 45));
        l_down_etco2->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_izq.png")));
        l_down_etco2->setScaledContents(true);
        l_value_9 = new QLabel(widget_capnography);
        l_value_9->setObjectName(QStringLiteral("l_value_9"));
        l_value_9->setGeometry(QRect(10, 9, 64, 31));
        l_value_9->setFont(font5);
        l_value_9->setStyleSheet(QStringLiteral("color: rgb(255, 222, 99);"));
        l_value_9->setPixmap(QPixmap(QString::fromUtf8(":/icons/PCO2.png")));
        l_value_9->setScaledContents(false);
        l_value_9->setAlignment(Qt::AlignCenter);
        l_value_10 = new QLabel(widget_capnography);
        l_value_10->setObjectName(QStringLiteral("l_value_10"));
        l_value_10->setGeometry(QRect(210, 13, 61, 23));
        l_value_10->setFont(font4);
        l_value_10->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_value_10->setPixmap(QPixmap(QString::fromUtf8(":/icons/mmHg.png")));
        l_value_10->setScaledContents(false);
        l_value_10->setAlignment(Qt::AlignCenter);
        l_up_etco2 = new MyLabelLongPressAnimated(widget_capnography);
        l_up_etco2->setObjectName(QStringLiteral("l_up_etco2"));
        l_up_etco2->setGeometry(QRect(160, 0, 45, 45));
        l_up_etco2->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_der.png")));
        l_up_etco2->setScaledContents(true);
        l_value_etco2 = new QLabel(widget_capnography);
        l_value_etco2->setObjectName(QStringLiteral("l_value_etco2"));
        l_value_etco2->setGeometry(QRect(120, 0, 45, 41));
        l_value_etco2->setFont(font);
        l_value_etco2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_value_etco2->setAlignment(Qt::AlignCenter);
        l_value->raise();
        l_title->raise();
        l_value_min->raise();
        l_up_min->raise();
        l_down_min->raise();
        l_down->raise();
        l_up->raise();
        l_value_2->raise();
        l_value_3->raise();
        l_ok->raise();
        l_value_4->raise();
        l_value_5->raise();
        l_value_6->raise();
        l_up_fio2->raise();
        l_value_fio2->raise();
        l_down_fio2->raise();
        l_value_7->raise();
        l_value_8->raise();
        widget_capnography->raise();

        retranslateUi(SettingParameter);

        QMetaObject::connectSlotsByName(SettingParameter);
    } // setupUi

    void retranslateUi(QWidget *SettingParameter)
    {
        SettingParameter->setWindowTitle(QApplication::translate("SettingParameter", "Form", nullptr));
        l_value->setText(QApplication::translate("SettingParameter", "38", nullptr));
        l_title->setText(QApplication::translate("SettingParameter", "...", nullptr));
        l_up->setText(QString());
        l_down->setText(QString());
        l_value_min->setText(QApplication::translate("SettingParameter", "0", nullptr));
        l_up_min->setText(QString());
        l_down_min->setText(QString());
        l_value_2->setText(QString());
        l_value_3->setText(QString());
        l_ok->setText(QApplication::translate("SettingParameter", "ACEPTAR", nullptr));
        l_value_4->setText(QApplication::translate("SettingParameter", "PEEK", nullptr));
        l_value_5->setText(QString());
        l_value_6->setText(QString());
        l_up_fio2->setText(QString());
        l_value_fio2->setText(QApplication::translate("SettingParameter", "0", nullptr));
        l_down_fio2->setText(QString());
        l_value_7->setText(QString());
        l_value_8->setText(QString());
        l_down_etco2->setText(QString());
        l_value_9->setText(QString());
        l_value_10->setText(QString());
        l_up_etco2->setText(QString());
        l_value_etco2->setText(QApplication::translate("SettingParameter", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingParameter: public Ui_SettingParameter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGPARAMETER_H
