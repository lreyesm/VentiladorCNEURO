#ifndef LOADINGANIMATION_H
#define LOADINGANIMATION_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class LoadingAnimation;
}

class LoadingAnimation : public QWidget
{
    Q_OBJECT

public:
    explicit LoadingAnimation(QWidget *parent = nullptr, QString text = "");
    ~LoadingAnimation();

    QString getLoadingText();
    void setLoadingText(QString text);

    void showAnimation();
    void centerWidget();
    void showLoadingAnimation(bool show);
signals:
    void stoppedAnimation();
public slots:
    void startAnimation(); //tiempo de animacion en ms
    void stopAnimation();

private slots:
    void rotate_right();
private:
    Ui::LoadingAnimation *ui;
    QPixmap pix = QPixmap();
    QTimer timer;
    bool show_animation = true;
};

#endif // LOADINGANIMATION_H
