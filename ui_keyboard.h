/********************************************************************************
** Form generated from reading UI file 'keyboard.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYBOARD_H
#define UI_KEYBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KeyBoard
{
public:
    QWidget *widget_keys;
    QLabel *l_background;

    void setupUi(QWidget *KeyBoard)
    {
        if (KeyBoard->objectName().isEmpty())
            KeyBoard->setObjectName(QStringLiteral("KeyBoard"));
        KeyBoard->resize(801, 229);
        widget_keys = new QWidget(KeyBoard);
        widget_keys->setObjectName(QStringLiteral("widget_keys"));
        widget_keys->setGeometry(QRect(0, 0, 800, 228));
        QFont font;
        font.setFamily(QStringLiteral("DIN Pro"));
        font.setPointSize(10);
        widget_keys->setFont(font);
        l_background = new QLabel(KeyBoard);
        l_background->setObjectName(QStringLiteral("l_background"));
        l_background->setGeometry(QRect(-1, -1, 802, 230));
        l_background->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        l_background->setScaledContents(true);
        l_background->raise();
        widget_keys->raise();

        retranslateUi(KeyBoard);

        QMetaObject::connectSlotsByName(KeyBoard);
    } // setupUi

    void retranslateUi(QWidget *KeyBoard)
    {
        KeyBoard->setWindowTitle(QApplication::translate("KeyBoard", "Form", nullptr));
        l_background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class KeyBoard: public Ui_KeyBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOARD_H
