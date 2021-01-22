/********************************************************************************
** Form generated from reading UI file 'messagedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEDIALOG_H
#define UI_MESSAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>

QT_BEGIN_NAMESPACE

class Ui_MessageDialog
{
public:
    QWidget *widget;
    MyLabelAnimated *pb_ok;
    QLabel *label;
    QLabel *l_descripcion;
    QLabel *l_alarma;

    void setupUi(QWidget *MessageDialog)
    {
        if (MessageDialog->objectName().isEmpty())
            MessageDialog->setObjectName(QStringLiteral("MessageDialog"));
        MessageDialog->resize(801, 481);
        widget = new QWidget(MessageDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(140, 140, 531, 201));
        pb_ok = new MyLabelAnimated(widget);
        pb_ok->setObjectName(QStringLiteral("pb_ok"));
        pb_ok->setGeometry(QRect(410, 160, 111, 31));
        QFont font;
        font.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font.setPointSize(15);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        pb_ok->setFont(font);
        pb_ok->setStyleSheet(QLatin1String("QLabel {\n"
"     border: 2px solid #E3E3E3;\n"
"     border-radius: 5px;\n"
"     color: #E3E3E3\n"
" }"));
        pb_ok->setScaledContents(true);
        pb_ok->setAlignment(Qt::AlignCenter);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 531, 201));
        label->setFont(font);
        label->setStyleSheet(QLatin1String("QLabel {\n"
"     background-color: rgb(35, 33, 30);\n"
"     border-radius: 10px;\n"
"     color: #E3E3E3\n"
" }"));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        l_descripcion = new QLabel(widget);
        l_descripcion->setObjectName(QStringLiteral("l_descripcion"));
        l_descripcion->setGeometry(QRect(10, 82, 511, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        l_descripcion->setFont(font1);
        l_descripcion->setStyleSheet(QStringLiteral("color: #E3E3E3"));
        l_descripcion->setAlignment(Qt::AlignCenter);
        l_alarma = new QLabel(widget);
        l_alarma->setObjectName(QStringLiteral("l_alarma"));
        l_alarma->setGeometry(QRect(10, 30, 511, 41));
        l_alarma->setFont(font1);
        l_alarma->setStyleSheet(QStringLiteral("color: #E3E3E3"));
        l_alarma->setAlignment(Qt::AlignCenter);
        label->raise();
        pb_ok->raise();
        l_descripcion->raise();
        l_alarma->raise();

        retranslateUi(MessageDialog);

        QMetaObject::connectSlotsByName(MessageDialog);
    } // setupUi

    void retranslateUi(QWidget *MessageDialog)
    {
        MessageDialog->setWindowTitle(QApplication::translate("MessageDialog", "Form", nullptr));
        pb_ok->setText(QApplication::translate("MessageDialog", "ACEPTAR", nullptr));
        label->setText(QString());
        l_descripcion->setText(QApplication::translate("MessageDialog", "Descripci\303\263n", nullptr));
        l_alarma->setText(QApplication::translate("MessageDialog", "Alarma", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessageDialog: public Ui_MessageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEDIALOG_H
