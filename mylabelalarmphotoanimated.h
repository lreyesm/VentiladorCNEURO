#ifndef MYLABELALARMPHOTOANIMATED_H
#define MYLABELALARMPHOTOANIMATED_H


#include <QLabel>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <globals_settings.h>
#include <QTimer>

#define ANIM_TIME_L 150
#define ANIM_SCALE_L 10

class MyLabelAlarmPhotoAnimated : public QLabel
{
    Q_OBJECT

    enum{ACTIVE_STATE, UNACTIVE_STATE};

public:
    explicit MyLabelAlarmPhotoAnimated(QWidget *parent = nullptr);
     ~MyLabelAlarmPhotoAnimated();
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

    void setConfigure();
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

    void setBackgroundColor(QColor color);
protected slots:
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void setAnimationEnd();
    void finalizadaAnimacion();
    void setFotoInit(const QString&);
    void emitirClicked();
    void changeColor();
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
    bool alarm_activated = false;
    bool isConfigure = false;

    QString getStringBackgroundColor(QColor color);
};

#endif // MYLABELALARMPHOTOANIMATED_H
