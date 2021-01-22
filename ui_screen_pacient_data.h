/********************************************************************************
** Form generated from reading UI file 'screen_pacient_data.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREEN_PACIENT_DATA_H
#define UI_SCREEN_PACIENT_DATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>
#include <mylineedit.h>
#include <myplaintextedit.h>

QT_BEGIN_NAMESPACE

class Ui_Screen_Pacient_Data
{
public:
    MyLabelAnimated *pb_aceptar;
    MyLabelAnimated *pb_ajustar_fecha_hora;
    QLabel *label_13;
    MyLineEdit *le_nombre;
    MyLineEdit *le_CI_HC;
    MyLineEdit *le_edad;
    MyLineEdit *le_height;
    MyLineEdit *le_weight;
    QLabel *label_9;
    QLabel *label_14;
    QLabel *label;
    QLabel *l_icon_comentarios;
    QLabel *label_11;
    MyLineEdit *le_sexo;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_4;
    MyPlainTextEdit *pt_comentarios;
    QLabel *l_version;
    QLabel *label_5;

    void setupUi(QWidget *Screen_Pacient_Data)
    {
        if (Screen_Pacient_Data->objectName().isEmpty())
            Screen_Pacient_Data->setObjectName(QStringLiteral("Screen_Pacient_Data"));
        Screen_Pacient_Data->resize(801, 481);
        pb_aceptar = new MyLabelAnimated(Screen_Pacient_Data);
        pb_aceptar->setObjectName(QStringLiteral("pb_aceptar"));
        pb_aceptar->setGeometry(QRect(540, 384, 160, 40));
        QFont font;
        font.setFamily(QStringLiteral("DIN Pro"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        pb_aceptar->setFont(font);
        pb_aceptar->setStyleSheet(QLatin1String("QLabel {\n"
"     border: 3px solid #E3E3E3;\n"
"     border-radius: 5px;\n"
"     color: #E3E3E3\n"
" }"));
        pb_aceptar->setScaledContents(true);
        pb_aceptar->setAlignment(Qt::AlignCenter);
        pb_ajustar_fecha_hora = new MyLabelAnimated(Screen_Pacient_Data);
        pb_ajustar_fecha_hora->setObjectName(QStringLiteral("pb_ajustar_fecha_hora"));
        pb_ajustar_fecha_hora->setGeometry(QRect(180, 384, 190, 40));
        pb_ajustar_fecha_hora->setFont(font);
        pb_ajustar_fecha_hora->setStyleSheet(QLatin1String("QLabel {\n"
"     border: 3px solid #E3E3E3;\n"
"     border-radius: 5px;\n"
"     color: #E3E3E3\n"
" }"));
        pb_ajustar_fecha_hora->setScaledContents(true);
        pb_ajustar_fecha_hora->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(Screen_Pacient_Data);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(0, 0, 802, 482));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        label_13->setFont(font1);
        label_13->setStyleSheet(QStringLiteral("background-color: rgb(17, 21, 25);"));
        le_nombre = new MyLineEdit(Screen_Pacient_Data);
        le_nombre->setObjectName(QStringLiteral("le_nombre"));
        le_nombre->setGeometry(QRect(267, 96, 434, 24));
        QFont font2;
        font2.setFamily(QStringLiteral("DIN Pro"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        le_nombre->setFont(font2);
        le_nombre->setStyleSheet(QLatin1String("QLineEdit {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #444444\n"
" }"));
        le_CI_HC = new MyLineEdit(Screen_Pacient_Data);
        le_CI_HC->setObjectName(QStringLiteral("le_CI_HC"));
        le_CI_HC->setGeometry(QRect(276, 133, 245, 24));
        le_CI_HC->setFont(font2);
        le_CI_HC->setStyleSheet(QLatin1String("QLineEdit {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #444444\n"
" }"));
        le_edad = new MyLineEdit(Screen_Pacient_Data);
        le_edad->setObjectName(QStringLiteral("le_edad"));
        le_edad->setGeometry(QRect(270, 170, 71, 24));
        le_edad->setFont(font2);
        le_edad->setStyleSheet(QLatin1String("QLineEdit {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #444444\n"
" }"));
        le_edad->setAlignment(Qt::AlignCenter);
        le_height = new MyLineEdit(Screen_Pacient_Data);
        le_height->setObjectName(QStringLiteral("le_height"));
        le_height->setGeometry(QRect(440, 170, 51, 24));
        le_height->setFont(font2);
        le_height->setStyleSheet(QLatin1String("QLineEdit {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #444444\n"
" }"));
        le_height->setAlignment(Qt::AlignCenter);
        le_weight = new MyLineEdit(Screen_Pacient_Data);
        le_weight->setObjectName(QStringLiteral("le_weight"));
        le_weight->setGeometry(QRect(620, 170, 61, 24));
        le_weight->setFont(font2);
        le_weight->setStyleSheet(QLatin1String("QLineEdit {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #444444\n"
" }"));
        le_weight->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(Screen_Pacient_Data);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(480, 170, 41, 24));
        label_9->setMaximumSize(QSize(100, 16777215));
        label_9->setFont(font2);
        label_9->setStyleSheet(QLatin1String("QLabel {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #24292E\n"
" }"));
        label_9->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(Screen_Pacient_Data);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(670, 170, 31, 24));
        label_14->setMaximumSize(QSize(100, 16777215));
        QFont font3;
        font3.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        label_14->setFont(font3);
        label_14->setStyleSheet(QLatin1String("QLabel {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #24292E\n"
" }"));
        label_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label = new QLabel(Screen_Pacient_Data);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 96, 60, 60));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/paciente.png")));
        label->setScaledContents(true);
        l_icon_comentarios = new QLabel(Screen_Pacient_Data);
        l_icon_comentarios->setObjectName(QStringLiteral("l_icon_comentarios"));
        l_icon_comentarios->setGeometry(QRect(100, 216, 61, 120));
        l_icon_comentarios->setStyleSheet(QStringLiteral("background-color: rgb(17, 21, 25);"));
        l_icon_comentarios->setPixmap(QPixmap(QString::fromUtf8(":/icons/comentarios.png")));
        l_icon_comentarios->setScaledContents(false);
        l_icon_comentarios->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_11 = new QLabel(Screen_Pacient_Data);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(540, 133, 100, 24));
        label_11->setMaximumSize(QSize(100, 16777215));
        label_11->setFont(font2);
        label_11->setStyleSheet(QLatin1String("QLabel {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #24292E\n"
" }"));
        label_11->setAlignment(Qt::AlignCenter);
        le_sexo = new MyLineEdit(Screen_Pacient_Data);
        le_sexo->setObjectName(QStringLiteral("le_sexo"));
        le_sexo->setGeometry(QRect(620, 133, 81, 24));
        le_sexo->setFont(font2);
        le_sexo->setStyleSheet(QLatin1String("QLineEdit {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #444444\n"
" }"));
        le_sexo->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Screen_Pacient_Data);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 96, 91, 24));
        label_2->setMaximumSize(QSize(100, 16777215));
        label_2->setFont(font3);
        label_2->setStyleSheet(QLatin1String("QLabel {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #24292E\n"
" }"));
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(Screen_Pacient_Data);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(180, 170, 111, 24));
        label_6->setMaximumSize(QSize(16777215, 16777215));
        label_6->setFont(font2);
        label_6->setStyleSheet(QLatin1String("QLabel {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #24292E\n"
" }"));
        label_6->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(Screen_Pacient_Data);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(360, 170, 91, 24));
        label_8->setMaximumSize(QSize(100, 16777215));
        label_8->setFont(font2);
        label_8->setStyleSheet(QLatin1String("QLabel {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #24292E\n"
" }"));
        label_8->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(Screen_Pacient_Data);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(540, 170, 100, 24));
        label_10->setMaximumSize(QSize(100, 16777215));
        label_10->setFont(font2);
        label_10->setStyleSheet(QLatin1String("QLabel {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #24292E\n"
" }"));
        label_10->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(Screen_Pacient_Data);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(180, 133, 100, 24));
        label_4->setMaximumSize(QSize(100, 16777215));
        label_4->setFont(font2);
        label_4->setStyleSheet(QLatin1String("QLabel {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #24292E\n"
" }"));
        label_4->setAlignment(Qt::AlignCenter);
        pt_comentarios = new MyPlainTextEdit(Screen_Pacient_Data);
        pt_comentarios->setObjectName(QStringLiteral("pt_comentarios"));
        pt_comentarios->setGeometry(QRect(180, 216, 521, 120));
        pt_comentarios->setFont(font3);
        pt_comentarios->setStyleSheet(QLatin1String("QPlainTextEdit {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #444444\n"
" }"));
        l_version = new QLabel(Screen_Pacient_Data);
        l_version->setObjectName(QStringLiteral("l_version"));
        l_version->setGeometry(QRect(73, 0, 51, 32));
        QFont font4;
        font4.setFamily(QStringLiteral("DIN Pro"));
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        l_version->setFont(font4);
        l_version->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_version->setPixmap(QPixmap(QString::fromUtf8(":/icons/version.png")));
        l_version->setScaledContents(false);
        label_5 = new QLabel(Screen_Pacient_Data);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 0, 71, 32));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/icons/version.png")));
        label_5->setScaledContents(false);
        label_13->raise();
        pb_aceptar->raise();
        pb_ajustar_fecha_hora->raise();
        label_2->raise();
        le_nombre->raise();
        label_6->raise();
        label_8->raise();
        label_10->raise();
        label_4->raise();
        le_CI_HC->raise();
        label->raise();
        le_height->raise();
        label_9->raise();
        le_edad->raise();
        label_11->raise();
        le_sexo->raise();
        pt_comentarios->raise();
        l_icon_comentarios->raise();
        le_weight->raise();
        label_14->raise();
        l_version->raise();
        label_5->raise();

        retranslateUi(Screen_Pacient_Data);

        QMetaObject::connectSlotsByName(Screen_Pacient_Data);
    } // setupUi

    void retranslateUi(QWidget *Screen_Pacient_Data)
    {
        Screen_Pacient_Data->setWindowTitle(QApplication::translate("Screen_Pacient_Data", "Form", nullptr));
        pb_aceptar->setText(QApplication::translate("Screen_Pacient_Data", "ACEPTAR", nullptr));
        pb_ajustar_fecha_hora->setText(QApplication::translate("Screen_Pacient_Data", "FECHA / HORA", nullptr));
        label_13->setText(QString());
        le_nombre->setText(QString());
        le_CI_HC->setText(QString());
        le_edad->setText(QString());
        le_height->setText(QString());
        le_weight->setText(QString());
        label_9->setText(QApplication::translate("Screen_Pacient_Data", "cm", nullptr));
        label_14->setText(QApplication::translate("Screen_Pacient_Data", "kg", nullptr));
        label->setText(QString());
        l_icon_comentarios->setText(QString());
        label_11->setText(QApplication::translate("Screen_Pacient_Data", "Sexo: |", nullptr));
        le_sexo->setText(QString());
        label_2->setText(QApplication::translate("Screen_Pacient_Data", "Nombre: |", nullptr));
        label_6->setText(QApplication::translate("Screen_Pacient_Data", "  Edad: |", nullptr));
        label_8->setText(QApplication::translate("Screen_Pacient_Data", "Talla: |", nullptr));
        label_10->setText(QApplication::translate("Screen_Pacient_Data", "Peso: |", nullptr));
        label_4->setText(QApplication::translate("Screen_Pacient_Data", " CI:/HC: |", nullptr));
        pt_comentarios->setPlainText(QString());
        l_version->setText(QApplication::translate("Screen_Pacient_Data", "...", nullptr));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Screen_Pacient_Data: public Ui_Screen_Pacient_Data {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREEN_PACIENT_DATA_H
