#include "mylineedit.h"

MyLineEdit::MyLineEdit(QWidget *parent) : QLineEdit(parent)
{

}

MyLineEdit::~MyLineEdit()
{}

//void MyLineEdit::focusInEvent(QFocusEvent *e)
//{
//  QLineEdit::focusInEvent(e);
//  //emit focussedIn(this);
//}

//void MyLineEdit::focusOutEvent(QFocusEvent *e)
//{
//  QLineEdit::focusOutEvent(e);
//  //emit focussedOut(this);
//}

void MyLineEdit::mousePressEvent(QMouseEvent *e)
{
    emit pressedLineEdit(this);
    QLineEdit::mousePressEvent(e);
}
