/********************************************************************************
** Form generated from reading UI file 'screen_modo_at.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREEN_MODO_AT_H
#define UI_SCREEN_MODO_AT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mylabelstateanimated.h>

QT_BEGIN_NAMESPACE

class Ui_Screen_Modo_AT
{
public:
    QLabel *label_2;
    QLabel *pb_modoAT;
    MyLabelStateAnimated *pb_update;
    MyLabelStateAnimated *pb_calibrate_pressure_s1;
    MyLabelStateAnimated *pb_calibrate_volumen;
    MyLabelStateAnimated *pb_calibrate_pressure_s2;
    MyLabelStateAnimated *pb_cerrar;
    QCheckBox *cb_capnography_state;
    QPushButton *pb_fluke_controller;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *rb_mark_4;
    QRadioButton *rb_ambu_silicona;
    QLabel *l_version;
    QLabel *label_5;

    void setupUi(QWidget *Screen_Modo_AT)
    {
        if (Screen_Modo_AT->objectName().isEmpty())
            Screen_Modo_AT->setObjectName(QStringLiteral("Screen_Modo_AT"));
        Screen_Modo_AT->resize(801, 481);
        label_2 = new QLabel(Screen_Modo_AT);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(-1, -1, 802, 482));
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg 2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(17, 21, 25);"));
        pb_modoAT = new QLabel(Screen_Modo_AT);
        pb_modoAT->setObjectName(QStringLiteral("pb_modoAT"));
        pb_modoAT->setGeometry(QRect(280, 20, 150, 50));
        QFont font1;
        font1.setFamily(QStringLiteral("DINPro-Medium"));
        font1.setPointSize(18);
        pb_modoAT->setFont(font1);
        pb_modoAT->setStyleSheet(QStringLiteral("color: rgb(227, 227, 227);"));
        pb_modoAT->setScaledContents(true);
        pb_modoAT->setAlignment(Qt::AlignCenter);
        pb_update = new MyLabelStateAnimated(Screen_Modo_AT);
        pb_update->setObjectName(QStringLiteral("pb_update"));
        pb_update->setGeometry(QRect(60, 270, 241, 50));
        QFont font2;
        font2.setFamily(QStringLiteral("DIN Pro Medium"));
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        pb_update->setFont(font2);
        pb_update->setStyleSheet(QLatin1String("QLabel {\n"
"     border: 3px solid #E3E3E3;\n"
"     border-radius: 5px;\n"
"     color: #E3E3E3\n"
" }"));
        pb_update->setScaledContents(true);
        pb_update->setAlignment(Qt::AlignCenter);
        pb_calibrate_pressure_s1 = new MyLabelStateAnimated(Screen_Modo_AT);
        pb_calibrate_pressure_s1->setObjectName(QStringLiteral("pb_calibrate_pressure_s1"));
        pb_calibrate_pressure_s1->setGeometry(QRect(420, 270, 241, 50));
        pb_calibrate_pressure_s1->setFont(font2);
        pb_calibrate_pressure_s1->setStyleSheet(QLatin1String("QLabel {\n"
"     border: 3px solid #E3E3E3;\n"
"     border-radius: 5px;\n"
"     color: #E3E3E3\n"
" }"));
        pb_calibrate_pressure_s1->setScaledContents(true);
        pb_calibrate_pressure_s1->setAlignment(Qt::AlignCenter);
        pb_calibrate_volumen = new MyLabelStateAnimated(Screen_Modo_AT);
        pb_calibrate_volumen->setObjectName(QStringLiteral("pb_calibrate_volumen"));
        pb_calibrate_volumen->setGeometry(QRect(60, 350, 241, 50));
        pb_calibrate_volumen->setFont(font2);
        pb_calibrate_volumen->setStyleSheet(QLatin1String("QLabel {\n"
"     border: 3px solid #E3E3E3;\n"
"     border-radius: 5px;\n"
"     color: #E3E3E3\n"
" }"));
        pb_calibrate_volumen->setScaledContents(true);
        pb_calibrate_volumen->setAlignment(Qt::AlignCenter);
        pb_calibrate_pressure_s2 = new MyLabelStateAnimated(Screen_Modo_AT);
        pb_calibrate_pressure_s2->setObjectName(QStringLiteral("pb_calibrate_pressure_s2"));
        pb_calibrate_pressure_s2->setGeometry(QRect(420, 350, 241, 50));
        pb_calibrate_pressure_s2->setFont(font2);
        pb_calibrate_pressure_s2->setStyleSheet(QLatin1String("QLabel {\n"
"     border: 3px solid #E3E3E3;\n"
"     border-radius: 5px;\n"
"     color: #E3E3E3\n"
" }"));
        pb_calibrate_pressure_s2->setScaledContents(true);
        pb_calibrate_pressure_s2->setAlignment(Qt::AlignCenter);
        pb_cerrar = new MyLabelStateAnimated(Screen_Modo_AT);
        pb_cerrar->setObjectName(QStringLiteral("pb_cerrar"));
        pb_cerrar->setGeometry(QRect(730, 20, 51, 50));
        QFont font3;
        font3.setFamily(QStringLiteral("Droid Sans Fallback"));
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        pb_cerrar->setFont(font3);
        pb_cerrar->setStyleSheet(QLatin1String("QLabel {\n"
"     border: 2px solid #FFFFFF;\n"
"     border-radius: 25px;\n"
"     color: #FFFFFF\n"
" }"));
        pb_cerrar->setScaledContents(true);
        pb_cerrar->setAlignment(Qt::AlignCenter);
        cb_capnography_state = new QCheckBox(Screen_Modo_AT);
        cb_capnography_state->setObjectName(QStringLiteral("cb_capnography_state"));
        cb_capnography_state->setGeometry(QRect(410, 120, 381, 41));
        QFont font4;
        font4.setFamily(QStringLiteral("DIN Pro"));
        font4.setPointSize(18);
        font4.setBold(true);
        font4.setWeight(75);
        cb_capnography_state->setFont(font4);
        cb_capnography_state->setStyleSheet(QLatin1String("QCheckBox {\n"
"    color: rgb(227, 227, 227); \n"
"	weight: 20px;\n"
"	height: 20px;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	image: url(:/icons/checked_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"	image: url(:/icons/checked_off.png);\n"
"}"));
        pb_fluke_controller = new QPushButton(Screen_Modo_AT);
        pb_fluke_controller->setObjectName(QStringLiteral("pb_fluke_controller"));
        pb_fluke_controller->setGeometry(QRect(700, 440, 80, 23));
        layoutWidget = new QWidget(Screen_Modo_AT);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 110, 297, 108));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        rb_mark_4 = new QRadioButton(layoutWidget);
        rb_mark_4->setObjectName(QStringLiteral("rb_mark_4"));
        QFont font5;
        font5.setFamily(QStringLiteral("DIN Pro"));
        font5.setPointSize(18);
        font5.setBold(false);
        font5.setWeight(50);
        rb_mark_4->setFont(font5);
        rb_mark_4->setStyleSheet(QLatin1String("QRadioButton{\n"
"    color: rgb(227, 227, 227); \n"
"	weight: 15px;\n"
"	height: 15px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"	image: url(:/icons/checked_on.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"	image: url(:/icons/checked_off.png);\n"
"}"));

        verticalLayout->addWidget(rb_mark_4);

        rb_ambu_silicona = new QRadioButton(layoutWidget);
        rb_ambu_silicona->setObjectName(QStringLiteral("rb_ambu_silicona"));
        QFont font6;
        font6.setFamily(QStringLiteral("DIN Pro"));
        font6.setPointSize(18);
        rb_ambu_silicona->setFont(font6);
        rb_ambu_silicona->setStyleSheet(QLatin1String("QRadioButton{\n"
"    color: rgb(227, 227, 227); \n"
"	weight: 15px;\n"
"	height: 15px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"	image: url(:/icons/checked_on.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"	image: url(:/icons/checked_off.png);\n"
"}"));

        verticalLayout->addWidget(rb_ambu_silicona);

        l_version = new QLabel(Screen_Modo_AT);
        l_version->setObjectName(QStringLiteral("l_version"));
        l_version->setGeometry(QRect(73, 0, 51, 32));
        QFont font7;
        font7.setFamily(QStringLiteral("DIN Pro"));
        font7.setPointSize(14);
        font7.setBold(true);
        font7.setWeight(75);
        l_version->setFont(font7);
        l_version->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_version->setPixmap(QPixmap(QString::fromUtf8(":/icons/version.png")));
        l_version->setScaledContents(false);
        label_5 = new QLabel(Screen_Modo_AT);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 0, 71, 32));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/icons/version.png")));
        label_5->setScaledContents(false);

        retranslateUi(Screen_Modo_AT);

        QMetaObject::connectSlotsByName(Screen_Modo_AT);
    } // setupUi

    void retranslateUi(QWidget *Screen_Modo_AT)
    {
        Screen_Modo_AT->setWindowTitle(QApplication::translate("Screen_Modo_AT", "Form", nullptr));
        label_2->setText(QString());
        pb_modoAT->setText(QApplication::translate("Screen_Modo_AT", "MODO AT", nullptr));
        pb_update->setText(QApplication::translate("Screen_Modo_AT", "Actualizar", nullptr));
        pb_calibrate_pressure_s1->setText(QApplication::translate("Screen_Modo_AT", "Sensor de Presi\303\263n 1", nullptr));
        pb_calibrate_volumen->setText(QApplication::translate("Screen_Modo_AT", "Calibrar Volumen", nullptr));
        pb_calibrate_pressure_s2->setText(QApplication::translate("Screen_Modo_AT", "Sensor de Presi\303\263n 2", nullptr));
        pb_cerrar->setText(QApplication::translate("Screen_Modo_AT", "X", nullptr));
        cb_capnography_state->setText(QApplication::translate("Screen_Modo_AT", "Capnograf\303\255a", nullptr));
        pb_fluke_controller->setText(QApplication::translate("Screen_Modo_AT", "Fluke", nullptr));
        rb_mark_4->setText(QApplication::translate("Screen_Modo_AT", "Mark 4 (700ml)", nullptr));
        rb_ambu_silicona->setText(QApplication::translate("Screen_Modo_AT", "Ambu Silicona (800ml)", nullptr));
        l_version->setText(QApplication::translate("Screen_Modo_AT", "...", nullptr));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Screen_Modo_AT: public Ui_Screen_Modo_AT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREEN_MODO_AT_H
