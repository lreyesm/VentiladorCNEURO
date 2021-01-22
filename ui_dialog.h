/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *widget;
    MyLabelAnimated *pb_ok;
    QLabel *label;
    QLabel *l_pregunta;
    QLabel *l_situacion;
    MyLabelAnimated *pb_cancel;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(801, 481);
        widget = new QWidget(Dialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(210, 140, 381, 201));
        pb_ok = new MyLabelAnimated(widget);
        pb_ok->setObjectName(QStringLiteral("pb_ok"));
        pb_ok->setGeometry(QRect(20, 150, 131, 31));
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
        label->setGeometry(QRect(0, 0, 381, 201));
        label->setFont(font);
        label->setStyleSheet(QLatin1String("QLabel {\n"
"background-color: rgb(35, 33, 30);\n"
"     border-radius: 10px;\n"
"     color: #E3E3E3\n"
" }"));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        l_pregunta = new QLabel(widget);
        l_pregunta->setObjectName(QStringLiteral("l_pregunta"));
        l_pregunta->setGeometry(QRect(10, 50, 361, 91));
        QFont font1;
        font1.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        l_pregunta->setFont(font1);
        l_pregunta->setStyleSheet(QStringLiteral("color: #E3E3E3"));
        l_pregunta->setAlignment(Qt::AlignCenter);
        l_situacion = new QLabel(widget);
        l_situacion->setObjectName(QStringLiteral("l_situacion"));
        l_situacion->setGeometry(QRect(10, 20, 361, 41));
        l_situacion->setFont(font1);
        l_situacion->setStyleSheet(QStringLiteral("color: #E3E3E3"));
        l_situacion->setAlignment(Qt::AlignCenter);
        pb_cancel = new MyLabelAnimated(widget);
        pb_cancel->setObjectName(QStringLiteral("pb_cancel"));
        pb_cancel->setGeometry(QRect(230, 150, 131, 31));
        pb_cancel->setFont(font);
        pb_cancel->setStyleSheet(QLatin1String("QLabel {\n"
"     border: 2px solid #E3E3E3;\n"
"     border-radius: 5px;\n"
"     color: #E3E3E3\n"
" }"));
        pb_cancel->setScaledContents(true);
        pb_cancel->setAlignment(Qt::AlignCenter);
        label->raise();
        pb_ok->raise();
        l_pregunta->raise();
        l_situacion->raise();
        pb_cancel->raise();

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        pb_ok->setText(QApplication::translate("Dialog", "ACEPTAR", nullptr));
        label->setText(QString());
        l_pregunta->setText(QApplication::translate("Dialog", "Pregunta", nullptr));
        l_situacion->setText(QApplication::translate("Dialog", "Situacion", nullptr));
        pb_cancel->setText(QApplication::translate("Dialog", "CANCELAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
