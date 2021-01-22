/********************************************************************************
** Form generated from reading UI file 'screen_datetime.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREEN_DATETIME_H
#define UI_SCREEN_DATETIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>
#include <mylabellongpressanimated.h>
#include <mylabelstateanimated.h>

QT_BEGIN_NAMESPACE

class Ui_Screen_DateTime
{
public:
    QWidget *widget_days;
    QLabel *label_14;
    QLabel *l_month;
    MyLabelAnimated *l_am_pm;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_8;
    QLabel *l_year;
    QLabel *label_9;
    QLabel *l_minutes_2;
    QLabel *label_12;
    QLabel *label_13;
    MyLabelStateAnimated *pb_ok;
    QLabel *pb_ok_2;
    QLabel *l_minutes_3;
    QLabel *pb_ok_3;
    MyLabelLongPressAnimated *l_down_year;
    MyLabelLongPressAnimated *l_down_hour;
    MyLabelLongPressAnimated *l_down_minutes;
    MyLabelLongPressAnimated *l_up_year;
    MyLabelLongPressAnimated *l_up_month;
    MyLabelLongPressAnimated *l_up_hour;
    MyLabelLongPressAnimated *l_up_minutes;
    MyLabelLongPressAnimated *l_down_month;
    QLabel *label_2;
    QLineEdit *l_minutes;
    QLineEdit *l_hour;
    QLabel *l_version;
    QLabel *label_5;

    void setupUi(QWidget *Screen_DateTime)
    {
        if (Screen_DateTime->objectName().isEmpty())
            Screen_DateTime->setObjectName(QStringLiteral("Screen_DateTime"));
        Screen_DateTime->resize(801, 481);
        widget_days = new QWidget(Screen_DateTime);
        widget_days->setObjectName(QStringLiteral("widget_days"));
        widget_days->setGeometry(QRect(424, 190, 271, 151));
        label_14 = new QLabel(Screen_DateTime);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(639, 160, 21, 21));
        QFont font;
        font.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font.setPointSize(16);
        label_14->setFont(font);
        label_14->setStyleSheet(QStringLiteral("color: rgb(153, 235, 255);"));
        label_14->setAlignment(Qt::AlignCenter);
        l_month = new QLabel(Screen_DateTime);
        l_month->setObjectName(QStringLiteral("l_month"));
        l_month->setGeometry(QRect(495, 120, 131, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        l_month->setFont(font1);
        l_month->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_month->setAlignment(Qt::AlignCenter);
        l_am_pm = new MyLabelAnimated(Screen_DateTime);
        l_am_pm->setObjectName(QStringLiteral("l_am_pm"));
        l_am_pm->setGeometry(QRect(300, 210, 41, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font2.setPointSize(20);
        l_am_pm->setFont(font2);
        l_am_pm->setStyleSheet(QLatin1String("color: rgb(227, 227, 227);\n"
""));
        l_am_pm->setScaledContents(true);
        l_am_pm->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(Screen_DateTime);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(519, 160, 21, 21));
        label_10->setFont(font);
        label_10->setStyleSheet(QStringLiteral("color: rgb(153, 235, 255);"));
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(Screen_DateTime);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(549, 160, 21, 21));
        label_11->setFont(font);
        label_11->setStyleSheet(QStringLiteral("color: rgb(153, 235, 255);"));
        label_11->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(Screen_DateTime);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(459, 160, 21, 21));
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral("color: rgb(153, 235, 255);"));
        label_8->setAlignment(Qt::AlignCenter);
        l_year = new QLabel(Screen_DateTime);
        l_year->setObjectName(QStringLiteral("l_year"));
        l_year->setGeometry(QRect(533, 80, 51, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font3.setPointSize(17);
        font3.setBold(false);
        font3.setWeight(50);
        l_year->setFont(font3);
        l_year->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_year->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(Screen_DateTime);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(489, 160, 21, 21));
        label_9->setFont(font);
        label_9->setStyleSheet(QStringLiteral("color: rgb(153, 235, 255);"));
        label_9->setAlignment(Qt::AlignCenter);
        l_minutes_2 = new QLabel(Screen_DateTime);
        l_minutes_2->setObjectName(QStringLiteral("l_minutes_2"));
        l_minutes_2->setGeometry(QRect(210, 210, 51, 41));
        QFont font4;
        font4.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font4.setPointSize(24);
        l_minutes_2->setFont(font4);
        l_minutes_2->setStyleSheet(QLatin1String("color: rgb(227, 227, 227);\n"
""));
        l_minutes_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_12 = new QLabel(Screen_DateTime);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(579, 160, 21, 21));
        label_12->setFont(font);
        label_12->setStyleSheet(QStringLiteral("color: rgb(153, 235, 255);"));
        label_12->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(Screen_DateTime);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(609, 160, 21, 21));
        label_13->setFont(font);
        label_13->setStyleSheet(QStringLiteral("color: rgb(153, 235, 255);"));
        label_13->setAlignment(Qt::AlignCenter);
        pb_ok = new MyLabelStateAnimated(Screen_DateTime);
        pb_ok->setObjectName(QStringLiteral("pb_ok"));
        pb_ok->setGeometry(QRect(160, 360, 160, 41));
        QFont font5;
        font5.setFamily(QStringLiteral("DIN Pro Bold"));
        font5.setPointSize(16);
        pb_ok->setFont(font5);
        pb_ok->setStyleSheet(QLatin1String("QLabel {\n"
"	color: rgb(227, 227, 227);\n"
"     border: 2px solid #FFFFFF;\n"
"     border-radius: 5px;\n"
"\n"
" }"));
        pb_ok->setScaledContents(true);
        pb_ok->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        pb_ok_2 = new QLabel(Screen_DateTime);
        pb_ok_2->setObjectName(QStringLiteral("pb_ok_2"));
        pb_ok_2->setGeometry(QRect(160, 74, 160, 41));
        QFont font6;
        font6.setFamily(QStringLiteral("DIN Pro Bold"));
        font6.setPointSize(15);
        font6.setBold(false);
        font6.setItalic(false);
        font6.setWeight(50);
        pb_ok_2->setFont(font6);
        pb_ok_2->setStyleSheet(QLatin1String("QLabel {\n"
"     border-radius: 5px;\n"
"	background-color: rgb(153, 235, 255);\n"
"	color: rgb(36, 41, 46);\n"
" }"));
        pb_ok_2->setScaledContents(true);
        pb_ok_2->setAlignment(Qt::AlignCenter);
        l_minutes_3 = new QLabel(Screen_DateTime);
        l_minutes_3->setObjectName(QStringLiteral("l_minutes_3"));
        l_minutes_3->setGeometry(QRect(400, 120, 3, 241));
        l_minutes_3->setFont(font4);
        l_minutes_3->setStyleSheet(QStringLiteral("background-color: rgb(120, 120, 120);"));
        l_minutes_3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        pb_ok_3 = new QLabel(Screen_DateTime);
        pb_ok_3->setObjectName(QStringLiteral("pb_ok_3"));
        pb_ok_3->setGeometry(QRect(100, 210, 48, 48));
        QFont font7;
        font7.setFamily(QStringLiteral("DIN Pro Medium"));
        font7.setPointSize(15);
        pb_ok_3->setFont(font7);
        pb_ok_3->setStyleSheet(QStringLiteral(""));
        pb_ok_3->setPixmap(QPixmap(QString::fromUtf8(":/icons/clock.png")));
        pb_ok_3->setScaledContents(true);
        pb_ok_3->setAlignment(Qt::AlignCenter);
        l_down_year = new MyLabelLongPressAnimated(Screen_DateTime);
        l_down_year->setObjectName(QStringLiteral("l_down_year"));
        l_down_year->setGeometry(QRect(490, 75, 40, 40));
        l_down_year->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_izq.png")));
        l_down_year->setScaledContents(true);
        l_down_hour = new MyLabelLongPressAnimated(Screen_DateTime);
        l_down_hour->setObjectName(QStringLiteral("l_down_hour"));
        l_down_hour->setGeometry(QRect(175, 245, 40, 40));
        l_down_hour->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_abajo.png")));
        l_down_hour->setScaledContents(true);
        l_down_minutes = new MyLabelLongPressAnimated(Screen_DateTime);
        l_down_minutes->setObjectName(QStringLiteral("l_down_minutes"));
        l_down_minutes->setGeometry(QRect(255, 245, 40, 40));
        l_down_minutes->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_abajo.png")));
        l_down_minutes->setScaledContents(true);
        l_up_year = new MyLabelLongPressAnimated(Screen_DateTime);
        l_up_year->setObjectName(QStringLiteral("l_up_year"));
        l_up_year->setGeometry(QRect(588, 75, 40, 40));
        l_up_year->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_der.png")));
        l_up_year->setScaledContents(true);
        l_up_month = new MyLabelLongPressAnimated(Screen_DateTime);
        l_up_month->setObjectName(QStringLiteral("l_up_month"));
        l_up_month->setGeometry(QRect(613, 115, 40, 40));
        l_up_month->setMaximumSize(QSize(51, 53));
        l_up_month->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_der.png")));
        l_up_month->setScaledContents(true);
        l_up_hour = new MyLabelLongPressAnimated(Screen_DateTime);
        l_up_hour->setObjectName(QStringLiteral("l_up_hour"));
        l_up_hour->setGeometry(QRect(175, 180, 40, 40));
        l_up_hour->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_arriba.png")));
        l_up_hour->setScaledContents(true);
        l_up_minutes = new MyLabelLongPressAnimated(Screen_DateTime);
        l_up_minutes->setObjectName(QStringLiteral("l_up_minutes"));
        l_up_minutes->setGeometry(QRect(255, 180, 40, 40));
        l_up_minutes->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_arriba.png")));
        l_up_minutes->setScaledContents(true);
        l_down_month = new MyLabelLongPressAnimated(Screen_DateTime);
        l_down_month->setObjectName(QStringLiteral("l_down_month"));
        l_down_month->setGeometry(QRect(470, 115, 40, 40));
        l_down_month->setMaximumSize(QSize(51, 53));
        l_down_month->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_izq.png")));
        l_down_month->setScaledContents(true);
        label_2 = new QLabel(Screen_DateTime);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(-1, -1, 802, 482));
        QFont font8;
        font8.setFamily(QStringLiteral("MS Shell Dlg 2"));
        label_2->setFont(font8);
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(17, 21, 25);"));
        l_minutes = new QLineEdit(Screen_DateTime);
        l_minutes->setObjectName(QStringLiteral("l_minutes"));
        l_minutes->setGeometry(QRect(250, 212, 51, 41));
        QFont font9;
        font9.setFamily(QStringLiteral("DIN Pro"));
        font9.setPointSize(20);
        l_minutes->setFont(font9);
        l_minutes->setStyleSheet(QLatin1String("background-color: rgb(17, 21, 25);\n"
"border-radius: 5px;\n"
"color: rgb(153, 235, 255);"));
        l_minutes->setAlignment(Qt::AlignCenter);
        l_hour = new QLineEdit(Screen_DateTime);
        l_hour->setObjectName(QStringLiteral("l_hour"));
        l_hour->setGeometry(QRect(170, 212, 51, 41));
        l_hour->setFont(font9);
        l_hour->setStyleSheet(QLatin1String("background-color: rgb(17, 21, 25);\n"
"border-radius: 5px;\n"
"color: rgb(153, 235, 255);"));
        l_hour->setAlignment(Qt::AlignCenter);
        l_version = new QLabel(Screen_DateTime);
        l_version->setObjectName(QStringLiteral("l_version"));
        l_version->setGeometry(QRect(73, 0, 51, 32));
        QFont font10;
        font10.setFamily(QStringLiteral("DIN Pro"));
        font10.setPointSize(14);
        font10.setBold(true);
        font10.setWeight(75);
        l_version->setFont(font10);
        l_version->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_version->setPixmap(QPixmap(QString::fromUtf8(":/icons/version.png")));
        l_version->setScaledContents(false);
        label_5 = new QLabel(Screen_DateTime);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 0, 71, 32));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/icons/version.png")));
        label_5->setScaledContents(false);
        label_2->raise();
        widget_days->raise();
        label_14->raise();
        l_month->raise();
        l_am_pm->raise();
        label_10->raise();
        label_11->raise();
        label_8->raise();
        l_year->raise();
        label_9->raise();
        l_minutes_2->raise();
        label_12->raise();
        label_13->raise();
        pb_ok->raise();
        pb_ok_2->raise();
        l_minutes_3->raise();
        pb_ok_3->raise();
        l_down_year->raise();
        l_down_hour->raise();
        l_down_minutes->raise();
        l_up_year->raise();
        l_up_month->raise();
        l_up_hour->raise();
        l_up_minutes->raise();
        l_down_month->raise();
        l_minutes->raise();
        l_hour->raise();
        l_version->raise();
        label_5->raise();

        retranslateUi(Screen_DateTime);

        QMetaObject::connectSlotsByName(Screen_DateTime);
    } // setupUi

    void retranslateUi(QWidget *Screen_DateTime)
    {
        Screen_DateTime->setWindowTitle(QApplication::translate("Screen_DateTime", "Form", nullptr));
        label_14->setText(QApplication::translate("Screen_DateTime", "S", nullptr));
        l_month->setText(QApplication::translate("Screen_DateTime", "ENERO", nullptr));
        l_am_pm->setText(QApplication::translate("Screen_DateTime", "am", nullptr));
        label_10->setText(QApplication::translate("Screen_DateTime", "M", nullptr));
        label_11->setText(QApplication::translate("Screen_DateTime", "M", nullptr));
        label_8->setText(QApplication::translate("Screen_DateTime", "D", nullptr));
        l_year->setText(QApplication::translate("Screen_DateTime", "2020", nullptr));
        label_9->setText(QApplication::translate("Screen_DateTime", "L", nullptr));
        l_minutes_2->setText(QApplication::translate("Screen_DateTime", ":", nullptr));
        label_12->setText(QApplication::translate("Screen_DateTime", "J", nullptr));
        label_13->setText(QApplication::translate("Screen_DateTime", "V", nullptr));
        pb_ok->setText(QApplication::translate("Screen_DateTime", "ACEPTAR", nullptr));
        pb_ok_2->setText(QApplication::translate("Screen_DateTime", "FECHA / HORA", nullptr));
        l_minutes_3->setText(QString());
        pb_ok_3->setText(QString());
        l_down_year->setText(QString());
        l_down_hour->setText(QString());
        l_down_minutes->setText(QString());
        l_up_year->setText(QString());
        l_up_month->setText(QString());
        l_up_hour->setText(QString());
        l_up_minutes->setText(QString());
        l_down_month->setText(QString());
        label_2->setText(QString());
        l_minutes->setText(QApplication::translate("Screen_DateTime", "05", nullptr));
        l_hour->setText(QApplication::translate("Screen_DateTime", "9", nullptr));
        l_version->setText(QApplication::translate("Screen_DateTime", "...", nullptr));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Screen_DateTime: public Ui_Screen_DateTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREEN_DATETIME_H
