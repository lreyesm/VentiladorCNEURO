#include "myplaintextedit.h"

MyPlainTextEdit::MyPlainTextEdit(QWidget *parent) : QPlainTextEdit(parent)
{

}

MyPlainTextEdit::~MyPlainTextEdit()
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

void MyPlainTextEdit::mousePressEvent(QMouseEvent *e)
{
    emit pressedPlainTextEdit(this);
    QPlainTextEdit::mousePressEvent(e);
}
