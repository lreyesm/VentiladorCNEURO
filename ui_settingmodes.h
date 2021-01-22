/********************************************************************************
** Form generated from reading UI file 'settingmodes.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGMODES_H
#define UI_SETTINGMODES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>
#include <myradiobuttonanimated.h>

QT_BEGIN_NAMESPACE

class Ui_SettingModes
{
public:
    MyRadioButtonAnimated *l_pcv;
    MyRadioButtonAnimated *l_acv;
    MyLabelAnimated *l_ok;
    QLabel *l_title;
    QLabel *label;

    void setupUi(QWidget *SettingModes)
    {
        if (SettingModes->objectName().isEmpty())
            SettingModes->setObjectName(QStringLiteral("SettingModes"));
        SettingModes->resize(388, 240);
        l_pcv = new MyRadioButtonAnimated(SettingModes);
        l_pcv->setObjectName(QStringLiteral("l_pcv"));
        l_pcv->setGeometry(QRect(40, 45, 131, 81));
        QFont font;
        font.setFamily(QStringLiteral("DINPro-Medium"));
        font.setPointSize(40);
        font.setBold(true);
        font.setWeight(75);
        l_pcv->setFont(font);
        l_pcv->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_pcv->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        l_acv = new MyRadioButtonAnimated(SettingModes);
        l_acv->setObjectName(QStringLiteral("l_acv"));
        l_acv->setGeometry(QRect(180, 45, 131, 81));
        l_acv->setFont(font);
        l_acv->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
""));
        l_acv->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        l_ok = new MyLabelAnimated(SettingModes);
        l_ok->setObjectName(QStringLiteral("l_ok"));
        l_ok->setGeometry(QRect(310, 160, 40, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Quicksand Light"));
        l_ok->setFont(font1);
        l_ok->setStyleSheet(QStringLiteral(""));
        l_ok->setPixmap(QPixmap(QString::fromUtf8(":/icons/check.png")));
        l_ok->setScaledContents(true);
        l_title = new QLabel(SettingModes);
        l_title->setObjectName(QStringLiteral("l_title"));
        l_title->setGeometry(QRect(30, -30, 131, 31));
        QFont font2;
        font2.setPointSize(24);
        l_title->setFont(font2);
        l_title->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_title->setAlignment(Qt::AlignCenter);
        label = new QLabel(SettingModes);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 330, 181));
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
        l_pcv->raise();
        l_acv->raise();
        l_ok->raise();
        l_title->raise();

        retranslateUi(SettingModes);

        QMetaObject::connectSlotsByName(SettingModes);
    } // setupUi

    void retranslateUi(QWidget *SettingModes)
    {
        SettingModes->setWindowTitle(QApplication::translate("SettingModes", "Form", nullptr));
        l_pcv->setText(QApplication::translate("SettingModes", "VCV", nullptr));
        l_acv->setText(QApplication::translate("SettingModes", "VAC", nullptr));
        l_ok->setText(QString());
        l_title->setText(QApplication::translate("SettingModes", "...", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SettingModes: public Ui_SettingModes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGMODES_H
