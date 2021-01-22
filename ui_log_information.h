/********************************************************************************
** Form generated from reading UI file 'log_information.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_INFORMATION_H
#define UI_LOG_INFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>

QT_BEGIN_NAMESPACE

class Ui_Log_Information
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    MyLabelAnimated *l_down_trigger;
    QLabel *l_page;
    MyLabelAnimated *l_up_trigger;
    QListWidget *listWidget;

    void setupUi(QWidget *Log_Information)
    {
        if (Log_Information->objectName().isEmpty())
            Log_Information->setObjectName(QStringLiteral("Log_Information"));
        Log_Information->resize(580, 372);
        verticalLayout = new QVBoxLayout(Log_Information);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(Log_Information);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font.setPointSize(16);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(227, 227, 227);"));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        l_down_trigger = new MyLabelAnimated(Log_Information);
        l_down_trigger->setObjectName(QStringLiteral("l_down_trigger"));
        l_down_trigger->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_izq.png")));
        l_down_trigger->setScaledContents(true);

        horizontalLayout->addWidget(l_down_trigger);

        l_page = new QLabel(Log_Information);
        l_page->setObjectName(QStringLiteral("l_page"));
        l_page->setFont(font);
        l_page->setStyleSheet(QStringLiteral("color: rgb(227, 227, 227);"));
        l_page->setScaledContents(true);
        l_page->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(l_page);

        l_up_trigger = new MyLabelAnimated(Log_Information);
        l_up_trigger->setObjectName(QStringLiteral("l_up_trigger"));
        l_up_trigger->setPixmap(QPixmap(QString::fromUtf8(":/icons/flecha_der.png")));
        l_up_trigger->setScaledContents(true);

        horizontalLayout->addWidget(l_up_trigger);


        verticalLayout->addLayout(horizontalLayout);

        listWidget = new QListWidget(Log_Information);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        QFont font1;
        font1.setFamily(QStringLiteral("DIN Pro Cond Bold"));
        font1.setPointSize(12);
        listWidget->setFont(font1);
        listWidget->setStyleSheet(QLatin1String("QListWidget {\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #444444\n"
" }\n"
""));
        listWidget->setMovement(QListView::Static);
        listWidget->setSpacing(2);

        verticalLayout->addWidget(listWidget);


        retranslateUi(Log_Information);

        QMetaObject::connectSlotsByName(Log_Information);
    } // setupUi

    void retranslateUi(QWidget *Log_Information)
    {
        Log_Information->setWindowTitle(QApplication::translate("Log_Information", "Form", nullptr));
        label->setText(QApplication::translate("Log_Information", "EVENTOS", nullptr));
        l_down_trigger->setText(QString());
        l_page->setText(QApplication::translate("Log_Information", "0/0", nullptr));
        l_up_trigger->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Log_Information: public Ui_Log_Information {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_INFORMATION_H
