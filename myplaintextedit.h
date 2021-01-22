#ifndef MYPLAINTEXTEDIT_H
#define MYPLAINTEXTEDIT_H

#include <QPlainTextEdit>

class MyPlainTextEdit : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit MyPlainTextEdit(QWidget *parent = nullptr);
    ~MyPlainTextEdit();

signals:
    void pressedPlainTextEdit(QPlainTextEdit *widget);
//    void focussedIn(QLineEdit *widget);
//    void focussedOut(QLineEdit *widget);

protected:
//    virtual void focusInEvent(QFocusEvent *e);
//    virtual void focusOutEvent(QFocusEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);

};

#endif // MYPLAINTEXTEDIT_H
