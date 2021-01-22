/********************************************************************************
** Form generated from reading UI file 'settingotherparameters.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGOTHERPARAMETERS_H
#define UI_SETTINGOTHERPARAMETERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>
#include <mylabellongpressanimated.h>

QT_BEGIN_NAMESPACE

class Ui_SettingOtherParameters
{
public:
    QLabel *l_value_trigger;
    MyLabelLongPressAnimated *l_down_trigger;
    MyLabelLongPressAnimated *l_down_plateau;
    QLabel *l_value_3;
    QLabel *l_value_5;
    QLabel *l_value_plateau;
    QLabel *l_value_4;
    MyLabelLongPressAnimated *l_up_plateau;
    QLabel *l_title;
    QLabel *l_value_6;
    MyLabelAnimated *l_ok;
    MyLabelLongPressAnimated *l_up_trigger;
    QLabel *l_value_2;
    QLabel *l_value_7;

    void setupUi(QWidget *SettingOtherParameters)
    {
        if (SettingOtherParameters->objectName().isEmpty())
            SettingOtherParameters->setObjectName(QStringLiteral("SettingOtherParameters"));
        SettingOtherParameters->resize(300, 384);
        l_value_trigger = new QLabel(SettingOtherParameters);
        l_value_trigger->setObjectName(QStringLiteral("l_value_trigger"));
        l_value_trigger->setGeometry(QRect(85, 80, 45, 41));
        QFont font;
        font.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        l_value_trigger->setFont(font);
        l_value_trigger->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_value_trigger->setAlignment(Qt::AlignCenter);
        l_down_trigger = new MyLabelLongPressAnimated(SettingOtherParameters);
        l_down_trigger->setObjectName(QStringLiteral("l_down_trigger"));
        l_down_trigger->setGeometry(QRect(30, 80, 45, 45));
        l_down_trigger->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_izq.png")));
        l_down_trigger->setScaledContents(true);
        l_down_plateau = new MyLabelLongPressAnimated(SettingOtherParameters);
        l_down_plateau->setObjectName(QStringLiteral("l_down_plateau"));
        l_down_plateau->setGeometry(QRect(30, 213, 45, 45));
        l_down_plateau->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_izq.png")));
        l_down_plateau->setScaledContents(true);
        l_value_3 = new QLabel(SettingOtherParameters);
        l_value_3->setObjectName(QStringLiteral("l_value_3"));
        l_value_3->setGeometry(QRect(45, 30, 131, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("DIN Pro"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        l_value_3->setFont(font1);
        l_value_3->setStyleSheet(QStringLiteral("color: rgb(255, 222, 99);"));
        l_value_3->setScaledContents(true);
        l_value_3->setAlignment(Qt::AlignCenter);
        l_value_5 = new QLabel(SettingOtherParameters);
        l_value_5->setObjectName(QStringLiteral("l_value_5"));
        l_value_5->setGeometry(QRect(170, 225, 71, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setWeight(75);
        l_value_5->setFont(font2);
        l_value_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_value_5->setPixmap(QPixmap(QString::fromUtf8(":/icons/seconds.png")));
        l_value_5->setScaledContents(false);
        l_value_5->setAlignment(Qt::AlignCenter);
        l_value_plateau = new QLabel(SettingOtherParameters);
        l_value_plateau->setObjectName(QStringLiteral("l_value_plateau"));
        l_value_plateau->setGeometry(QRect(70, 213, 79, 41));
        l_value_plateau->setFont(font);
        l_value_plateau->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_value_plateau->setAlignment(Qt::AlignCenter);
        l_value_4 = new QLabel(SettingOtherParameters);
        l_value_4->setObjectName(QStringLiteral("l_value_4"));
        l_value_4->setGeometry(QRect(0, 0, 3, 360));
        QFont font3;
        font3.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font3.setPointSize(25);
        font3.setBold(true);
        font3.setWeight(75);
        l_value_4->setFont(font3);
        l_value_4->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        l_value_4->setAlignment(Qt::AlignCenter);
        l_up_plateau = new MyLabelLongPressAnimated(SettingOtherParameters);
        l_up_plateau->setObjectName(QStringLiteral("l_up_plateau"));
        l_up_plateau->setGeometry(QRect(140, 213, 45, 45));
        l_up_plateau->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_der.png")));
        l_up_plateau->setScaledContents(true);
        l_title = new QLabel(SettingOtherParameters);
        l_title->setObjectName(QStringLiteral("l_title"));
        l_title->setGeometry(QRect(0, -50, 131, 31));
        QFont font4;
        font4.setPointSize(24);
        l_title->setFont(font4);
        l_title->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_title->setAlignment(Qt::AlignCenter);
        l_value_6 = new QLabel(SettingOtherParameters);
        l_value_6->setObjectName(QStringLiteral("l_value_6"));
        l_value_6->setGeometry(QRect(180, 91, 75, 25));
        l_value_6->setFont(font2);
        l_value_6->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_value_6->setPixmap(QPixmap(QString::fromUtf8(":/icons/cmH2O.png")));
        l_value_6->setScaledContents(true);
        l_value_6->setAlignment(Qt::AlignCenter);
        l_ok = new MyLabelAnimated(SettingOtherParameters);
        l_ok->setObjectName(QStringLiteral("l_ok"));
        l_ok->setGeometry(QRect(90, 307, 141, 31));
        QFont font5;
        font5.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font5.setPointSize(15);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        l_ok->setFont(font5);
        l_ok->setStyleSheet(QLatin1String("QLabel {\n"
"     border: 2px solid #E3E3E3;\n"
"     border-radius: 5px;\n"
"     color: #E3E3E3\n"
" }"));
        l_ok->setScaledContents(true);
        l_ok->setAlignment(Qt::AlignCenter);
        l_up_trigger = new MyLabelLongPressAnimated(SettingOtherParameters);
        l_up_trigger->setObjectName(QStringLiteral("l_up_trigger"));
        l_up_trigger->setGeometry(QRect(140, 80, 45, 45));
        l_up_trigger->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_der.png")));
        l_up_trigger->setScaledContents(true);
        l_value_2 = new QLabel(SettingOtherParameters);
        l_value_2->setObjectName(QStringLiteral("l_value_2"));
        l_value_2->setGeometry(QRect(35, 160, 71, 50));
        QFont font6;
        font6.setFamily(QStringLiteral("DIN Pro"));
        font6.setPointSize(25);
        font6.setBold(true);
        font6.setWeight(75);
        l_value_2->setFont(font6);
        l_value_2->setStyleSheet(QStringLiteral("color: rgb(255, 222, 99);"));
        l_value_2->setScaledContents(true);
        l_value_2->setAlignment(Qt::AlignCenter);
        l_value_7 = new QLabel(SettingOtherParameters);
        l_value_7->setObjectName(QStringLiteral("l_value_7"));
        l_value_7->setGeometry(QRect(75, 180, 81, 21));
        QFont font7;
        font7.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font7.setPointSize(16);
        font7.setBold(true);
        font7.setWeight(75);
        l_value_7->setFont(font7);
        l_value_7->setStyleSheet(QStringLiteral("color: rgb(255, 222, 99);"));
        l_value_7->setScaledContents(true);
        l_value_7->setAlignment(Qt::AlignCenter);
        l_value_trigger->raise();
        l_down_trigger->raise();
        l_down_plateau->raise();
        l_value_3->raise();
        l_value_plateau->raise();
        l_value_4->raise();
        l_up_plateau->raise();
        l_title->raise();
        l_value_6->raise();
        l_ok->raise();
        l_up_trigger->raise();
        l_value_2->raise();
        l_value_7->raise();
        l_value_5->raise();

        retranslateUi(SettingOtherParameters);

        QMetaObject::connectSlotsByName(SettingOtherParameters);
    } // setupUi

    void retranslateUi(QWidget *SettingOtherParameters)
    {
        SettingOtherParameters->setWindowTitle(QApplication::translate("SettingOtherParameters", "Form", nullptr));
        l_value_trigger->setText(QApplication::translate("SettingOtherParameters", "1", nullptr));
        l_down_trigger->setText(QString());
        l_down_plateau->setText(QString());
        l_value_3->setText(QApplication::translate("SettingOtherParameters", "Disparo", nullptr));
        l_value_5->setText(QString());
        l_value_plateau->setText(QApplication::translate("SettingOtherParameters", "0.1", nullptr));
        l_value_4->setText(QApplication::translate("SettingOtherParameters", "PEEK", nullptr));
        l_up_plateau->setText(QString());
        l_title->setText(QApplication::translate("SettingOtherParameters", "...", nullptr));
        l_value_6->setText(QString());
        l_ok->setText(QApplication::translate("SettingOtherParameters", "ACEPTAR", nullptr));
        l_up_trigger->setText(QString());
        l_value_2->setText(QApplication::translate("SettingOtherParameters", "T", nullptr));
        l_value_7->setText(QApplication::translate("SettingOtherParameters", "plateau", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingOtherParameters: public Ui_SettingOtherParameters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGOTHERPARAMETERS_H
