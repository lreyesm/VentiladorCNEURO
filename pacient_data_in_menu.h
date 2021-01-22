#ifndef PACIENT_DATA_IN_MENU_H
#define PACIENT_DATA_IN_MENU_H

#include <QWidget>
#include "keyboard.h"
#include "pacientclass.h"

namespace Ui {
class Pacient_Data_in_Menu;
}

class Pacient_Data_in_Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Pacient_Data_in_Menu(QWidget *parent = nullptr);
    ~Pacient_Data_in_Menu();

public slots:
    void setPacientData(const PacientClass &);
signals:
    void aceptedChanges();
    void sendPacient(PacientClass &);
private slots:
    void showKeyBoardonPlainTextEdit(QPlainTextEdit *widget);
    void showKeyBoard(QLineEdit *widget);
    void moveDownPlaintextEdit();
    void on_pb_aceptar_clicked();

    void on_le_edad_editingFinished();

    void on_le_height_editingFinished();

    void on_le_weight_editingFinished();

private:
    Ui::Pacient_Data_in_Menu *ui;
    KeyBoard *teclado = nullptr;
    void animateWidgetUpToDown(QWidget *widget, int anim_time=300);
    void animateWidgetDownToUp(QWidget *widget, int anim_time=300);
    bool pt_on_upPosition = false;
    PacientClass pacient;
};

#endif // PACIENT_DATA_IN_MENU_H
