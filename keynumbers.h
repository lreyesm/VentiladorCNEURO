#ifndef KEYNUMBERS_H
#define KEYNUMBERS_H

#include <QWidget>
#include "qlabel_button.h"

#define X_POS_LABEL_KEY_INIT 30
#define Y_POS_LABEL_KEY_INIT 0
#define X_POS_LABEL_KEY_INC 50


namespace Ui {
class KeyNumbers;
}

class KeyNumbers : public QWidget
{
    Q_OBJECT

public:
    explicit KeyNumbers(QWidget *parent = nullptr, int x_pos =0, int y_pos=0);
    ~KeyNumbers();

private slots:
    void onClickedDay(QString text);
    void on_pb_ok_clicked();
private:
    Ui::KeyNumbers *ui;
    void setKey(QString key, QPoint pos, bool upper, bool letter, QSize size = QSize(30,30));
    void deleteAllChilds();
    void fillKeys(bool upper);
    void unmarkAllOtherDays();
};

#endif // KEYNUMBERS_H
