#include "keyboard.h"
#include "ui_keyboard.h"
#include <QDebug>
#include <QPushButton>
#include <QPropertyAnimation>

KeyBoard::KeyBoard(QWidget *parent, QWidget *widget,  bool numeric, double width, double height, int xpos, int ypos) :
    QWidget(parent),
    ui(new Ui::KeyBoard)
{
    ui->setupUi(this);
    if(xpos < 0){
        xpos = 0;
    }
    if(ypos < 0){
        ypos = widget->pos().y() + widget->height();
    }
    move(xpos, ypos);


    this->setFixedSize(static_cast<int>(width+1),
                       static_cast<int>(height+1));
    ui->widget_keys->setFixedSize(static_cast<int>(width),
                                  static_cast<int>(height));
    ui->l_background->setFixedSize(static_cast<int>(width+2),
                                   static_cast<int>(height+2));


    xpos_init = static_cast<int>(width / 12.307692);///
    ypos_init = static_cast<int>(height / 21.8);////

    xpos_inc = static_cast<int>(width/66.666667);///
    ypos_inc = static_cast<int>(height / 4.192307);////

    short_letter_width = static_cast<int>(width/28.571428);///
    letter_width = static_cast<int>(width/14.285714);///
    button_height = static_cast<int>(height/5.190476);//////
    button_width = static_cast<int>(width/8.988764044);///

    spacebar_width = static_cast<int>(width/2.5236593059);///

    icons_size = static_cast<int>(width/26.67);

    if(numeric){
        fillNumericKeys(false);
    }else{
        fillKeys();
    }

}

KeyBoard::~KeyBoard()
{
    delete ui;
}

void KeyBoard::setWidget(QLineEdit *widget){
    widget_to_write = widget;
    widget_type= QLINEEDIT;
}
void KeyBoard::setWidget(QPlainTextEdit *widget){
    widget_to_write_pt = widget;
    widget_type= QPLAINTEXTEDIT;
}

void KeyBoard::showKeyBoard(){
    this->show();
    this->raise();
    animateWidgetDownToUp(this, 300);
}

void KeyBoard::animateWidgetDownToUp(QWidget *widget, int anim_time){
    QRect endValue = widget->geometry();
    QRect startValue = QRect(endValue.x(),endValue.y() + endValue.height()
                             ,endValue.width(), endValue.height());


    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
    animation->start();
}
void KeyBoard::animateHideWidgetUpToDown(QWidget *widget, int anim_time){

    QRect startValue = widget->geometry();
    QRect endValue = QRect(startValue.x(),startValue.y() + startValue.height()
                           ,startValue.width(), startValue.height());

    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
    emit closeKeyboard();
    QObject::connect(animation, &QPropertyAnimation::finished, widget, &QWidget::close);
    animation->start();
}

void KeyBoard::fillKeys(bool upper){
    numeric = false;
    isUpper = upper;
    deleteAllChilds();

    QString letters_all = "qwertyuiopasdfghjklñzxcvbnm,....";
    QStringList letters;
    for (int i=0; i < letters_all.size(); i++) {
        letters << letters_all.at(i) + QString("");
    }
    int x_pos = xpos_init;
    int y_pos = ypos_init;

    for (int i =0;  i < 10;i++) {
        QString key = letters.at(i);
        setKey(key, QPoint(x_pos, y_pos), upper, QSize(letter_width, button_height));
        x_pos+= letter_width + xpos_inc;
    }
    x_pos = xpos_init;
    y_pos += ypos_inc;
    for (int i =10;  i < 20;i++) {
        QString key = letters.at(i);
        setKey(key, QPoint(x_pos, y_pos), upper, QSize(letter_width, button_height));
        x_pos+= letter_width + xpos_inc;
    }

    x_pos = xpos_init;
    y_pos += ypos_inc;
    setKeyButton("shift", QPoint(x_pos, y_pos), QSize(button_width, button_height), &KeyBoard::onShiftClicked);
    x_pos+= button_width + xpos_inc;
    for (int i =20;  i < 27;i++) {
        QString key = letters.at(i);
        setKey(key, QPoint(x_pos, y_pos), upper, QSize(letter_width, button_height));
        x_pos+= letter_width + xpos_inc;
    }
    setKeyButton("erase_key", QPoint(x_pos, y_pos), QSize(button_width, button_height), &KeyBoard::onEraseClicked);

    x_pos = xpos_init;
    y_pos += ypos_inc;
    setKeyButton("change_to_numbers", QPoint(x_pos, y_pos), QSize(button_width, button_height),
                 &KeyBoard::onChangeToNumbersClicked);

    x_pos+= button_width + xpos_inc;

    setKeyButton("hide_keyword", QPoint(x_pos, y_pos), QSize(letter_width, button_height),
                 &KeyBoard::onHideKeyboardClicked);

    x_pos+= letter_width + xpos_inc;

    setKey(letters.at(27), QPoint(x_pos, y_pos), upper, QSize(short_letter_width, button_height));

    x_pos+= short_letter_width + xpos_inc;

    setKey(" ", QPoint(x_pos, y_pos), upper, QSize(spacebar_width, button_height));//spacebar

    x_pos+= spacebar_width + xpos_inc;

    setKey(letters.at(28), QPoint(x_pos, y_pos), upper, QSize(short_letter_width, button_height));

    x_pos+= short_letter_width + xpos_inc;

    setKeyButton("enter", QPoint(x_pos, y_pos), QSize(button_width, button_height), &KeyBoard::onEnterClicked);


}

