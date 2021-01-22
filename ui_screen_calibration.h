/********************************************************************************
** Form generated from reading UI file 'screen_calibration.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREEN_CALIBRATION_H
#define UI_SCREEN_CALIBRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>
#include <mylabelstateanimated.h>

QT_BEGIN_NAMESPACE

class Ui_Screen_Calibration
{
public:
    QLabel *label_2;
    MyLabelAnimated *pb_modo_at;
    MyLabelStateAnimated *l_logo;
    QLabel *l_calibration_text_label;
    QProgressBar *progressBar_calibracion;
    QLabel *l_version;
    QLabel *label_5;

    void setupUi(QWidget *Screen_Calibration)
    {
        if (Screen_Calibration->objectName().isEmpty())
            Screen_Calibration->setObjectName(QStringLiteral("Screen_Calibration"));
        Screen_Calibration->resize(801, 481);
        label_2 = new QLabel(Screen_Calibration);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(-1, -1, 802, 482));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(17, 21, 25);"));
        pb_modo_at = new MyLabelAnimated(Screen_Calibration);
        pb_modo_at->setObjectName(QStringLiteral("pb_modo_at"));
        pb_modo_at->setGeometry(QRect(610, 400, 150, 40));
        QFont font;
        font.setFamily(QStringLiteral("DIN Pro"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferAntialias);
        pb_modo_at->setFont(font);
        pb_modo_at->setCursor(QCursor(Qt::PointingHandCursor));
        pb_modo_at->setStyleSheet(QLatin1String("QLabel {\n"
"     border: 3px solid #E3E3E3;\n"
"     border-radius: 5px;\n"
"     color: #E3E3E3\n"
" }"));
        pb_modo_at->setScaledContents(true);
        pb_modo_at->setAlignment(Qt::AlignCenter);
        l_logo = new MyLabelStateAnimated(Screen_Calibration);
        l_logo->setObjectName(QStringLiteral("l_logo"));
        l_logo->setGeometry(QRect(233, 125, 335, 55));
        l_logo->setPixmap(QPixmap(QString::fromUtf8(":/icons/neuronic.png")));
        l_logo->setScaledContents(true);
        l_calibration_text_label = new QLabel(Screen_Calibration);
        l_calibration_text_label->setObjectName(QStringLiteral("l_calibration_text_label"));
        l_calibration_text_label->setGeometry(QRect(200, 280, 401, 34));
        QFont font1;
        font1.setFamily(QStringLiteral("DIN Pro"));
        font1.setPointSize(19);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        l_calibration_text_label->setFont(font1);
        l_calibration_text_label->setStyleSheet(QLatin1String("color: rgb(227, 227, 227);\n"
""));
        l_calibration_text_label->setAlignment(Qt::AlignCenter);
        progressBar_calibracion = new QProgressBar(Screen_Calibration);
        progressBar_calibracion->setObjectName(QStringLiteral("progressBar_calibracion"));
        progressBar_calibracion->setGeometry(QRect(200, 230, 400, 20));
        QPalette palette;
        QBrush brush(QColor(227, 227, 227, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush1(QColor(0, 204, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        QBrush brush2(QColor(29, 84, 92, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        progressBar_calibracion->setPalette(palette);
        progressBar_calibracion->setStyleSheet(QLatin1String(" QProgressBar::chunk {\n"
"     border-radius: 4px;\n"
"     background-color: #00CCFF;\n"
" }\n"
"QProgressBar {\n"
"     border-radius: 4px;\n"
"     background-color: #E3E3E3;\n"
" }"));
        progressBar_calibracion->setMaximum(100);
        progressBar_calibracion->setValue(10);
        progressBar_calibracion->setTextVisible(false);
        l_version = new QLabel(Screen_Calibration);
        l_version->setObjectName(QStringLiteral("l_version"));
        l_version->setGeometry(QRect(73, 0, 51, 32));
        QFont font2;
        font2.setFamily(QStringLiteral("DIN Pro"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        l_version->setFont(font2);
        l_version->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        l_version->setPixmap(QPixmap(QString::fromUtf8(":/icons/version.png")));
        l_version->setScaledContents(false);
        label_5 = new QLabel(Screen_Calibration);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 0, 71, 32));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/icons/version.png")));
        label_5->setScaledContents(false);

        retranslateUi(Screen_Calibration);

        QMetaObject::connectSlotsByName(Screen_Calibration);
    } // setupUi

    void retranslateUi(QWidget *Screen_Calibration)
    {
        Screen_Calibration->setWindowTitle(QApplication::translate("Screen_Calibration", "Form", nullptr));
        label_2->setText(QString());
        pb_modo_at->setText(QApplication::translate("Screen_Calibration", "MODO AT", nullptr));
        l_logo->setText(QString());
        l_calibration_text_label->setText(QApplication::translate("Screen_Calibration", "Iniciando Sistema", nullptr));
        l_version->setText(QApplication::translate("Screen_Calibration", "...", nullptr));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Screen_Calibration: public Ui_Screen_Calibration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREEN_CALIBRATION_H
