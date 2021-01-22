/********************************************************************************
** Form generated from reading UI file 'passwordrequest.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDREQUEST_H
#define UI_PASSWORDREQUEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>
#include <mylineedit.h>
#include <qlabel_button.h>

QT_BEGIN_NAMESPACE

class Ui_PasswordRequest
{
public:
    QWidget *widget;
    MyLabelAnimated *pb_ok;
    QLabel *label;
    QLabel *l_nombre_usuario;
    MyLineEdit *le_nombre_usuario;
    MyLineEdit *le_clave;
    QLabel *l_clave;
    MyLabelAnimated *pb_show_hide_password;
    QLabel_Button *l_background_blur;

    void setupUi(QWidget *PasswordRequest)
    {
        if (PasswordRequest->objectName().isEmpty())
            PasswordRequest->setObjectName(QStringLiteral("PasswordRequest"));
        PasswordRequest->resize(801, 481);
        widget = new QWidget(PasswordRequest);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(161, 80, 491, 251));
        pb_ok = new MyLabelAnimated(widget);
        pb_ok->setObjectName(QStringLiteral("pb_ok"));
        pb_ok->setGeometry(QRect(340, 200, 131, 31));
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
        label->setGeometry(QRect(0, 0, 491, 251));
        label->setFont(font);
        label->setStyleSheet(QLatin1String("QLabel {\n"
"background-color: rgb(35, 33, 30);\n"
"     border-radius: 10px;\n"
"     color: #E3E3E3\n"
" }"));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        l_nombre_usuario = new QLabel(widget);
        l_nombre_usuario->setObjectName(QStringLiteral("l_nombre_usuario"));
        l_nombre_usuario->setGeometry(QRect(45, 23, 401, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("DIN Pro"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        l_nombre_usuario->setFont(font1);
        l_nombre_usuario->setStyleSheet(QStringLiteral("color: #E3E3E3"));
        l_nombre_usuario->setAlignment(Qt::AlignCenter);
        le_nombre_usuario = new MyLineEdit(widget);
        le_nombre_usuario->setObjectName(QStringLiteral("le_nombre_usuario"));
        le_nombre_usuario->setGeometry(QRect(41, 50, 411, 31));
        le_nombre_usuario->setMinimumSize(QSize(0, 23));
        QFont font2;
        font2.setFamily(QStringLiteral("DIN Pro"));
        font2.setPointSize(14);
        le_nombre_usuario->setFont(font2);
        le_nombre_usuario->setStyleSheet(QLatin1String("QLineEdit {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #444444\n"
" }"));
        le_nombre_usuario->setAlignment(Qt::AlignCenter);
        le_clave = new MyLineEdit(widget);
        le_clave->setObjectName(QStringLiteral("le_clave"));
        le_clave->setGeometry(QRect(41, 136, 411, 31));
        le_clave->setMinimumSize(QSize(0, 23));
        le_clave->setFont(font2);
        le_clave->setStyleSheet(QLatin1String("QLineEdit {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #444444\n"
" }"));
        le_clave->setEchoMode(QLineEdit::Password);
        le_clave->setAlignment(Qt::AlignCenter);
        l_clave = new QLabel(widget);
        l_clave->setObjectName(QStringLiteral("l_clave"));
        l_clave->setGeometry(QRect(41, 110, 411, 20));
        l_clave->setFont(font1);
        l_clave->setStyleSheet(QStringLiteral("color: #E3E3E3"));
        l_clave->setAlignment(Qt::AlignCenter);
        pb_show_hide_password = new MyLabelAnimated(widget);
        pb_show_hide_password->setObjectName(QStringLiteral("pb_show_hide_password"));
        pb_show_hide_password->setGeometry(QRect(417, 137, 30, 30));
        pb_show_hide_password->setFont(font);
        pb_show_hide_password->setStyleSheet(QStringLiteral(""));
        pb_show_hide_password->setPixmap(QPixmap(QString::fromUtf8(":/icons/show.png")));
        pb_show_hide_password->setScaledContents(true);
        pb_show_hide_password->setAlignment(Qt::AlignCenter);
        label->raise();
        le_clave->raise();
        pb_ok->raise();
        pb_show_hide_password->raise();
        l_clave->raise();
        le_nombre_usuario->raise();
        l_nombre_usuario->raise();
        l_background_blur = new QLabel_Button(PasswordRequest);
        l_background_blur->setObjectName(QStringLiteral("l_background_blur"));
        l_background_blur->setGeometry(QRect(0, 0, 820, 500));
        l_background_blur->setPixmap(QPixmap(QString::fromUtf8(":/icons/menu_on.png")));
        l_background_blur->setScaledContents(true);
        l_background_blur->raise();
        widget->raise();

        retranslateUi(PasswordRequest);

        QMetaObject::connectSlotsByName(PasswordRequest);
    } // setupUi

    void retranslateUi(QWidget *PasswordRequest)
    {
        PasswordRequest->setWindowTitle(QApplication::translate("PasswordRequest", "Form", nullptr));
        pb_ok->setText(QApplication::translate("PasswordRequest", "ACEPTAR", nullptr));
        label->setText(QString());
        l_nombre_usuario->setText(QApplication::translate("PasswordRequest", "Usuario", nullptr));
        le_nombre_usuario->setText(QApplication::translate("PasswordRequest", "NEURONIC", nullptr));
        l_clave->setText(QApplication::translate("PasswordRequest", "Contrase\303\261a", nullptr));
        pb_show_hide_password->setText(QString());
        l_background_blur->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PasswordRequest: public Ui_PasswordRequest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDREQUEST_H