void KeyBoard::fillNumericKeys(bool non_numeric_enable){
    numeric = true;
    numeric_extra_keys = false;
    deleteAllChilds();

    QString letters_all = "1234567890@:;_-#[]/+'¨¿?!\"%,....";
    QStringList letters;
    for (int i=0; i < letters_all.size(); i++) {
        letters << letters_all.at(i) + QString("");
    }
    int x_pos = xpos_init;
    int y_pos = ypos_init;

    for (int i =0;  i < 10;i++) {
        QString key = letters.at(i);
        setKey(key, QPoint(x_pos, y_pos), false, QSize(letter_width, button_height));
        x_pos+= letter_width + xpos_inc;
    }

    x_pos = xpos_init;
    y_pos += ypos_inc;
    for (int i =10;  i < 20;i++) {
        QString key = letters.at(i);
        setKey(key, QPoint(x_pos, y_pos), false, QSize(letter_width, button_height), non_numeric_enable);
        x_pos+= letter_width + xpos_inc;
    }

    x_pos = xpos_init;
    y_pos += ypos_inc;
    setKeyButton("change_to_numbers_extra_keys_1", QPoint(x_pos, y_pos),
                 QSize(button_width, button_height),
                 &KeyBoard::onChangeToNumbersExtraKeysClicked, non_numeric_enable);
    x_pos+= button_width + xpos_inc;
    for (int i =20;  i < 27;i++) {
        QString key = letters.at(i);
        setKey(key, QPoint(x_pos, y_pos), false, QSize(letter_width, button_height), non_numeric_enable);
        x_pos+= letter_width + xpos_inc;
    }
    setKeyButton("erase_key", QPoint(x_pos, y_pos), QSize(button_width, button_height), &KeyBoard::onEraseClicked);

    x_pos = xpos_init;
    y_pos += ypos_inc;
    setKeyButton("change_to_numbers", QPoint(x_pos, y_pos), QSize(button_width, button_height),
                 &KeyBoard::onChangeToNumbersClicked, non_numeric_enable);

    x_pos+= button_width + xpos_inc;

    setKeyButton("hide_keyword", QPoint(x_pos, y_pos), QSize(letter_width, button_height),
                 &KeyBoard::onHideKeyboardClicked);

    x_pos+= letter_width + xpos_inc;

    setKey(letters.at(27), QPoint(x_pos, y_pos), false, QSize(short_letter_width, button_height),non_numeric_enable);

    x_pos+= short_letter_width + xpos_inc;

    setKey(" ", QPoint(x_pos, y_pos), false, QSize(spacebar_width, button_height),non_numeric_enable);//spacebar

    x_pos+= spacebar_width + xpos_inc;

    setKey(letters.at(28), QPoint(x_pos, y_pos), false, QSize(short_letter_width, button_height),non_numeric_enable);

    x_pos+= short_letter_width + xpos_inc;

    setKeyButton("enter", QPoint(x_pos, y_pos), QSize(button_width, button_height), &KeyBoard::onEnterClicked);


}

