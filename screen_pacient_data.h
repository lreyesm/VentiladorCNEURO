#ifndef SCREEN_PACIENT_DATA_H
#define SCREEN_PACIENT_DATA_H

#include <QWidget>
#include "serialport.h"
#include "pacientclass.h"
#include "keyboard.h"
#include <QLineEdit>
#include "screen_datetime.h"

namespace Ui {
class Screen_Pacient_Data;
}

class Screen_Pacient_Data : public QWidget
{
    Q_OBJECT

public:
    explicit Screen_Pacient_Data(QWidget *parent = nullptr);
    ~Screen_Pacient_Data();

    static int fitHeightMaleWithData(int height);
    static int fitHeightFemaleWithData(int height);

    static int estimateVolumen(int volumen);

signals:
    void closed_Screen_Pacient_Data(PacientClass &);
    void settedFechaHora(QDateTime);
private slots:
    void close_Screen_Pacient_Data();
    void on_pb_aceptar_clicked();
    void on_pb_ajustar_fecha_hora_clicked();

    void showKeyBoard(QLineEdit *widget);
    void showKeyBoardonPlainTextEdit(QPlainTextEdit *widget);
    void moveDownPlaintextEdit();
    void setFechaHora(QDateTime);
    void on_le_height_editingFinished();

    void on_le_edad_editingFinished();

    void on_le_weight_editingFinished();

private:
    Ui::Screen_Pacient_Data *ui;
    KeyBoard *teclado = nullptr;
    void animateWidgetDownToUp(QWidget *widget, int anim_time=300);
    void animateWidgetUpToDown(QWidget *widget, int anim_time=300);
    bool pt_on_upPosition= false;


};

#endif // SCREEN_PACIENT_DATA_H
