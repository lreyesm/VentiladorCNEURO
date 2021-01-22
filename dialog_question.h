#ifndef DIALOG_QUESTION_H
#define DIALOG_QUESTION_H

#include <QWidget>

namespace Ui {
class Dialog_Question;
}

class Dialog_Question : public QWidget
{
    Q_OBJECT

public:
    explicit Dialog_Question(QWidget *parent = nullptr, QString title="", QString question="");
    ~Dialog_Question();

    void showCenter();

    void resizeWidgetQuestion(int w, int h);
signals:
    void accepted(int);
    void rejected(int);
    void aceptado();
    void cancelado();

private slots:
    void on_pb_cancel_clicked();
    void on_pb_ok_clicked();

private:
    Ui::Dialog_Question *ui;
};

#endif // DIALOG_QUESTION_H
