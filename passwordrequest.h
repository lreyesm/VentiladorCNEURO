#ifndef PASSWORDREQUEST_H
#define PASSWORDREQUEST_H

#include <QWidget>
#include <QLineEdit>
#include"keyboard.h"

namespace Ui {
class PasswordRequest;
}

class PasswordRequest : public QWidget
{
    Q_OBJECT

public:
    explicit PasswordRequest(QWidget *parent = nullptr);
    ~PasswordRequest();

    void showCenter();

signals:
    void loginCorrect();
    void loginFailed();
private slots:
    void on_pb_ok_clicked();
    void on_pb_show_hide_password_clicked();

    void showKeyBoard(QLineEdit *widget);
private:
    Ui::PasswordRequest *ui;
    bool showPassword = false;
    KeyBoard *teclado = nullptr;
    void animateWidgetDownToUp(QWidget *widget, int anim_time=300);
    void animateWidgetUpToDown(QWidget *widget, int anim_time=300);
};

#endif // PASSWORDREQUEST_H
