/********************************************************************************
** Form generated from reading UI file 'optionsselector.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSSELECTOR_H
#define UI_OPTIONSSELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptionsSelector
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QWidget *widget_options;

    void setupUi(QWidget *OptionsSelector)
    {
        if (OptionsSelector->objectName().isEmpty())
            OptionsSelector->setObjectName(QStringLiteral("OptionsSelector"));
        OptionsSelector->resize(308, 114);
        verticalLayout = new QVBoxLayout(OptionsSelector);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(OptionsSelector);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QLatin1String("QWidget{\n"
"background-color: rgb(35, 33, 30);\n"
"     border-radius: 10px;\n"
"     color: #E3E3E3\n"
" }"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, 20, 20, 20);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("DIN Pro"));
        font.setPointSize(16);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        widget_options = new QWidget(widget);
        widget_options->setObjectName(QStringLiteral("widget_options"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_options->sizePolicy().hasHeightForWidth());
        widget_options->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(widget_options);


        verticalLayout->addWidget(widget);


        retranslateUi(OptionsSelector);

        QMetaObject::connectSlotsByName(OptionsSelector);
    } // setupUi

    void retranslateUi(QWidget *OptionsSelector)
    {
        OptionsSelector->setWindowTitle(QApplication::translate("OptionsSelector", "Form", nullptr));
        label->setText(QApplication::translate("OptionsSelector", "SELECCIONE DISPOSITIVO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionsSelector: public Ui_OptionsSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSSELECTOR_H
