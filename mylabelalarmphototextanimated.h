#ifndef MYLABELALARMPHOTOTEXTANIMATED_H
#define MYLABELALARMPHOTOTEXTANIMATED_H


#include <QLabel>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <globals_settings.h>
#include <QTimer>

#define ANIM_TIME_L 150
#define ANIM_SCALE_L 10

class MyLabelAlarmPhotoTextAnimated : public QLabel
{
    Q_OBJECT

    enum{ACTIVE_STATE, UNACTIVE_STATE};

public:
    explicit MyLabelAlarmPhotoTextAnimated(QWidget *parent = nullptr);
     ~MyLabelAlarmPhotoTextAnimated();
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
    void startAnimation(int delay = 0, int scale =ANIM_SCALE_L, int anim_time =ANIM_TIME_L);

    void setChecked(bool checked);
    bool isChecked();
    void setBackgroundImage(const QString image_filename);

    bool isActiveState();
signals:
    void doubleClickedLabel();
    void mouseLeftClicked(QString);
    void pressed();
    void clicked();
    void mouseEntered(QPoint);
    void startedAlarm(int);
    void stopedAlarm();


public slots:
    void hideChilds();
    void startAlarm(int interval = 500);
    void stopAlarm();
    void changeColor();
    void setPhotoColor(QColor);
protected slots:
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void setAnimationEnd();
    void finalizadaAnimacion();
    void setFotoInit(const QString&);
    void emitirClicked();

private:
    QString info ="";
    bool activated_state=false;
    bool animationOnGoing =false;
    QPropertyAnimation *animation=nullptr;
    QRect startValue;
    QRect endValue;
    QSize maxSize;
    int anim_scale = ANIM_SCALE_L;
    int anim_time = ANIM_TIME_L;
    QTimer timer_alarm;
    QColor currentState = UNACTIVE_STATE;

    QColor text_activeColor = QColor(Qt::white);
    QColor text_unactiveColor = QColor(50,50,50);
    bool alarm_activated = false;

    QString getStringBackgroundColor(QColor color);
};
#endif // MYLABELALARMPHOTOTEXTANIMATED_H