void KeyBoard::fillNumericExtraKeys(){
    numeric = true;
    numeric_extra_keys = true;
    deleteAllChilds();

    QString letters_all = "~`|∙√÷{}π$€£¢¥=≈[]_™©«»\"/\\^½¼.!--";
    QStringList letters;
    for (int i=0; i < letters_all.size(); i++) {
        letters << letters_all.at(i) + QString("");
    }
    int x_pos = xpos_init;
    int y_pos = ypos_init;

    for (int i =0;  i < 10;i++) {
        QString key = letters.at(i);
        setKey(key, QPoint(x_pos, y_pos), false, QSize(letter_width, button_height));
        x_pos+= letter_width + xpos_inc;
    }

    x_pos = xpos_init;
    y_pos += ypos_inc;
    for (int i =10;  i < 20;i++) {
        QString key = letters.at(i);
        setKey(key, QPoint(x_pos, y_pos), false, QSize(letter_width, button_height));
        x_pos+= letter_width + xpos_inc;
    }

    x_pos = xpos_init;
    y_pos += ypos_inc;
    setKeyButton("change_to_numbers_extra_keys_2", QPoint(x_pos, y_pos), QSize(button_width, button_height), &KeyBoard::onChangeToNumbersExtraKeysClicked);
    x_pos+= button_width + xpos_inc;
    for (int i =20;  i < 27;i++) {
        QString key = letters.at(i);
        setKey(key, QPoint(x_pos, y_pos), false, QSize(letter_width, button_height));
        x_pos+= letter_width + xpos_inc;
    }
    setKeyButton("erase_key", QPoint(x_pos, y_pos), QSize(button_width, button_height), &KeyBoard::onEraseClicked);

    x_pos = xpos_init;
    y_pos += ypos_inc;
    setKeyButton("change_to_numbers", QPoint(x_pos, y_pos), QSize(button_width, button_height),
                 &KeyBoard::onChangeToNumbersClicked);

    x_pos+= button_width + xpos_inc;

    setKeyButton("hide_keyword", QPoint(x_pos, y_pos), QSize(letter_width, button_height),
                 &KeyBoard::onHideKeyboardClicked);

    x_pos+= letter_width + xpos_inc;

    setKey(letters.at(27), QPoint(x_pos, y_pos), false, QSize(short_letter_width, button_height));

    x_pos+= short_letter_width + xpos_inc;

    setKey(" ", QPoint(x_pos, y_pos), false, QSize(spacebar_width, button_height));//spacebar

    x_pos+= spacebar_width + xpos_inc;

    setKey(letters.at(28), QPoint(x_pos, y_pos), false, QSize(short_letter_width, button_height));

    x_pos+= short_letter_width + xpos_inc;

    setKeyButton("enter", QPoint(x_pos, y_pos), QSize(button_width, button_height), &KeyBoard::onEnterClicked);

}

