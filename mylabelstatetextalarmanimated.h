#ifndef MYLABELSTATETEXTALARMANIMATED_H
#define MYLABELSTATETEXTALARMANIMATED_H

#include "mytextanimated.h"
#include <QTimer>

#define ANIM_TIME_RB 150
#define ANIM_SCALE_RB 10

class MyLabelStateTextAlarmAnimated : public QLabel
{
    Q_OBJECT

    enum{ACTIVE_STATE, UNACTIVE_STATE};
public:

    explicit MyLabelStateTextAlarmAnimated(QWidget *parent = nullptr);
    ~MyLabelStateTextAlarmAnimated();
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

    void setActiveTextString(QString text);
    QString getActiveText();
    QString getDefaultText();
    void setBackgroundImage(const QString image_filename);
    void setActiveTextColor(QColor text_active_color, QColor text_unactive_color);
    void setDefautTextString(QString text);
    QColor getTextColorCurrent();
    QColor getTextDefaultCurrent();
    QColor getTextActiveColor();
public slots:
   void startAlarm(int interval = 1000);
    void stopAlarm();
signals:
    void doubleClickedLabel();
    void mouseRightClicked();
    void mouseLeftClicked();
    void clicked();
    void mouseEntered(QPoint);
    void stopedAlarm();
    void startedAlarm(int);
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
    void changeColor();

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

    QString activeText = "0";
    QString defaultText = "0";

    bool alarm_activated;
    QTimer timer_alarm;



    int currentState = UNACTIVE_STATE;
    QString getStringBackgroundColor(QColor color);

    QColor text_activeColor;
    QColor text_unactiveColor;
};

#endif // MYLABELSTATETEXTALARMANIMATED_H
