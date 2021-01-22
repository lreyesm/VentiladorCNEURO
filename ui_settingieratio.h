/********************************************************************************
** Form generated from reading UI file 'settingieratio.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGIERATIO_H
#define UI_SETTINGIERATIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>
#include <mylabellongpressanimated.h>

QT_BEGIN_NAMESPACE

class Ui_SettingIERatio
{
public:
    QLabel *l_title;
    MyLabelLongPressAnimated *l_down;
    QLabel *l_value;
    MyLabelAnimated *l_ok;
    MyLabelLongPressAnimated *l_up;
    QLabel *label;
    MyLabelLongPressAnimated *l_down_ti;
    MyLabelLongPressAnimated *l_up_ti;
    QLabel *l_value_ti;
    QLabel *l_value_ti_2;
    QLabel *label_2;

    void setupUi(QWidget *SettingIERatio)
    {
        if (SettingIERatio->objectName().isEmpty())
            SettingIERatio->setObjectName(QStringLiteral("SettingIERatio"));
        SettingIERatio->resize(602, 267);
        l_title = new QLabel(SettingIERatio);
        l_title->setObjectName(QStringLiteral("l_title"));
        l_title->setGeometry(QRect(15, -40, 131, 31));
        QFont font;
        font.setPointSize(24);
        l_title->setFont(font);
        l_title->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_title->setAlignment(Qt::AlignCenter);
        l_down = new MyLabelLongPressAnimated(SettingIERatio);
        l_down->setObjectName(QStringLiteral("l_down"));
        l_down->setGeometry(QRect(330, 145, 61, 61));
        l_down->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_abajo.png")));
        l_down->setScaledContents(true);
        l_value = new QLabel(SettingIERatio);
        l_value->setObjectName(QStringLiteral("l_value"));
        l_value->setGeometry(QRect(370, 85, 171, 81));
        QFont font1;
        font1.setFamily(QStringLiteral("DIN Pro"));
        font1.setPointSize(40);
        font1.setBold(true);
        font1.setWeight(75);
        l_value->setFont(font1);
        l_value->setStyleSheet(QStringLiteral("color: rgb(194, 153, 209);"));
        l_value->setAlignment(Qt::AlignCenter);
        l_ok = new MyLabelAnimated(SettingIERatio);
        l_ok->setObjectName(QStringLiteral("l_ok"));
        l_ok->setGeometry(QRect(510, 185, 40, 40));
        l_ok->setPixmap(QPixmap(QString::fromUtf8(":/icons/check.png")));
        l_ok->setScaledContents(true);
        l_up = new MyLabelLongPressAnimated(SettingIERatio);
        l_up->setObjectName(QStringLiteral("l_up"));
        l_up->setGeometry(QRect(330, 55, 61, 61));
        l_up->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_arriba.png")));
        l_up->setScaledContents(true);
        label = new QLabel(SettingIERatio);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 35, 541, 201));
        QFont font2;
        font2.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font2.setPointSize(15);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        label->setFont(font2);
        label->setStyleSheet(QLatin1String("QLabel {\n"
"background-color: rgb(35, 33, 30);\n"
"     border-radius: 10px;\n"
"     color: #E3E3E3\n"
" }"));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        l_down_ti = new MyLabelLongPressAnimated(SettingIERatio);
        l_down_ti->setObjectName(QStringLiteral("l_down_ti"));
        l_down_ti->setGeometry(QRect(60, 145, 61, 61));
        l_down_ti->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_abajo.png")));
        l_down_ti->setScaledContents(true);
        l_up_ti = new MyLabelLongPressAnimated(SettingIERatio);
        l_up_ti->setObjectName(QStringLiteral("l_up_ti"));
        l_up_ti->setGeometry(QRect(60, 55, 61, 61));
        l_up_ti->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_arriba.png")));
        l_up_ti->setScaledContents(true);
        l_value_ti = new QLabel(SettingIERatio);
        l_value_ti->setObjectName(QStringLiteral("l_value_ti"));
        l_value_ti->setGeometry(QRect(100, 85, 151, 81));
        QFont font3;
        font3.setFamily(QStringLiteral("DIN Pro"));
        font3.setPointSize(50);
        font3.setBold(true);
        font3.setWeight(75);
        l_value_ti->setFont(font3);
        l_value_ti->setStyleSheet(QStringLiteral("color: rgb(194, 153, 209);"));
        l_value_ti->setAlignment(Qt::AlignCenter);
        l_value_ti_2 = new QLabel(SettingIERatio);
        l_value_ti_2->setObjectName(QStringLiteral("l_value_ti_2"));
        l_value_ti_2->setGeometry(QRect(230, 75, 31, 101));
        l_value_ti_2->setFont(font3);
        l_value_ti_2->setStyleSheet(QStringLiteral("color: rgb(194, 153, 209);"));
        l_value_ti_2->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(SettingIERatio);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(300, 60, 3, 151));
        label_2->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius: 1px"));
        label->raise();
        l_title->raise();
        l_value->raise();
        l_ok->raise();
        l_up->raise();
        l_down->raise();
        l_down_ti->raise();
        l_up_ti->raise();
        l_value_ti->raise();
        l_value_ti_2->raise();
        label_2->raise();

        retranslateUi(SettingIERatio);

        QMetaObject::connectSlotsByName(SettingIERatio);
    } // setupUi

    void retranslateUi(QWidget *SettingIERatio)
    {
        SettingIERatio->setWindowTitle(QApplication::translate("SettingIERatio", "Form", nullptr));
        l_title->setText(QApplication::translate("SettingIERatio", "...", nullptr));
        l_down->setText(QString());
        l_value->setText(QApplication::translate("SettingIERatio", "1:4.0", nullptr));
        l_ok->setText(QString());
        l_up->setText(QString());
        label->setText(QString());
        l_down_ti->setText(QString());
        l_up_ti->setText(QString());
        l_value_ti->setText(QApplication::translate("SettingIERatio", "0.2", nullptr));
        l_value_ti_2->setText(QApplication::translate("SettingIERatio", "s", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SettingIERatio: public Ui_SettingIERatio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGIERATIO_H
