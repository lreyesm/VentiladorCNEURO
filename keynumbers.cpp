#include "keynumbers.h"
#include "ui_keynumbers.h"

KeyNumbers::KeyNumbers(QWidget *parent, int x_pos, int y_pos) :
    QWidget(parent),
    ui(new Ui::KeyNumbers)
{
    ui->setupUi(this);
    move(x_pos, y_pos);
    fillKeys(true);
}

KeyNumbers::~KeyNumbers()
{
    delete ui;
}

void KeyNumbers::fillKeys(bool upper){
    deleteAllChilds();

    QString letters_all = "123456789";
    QStringList letters;
    for (int i=0; i < letters_all.size(); i++) {
        letters << letters_all.at(i) + QString("");
    }
    int x_pos = X_POS_LABEL_KEY_INIT;
    int y_pos = Y_POS_LABEL_KEY_INIT;

    for (int i =0;  i < letters.size();i++) {
        QString key = letters.at(i);
        setKey(key, QPoint(x_pos, y_pos), upper, true);
        x_pos+=X_POS_LABEL_KEY_INC;
        if(x_pos >= X_POS_LABEL_KEY_INIT + 3*X_POS_LABEL_KEY_INC){
            y_pos+= Y_POS_LABEL_KEY_INC;
            x_pos = X_POS_LABEL_KEY_INIT;
        }

    }
    setKey("#", QPoint(x_pos, y_pos), upper, true);
    x_pos+=X_POS_LABEL_KEY_INC;
    setKey("0", QPoint(x_pos, y_pos), upper, true);
    x_pos+=X_POS_LABEL_KEY_INC;
    setKey("delete", QPoint(x_pos, y_pos), false, false);
}

void KeyNumbers::setKey(QString key, QPoint pos, bool upper, bool letter, QSize size){

    QLabel_Button *key_label = new QLabel_Button(ui->widget_keys);

    if(upper){
        key = key.toUpper();
    }
    key_label->setText(key);
    if(!letter){
        key_label->setPixmap(QPixmap(":/icons/keyword/" + key + ".png"));
    }
    key_label->setScaledContents(true);
    key_label->move(pos);
    key_label->setAlignment(Qt::AlignHCenter| Qt::AlignVCenter);
    QFont font = key_label->font();
    font.setPointSize(16);
    key_label->setFont(font);
    key_label->setCheckedBackground(QColor(54, 141, 206));

    key_label->setFixedSize(size);
    key_label->show();
    connect(key_label, &QLabel_Button::send_text, this, &KeyNumbers::onClickedDay);
}

void KeyNumbers::deleteAllChilds(){
    int c= ui->widget_keys->children().size();
    for (int i=0; i < c; i++) {
        disconnect(static_cast<QLabel_Button*>((ui->widget_keys->
                                                children().at(i))),
                   &QLabel_Button::send_text, this, &KeyNumbers::onClickedDay);
        static_cast<QLabel_Button*>((ui->widget_keys->
                                     children().at(i)))->deleteLater();

    }
}
void KeyNumbers::unmarkAllOtherDays(){
    int c= ui->widget_keys->children().size();
    for (int i=0; i < c; i++) {
        static_cast<QLabel_Button*>((ui->widget_keys->
                                     children().at(i)))->setChecked(false);

    }
}

void KeyNumbers::onClickedDay(QString text){

    unmarkAllOtherDays();
    ui->le_text->setText(ui->le_text->text() + text);
}

void KeyNumbers::on_pb_ok_clicked()
{
    this->close();
}
