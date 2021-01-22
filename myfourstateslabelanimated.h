#ifndef MYFOURSTATESLABELANIMATED_H
#define MYFOURSTATESLABELANIMATED_H

#include <QDebug>
#include <QLabel>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <globals_settings.h>

#define ANIM_TIME_RB 150
#define ANIM_SCALE_RB 10 //en porciento

class MyFourStatesLabelAnimated : public QLabel
{
    Q_OBJECT

    enum{OFF_STATE, ON_STATE, THIRTH_STATE, FOURTH_STATE};
public:
    explicit MyFourStatesLabelAnimated(QWidget *parent = nullptr);
     ~MyFourStatesLabelAnimated();
    void setEditable(bool);
    void setTextInfo(QString information);
    int currentState(){
        return current_state;
    }
    void setCurrentState(int state){
        qDebug()<<"Setting: ->"<<state;
        current_state = state;
    }
    bool isFourthState();
    void setAnimationInit();
    void setAnimation(QPropertyAnimation *);
    void startAnimation(bool emit_clicked = true, int scale =ANIM_SCALE_RB, int anim_time =ANIM_TIME_RB);

    void setChecked(bool checked);
    bool isChecked();
    bool is_Enabled(){return enabled;}
    void set_Enabled(bool enable){ enabled = enable;}
    void setFourthState(bool enable);
public slots:
    void setThirdState(bool enable = true);

signals:
    void doubleClickedLabel();
    void mouseRightClicked();
    void mouseLeftClicked();
    void clicked();
    void send_text(QString);
    void mouseEntered(QPoint);

protected:
    void mousePressEvent(QMouseEvent *ev);
//    void mouseMoveEvent(QMouseEvent *ev);
//    void leaveEvent(QEvent *event);
//    void enterEvent(QEvent *event);
    void moveEvent(QMoveEvent *event);

private slots:
    void setAnimationEnd();
    void finalizadaAnimacion();
    void setFotoInit(const QString&);
    void startAnimationFromChild();
    void emitirClicked();
private:
    QString info ="";
    bool enteredEvent=false;
    bool animationOnGoing =false;
    QPropertyAnimation *animation=nullptr, *animation_child=nullptr;
    QRect startValue, child_startValue;
    QRect endValue, child_endValue;
    QSize maxSize, minSize, child_size, label_size;
    int anim_scale = ANIM_SCALE_RB;
    int anim_time = ANIM_TIME_RB;
    bool enabled=true;
    bool emit_enabled;
    int current_state = OFF_STATE;

};


#endif // MYFOURSTATESLABELANIMATED_H
