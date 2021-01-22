/********************************************************************************
** Form generated from reading UI file 'screen_apagado_sistema.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREEN_APAGADO_SISTEMA_H
#define UI_SCREEN_APAGADO_SISTEMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <mylabelstateanimated.h>

QT_BEGIN_NAMESPACE

class Ui_Screen_Apagado_Sistema
{
public:
    MyLabelStateAnimated *l_logo;
    QLabel *l_calibration_text_label;
    QLabel *label_2;

    void setupUi(QWidget *Screen_Apagado_Sistema)
    {
        if (Screen_Apagado_Sistema->objectName().isEmpty())
            Screen_Apagado_Sistema->setObjectName(QStringLiteral("Screen_Apagado_Sistema"));
        Screen_Apagado_Sistema->resize(801, 481);
        l_logo = new MyLabelStateAnimated(Screen_Apagado_Sistema);
        l_logo->setObjectName(QStringLiteral("l_logo"));
        l_logo->setGeometry(QRect(233, 125, 335, 55));
        l_logo->setPixmap(QPixmap(QString::fromUtf8(":/icons/neuronic.png")));
        l_logo->setScaledContents(true);
        l_calibration_text_label = new QLabel(Screen_Apagado_Sistema);
        l_calibration_text_label->setObjectName(QStringLiteral("l_calibration_text_label"));
        l_calibration_text_label->setGeometry(QRect(300, 281, 281, 34));
        QFont font;
        font.setFamily(QStringLiteral("DINPro-Light"));
        font.setPointSize(19);
        font.setBold(false);
        font.setWeight(50);
        font.setStyleStrategy(QFont::PreferAntialias);
        l_calibration_text_label->setFont(font);
        l_calibration_text_label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_calibration_text_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_2 = new QLabel(Screen_Apagado_Sistema);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(-1, -1, 802, 482));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(17, 21, 25);"));
        label_2->raise();
        l_calibration_text_label->raise();
        l_logo->raise();

        retranslateUi(Screen_Apagado_Sistema);

        QMetaObject::connectSlotsByName(Screen_Apagado_Sistema);
    } // setupUi

    void retranslateUi(QWidget *Screen_Apagado_Sistema)
    {
        Screen_Apagado_Sistema->setWindowTitle(QApplication::translate("Screen_Apagado_Sistema", "Form", nullptr));
        l_logo->setText(QString());
        l_calibration_text_label->setText(QApplication::translate("Screen_Apagado_Sistema", "Apagando Sistema", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Screen_Apagado_Sistema: public Ui_Screen_Apagado_Sistema {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREEN_APAGADO_SISTEMA_H
