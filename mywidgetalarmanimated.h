#ifndef MYWIDGETALARMANIMATED_H
#define MYWIDGETALARMANIMATED_H

#include <QMouseEvent>
#include <QPropertyAnimation>
#include <globals_settings.h>
#include <QTimer>
#include "mywidgetanimated.h"

#define ANIM_TIME_L 150
#define ANIM_SCALE_L 10

class MyWidgetAlarmAnimated : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidgetAlarmAnimated(QWidget *parent = nullptr);
     ~MyWidgetAlarmAnimated();
    void setEditable(bool);
    void setText(QString text);
    QStringList getText();
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
    void setActiveColor(QColor color = color_high_priority, QColor text_color = QColor(Qt::black));
    void removeAlarm(QString text);
    bool isActiveState();
    bool isActiveAlarm(QString alarm);
    void setBlankState();
    QString getLastAlarm();
    void removeAlarmAltaPriority(QString text);
    bool hasHighPriorityAlarms();
    void setActiveAlarm(QString text);
    QString getActiveAlarm();
signals:
    void showing_menu_alarms(bool);
    void doubleClickedLabel();
    void mouseLeftClicked(QString);
    void pressed();
    void pressEvent(QMouseEvent *ev);
    void clicked();
    void mouseEntered(QPoint);
    void nuevaAlarma(QString);
    void removidaAlarma(QString);
    void alarm_count(QString);
    void startedAlarm(int);
    void stopedAlarm();
    void changedColor(QColor);
    void hidingWidgetAlarms();

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);

public slots:
    void hideChilds();

    void startAlarm(int interval = 500);
    void stopAlarm();
    void cleanHighPriorityAlarms();
    void changeColor();

private slots:
    void setAnimationEnd();
    void finalizadaAnimacion();
    void emitirClicked();

    void animateWidgetUpToDown(QWidget *widget, int anim_time = 250);
    void animateWidgetDownToUp(QWidget *widget, int anim_time = 250);
    void showWidgetNotifications();
    void hideWidgetNotifications();
    void resizeWidgetNotifications();
    void alarmaLimpiada(QObject *widget);
    void hideMenuAlarms();
    void loadEraseHighPriority();
private:
    MyWidgetAnimated *widget_notifications;
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
    QList<QColor> posibles_actives_colors;
    QColor currentColor = QColor(Qt::transparent);
    QColor activeColor = color_high_priority;
    QColor text_unactiveColor = QColor(Qt::white);
    QColor text_activeColor = QColor(Qt::white);
    bool alarm_activated = false;

    QString getStringBackgroundColor(QColor color);
    QStringList listaAlarmas, listaAlarmas_AltaPrioridad, salvaLista;
    void deleteAllChilds();
    void setOffState();


    QMap<int, QString> mapaAlarmas;

    void fillMapAlarms();
    int getPriorityOfAlarm(int alarm_code);
    int getAlarmCode(QString alarm);
    void deleteOneAlarm(QString alarm);
    QString getAlarmString(int code_alarm);
    void removeAlarmDeLista(QString text);
    void removeAlarmDeListaAltaPrioridad(QString text);
    bool hasChild(QString n);
    void addAllAlarmsToWidget();
    void addHighPriorityAlarmsToWidget();
    int countTotalAlarmas();
    bool isHighPriorityAlarm(QString text);
    QString alarmSaved = "", activeAlarm="";
    void transformOneToActive(QString alarm);
    void transformOneToUnActive(QString alarm);
};

#endif // MYWIDGETALARMANIMATED_H
