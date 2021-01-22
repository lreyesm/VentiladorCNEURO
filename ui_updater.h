/********************************************************************************
** Form generated from reading UI file 'updater.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATER_H
#define UI_UPDATER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>
#include <mylabelstateanimated.h>

QT_BEGIN_NAMESPACE

class Ui_Updater
{
public:
    MyLabelStateAnimated *pb_update_raspberry_pi_qt;
    MyLabelStateAnimated *pb_update_arduino;
    QPlainTextEdit *plainTextEdit;
    QLabel *label;
    MyLabelStateAnimated *pb_close;
    QLabel *label_2;

    void setupUi(QWidget *Updater)
    {
        if (Updater->objectName().isEmpty())
            Updater->setObjectName(QStringLiteral("Updater"));
        Updater->resize(801, 481);
        pb_update_raspberry_pi_qt = new MyLabelStateAnimated(Updater);
        pb_update_raspberry_pi_qt->setObjectName(QStringLiteral("pb_update_raspberry_pi_qt"));
        pb_update_raspberry_pi_qt->setGeometry(QRect(90, 110, 291, 50));
        QFont font;
        font.setFamily(QStringLiteral("DIN Pro Medium"));
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(7);
        pb_update_raspberry_pi_qt->setFont(font);
        pb_update_raspberry_pi_qt->setStyleSheet(QLatin1String("QLabel {\n"
"	font: 57 18pt \"DIN Pro Medium\";\n"
"     border: 2px solid #FFFFFF;\n"
"     border-radius: 10px;\n"
"     color: #FFFFFF\n"
" }"));
        pb_update_raspberry_pi_qt->setScaledContents(true);
        pb_update_raspberry_pi_qt->setAlignment(Qt::AlignCenter);
        pb_update_arduino = new MyLabelStateAnimated(Updater);
        pb_update_arduino->setObjectName(QStringLiteral("pb_update_arduino"));
        pb_update_arduino->setGeometry(QRect(440, 110, 271, 50));
        pb_update_arduino->setFont(font);
        pb_update_arduino->setStyleSheet(QLatin1String("QLabel {\n"
"	font: 57 18pt \"DIN Pro Medium\";\n"
"     border: 2px solid #FFFFFF;\n"
"     border-radius: 10px;\n"
"     color: #FFFFFF\n"
" }"));
        pb_update_arduino->setScaledContents(true);
        pb_update_arduino->setAlignment(Qt::AlignCenter);
        plainTextEdit = new QPlainTextEdit(Updater);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(90, 220, 621, 191));
        plainTextEdit->setStyleSheet(QLatin1String("QPlainTextEdit {\n"
"	font: 57 15pt \"DIN Pro Cond Medium\";\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #24292E\n"
" }"));
        label = new QLabel(Updater);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 180, 59, 31));
        label->setStyleSheet(QLatin1String("font: 57 14pt \"DIN Pro Medium\";\n"
"     color: #FFFFFF"));
        pb_close = new MyLabelStateAnimated(Updater);
        pb_close->setObjectName(QStringLiteral("pb_close"));
        pb_close->setGeometry(QRect(20, 20, 51, 50));
        QFont font1;
        font1.setFamily(QStringLiteral("Droid Sans Fallback"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        pb_close->setFont(font1);
        pb_close->setStyleSheet(QLatin1String("QLabel {\n"
"     border: 2px solid #FFFFFF;\n"
"     border-radius: 25px;\n"
"     color: #FFFFFF\n"
" }"));
        pb_close->setScaledContents(true);
        pb_close->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Updater);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(-1, -1, 802, 482));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(17, 21, 25);"));
        label_2->raise();
        pb_update_raspberry_pi_qt->raise();
        pb_update_arduino->raise();
        plainTextEdit->raise();
        label->raise();
        pb_close->raise();

        retranslateUi(Updater);

        QMetaObject::connectSlotsByName(Updater);
    } // setupUi

    void retranslateUi(QWidget *Updater)
    {
        Updater->setWindowTitle(QApplication::translate("Updater", "Form", nullptr));
        pb_update_raspberry_pi_qt->setText(QApplication::translate("Updater", "Update Qt app", nullptr));
        pb_update_arduino->setText(QApplication::translate("Updater", "Update Arduino", nullptr));
        label->setText(QApplication::translate("Updater", "Log:", nullptr));
        pb_close->setText(QApplication::translate("Updater", "X", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Updater: public Ui_Updater {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATER_H
