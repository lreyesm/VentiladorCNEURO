/********************************************************************************
** Form generated from reading UI file 'screenflukecontroller.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENFLUKECONTROLLER_H
#define UI_SCREENFLUKECONTROLLER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScreenFlukeController
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *FTDIConfig_GB;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *VID_LE;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *PID_LE;
    QPushButton *CheckFTDI_PB;
    QSpacerItem *verticalSpacer;
    QGroupBox *SerialPortConfig_GB;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *Baudrate_CB;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *Parity_CB;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *DataBits_CB;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *StopBits_CB;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *FlowControl_CB;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *OpenSerialPort_PB;
    QPushButton *CLoseSerialPort_PB;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QComboBox *TypeOfCommandToSend_CB;
    QComboBox *CommandToSend_CB;
    QPushButton *SendCommand_PB;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_10;
    QPushButton *pb_close;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_5;
    QPushButton *GetOxygenCB;
    QPushButton *GetPressureCB;
    QVBoxLayout *verticalLayout_4;
    QPushButton *GetVolumeCB;
    QPushButton *GetFlowCB;
    QPushButton *GetAllBreathParametersCB_2;
    QTextEdit *textEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ScreenFlukeController)
    {
        if (ScreenFlukeController->objectName().isEmpty())
            ScreenFlukeController->setObjectName(QStringLiteral("ScreenFlukeController"));
        ScreenFlukeController->resize(801, 481);
        QPalette palette;
        QBrush brush(QColor(46, 47, 48, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        ScreenFlukeController->setPalette(palette);
        centralwidget = new QWidget(ScreenFlukeController);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_12 = new QHBoxLayout(centralwidget);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        FTDIConfig_GB = new QGroupBox(centralwidget);
        FTDIConfig_GB->setObjectName(QStringLiteral("FTDIConfig_GB"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FTDIConfig_GB->sizePolicy().hasHeightForWidth());
        FTDIConfig_GB->setSizePolicy(sizePolicy);
        QPalette palette1;
        QBrush brush2(QColor(54, 141, 206, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        QBrush brush3(QColor(164, 166, 168, 96));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        FTDIConfig_GB->setPalette(palette1);
        verticalLayout_2 = new QVBoxLayout(FTDIConfig_GB);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(FTDIConfig_GB);
        label_6->setObjectName(QStringLiteral("label_6"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        label_6->setPalette(palette2);

        horizontalLayout_6->addWidget(label_6);

        VID_LE = new QLineEdit(FTDIConfig_GB);
        VID_LE->setObjectName(QStringLiteral("VID_LE"));
        VID_LE->setStyleSheet(QLatin1String("QLineEdit{\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #444444\n"
" }"));

        horizontalLayout_6->addWidget(VID_LE);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(FTDIConfig_GB);
        label_7->setObjectName(QStringLiteral("label_7"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        label_7->setPalette(palette3);

        horizontalLayout_7->addWidget(label_7);

        PID_LE = new QLineEdit(FTDIConfig_GB);
        PID_LE->setObjectName(QStringLiteral("PID_LE"));
        PID_LE->setStyleSheet(QLatin1String("QLineEdit{\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #444444\n"
" }"));

        horizontalLayout_7->addWidget(PID_LE);


        verticalLayout_2->addLayout(horizontalLayout_7);

        CheckFTDI_PB = new QPushButton(FTDIConfig_GB);
        CheckFTDI_PB->setObjectName(QStringLiteral("CheckFTDI_PB"));

        verticalLayout_2->addWidget(CheckFTDI_PB);


        verticalLayout_8->addWidget(FTDIConfig_GB);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);


        horizontalLayout_11->addLayout(verticalLayout_8);

        SerialPortConfig_GB = new QGroupBox(centralwidget);
        SerialPortConfig_GB->setObjectName(QStringLiteral("SerialPortConfig_GB"));
        sizePolicy.setHeightForWidth(SerialPortConfig_GB->sizePolicy().hasHeightForWidth());
        SerialPortConfig_GB->setSizePolicy(sizePolicy);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        SerialPortConfig_GB->setPalette(palette4);
        verticalLayout = new QVBoxLayout(SerialPortConfig_GB);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(SerialPortConfig_GB);
        label->setObjectName(QStringLiteral("label"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        label->setPalette(palette5);

        horizontalLayout->addWidget(label);

        Baudrate_CB = new QComboBox(SerialPortConfig_GB);
        Baudrate_CB->addItem(QString());
        Baudrate_CB->addItem(QString());
        Baudrate_CB->setObjectName(QStringLiteral("Baudrate_CB"));

        horizontalLayout->addWidget(Baudrate_CB);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(SerialPortConfig_GB);
        label_2->setObjectName(QStringLiteral("label_2"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        label_2->setPalette(palette6);

        horizontalLayout_2->addWidget(label_2);

        Parity_CB = new QComboBox(SerialPortConfig_GB);
        Parity_CB->addItem(QString());
        Parity_CB->addItem(QString());
        Parity_CB->addItem(QString());
        Parity_CB->setObjectName(QStringLiteral("Parity_CB"));

        horizontalLayout_2->addWidget(Parity_CB);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_3 = new QLabel(SerialPortConfig_GB);
        label_3->setObjectName(QStringLiteral("label_3"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        label_3->setPalette(palette7);

        horizontalLayout_3->addWidget(label_3);

        DataBits_CB = new QComboBox(SerialPortConfig_GB);
        DataBits_CB->addItem(QString());
        DataBits_CB->addItem(QString());
        DataBits_CB->addItem(QString());
        DataBits_CB->addItem(QString());
        DataBits_CB->setObjectName(QStringLiteral("DataBits_CB"));

        horizontalLayout_3->addWidget(DataBits_CB);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(SerialPortConfig_GB);
        label_4->setObjectName(QStringLiteral("label_4"));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        label_4->setPalette(palette8);

        horizontalLayout_4->addWidget(label_4);

        StopBits_CB = new QComboBox(SerialPortConfig_GB);
        StopBits_CB->addItem(QString());
        StopBits_CB->addItem(QString());
        StopBits_CB->addItem(QString());
        StopBits_CB->setObjectName(QStringLiteral("StopBits_CB"));

        horizontalLayout_4->addWidget(StopBits_CB);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_5 = new QLabel(SerialPortConfig_GB);
        label_5->setObjectName(QStringLiteral("label_5"));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        label_5->setPalette(palette9);
        label_5->setScaledContents(false);
        label_5->setWordWrap(false);

        horizontalLayout_5->addWidget(label_5);

        FlowControl_CB = new QComboBox(SerialPortConfig_GB);
        FlowControl_CB->addItem(QString());
        FlowControl_CB->addItem(QString());
        FlowControl_CB->setObjectName(QStringLiteral("FlowControl_CB"));

        horizontalLayout_5->addWidget(FlowControl_CB);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        OpenSerialPort_PB = new QPushButton(SerialPortConfig_GB);
        OpenSerialPort_PB->setObjectName(QStringLiteral("OpenSerialPort_PB"));

        horizontalLayout_8->addWidget(OpenSerialPort_PB);

        CLoseSerialPort_PB = new QPushButton(SerialPortConfig_GB);
        CLoseSerialPort_PB->setObjectName(QStringLiteral("CLoseSerialPort_PB"));

        horizontalLayout_8->addWidget(CLoseSerialPort_PB);


        verticalLayout->addLayout(horizontalLayout_8);


        horizontalLayout_11->addWidget(SerialPortConfig_GB);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        label_8->setPalette(palette10);

        verticalLayout_3->addWidget(label_8);

        TypeOfCommandToSend_CB = new QComboBox(centralwidget);
        TypeOfCommandToSend_CB->setObjectName(QStringLiteral("TypeOfCommandToSend_CB"));

        verticalLayout_3->addWidget(TypeOfCommandToSend_CB);

        CommandToSend_CB = new QComboBox(centralwidget);
        CommandToSend_CB->setObjectName(QStringLiteral("CommandToSend_CB"));

        verticalLayout_3->addWidget(CommandToSend_CB);

        SendCommand_PB = new QPushButton(centralwidget);
        SendCommand_PB->setObjectName(QStringLiteral("SendCommand_PB"));

        verticalLayout_3->addWidget(SendCommand_PB);


        horizontalLayout_10->addLayout(verticalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        pb_close = new QPushButton(centralwidget);
        pb_close->setObjectName(QStringLiteral("pb_close"));
        pb_close->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/close_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_close->setIcon(icon);
        pb_close->setIconSize(QSize(40, 40));
        pb_close->setFlat(true);

        verticalLayout_10->addWidget(pb_close);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_2);


        horizontalLayout_10->addLayout(verticalLayout_10);


        verticalLayout_7->addLayout(horizontalLayout_10);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        GetOxygenCB = new QPushButton(centralwidget);
        GetOxygenCB->setObjectName(QStringLiteral("GetOxygenCB"));

        verticalLayout_5->addWidget(GetOxygenCB);

        GetPressureCB = new QPushButton(centralwidget);
        GetPressureCB->setObjectName(QStringLiteral("GetPressureCB"));

        verticalLayout_5->addWidget(GetPressureCB);


        horizontalLayout_9->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        GetVolumeCB = new QPushButton(centralwidget);
        GetVolumeCB->setObjectName(QStringLiteral("GetVolumeCB"));

        verticalLayout_4->addWidget(GetVolumeCB);

        GetFlowCB = new QPushButton(centralwidget);
        GetFlowCB->setObjectName(QStringLiteral("GetFlowCB"));

        verticalLayout_4->addWidget(GetFlowCB);


        horizontalLayout_9->addLayout(verticalLayout_4);


        verticalLayout_6->addLayout(horizontalLayout_9);

        GetAllBreathParametersCB_2 = new QPushButton(centralwidget);
        GetAllBreathParametersCB_2->setObjectName(QStringLiteral("GetAllBreathParametersCB_2"));

        verticalLayout_6->addWidget(GetAllBreathParametersCB_2);


        verticalLayout_7->addLayout(verticalLayout_6);


        horizontalLayout_11->addLayout(verticalLayout_7);


        verticalLayout_9->addLayout(horizontalLayout_11);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setStyleSheet(QLatin1String("QTextEdit{\n"
"     border-radius: 3px;\n"
"     background-color: #E3E3E3;\n"
"     color: #444444\n"
" }"));

        verticalLayout_9->addWidget(textEdit);


        horizontalLayout_12->addLayout(verticalLayout_9);

        ScreenFlukeController->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ScreenFlukeController);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ScreenFlukeController->setStatusBar(statusbar);

        retranslateUi(ScreenFlukeController);

        Baudrate_CB->setCurrentIndex(1);
        Parity_CB->setCurrentIndex(2);
        DataBits_CB->setCurrentIndex(3);
        FlowControl_CB->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ScreenFlukeController);
    } // setupUi

    void retranslateUi(QMainWindow *ScreenFlukeController)
    {
        ScreenFlukeController->setWindowTitle(QApplication::translate("ScreenFlukeController", "MainWindow", nullptr));
        FTDIConfig_GB->setTitle(QApplication::translate("ScreenFlukeController", "FTDI Config:", nullptr));
        label_6->setText(QApplication::translate("ScreenFlukeController", "VID:", nullptr));
        label_7->setText(QApplication::translate("ScreenFlukeController", "PID:", nullptr));
        CheckFTDI_PB->setText(QApplication::translate("ScreenFlukeController", "Check  FTDI", nullptr));
        SerialPortConfig_GB->setTitle(QApplication::translate("ScreenFlukeController", "Serial Port Config:", nullptr));
        label->setText(QApplication::translate("ScreenFlukeController", "Baudrate:", nullptr));
        Baudrate_CB->setItemText(0, QApplication::translate("ScreenFlukeController", "9600", nullptr));
        Baudrate_CB->setItemText(1, QApplication::translate("ScreenFlukeController", "115200", nullptr));

        label_2->setText(QApplication::translate("ScreenFlukeController", "Parity:", nullptr));
        Parity_CB->setItemText(0, QApplication::translate("ScreenFlukeController", "Even", nullptr));
        Parity_CB->setItemText(1, QApplication::translate("ScreenFlukeController", "Odd", nullptr));
        Parity_CB->setItemText(2, QApplication::translate("ScreenFlukeController", "None", nullptr));

        label_3->setText(QApplication::translate("ScreenFlukeController", "Data Bits:", nullptr));
        DataBits_CB->setItemText(0, QApplication::translate("ScreenFlukeController", "5", nullptr));
        DataBits_CB->setItemText(1, QApplication::translate("ScreenFlukeController", "6", nullptr));
        DataBits_CB->setItemText(2, QApplication::translate("ScreenFlukeController", "7", nullptr));
        DataBits_CB->setItemText(3, QApplication::translate("ScreenFlukeController", "8", nullptr));

        label_4->setText(QApplication::translate("ScreenFlukeController", "Stop Bits:", nullptr));
        StopBits_CB->setItemText(0, QApplication::translate("ScreenFlukeController", "1", nullptr));
        StopBits_CB->setItemText(1, QApplication::translate("ScreenFlukeController", "1.5", nullptr));
        StopBits_CB->setItemText(2, QApplication::translate("ScreenFlukeController", "2", nullptr));

        label_5->setText(QApplication::translate("ScreenFlukeController", "Flow Control:", nullptr));
        FlowControl_CB->setItemText(0, QApplication::translate("ScreenFlukeController", "None", nullptr));
        FlowControl_CB->setItemText(1, QApplication::translate("ScreenFlukeController", "Hardware", nullptr));

        OpenSerialPort_PB->setText(QApplication::translate("ScreenFlukeController", "Open", nullptr));
        CLoseSerialPort_PB->setText(QApplication::translate("ScreenFlukeController", "Close", nullptr));
        label_8->setText(QApplication::translate("ScreenFlukeController", "Command to Send", nullptr));
        SendCommand_PB->setText(QApplication::translate("ScreenFlukeController", "Send Command", nullptr));
        pb_close->setText(QString());
        GetOxygenCB->setText(QApplication::translate("ScreenFlukeController", "Get Oxygen", nullptr));
        GetPressureCB->setText(QApplication::translate("ScreenFlukeController", "Get Pressure", nullptr));
        GetVolumeCB->setText(QApplication::translate("ScreenFlukeController", "Get Volume", nullptr));
        GetFlowCB->setText(QApplication::translate("ScreenFlukeController", "Get Flow", nullptr));
        GetAllBreathParametersCB_2->setText(QApplication::translate("ScreenFlukeController", "Get All Breath Parameters", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScreenFlukeController: public Ui_ScreenFlukeController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENFLUKECONTROLLER_H
