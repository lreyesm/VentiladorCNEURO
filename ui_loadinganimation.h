/********************************************************************************
** Form generated from reading UI file 'loadinganimation.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADINGANIMATION_H
#define UI_LOADINGANIMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <qlabel_button.h>

QT_BEGIN_NAMESPACE

class Ui_LoadingAnimation
{
public:
    QWidget *widget;
    QLabel *label;
    QLabel *l_loading_text;
    QWidget *widget_loading;
    QLabel *l_sand_watch;
    QLabel_Button *l_background_blur;

    void setupUi(QWidget *LoadingAnimation)
    {
        if (LoadingAnimation->objectName().isEmpty())
            LoadingAnimation->setObjectName(QStringLiteral("LoadingAnimation"));
        LoadingAnimation->resize(801, 481);
        widget = new QWidget(LoadingAnimation);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(161, 121, 491, 201));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 491, 201));
        QFont font;
        font.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font.setPointSize(15);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("QLabel {\n"
"background-color: rgb(35, 33, 30);\n"
"     border-radius: 10px;\n"
"     color: #E3E3E3\n"
" }"));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        l_loading_text = new QLabel(widget);
        l_loading_text->setObjectName(QStringLiteral("l_loading_text"));
        l_loading_text->setGeometry(QRect(19, 20, 451, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        l_loading_text->setFont(font1);
        l_loading_text->setStyleSheet(QStringLiteral("color: #E3E3E3"));
        l_loading_text->setScaledContents(true);
        l_loading_text->setAlignment(Qt::AlignCenter);
        widget_loading = new QWidget(widget);
        widget_loading->setObjectName(QStringLiteral("widget_loading"));
        widget_loading->setGeometry(QRect(195, 70, 100, 100));
        l_sand_watch = new QLabel(widget);
        l_sand_watch->setObjectName(QStringLiteral("l_sand_watch"));
        l_sand_watch->setGeometry(QRect(210, 80, 52, 70));
        l_sand_watch->setPixmap(QPixmap(QString::fromUtf8(":/icons/sand_watch.png")));
        l_sand_watch->setScaledContents(true);
        l_background_blur = new QLabel_Button(LoadingAnimation);
        l_background_blur->setObjectName(QStringLiteral("l_background_blur"));
        l_background_blur->setGeometry(QRect(-10, -10, 820, 500));
        l_background_blur->setPixmap(QPixmap(QString::fromUtf8(":/icons/menu_on.png")));
        l_background_blur->setScaledContents(true);
        l_background_blur->raise();
        widget->raise();

        retranslateUi(LoadingAnimation);

        QMetaObject::connectSlotsByName(LoadingAnimation);
    } // setupUi

    void retranslateUi(QWidget *LoadingAnimation)
    {
        LoadingAnimation->setWindowTitle(QApplication::translate("LoadingAnimation", "Form", nullptr));
        label->setText(QString());
        l_loading_text->setText(QApplication::translate("LoadingAnimation", "Cargando...", nullptr));
        l_sand_watch->setText(QString());
        l_background_blur->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoadingAnimation: public Ui_LoadingAnimation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADINGANIMATION_H
