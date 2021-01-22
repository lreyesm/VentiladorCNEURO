//#include <QException>
#include "butterworthlowpassfilter.h"


ButterworthLowPassFilter::ButterworthLowPassFilter(unsigned int array_size)
{
    m_array_size = array_size;

    b_coeficient = new double[LowPassOrder + 1];
    a_coeficient = new double[LowPassOrder + 1];

    lastInputValues = new double[LowPassOrder];
    lastOutputValues = new double[LowPassOrder];

    for (unsigned int i = 0; i < LowPassOrder; i++) {
        lastInputValues[i] = 0;
        lastOutputValues[i] = 0;
    }

    array_filtered = new double[array_size];

    b_coeficient[0] = 0.0000085765570732594062;
    b_coeficient[1] = 0.000051459342439556437;
    b_coeficient[2] = 0.00012864835609889108;
    b_coeficient[3] = 0.00017153114146518814;
    b_coeficient[4] = 0.0001286483560988911;
    b_coeficient[5] = 0.000051459342439556437;
    b_coeficient[6] = 0.0000085765570732594062;

    a_coeficient[0] =   1;
    a_coeficient[1] =   -4.7871354988521331;
    a_coeficient[2] =   9.6495177287219089;
    a_coeficient[3] =   -10.469078892543861;
    a_coeficient[4] =   6.4411118810080676;
    a_coeficient[5] =   -2.1290387500304502;
    a_coeficient[6] =   0.29517243134915505;
}

double* ButterworthLowPassFilter::filter(double* array_to_filtered)
{
//    double array_entrada[100]; //para depuracion
    for (unsigned int i = 0; i < m_array_size; i++) {
        array_filtered[i] = 0;
//        array_entrada[i] = array_to_filtered[i]; //para depuracion
    }

    for (unsigned int m = 0; m < m_array_size; m++) {
        if(m >= 6){
            double num = 0, den = 0;
            for (unsigned int i = 1; i <= 6; i++) {
                num += b_coeficient[i]*array_to_filtered[m-i];
                den -= a_coeficient[i]*array_filtered[m-i];
            }
            array_filtered[m] = b_coeficient[0]*array_to_filtered[m] + num +den;
        }
        else{
             double num = 0, den = 0;
            for (unsigned int i = 1; i <= LowPassOrder-m; i++) {
                num += b_coeficient[i+m]*lastInputValues[LowPassOrder - i];
                den -= a_coeficient[i+m]*lastOutputValues[LowPassOrder - i];
            }
            double num_m = 0, den_m = 0;
            for (unsigned int i = 1; i <= m; i++) {
                num_m += b_coeficient[i]*array_to_filtered[m-i];
                den_m -= a_coeficient[i]*array_filtered[m-i];
            }
            array_filtered[m] = b_coeficient[0]*array_to_filtered[m]
                    + num_m + den_m + num + den;
        }
    }
//    double array_salida[100];
//    double array_last_entrada[6]; //para depuracion
    for (unsigned int i = 0; i < LowPassOrder; i++) {
        lastInputValues[i] = array_to_filtered[i + m_array_size - LowPassOrder];
        lastOutputValues[i] = array_filtered[i + m_array_size - LowPassOrder];
//        array_last_salidas[i] = array_filtered[i + m_array_size - LowPassOrder];//para depuracion
//        array_last_entrada[i] = array_to_filtered[i + m_array_size - LowPassOrder];//para depuracion
    }

//    for (unsigned int i = 0; i < m_array_size; i++) {
//        array_salida[i] = array_filtered[i];
//    }

    return array_filtered;
}











