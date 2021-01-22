/********************************************************************************
** Form generated from reading UI file 'keynumbers.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYNUMBERS_H
#define UI_KEYNUMBERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>

QT_BEGIN_NAMESPACE

class Ui_KeyNumbers
{
public:
    QLineEdit *le_text;
    QWidget *widget_keys;
    MyLabelAnimated *pb_ok;
    QLabel *label;

    void setupUi(QWidget *KeyNumbers)
    {
        if (KeyNumbers->objectName().isEmpty())
            KeyNumbers->setObjectName(QStringLiteral("KeyNumbers"));
        KeyNumbers->resize(316, 327);
        le_text = new QLineEdit(KeyNumbers);
        le_text->setObjectName(QStringLiteral("le_text"));
        le_text->setGeometry(QRect(30, 20, 211, 21));
        widget_keys = new QWidget(KeyNumbers);
        widget_keys->setObjectName(QStringLiteral("widget_keys"));
        widget_keys->setGeometry(QRect(30, 60, 211, 151));
        pb_ok = new MyLabelAnimated(KeyNumbers);
        pb_ok->setObjectName(QStringLiteral("pb_ok"));
        pb_ok->setGeometry(QRect(225, 220, 41, 41));
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
        label = new QLabel(KeyNumbers);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 311, 341));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/messagedialog.png")));
        label->setScaledContents(true);
        label->raise();
        le_text->raise();
        widget_keys->raise();
        pb_ok->raise();

        retranslateUi(KeyNumbers);

        QMetaObject::connectSlotsByName(KeyNumbers);
    } // setupUi

    void retranslateUi(QWidget *KeyNumbers)
    {
        KeyNumbers->setWindowTitle(QApplication::translate("KeyNumbers", "Form", nullptr));
        pb_ok->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class KeyNumbers: public Ui_KeyNumbers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYNUMBERS_H
