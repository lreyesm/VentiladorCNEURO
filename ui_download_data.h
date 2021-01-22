/********************************************************************************
** Form generated from reading UI file 'download_data.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOAD_DATA_H
#define UI_DOWNLOAD_DATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>
#include <mythreestateslabelanimated.h>

QT_BEGIN_NAMESPACE

class Ui_Download_Data
{
public:
    MyThreeStatesLabelAnimated *l_descargar_todos;
    MyThreeStatesLabelAnimated *l_descargar_paciente;
    QLabel *label;
    QListWidget *listWidget;
    MyLabelAnimated *l_eject_memory;
    MyLabelAnimated *l_down_trigger;
    QLabel *l_page;
    MyLabelAnimated *l_up_trigger;

    void setupUi(QWidget *Download_Data)
    {
        if (Download_Data->objectName().isEmpty())
            Download_Data->setObjectName(QStringLiteral("Download_Data"));
        Download_Data->resize(582, 371);
        Download_Data->setMaximumSize(QSize(16777215, 16777215));
        l_descargar_todos = new MyThreeStatesLabelAnimated(Download_Data);
        l_descargar_todos->setObjectName(QStringLiteral("l_descargar_todos"));
        l_descargar_todos->setGeometry(QRect(34, 320, 189, 32));
        l_descargar_todos->setPixmap(QPixmap(QString::fromUtf8(":/icons/descargar_todos_off.png")));
        l_descargar_todos->setScaledContents(true);
        l_descargar_paciente = new MyThreeStatesLabelAnimated(Download_Data);
        l_descargar_paciente->setObjectName(QStringLiteral("l_descargar_paciente"));
        l_descargar_paciente->setGeometry(QRect(343, 323, 210, 31));
        l_descargar_paciente->setPixmap(QPixmap(QString::fromUtf8(":/icons/descargar_paciente_off.png")));
        l_descargar_paciente->setScaledContents(true);
        label = new QLabel(Download_Data);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 10, 221, 24));
        QFont font;
        font.setFamily(QStringLiteral("DIN Pro"));
        font.setPointSize(16);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(227, 227, 227);"));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        listWidget = new QListWidget(Download_Data);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(19, 54, 541, 251));
        QFont font1;
        font1.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font1.setPointSize(14);
        listWidget->setFont(font1);
        listWidget->setStyleSheet(QLatin1String("QListWidget {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #444444\n"
" }\n"
""));
        listWidget->setMovement(QListView::Static);
        listWidget->setSpacing(2);
        l_eject_memory = new MyLabelAnimated(Download_Data);
        l_eject_memory->setObjectName(QStringLiteral("l_eject_memory"));
        l_eject_memory->setGeometry(QRect(510, 0, 40, 40));
        QFont font2;
        font2.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font2.setPointSize(16);
        l_eject_memory->setFont(font2);
        l_eject_memory->setStyleSheet(QStringLiteral("color: rgb(227, 227, 227);"));
        l_eject_memory->setPixmap(QPixmap(QString::fromUtf8(":/icons/eject.png")));
        l_eject_memory->setScaledContents(true);
        l_eject_memory->setAlignment(Qt::AlignCenter);
        l_down_trigger = new MyLabelAnimated(Download_Data);
        l_down_trigger->setObjectName(QStringLiteral("l_down_trigger"));
        l_down_trigger->setGeometry(QRect(328, -3, 51, 51));
        l_down_trigger->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_izq.png")));
        l_down_trigger->setScaledContents(true);
        l_page = new QLabel(Download_Data);
        l_page->setObjectName(QStringLiteral("l_page"));
        l_page->setGeometry(QRect(383, -3, 41, 51));
        l_page->setFont(font2);
        l_page->setStyleSheet(QStringLiteral("color: rgb(227, 227, 227);"));
        l_page->setScaledContents(true);
        l_page->setAlignment(Qt::AlignCenter);
        l_up_trigger = new MyLabelAnimated(Download_Data);
        l_up_trigger->setObjectName(QStringLiteral("l_up_trigger"));
        l_up_trigger->setGeometry(QRect(430, -3, 51, 51));
        l_up_trigger->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_der.png")));
        l_up_trigger->setScaledContents(true);

        retranslateUi(Download_Data);

        QMetaObject::connectSlotsByName(Download_Data);
    } // setupUi

    void retranslateUi(QWidget *Download_Data)
    {
        Download_Data->setWindowTitle(QApplication::translate("Download_Data", "Form", nullptr));
        l_descargar_todos->setText(QString());
        l_descargar_paciente->setText(QString());
        label->setText(QApplication::translate("Download_Data", "DESCARGA DE DATOS", nullptr));
        l_eject_memory->setText(QString());
        l_down_trigger->setText(QString());
        l_page->setText(QApplication::translate("Download_Data", "0/0", nullptr));
        l_up_trigger->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Download_Data: public Ui_Download_Data {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOAD_DATA_H
