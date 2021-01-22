#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr, QString title = "", QString question = "");
    ~Dialog();

    void showCenter();
private slots:
    void on_pb_cancel_clicked();
    void on_pb_ok_clicked();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
