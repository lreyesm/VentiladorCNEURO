#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit MyLineEdit(QWidget *parent = nullptr);
    ~MyLineEdit();

signals:
    void pressedLineEdit(QLineEdit *widget);
//    void focussedIn(QLineEdit *widget);
//    void focussedOut(QLineEdit *widget);

protected:
//    virtual void focusInEvent(QFocusEvent *e);
//    virtual void focusOutEvent(QFocusEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);

};

#endif // MYLINEEDIT_H
