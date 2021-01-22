/********************************************************************************
** Form generated from reading UI file 'datetimewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATETIMEWIDGET_H
#define UI_DATETIMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>
#include <mylabellongpressanimated.h>

QT_BEGIN_NAMESPACE

class Ui_DateTimeWidget
{
public:
    QWidget *widget_days;
    MyLabelLongPressAnimated *l_down_minutes;
    MyLabelAnimated *pb_ok;
    QLabel *label_14;
    QLabel *l_month;
    MyLabelAnimated *l_am_pm;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_8;
    QLabel *l_year;
    MyLabelLongPressAnimated *l_up_minutes;
    MyLabelLongPressAnimated *l_up_year;
    QLabel *label_9;
    MyLabelLongPressAnimated *l_up_month;
    QLabel *label_12;
    MyLabelLongPressAnimated *l_up_hour;
    QLabel *label_13;
    MyLabelLongPressAnimated *l_down_month;
    MyLabelLongPressAnimated *l_down_year;
    MyLabelLongPressAnimated *l_down_hour;
    QLabel *l_minutes_2;
    QLabel *l_value_4;
    QLabel *l_hour;
    QLabel *l_minutes;

    void setupUi(QWidget *DateTimeWidget)
    {
        if (DateTimeWidget->objectName().isEmpty())
            DateTimeWidget->setObjectName(QStringLiteral("DateTimeWidget"));
        DateTimeWidget->resize(300, 400);
        DateTimeWidget->setStyleSheet(QStringLiteral(""));
        widget_days = new QWidget(DateTimeWidget);
        widget_days->setObjectName(QStringLiteral("widget_days"));
        widget_days->setGeometry(QRect(14, 110, 271, 151));
        l_down_minutes = new MyLabelLongPressAnimated(DateTimeWidget);
        l_down_minutes->setObjectName(QStringLiteral("l_down_minutes"));
        l_down_minutes->setGeometry(QRect(182, 325, 40, 40));
        l_down_minutes->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_abajo.png")));
        l_down_minutes->setScaledContents(true);
        pb_ok = new MyLabelAnimated(DateTimeWidget);
        pb_ok->setObjectName(QStringLiteral("pb_ok"));
        pb_ok->setGeometry(QRect(255, 355, 35, 35));
        QFont font;
        font.setFamily(QStringLiteral("Dosis"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        pb_ok->setFont(font);
        pb_ok->setStyleSheet(QStringLiteral("color: rgb(84, 84, 84);"));
        pb_ok->setPixmap(QPixmap(QString::fromUtf8(":/icons/check.png")));
        pb_ok->setScaledContents(true);
        pb_ok->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(DateTimeWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(229, 80, 21, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font1.setPointSize(16);
        label_14->setFont(font1);
        label_14->setStyleSheet(QStringLiteral("color: rgb(255, 222, 99);"));
        label_14->setAlignment(Qt::AlignCenter);
        l_month = new QLabel(DateTimeWidget);
        l_month->setObjectName(QStringLiteral("l_month"));
        l_month->setGeometry(QRect(82, 40, 125, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        l_month->setFont(font2);
        l_month->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_month->setAlignment(Qt::AlignCenter);
        l_am_pm = new MyLabelAnimated(DateTimeWidget);
        l_am_pm->setObjectName(QStringLiteral("l_am_pm"));
        l_am_pm->setGeometry(QRect(222, 300, 41, 41));
        QFont font3;
        font3.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font3.setPointSize(20);
        l_am_pm->setFont(font3);
        l_am_pm->setStyleSheet(QLatin1String("color: rgb(227, 227, 227);\n"
""));
        l_am_pm->setScaledContents(true);
        l_am_pm->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(DateTimeWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(109, 80, 21, 21));
        label_10->setFont(font1);
        label_10->setStyleSheet(QStringLiteral("color: rgb(255, 222, 99);"));
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(DateTimeWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(139, 80, 21, 21));
        label_11->setFont(font1);
        label_11->setStyleSheet(QStringLiteral("color: rgb(255, 222, 99);"));
        label_11->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(DateTimeWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(49, 80, 21, 21));
        label_8->setFont(font1);
        label_8->setStyleSheet(QStringLiteral("color: rgb(255, 222, 99);"));
        label_8->setAlignment(Qt::AlignCenter);
        l_year = new QLabel(DateTimeWidget);
        l_year->setObjectName(QStringLiteral("l_year"));
        l_year->setGeometry(QRect(120, 15, 51, 21));
        QFont font4;
        font4.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font4.setPointSize(16);
        font4.setBold(false);
        font4.setWeight(50);
        l_year->setFont(font4);
        l_year->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_year->setAlignment(Qt::AlignCenter);
        l_up_minutes = new MyLabelLongPressAnimated(DateTimeWidget);
        l_up_minutes->setObjectName(QStringLiteral("l_up_minutes"));
        l_up_minutes->setGeometry(QRect(182, 280, 40, 40));
        l_up_minutes->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_arriba.png")));
        l_up_minutes->setScaledContents(true);
        l_up_year = new MyLabelLongPressAnimated(DateTimeWidget);
        l_up_year->setObjectName(QStringLiteral("l_up_year"));
        l_up_year->setGeometry(QRect(170, 6, 40, 40));
        l_up_year->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_der.png")));
        l_up_year->setScaledContents(true);
        label_9 = new QLabel(DateTimeWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(79, 80, 21, 21));
        label_9->setFont(font1);
        label_9->setStyleSheet(QStringLiteral("color: rgb(255, 222, 99);"));
        label_9->setAlignment(Qt::AlignCenter);
        l_up_month = new MyLabelLongPressAnimated(DateTimeWidget);
        l_up_month->setObjectName(QStringLiteral("l_up_month"));
        l_up_month->setGeometry(QRect(200, 36, 40, 40));
        l_up_month->setMaximumSize(QSize(51, 53));
        l_up_month->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_der.png")));
        l_up_month->setScaledContents(true);
        label_12 = new QLabel(DateTimeWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(169, 80, 21, 21));
        label_12->setFont(font1);
        label_12->setStyleSheet(QStringLiteral("color: rgb(255, 222, 99);"));
        label_12->setAlignment(Qt::AlignCenter);
        l_up_hour = new MyLabelLongPressAnimated(DateTimeWidget);
        l_up_hour->setObjectName(QStringLiteral("l_up_hour"));
        l_up_hour->setGeometry(QRect(40, 280, 40, 40));
        l_up_hour->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_arriba.png")));
        l_up_hour->setScaledContents(true);
        label_13 = new QLabel(DateTimeWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(199, 80, 21, 21));
        label_13->setFont(font1);
        label_13->setStyleSheet(QStringLiteral("color: rgb(255, 222, 99);"));
        label_13->setAlignment(Qt::AlignCenter);
        l_down_month = new MyLabelLongPressAnimated(DateTimeWidget);
        l_down_month->setObjectName(QStringLiteral("l_down_month"));
        l_down_month->setGeometry(QRect(50, 36, 40, 40));
        l_down_month->setMaximumSize(QSize(51, 53));
        l_down_month->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_izq.png")));
        l_down_month->setScaledContents(true);
        l_down_year = new MyLabelLongPressAnimated(DateTimeWidget);
        l_down_year->setObjectName(QStringLiteral("l_down_year"));
        l_down_year->setGeometry(QRect(80, 6, 40, 40));
        l_down_year->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_izq.png")));
        l_down_year->setScaledContents(true);
        l_down_hour = new MyLabelLongPressAnimated(DateTimeWidget);
        l_down_hour->setObjectName(QStringLiteral("l_down_hour"));
        l_down_hour->setGeometry(QRect(40, 325, 40, 40));
        l_down_hour->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_abajo.png")));
        l_down_hour->setScaledContents(true);
        l_minutes_2 = new QLabel(DateTimeWidget);
        l_minutes_2->setObjectName(QStringLiteral("l_minutes_2"));
        l_minutes_2->setGeometry(QRect(105, 300, 51, 41));
        QFont font5;
        font5.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font5.setPointSize(24);
        l_minutes_2->setFont(font5);
        l_minutes_2->setStyleSheet(QLatin1String("color: rgb(227, 227, 227);\n"
""));
        l_minutes_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        l_value_4 = new QLabel(DateTimeWidget);
        l_value_4->setObjectName(QStringLiteral("l_value_4"));
        l_value_4->setGeometry(QRect(0, 20, 3, 360));
        QFont font6;
        font6.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font6.setPointSize(25);
        font6.setBold(true);
        font6.setWeight(75);
        l_value_4->setFont(font6);
        l_value_4->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        l_value_4->setAlignment(Qt::AlignCenter);
        l_hour = new QLabel(DateTimeWidget);
        l_hour->setObjectName(QStringLiteral("l_hour"));
        l_hour->setGeometry(QRect(70, 302, 51, 41));
        QFont font7;
        font7.setFamily(QStringLiteral("DIN Pro"));
        font7.setPointSize(20);
        l_hour->setFont(font7);
        l_hour->setStyleSheet(QLatin1String("color: rgb(255, 222, 99);\n"
""));
        l_hour->setAlignment(Qt::AlignCenter);
        l_minutes = new QLabel(DateTimeWidget);
        l_minutes->setObjectName(QStringLiteral("l_minutes"));
        l_minutes->setGeometry(QRect(140, 302, 51, 41));
        l_minutes->setFont(font7);
        l_minutes->setStyleSheet(QLatin1String("color: rgb(255, 222, 99);\n"
""));
        l_minutes->setAlignment(Qt::AlignCenter);

        retranslateUi(DateTimeWidget);

        QMetaObject::connectSlotsByName(DateTimeWidget);
    } // setupUi

    void retranslateUi(QWidget *DateTimeWidget)
    {
        DateTimeWidget->setWindowTitle(QApplication::translate("DateTimeWidget", "Form", nullptr));
        l_down_minutes->setText(QString());
        pb_ok->setText(QString());
        label_14->setText(QApplication::translate("DateTimeWidget", "S", nullptr));
        l_month->setText(QApplication::translate("DateTimeWidget", "NOVIEMBRE", nullptr));
        l_am_pm->setText(QApplication::translate("DateTimeWidget", "am", nullptr));
        label_10->setText(QApplication::translate("DateTimeWidget", "M", nullptr));
        label_11->setText(QApplication::translate("DateTimeWidget", "M", nullptr));
        label_8->setText(QApplication::translate("DateTimeWidget", "D", nullptr));
        l_year->setText(QApplication::translate("DateTimeWidget", "2020", nullptr));
        l_up_minutes->setText(QString());
        l_up_year->setText(QString());
        label_9->setText(QApplication::translate("DateTimeWidget", "L", nullptr));
        l_up_month->setText(QString());
        label_12->setText(QApplication::translate("DateTimeWidget", "J", nullptr));
        l_up_hour->setText(QString());
        label_13->setText(QApplication::translate("DateTimeWidget", "V", nullptr));
        l_down_month->setText(QString());
        l_down_year->setText(QString());
        l_down_hour->setText(QString());
        l_minutes_2->setText(QApplication::translate("DateTimeWidget", ":", nullptr));
        l_value_4->setText(QApplication::translate("DateTimeWidget", "PEEK", nullptr));
        l_hour->setText(QApplication::translate("DateTimeWidget", "12", nullptr));
        l_minutes->setText(QApplication::translate("DateTimeWidget", "00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DateTimeWidget: public Ui_DateTimeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATETIMEWIDGET_H
