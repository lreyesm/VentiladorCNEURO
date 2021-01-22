#ifndef BUTTERWORTHLOWPASSFILTER_H
#define BUTTERWORTHLOWPASSFILTER_H
#include "checkserialmessage.h"

class ButterworthLowPassFilter
{

public:
    ButterworthLowPassFilter(unsigned int size = UART_READ_DATA_FUNCTION_SIZE);
    double* filter(double* inputValue);

private:
    const unsigned int LowPassOrder = 6;

    double *a_coeficient = nullptr; //denominador
    double *b_coeficient = nullptr; //numerador

    double *lastInputValues = nullptr; //entradas anteriores (tamaño del orden)
    double *lastOutputValues = nullptr;//salidas anteriores (tamaño del orden)

    unsigned int m_array_size;//tamaño del orden

    double *array_filtered; //arreglo de salida filtrado
};

#endif // BUTTERWORTHLOWPASSFILTER_H
