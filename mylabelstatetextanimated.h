#ifndef MYLABELSTATETEXTANIMATED_H
#define MYLABELSTATETEXTANIMATED_H

#include "mytextanimated.h"

#define ANIM_TIME_RB 150
#define ANIM_SCALE_RB 10

class MyLabelStateTextAnimated : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabelStateTextAnimated(QWidget *parent = nullptr);
    ~MyLabelStateTextAnimated();
    void setEditable(bool);
    void setTextInfo(QString information);
    bool isActivatedState(){
        return activated_state;
    }
    void setActivadeState(bool state){
        activated_state = state;
    }
    void setAnimationInit();
    void setAnimation(QPropertyAnimation *);
    void startAnimation(int delay = 0, int scale =ANIM_SCALE_RB, int anim_time =ANIM_TIME_RB);

    void setChecked(bool checked);
    bool isChecked();
    QString getText();
    void setTextString(QString text);
    void highlight();
    void setTextColor(const QColor color);

signals:
    void doubleClickedLabel();
    void mouseRightClicked();
    void mouseLeftClicked();
    void clicked();
    void mouseEntered(QPoint);
    void pressEvent(QMouseEvent *ev);
protected:
    void mousePressEvent(QMouseEvent *ev);
    //    void mouseMoveEvent(QMouseEvent *ev);
    //    void leaveEvent(QEvent *event);
    //    void enterEvent(QEvent *event);
    //    void moveEvent(QMoveEvent *event);

private slots:
    void setAnimationEnd();
    void finalizadaAnimacion();
    void setFotoInit(const QString&);
    void startAnimationFromChild();
    void emitirClicked();
    void setRadioButtonPos();

private:
    QString info ="";
    bool activated_state=false, enteredEvent=false;
    bool animationOnGoing =false;
    QPropertyAnimation *animation=nullptr, *animation_child=nullptr;
    QRect startValue, child_startValue;
    QRect endValue, child_endValue;
    QSize maxSize, minSize, child_size;
    int anim_scale = ANIM_SCALE_RB;
    int anim_time = ANIM_TIME_RB;
    MyTextAnimated *textAnimated;



};
#endif // MYLABELSTATETEXTANIMATED_H