void KeyBoard::onHideKeyboardClicked(){
    qDebug()<<"onHideKeyboardClicked";
    animateHideWidgetUpToDown(this);
}
void KeyBoard::onChangeToNumbersClicked(){
    qDebug()<<"onChangeToNumbersClicked";
    if(numeric){
        fillKeys();
    }else{
        fillNumericKeys();
    }
}
void KeyBoard::onChangeToNumbersExtraKeysClicked(){
    qDebug()<<"onChangeToNumbersExtraKeysClicked";
    if(numeric_extra_keys){
        fillNumericKeys();
    }else{
        fillNumericExtraKeys();
    }
}
void KeyBoard::onShiftClicked(){
    qDebug()<<"onShiftClicked";
    isUpper = !isUpper;
    fillKeys(isUpper);
}
void KeyBoard::onSpaceBarClicked(){
    qDebug()<<"onSpaceBarClicked";
}
void KeyBoard::onEnterClicked(){
    qDebug()<<"onEnterClicked";
    if(widget_type == QLINEEDIT){
        if(widget_to_write!= nullptr){
            qDebug()<<"escribiendo en: "+widget_to_write->objectName();
            //            widget_to_write->insert("\n");
            onHideKeyboardClicked();
        }
    }else if(widget_type == QPLAINTEXTEDIT){
        if(widget_to_write_pt!= nullptr){
            qDebug()<<"escribiendo en: "+widget_to_write_pt->objectName();
            widget_to_write_pt->insertPlainText("\n");

        }
    }
}
void KeyBoard::onEraseClicked(){
    if(widget_type == QLINEEDIT){
        qDebug()<<"onEraseClicked selected: "+ widget_to_write->selectedText();
        widget_to_write->backspace();
    }
    else if(widget_type == QPLAINTEXTEDIT){
        if(widget_to_write_pt->textCursor().hasSelection()){
            widget_to_write_pt->textCursor().removeSelectedText();
        }
        else{
            widget_to_write_pt->textCursor().deletePreviousChar();
        }
    }
    //    QApplication::postEvent(widget_to_write, new QKeyEvent(QEvent::KeyPress,Qt::Key_Back,Qt::NoModifier));
}

void KeyBoard::setKeyButton(QString key, QPoint pos, QSize size, void (KeyBoard::*funcion)(), bool enabled){
    QPushButton *key_button = new QPushButton(ui->widget_keys);

    QIcon icon(":/icons/keyword/"+key+".png");
    key_button->setIcon(icon);
    key_button->setIconSize(QSize(icons_size, icons_size));

    key_button->move(pos);
    key_button->setStyleSheet(QStringLiteral("QPushButton {"
                                             "border-radius: 5px;"
                                             "background-color: rgb(255, 255, 255);"
                                             "}"));
    key_button->setFixedSize(size);
    key_button->show();
    key_button->setEnabled(enabled);
    connect(key_button, &QPushButton::clicked, this, funcion);
}

void KeyBoard::setKey(QString key, QPoint pos, bool upper, QSize size, bool enabled){

    MyLabelStateAnimated *key_label = new MyLabelStateAnimated(ui->widget_keys);

    if(upper){
        key = key.toUpper();
    }
    key_label->setText(key);

    QFont font = this->font();
//    font.setBold(true);
    font.setPointSize(20);

    key_label->move(pos);
    key_label->setAlignment(Qt::AlignHCenter| Qt::AlignVCenter);
    key_label->setStyleSheet(QStringLiteral("QLabel {"
                                            "border-radius: 5px;"
                                            "color: rgb(36, 41, 46);"
                                            "background-color: rgb(255, 255, 255);"
                                            "}"));
    key_label->setFont(font);
    key_label->setFixedSize(size);
    key_label->show();
    key_label->setEnabled(enabled);
    key_label->set_Enabled(enabled);
    connect(key_label, &MyLabelStateAnimated::send_text, this, &KeyBoard::onClickedKey);
}

void KeyBoard::deleteAllChilds(){
    int c= ui->widget_keys->children().size();
    for (int i=0; i < c; i++) {
        static_cast<QWidget*>((ui->widget_keys->
                               children().at(i)))->deleteLater();

    }
}
void KeyBoard::unmarkAllOtherDays(){
    int c= ui->widget_keys->children().size();
    for (int i=0; i < c; i++) {
        static_cast<MyLabelStateAnimated*>((ui->widget_keys->
                                            children().at(i)))->setChecked(false);

    }
}

void KeyBoard::onClickedKey(QString text){

    qDebug()<<"onEnterClicked";
    if(widget_type == QLINEEDIT){
        if(widget_to_write!= nullptr){
            qDebug()<<"escribiendo en: "+widget_to_write->objectName();
            widget_to_write->insert(text);
            qDebug()<<"key: " + text;
            qDebug()<<widget_to_write->text();
        }
    }else if(widget_type == QPLAINTEXTEDIT){
        if(widget_to_write_pt!= nullptr){
            qDebug()<<"escribiendo en: "+widget_to_write_pt->objectName();
            widget_to_write_pt->insertPlainText(text);
            qDebug()<<"key: " + text;
        }
    }



}

void KeyBoard::on_pb_ok_clicked()
{
    this->close();
}
