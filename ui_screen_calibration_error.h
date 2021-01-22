/********************************************************************************
** Form generated from reading UI file 'screen_calibration_error.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREEN_CALIBRATION_ERROR_H
#define UI_SCREEN_CALIBRATION_ERROR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Screen_Calibration_Error
{
public:
    QLabel *label_2;
    QLabel *l_error_de_calibracion;
    QLabel *pb_apagar;
    QLabel *pb_modoAT;

    void setupUi(QWidget *Screen_Calibration_Error)
    {
        if (Screen_Calibration_Error->objectName().isEmpty())
            Screen_Calibration_Error->setObjectName(QStringLiteral("Screen_Calibration_Error"));
        Screen_Calibration_Error->resize(801, 481);
        label_2 = new QLabel(Screen_Calibration_Error);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(-1, -1, 802, 482));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(17, 21, 25);"));
        l_error_de_calibracion = new QLabel(Screen_Calibration_Error);
        l_error_de_calibracion->setObjectName(QStringLiteral("l_error_de_calibracion"));
        l_error_de_calibracion->setGeometry(QRect(225, 140, 350, 100));
        QFont font;
        font.setFamily(QStringLiteral("DIN Pro Bold"));
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        l_error_de_calibracion->setFont(font);
        l_error_de_calibracion->setStyleSheet(QLatin1String("QLabel {\n"
"	font: 75 18pt \"DIN Pro Bold\";\n"
"     border-radius: 10px;\n"
"     background-color: #DC0000;\n"
"     color: #FFFFFF\n"
" }"));
        l_error_de_calibracion->setScaledContents(true);
        l_error_de_calibracion->setAlignment(Qt::AlignCenter);
        pb_apagar = new QLabel(Screen_Calibration_Error);
        pb_apagar->setObjectName(QStringLiteral("pb_apagar"));
        pb_apagar->setGeometry(QRect(225, 310, 150, 50));
        QFont font1;
        font1.setFamily(QStringLiteral("DIN Pro Medium"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(7);
        pb_apagar->setFont(font1);
        pb_apagar->setStyleSheet(QLatin1String("QLabel {\n"
"	font: 57 18pt \"DIN Pro Medium\";\n"
"     border: 2px solid #FFFFFF;\n"
"     border-radius: 10px;\n"
"     color: #FFFFFF\n"
" }"));
        pb_apagar->setScaledContents(true);
        pb_apagar->setAlignment(Qt::AlignCenter);
        pb_modoAT = new QLabel(Screen_Calibration_Error);
        pb_modoAT->setObjectName(QStringLiteral("pb_modoAT"));
        pb_modoAT->setGeometry(QRect(425, 310, 151, 50));
        pb_modoAT->setFont(font1);
        pb_modoAT->setStyleSheet(QLatin1String("QLabel {\n"
"	font: 57 18pt \"DIN Pro Medium\";\n"
"     border: 2px solid #FFFFFF;\n"
"     border-radius: 10px;\n"
"     color: #FFFFFF\n"
" }"));
        pb_modoAT->setScaledContents(true);
        pb_modoAT->setAlignment(Qt::AlignCenter);

        retranslateUi(Screen_Calibration_Error);

        QMetaObject::connectSlotsByName(Screen_Calibration_Error);
    } // setupUi

    void retranslateUi(QWidget *Screen_Calibration_Error)
    {
        Screen_Calibration_Error->setWindowTitle(QApplication::translate("Screen_Calibration_Error", "Form", nullptr));
        label_2->setText(QString());
        l_error_de_calibracion->setText(QApplication::translate("Screen_Calibration_Error", "ERROR DE CALIBRACI\303\223N", nullptr));
        pb_apagar->setText(QApplication::translate("Screen_Calibration_Error", "APAGAR", nullptr));
        pb_modoAT->setText(QApplication::translate("Screen_Calibration_Error", "MODO AT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Screen_Calibration_Error: public Ui_Screen_Calibration_Error {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREEN_CALIBRATION_ERROR_H
