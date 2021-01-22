#include "optionsselector.h"
#include "ui_optionsselector.h"
#include "qlabel_button.h"

OptionsSelector::OptionsSelector(QWidget *parent, QStringList options) :
    QWidget(parent),
    ui(new Ui::OptionsSelector)
{
    ui->setupUi(this);
    if(!options.isEmpty()){
        addOptions(options);
    }
}

OptionsSelector::~OptionsSelector()
{
    delete ui;
}
void OptionsSelector::moveCenter(){

    int h = this->parentWidget()->height();
    int w = this->parentWidget()->width();
    if(h > 480){ h=480;}
    if(w > 800){ w=800;}
    int xpos = static_cast<int>(static_cast<float>(w - this->width())/2);
    int ypos = static_cast<int>(static_cast<float>(h - this->height())/2);
    this->move(xpos, ypos);
}
void OptionsSelector::addOptions(QStringList options)
{
    QString option;
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(5,5,5,5);
    layout->setSpacing(15);
    ui->widget_options->setLayout(layout);
    ui->widget_options->layout()->setAlignment(Qt::AlignCenter);

    QFont font = ui->label->font();
    font.setPointSize(font.pointSize()-1);
    font.setBold(false);
    foreach(option, options){
        QLabel_Button *button = new QLabel_Button(ui->widget_options);
        button->setObjectName("pb_usb_" + option);
        button->setText(option);
        button->setFont(font);
        button->setAlignment(Qt::AlignCenter);
        button->setFixedSize(240, 30);
        connect(button, &QLabel_Button::send_text, this,
                &OptionsSelector::emitSelectedItem);

        ui->widget_options->layout()->addWidget(button);
        this->setFixedHeight(this->height()+ 40);
    }
}
void OptionsSelector::emitSelectedItem(QString option){
    emit selected_option(option);
    emit selected();
    this->close();
}
