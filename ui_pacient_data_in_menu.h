/********************************************************************************
** Form generated from reading UI file 'pacient_data_in_menu.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PACIENT_DATA_IN_MENU_H
#define UI_PACIENT_DATA_IN_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>
#include <mylineedit.h>
#include <myplaintextedit.h>

QT_BEGIN_NAMESPACE

class Ui_Pacient_Data_in_Menu
{
public:
    MyLabelAnimated *pb_aceptar;
    QLabel *label_9;
    MyLineEdit *le_weight;
    QLabel *label_2;
    QLabel *label_14;
    MyLineEdit *le_CI_HC;
    QLabel *label_6;
    QLabel *label_11;
    QLabel *label_8;
    QLabel *label_4;
    MyLineEdit *le_sexo;
    MyLineEdit *le_edad;
    MyLineEdit *le_height;
    QLabel *label_10;
    MyLineEdit *le_nombre;
    MyPlainTextEdit *pt_comentarios;

    void setupUi(QWidget *Pacient_Data_in_Menu)
    {
        if (Pacient_Data_in_Menu->objectName().isEmpty())
            Pacient_Data_in_Menu->setObjectName(QStringLiteral("Pacient_Data_in_Menu"));
        Pacient_Data_in_Menu->resize(580, 355);
        pb_aceptar = new MyLabelAnimated(Pacient_Data_in_Menu);
        pb_aceptar->setObjectName(QStringLiteral("pb_aceptar"));
        pb_aceptar->setGeometry(QRect(420, 287, 131, 31));
        QFont font;
        font.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font.setPointSize(15);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        pb_aceptar->setFont(font);
        pb_aceptar->setStyleSheet(QLatin1String("QLabel {\n"
"     border: 2px solid #E3E3E3;\n"
"     border-radius: 5px;\n"
"     color: #E3E3E3\n"
" }"));
        pb_aceptar->setScaledContents(true);
        pb_aceptar->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(Pacient_Data_in_Menu);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(330, 84, 41, 24));
        label_9->setMaximumSize(QSize(100, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label_9->setFont(font1);
        label_9->setStyleSheet(QLatin1String("QLabel {\n"
"	 border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #24292E\n"
" }"));
        label_9->setAlignment(Qt::AlignCenter);
        le_weight = new MyLineEdit(Pacient_Data_in_Menu);
        le_weight->setObjectName(QStringLiteral("le_weight"));
        le_weight->setGeometry(QRect(470, 84, 51, 24));
        QFont font2;
        font2.setFamily(QStringLiteral("DIN Pro"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        le_weight->setFont(font2);
        le_weight->setStyleSheet(QLatin1String("QLineEdit {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #444444\n"
" }"));
        le_weight->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Pacient_Data_in_Menu);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 10, 91, 24));
        label_2->setMaximumSize(QSize(100, 16777215));
        label_2->setFont(font2);
        label_2->setStyleSheet(QLatin1String("QLabel {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #24292E\n"
" }"));
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(Pacient_Data_in_Menu);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(510, 84, 41, 24));
        label_14->setMaximumSize(QSize(100, 16777215));
        label_14->setFont(font1);
        label_14->setStyleSheet(QLatin1String("QLabel {\n"
"	 border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #24292E\n"
" }"));
        label_14->setAlignment(Qt::AlignCenter);
        le_CI_HC = new MyLineEdit(Pacient_Data_in_Menu);
        le_CI_HC->setObjectName(QStringLiteral("le_CI_HC"));
        le_CI_HC->setGeometry(QRect(126, 47, 245, 24));
        le_CI_HC->setFont(font2);
        le_CI_HC->setStyleSheet(QLatin1String("QLineEdit {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #444444\n"
" }"));
        label_6 = new QLabel(Pacient_Data_in_Menu);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 84, 111, 24));
        label_6->setMaximumSize(QSize(16777215, 16777215));
        label_6->setFont(font2);
        label_6->setStyleSheet(QLatin1String("QLabel {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #24292E\n"
" }"));
        label_6->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(Pacient_Data_in_Menu);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(390, 47, 100, 24));
        label_11->setMaximumSize(QSize(100, 16777215));
        label_11->setFont(font2);
        label_11->setStyleSheet(QLatin1String("QLabel {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #24292E\n"
" }"));
        label_11->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(Pacient_Data_in_Menu);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(210, 84, 91, 24));
        label_8->setMaximumSize(QSize(100, 16777215));
        label_8->setFont(font2);
        label_8->setStyleSheet(QLatin1String("QLabel {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #24292E\n"
" }"));
        label_8->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(Pacient_Data_in_Menu);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 47, 100, 24));
        label_4->setMaximumSize(QSize(100, 16777215));
        label_4->setFont(font2);
        label_4->setStyleSheet(QLatin1String("QLabel {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #24292E\n"
" }"));
        label_4->setAlignment(Qt::AlignCenter);
        le_sexo = new MyLineEdit(Pacient_Data_in_Menu);
        le_sexo->setObjectName(QStringLiteral("le_sexo"));
        le_sexo->setGeometry(QRect(470, 47, 81, 24));
        le_sexo->setFont(font2);
        le_sexo->setStyleSheet(QLatin1String("QLineEdit {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #444444\n"
" }"));
        le_sexo->setAlignment(Qt::AlignCenter);
        le_edad = new MyLineEdit(Pacient_Data_in_Menu);
        le_edad->setObjectName(QStringLiteral("le_edad"));
        le_edad->setGeometry(QRect(120, 84, 71, 24));
        le_edad->setFont(font2);
        le_edad->setStyleSheet(QLatin1String("QLineEdit {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #444444\n"
" }"));
        le_edad->setAlignment(Qt::AlignCenter);
        le_height = new MyLineEdit(Pacient_Data_in_Menu);
        le_height->setObjectName(QStringLiteral("le_height"));
        le_height->setGeometry(QRect(290, 84, 51, 24));
        le_height->setFont(font2);
        le_height->setStyleSheet(QLatin1String("QLineEdit {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #444444\n"
" }"));
        le_height->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(Pacient_Data_in_Menu);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(390, 84, 100, 24));
        label_10->setMaximumSize(QSize(100, 16777215));
        label_10->setFont(font2);
        label_10->setStyleSheet(QLatin1String("QLabel {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #24292E\n"
" }"));
        label_10->setAlignment(Qt::AlignCenter);
        le_nombre = new MyLineEdit(Pacient_Data_in_Menu);
        le_nombre->setObjectName(QStringLiteral("le_nombre"));
        le_nombre->setGeometry(QRect(117, 10, 434, 24));
        le_nombre->setFont(font2);
        le_nombre->setStyleSheet(QLatin1String("QLineEdit {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #444444\n"
" }"));
        pt_comentarios = new MyPlainTextEdit(Pacient_Data_in_Menu);
        pt_comentarios->setObjectName(QStringLiteral("pt_comentarios"));
        pt_comentarios->setGeometry(QRect(30, 130, 521, 120));
        pt_comentarios->setFont(font2);
        pt_comentarios->setStyleSheet(QLatin1String("QPlainTextEdit {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #444444\n"
" }"));
        pb_aceptar->raise();
        label_2->raise();
        label_6->raise();
        label_11->raise();
        label_8->raise();
        label_4->raise();
        label_10->raise();
        le_weight->raise();
        label_14->raise();
        le_height->raise();
        label_9->raise();
        le_edad->raise();
        le_CI_HC->raise();
        le_nombre->raise();
        le_sexo->raise();
        pt_comentarios->raise();

        retranslateUi(Pacient_Data_in_Menu);

        QMetaObject::connectSlotsByName(Pacient_Data_in_Menu);
    } // setupUi

    void retranslateUi(QWidget *Pacient_Data_in_Menu)
    {
        Pacient_Data_in_Menu->setWindowTitle(QApplication::translate("Pacient_Data_in_Menu", "Form", nullptr));
        pb_aceptar->setText(QApplication::translate("Pacient_Data_in_Menu", "ACEPTAR", nullptr));
        label_9->setText(QApplication::translate("Pacient_Data_in_Menu", "cm", nullptr));
        le_weight->setText(QString());
        label_2->setText(QApplication::translate("Pacient_Data_in_Menu", "Nombre: |", nullptr));
        label_14->setText(QApplication::translate("Pacient_Data_in_Menu", "kg", nullptr));
        le_CI_HC->setText(QString());
        label_6->setText(QApplication::translate("Pacient_Data_in_Menu", "Edad: |", nullptr));
        label_11->setText(QApplication::translate("Pacient_Data_in_Menu", "Sexo: |", nullptr));
        label_8->setText(QApplication::translate("Pacient_Data_in_Menu", "Talla: |", nullptr));
        label_4->setText(QApplication::translate("Pacient_Data_in_Menu", "CI:/HC: |", nullptr));
        le_sexo->setText(QString());
        le_edad->setText(QString());
        le_height->setText(QString());
        label_10->setText(QApplication::translate("Pacient_Data_in_Menu", "Peso: |", nullptr));
        le_nombre->setText(QString());
        pt_comentarios->setPlainText(QString());
    } // retranslateUi

};

namespace Ui {
    class Pacient_Data_in_Menu: public Ui_Pacient_Data_in_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACIENT_DATA_IN_MENU_H
