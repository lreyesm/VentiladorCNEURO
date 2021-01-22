/********************************************************************************
** Form generated from reading UI file 'screen_logo.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREEN_LOGO_H
#define UI_SCREEN_LOGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <mylabelstateanimated.h>

QT_BEGIN_NAMESPACE

class Ui_Screen_Logo
{
public:
    QLabel *label;
    MyLabelStateAnimated *l_logo;
    QLabel *label_5;
    QLabel *l_version;

    void setupUi(QWidget *Screen_Logo)
    {
        if (Screen_Logo->objectName().isEmpty())
            Screen_Logo->setObjectName(QStringLiteral("Screen_Logo"));
        Screen_Logo->resize(801, 481);
        label = new QLabel(Screen_Logo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-1, -1, 802, 482));
        label->setStyleSheet(QStringLiteral("background-color: rgb(17, 21, 25);"));
        l_logo = new MyLabelStateAnimated(Screen_Logo);
        l_logo->setObjectName(QStringLiteral("l_logo"));
        l_logo->setGeometry(QRect(233, 125, 335, 55));
        l_logo->setPixmap(QPixmap(QString::fromUtf8(":/icons/neuronic.png")));
        l_logo->setScaledContents(true);
        label_5 = new QLabel(Screen_Logo);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 0, 71, 32));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/icons/version.png")));
        label_5->setScaledContents(false);
        l_version = new QLabel(Screen_Logo);
        l_version->setObjectName(QStringLiteral("l_version"));
        l_version->setGeometry(QRect(73, 0, 51, 32));
        QFont font;
        font.setFamily(QStringLiteral("DIN Pro"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        l_version->setFont(font);
        l_version->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_version->setPixmap(QPixmap(QString::fromUtf8(":/icons/version.png")));
        l_version->setScaledContents(false);

        retranslateUi(Screen_Logo);

        QMetaObject::connectSlotsByName(Screen_Logo);
    } // setupUi

    void retranslateUi(QWidget *Screen_Logo)
    {
        Screen_Logo->setWindowTitle(QApplication::translate("Screen_Logo", "Form", nullptr));
        label->setText(QString());
        l_logo->setText(QString());
        label_5->setText(QString());
        l_version->setText(QApplication::translate("Screen_Logo", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Screen_Logo: public Ui_Screen_Logo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREEN_LOGO_H
