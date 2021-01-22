#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
//#include "mylabelanimated.h"
#include "qlabel_button.h"
#include "mylabelstateanimated.h"
#include <QLineEdit>
#include <QPlainTextEdit>

#define X_POS_LABEL_KEY_INIT 30
#define Y_POS_LABEL_KEY_INIT 0
#define X_POS_LABEL_KEY_INC 50
#define Y_POS_LABEL_KEY_INC 50


namespace Ui {
class KeyBoard;
}

class KeyBoard : public QWidget
{
    Q_OBJECT
    enum{QLINEEDIT, QPLAINTEXTEDIT};
public:
    explicit KeyBoard(QWidget *parent = nullptr, QWidget *widget = nullptr, bool numeric = false,
                      double width = 800, double height = 228, int xpos = -1, int ypos = -1);
    ~KeyBoard();

    void setWidget(QLineEdit *widget);
    void setWidget(QPlainTextEdit *widget);

signals:
    void closeKeyboard();

public slots:
    void showKeyBoard();
private slots:
    void onClickedKey(QString);

    void on_pb_ok_clicked();
    void onEraseClicked();
    void onEnterClicked();
    void onSpaceBarClicked();
    void onShiftClicked();
    void onChangeToNumbersClicked();
    void onHideKeyboardClicked();
    void onChangeToNumbersExtraKeysClicked();
private:
    Ui::KeyBoard *ui;
    void fillKeys(bool upper = false);
    bool isUpper = true;

    void unmarkAllOtherDays();
    void deleteAllChilds();
    void setKey(QString name, QPoint pos, bool upper, QSize size = QSize(30,30), bool enabled = true);

    int width = 800;
    int height = 218;

    int xpos_init=65/* width/80 */, ypos_init=10/* height/22.8 */;
    int xpos_inc=12/* width/88.9 */, ypos_inc=52 /* height/4.145 */;

    int letter_width = 56; // width/13.8
    int short_letter_width = 28; // width/28.571428
    int button_height = 42;// height/4.75
    int button_width = 89;// width/7.207

    int spacebar_width = 317;//width/1.951

    int icons_size = 30;// width/26.67

    QLineEdit *widget_to_write = nullptr;
    QPlainTextEdit *widget_to_write_pt = nullptr;
    int widget_type = QLINEEDIT; //
    bool numeric = false;
    bool numeric_extra_keys = false;
    void setKeyButton(QString key, QPoint pos, QSize size,
                      void (KeyBoard::*funcion)(), bool enabled = true);
    void animateWidgetDownToUp(QWidget *widget, int anim_time=200);
    void animateHideWidgetUpToDown(QWidget *widget, int anim_time=200);
    void fillNumericKeys(bool non_numeric_enable = true);
    void fillNumericExtraKeys();
};

#endif // KEYBOARD_H
