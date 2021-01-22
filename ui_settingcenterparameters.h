/********************************************************************************
** Form generated from reading UI file 'settingcenterparameters.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGCENTERPARAMETERS_H
#define UI_SETTINGCENTERPARAMETERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>
#include <mylabellongpressanimated.h>

QT_BEGIN_NAMESPACE

class Ui_SettingCenterParameters
{
public:
    MyLabelAnimated *l_ok;
    MyLabelLongPressAnimated *l_up;
    MyLabelLongPressAnimated *l_down;
    QLabel *l_value;
    QLabel *l_title;
    QLabel *label;

    void setupUi(QWidget *SettingCenterParameters)
    {
        if (SettingCenterParameters->objectName().isEmpty())
            SettingCenterParameters->setObjectName(QStringLiteral("SettingCenterParameters"));
        SettingCenterParameters->resize(340, 283);
        l_ok = new MyLabelAnimated(SettingCenterParameters);
        l_ok->setObjectName(QStringLiteral("l_ok"));
        l_ok->setGeometry(QRect(255, 200, 40, 40));
        QFont font;
        font.setFamily(QStringLiteral("Piboto [Goog]"));
        l_ok->setFont(font);
        l_ok->setPixmap(QPixmap(QString::fromUtf8(":/icons/check.png")));
        l_ok->setScaledContents(true);
        l_up = new MyLabelLongPressAnimated(SettingCenterParameters);
        l_up->setObjectName(QStringLiteral("l_up"));
        l_up->setGeometry(QRect(235, 115, 60, 60));
        l_up->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_der.png")));
        l_up->setScaledContents(true);
        l_down = new MyLabelLongPressAnimated(SettingCenterParameters);
        l_down->setObjectName(QStringLiteral("l_down"));
        l_down->setGeometry(QRect(45, 115, 60, 60));
        l_down->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_izq.png")));
        l_down->setScaledContents(true);
        l_value = new QLabel(SettingCenterParameters);
        l_value->setObjectName(QStringLiteral("l_value"));
        l_value->setGeometry(QRect(100, 110, 141, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("DIN Pro"));
        font1.setPointSize(48);
        font1.setBold(true);
        font1.setWeight(75);
        l_value->setFont(font1);
        l_value->setStyleSheet(QStringLiteral("color: rgb(255, 222, 98);"));
        l_value->setAlignment(Qt::AlignCenter);
        l_title = new QLabel(SettingCenterParameters);
        l_title->setObjectName(QStringLiteral("l_title"));
        l_title->setGeometry(QRect(0, -30, 131, 31));
        QFont font2;
        font2.setPointSize(24);
        l_title->setFont(font2);
        l_title->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_title->setAlignment(Qt::AlignCenter);
        label = new QLabel(SettingCenterParameters);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(35, 40, 271, 211));
        QFont font3;
        font3.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font3.setPointSize(15);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        label->setFont(font3);
        label->setStyleSheet(QLatin1String("QLabel {\n"
"background-color: rgb(35, 33, 30);\n"
"     border-radius: 10px;\n"
"     color: #E3E3E3\n"
" }"));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        label->raise();
        l_up->raise();
        l_down->raise();
        l_ok->raise();
        l_value->raise();
        l_title->raise();

        retranslateUi(SettingCenterParameters);

        QMetaObject::connectSlotsByName(SettingCenterParameters);
    } // setupUi

    void retranslateUi(QWidget *SettingCenterParameters)
    {
        SettingCenterParameters->setWindowTitle(QApplication::translate("SettingCenterParameters", "Form", nullptr));
        l_ok->setText(QString());
        l_up->setText(QString());
        l_down->setText(QString());
        l_value->setText(QApplication::translate("SettingCenterParameters", "30", nullptr));
        l_title->setText(QApplication::translate("SettingCenterParameters", "...", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SettingCenterParameters: public Ui_SettingCenterParameters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGCENTERPARAMETERS_H
