/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[102];
    char stringdata0[1566];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "hideAdvanceMenu"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 18), // "ventilationStarted"
QT_MOC_LITERAL(4, 47, 16), // "parseInformation"
QT_MOC_LITERAL(5, 64, 12), // "dataReceived"
QT_MOC_LITERAL(6, 77, 10), // "closeEvent"
QT_MOC_LITERAL(7, 88, 12), // "QCloseEvent*"
QT_MOC_LITERAL(8, 101, 5), // "event"
QT_MOC_LITERAL(9, 107, 15), // "mousePressEvent"
QT_MOC_LITERAL(10, 123, 12), // "QMouseEvent*"
QT_MOC_LITERAL(11, 136, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(12, 154, 18), // "disableAlarmButton"
QT_MOC_LITERAL(13, 173, 16), // "on_newConnection"
QT_MOC_LITERAL(14, 190, 11), // "readTCPData"
QT_MOC_LITERAL(15, 202, 5), // "bytes"
QT_MOC_LITERAL(16, 208, 14), // "write_TCP_Data"
QT_MOC_LITERAL(17, 223, 12), // "inicialState"
QT_MOC_LITERAL(18, 236, 8), // "hideMenu"
QT_MOC_LITERAL(19, 245, 18), // "on_l_power_clicked"
QT_MOC_LITERAL(20, 264, 17), // "on_l_menu_clicked"
QT_MOC_LITERAL(21, 282, 18), // "on_l_p_max_clicked"
QT_MOC_LITERAL(22, 301, 15), // "on_l_ie_clicked"
QT_MOC_LITERAL(23, 317, 16), // "on_l_bpm_clicked"
QT_MOC_LITERAL(24, 334, 17), // "on_l_modo_clicked"
QT_MOC_LITERAL(25, 352, 20), // "on_l_volumen_clicked"
QT_MOC_LITERAL(26, 373, 19), // "on_l_alarma_clicked"
QT_MOC_LITERAL(27, 393, 14), // "readSerialPort"
QT_MOC_LITERAL(28, 408, 4), // "data"
QT_MOC_LITERAL(29, 413, 7), // "setPmax"
QT_MOC_LITERAL(30, 421, 5), // "value"
QT_MOC_LITERAL(31, 427, 8), // "sendData"
QT_MOC_LITERAL(32, 436, 5), // "state"
QT_MOC_LITERAL(33, 442, 17), // "testGraphFunction"
QT_MOC_LITERAL(34, 460, 16), // "setVolumen_Tidal"
QT_MOC_LITERAL(35, 477, 6), // "setBPM"
QT_MOC_LITERAL(36, 484, 22), // "on_l_hide_menu_clicked"
QT_MOC_LITERAL(37, 507, 7), // "setMode"
QT_MOC_LITERAL(38, 515, 13), // "setRelacionIE"
QT_MOC_LITERAL(39, 529, 5), // "setTi"
QT_MOC_LITERAL(40, 535, 19), // "conexion_encontrada"
QT_MOC_LITERAL(41, 555, 7), // "puertos"
QT_MOC_LITERAL(42, 563, 22), // "decodificarInformacion"
QT_MOC_LITERAL(43, 586, 14), // "onTimeOutAlarm"
QT_MOC_LITERAL(44, 601, 17), // "comunicacionCaida"
QT_MOC_LITERAL(45, 619, 14), // "on_close_Alarm"
QT_MOC_LITERAL(46, 634, 22), // "afterMinutesAlarmCheck"
QT_MOC_LITERAL(47, 657, 7), // "setPmin"
QT_MOC_LITERAL(48, 665, 11), // "decodeAlarm"
QT_MOC_LITERAL(49, 677, 1), // "a"
QT_MOC_LITERAL(50, 679, 16), // "showMessageAlarm"
QT_MOC_LITERAL(51, 696, 5), // "alarm"
QT_MOC_LITERAL(52, 702, 17), // "closeMessageAlarm"
QT_MOC_LITERAL(53, 720, 12), // "setFechaHora"
QT_MOC_LITERAL(54, 733, 21), // "on_closed_Screen_logo"
QT_MOC_LITERAL(55, 755, 27), // "on_close_Screen_Calibration"
QT_MOC_LITERAL(56, 783, 28), // "on_close_Screen_Pacient_Data"
QT_MOC_LITERAL(57, 812, 13), // "PacientClass&"
QT_MOC_LITERAL(58, 826, 7), // "pacient"
QT_MOC_LITERAL(59, 834, 21), // "readSerialPortStandby"
QT_MOC_LITERAL(60, 856, 15), // "setStandByState"
QT_MOC_LITERAL(61, 872, 14), // "readTempSensor"
QT_MOC_LITERAL(62, 887, 13), // "temp_received"
QT_MOC_LITERAL(63, 901, 10), // "menuClosed"
QT_MOC_LITERAL(64, 912, 20), // "setFechaHoraReceived"
QT_MOC_LITERAL(65, 933, 9), // "date_time"
QT_MOC_LITERAL(66, 943, 10), // "setPacient"
QT_MOC_LITERAL(67, 954, 1), // "p"
QT_MOC_LITERAL(68, 956, 28), // "on_l_background_blur_clicked"
QT_MOC_LITERAL(69, 985, 11), // "soundBuzzer"
QT_MOC_LITERAL(70, 997, 13), // "turnOffBuzzer"
QT_MOC_LITERAL(71, 1011, 9), // "resetGPIO"
QT_MOC_LITERAL(72, 1021, 12), // "turnOffMotor"
QT_MOC_LITERAL(73, 1034, 11), // "enableMotor"
QT_MOC_LITERAL(74, 1046, 16), // "closeApplication"
QT_MOC_LITERAL(75, 1063, 12), // "turnOffRaspi"
QT_MOC_LITERAL(76, 1076, 2), // "ok"
QT_MOC_LITERAL(77, 1079, 15), // "questionTurnOff"
QT_MOC_LITERAL(78, 1095, 14), // "updateDateTime"
QT_MOC_LITERAL(79, 1110, 9), // "write_LOG"
QT_MOC_LITERAL(80, 1120, 6), // "evento"
QT_MOC_LITERAL(81, 1127, 17), // "requestPauseGraph"
QT_MOC_LITERAL(82, 1145, 18), // "errorDeCalibracion"
QT_MOC_LITERAL(83, 1164, 22), // "changeCalibrationState"
QT_MOC_LITERAL(84, 1187, 17), // "sendDataWithDelay"
QT_MOC_LITERAL(85, 1205, 18), // "setTriggerAsistido"
QT_MOC_LITERAL(86, 1224, 11), // "setTplateau"
QT_MOC_LITERAL(87, 1236, 26), // "on_accept_Calibation_Error"
QT_MOC_LITERAL(88, 1263, 3), // "res"
QT_MOC_LITERAL(89, 1267, 24), // "clearAlarmsNotifications"
QT_MOC_LITERAL(90, 1292, 14), // "alarmMenuShown"
QT_MOC_LITERAL(91, 1307, 5), // "shown"
QT_MOC_LITERAL(92, 1313, 30), // "disconnectSignalsWidgetOptions"
QT_MOC_LITERAL(93, 1344, 7), // "setFiO2"
QT_MOC_LITERAL(94, 1352, 8), // "setETCO2"
QT_MOC_LITERAL(95, 1361, 24), // "requestOxygenCalibration"
QT_MOC_LITERAL(96, 1386, 22), // "startOxygenCalibration"
QT_MOC_LITERAL(97, 1409, 34), // "startOxygenCalibration21Porce..."
QT_MOC_LITERAL(98, 1444, 35), // "startOxygenCalibration100Porc..."
QT_MOC_LITERAL(99, 1480, 37), // "requestOxygenCalibration100Po..."
QT_MOC_LITERAL(100, 1518, 24), // "successOxygenCalibration"
QT_MOC_LITERAL(101, 1543, 22) // "errorOxygenCalibration"

    },
    "MainWindow\0hideAdvanceMenu\0\0"
    "ventilationStarted\0parseInformation\0"
    "dataReceived\0closeEvent\0QCloseEvent*\0"
    "event\0mousePressEvent\0QMouseEvent*\0"
    "mouseReleaseEvent\0disableAlarmButton\0"
    "on_newConnection\0readTCPData\0bytes\0"
    "write_TCP_Data\0inicialState\0hideMenu\0"
    "on_l_power_clicked\0on_l_menu_clicked\0"
    "on_l_p_max_clicked\0on_l_ie_clicked\0"
    "on_l_bpm_clicked\0on_l_modo_clicked\0"
    "on_l_volumen_clicked\0on_l_alarma_clicked\0"
    "readSerialPort\0data\0setPmax\0value\0"
    "sendData\0state\0testGraphFunction\0"
    "setVolumen_Tidal\0setBPM\0on_l_hide_menu_clicked\0"
    "setMode\0setRelacionIE\0setTi\0"
    "conexion_encontrada\0puertos\0"
    "decodificarInformacion\0onTimeOutAlarm\0"
    "comunicacionCaida\0on_close_Alarm\0"
    "afterMinutesAlarmCheck\0setPmin\0"
    "decodeAlarm\0a\0showMessageAlarm\0alarm\0"
    "closeMessageAlarm\0setFechaHora\0"
    "on_closed_Screen_logo\0on_close_Screen_Calibration\0"
    "on_close_Screen_Pacient_Data\0PacientClass&\0"
    "pacient\0readSerialPortStandby\0"
    "setStandByState\0readTempSensor\0"
    "temp_received\0menuClosed\0setFechaHoraReceived\0"
    "date_time\0setPacient\0p\0"
    "on_l_background_blur_clicked\0soundBuzzer\0"
    "turnOffBuzzer\0resetGPIO\0turnOffMotor\0"
    "enableMotor\0closeApplication\0turnOffRaspi\0"
    "ok\0questionTurnOff\0updateDateTime\0"
    "write_LOG\0evento\0requestPauseGraph\0"
    "errorDeCalibracion\0changeCalibrationState\0"
    "sendDataWithDelay\0setTriggerAsistido\0"
    "setTplateau\0on_accept_Calibation_Error\0"
    "res\0clearAlarmsNotifications\0"
    "alarmMenuShown\0shown\0"
    "disconnectSignalsWidgetOptions\0setFiO2\0"
    "setETCO2\0requestOxygenCalibration\0"
    "startOxygenCalibration\0"
    "startOxygenCalibration21Porcentyle\0"
    "startOxygenCalibration100Porcentyle\0"
    "requestOxygenCalibration100Porcentyle\0"
    "successOxygenCalibration\0"
    "errorOxygenCalibration"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      83,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  429,    2, 0x06 /* Public */,
       3,    1,  430,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,  433,    2, 0x0a /* Public */,
       6,    1,  436,    2, 0x09 /* Protected */,
       9,    1,  439,    2, 0x09 /* Protected */,
      11,    1,  442,    2, 0x09 /* Protected */,
      12,    0,  445,    2, 0x08 /* Private */,
      13,    1,  446,    2, 0x08 /* Private */,
      14,    1,  449,    2, 0x08 /* Private */,
      16,    0,  452,    2, 0x08 /* Private */,
      17,    0,  453,    2, 0x08 /* Private */,
      18,    0,  454,    2, 0x08 /* Private */,
      19,    0,  455,    2, 0x08 /* Private */,
      20,    0,  456,    2, 0x08 /* Private */,
      21,    0,  457,    2, 0x08 /* Private */,
      22,    0,  458,    2, 0x08 /* Private */,
      23,    0,  459,    2, 0x08 /* Private */,
      24,    0,  460,    2, 0x08 /* Private */,
      25,    0,  461,    2, 0x08 /* Private */,
      26,    0,  462,    2, 0x08 /* Private */,
      27,    1,  463,    2, 0x08 /* Private */,
      29,    1,  466,    2, 0x08 /* Private */,
      31,    1,  469,    2, 0x08 /* Private */,
      31,    0,  472,    2, 0x28 /* Private | MethodCloned */,
      33,    0,  473,    2, 0x08 /* Private */,
      34,    1,  474,    2, 0x08 /* Private */,
      35,    1,  477,    2, 0x08 /* Private */,
      36,    0,  480,    2, 0x08 /* Private */,
      37,    1,  481,    2, 0x08 /* Private */,
      38,    1,  484,    2, 0x08 /* Private */,
      39,    1,  487,    2, 0x08 /* Private */,
      40,    1,  490,    2, 0x08 /* Private */,
      42,    1,  493,    2, 0x08 /* Private */,
      43,    0,  496,    2, 0x08 /* Private */,
      44,    0,  497,    2, 0x08 /* Private */,
      45,    0,  498,    2, 0x08 /* Private */,
      46,    0,  499,    2, 0x08 /* Private */,
      47,    1,  500,    2, 0x08 /* Private */,
      48,    1,  503,    2, 0x08 /* Private */,
      48,    0,  506,    2, 0x28 /* Private | MethodCloned */,
      50,    1,  507,    2, 0x08 /* Private */,
      52,    0,  510,    2, 0x08 /* Private */,
      53,    0,  511,    2, 0x08 /* Private */,
      54,    0,  512,    2, 0x08 /* Private */,
      55,    0,  513,    2, 0x08 /* Private */,
      56,    1,  514,    2, 0x08 /* Private */,
      59,    1,  517,    2, 0x08 /* Private */,
      60,    0,  520,    2, 0x08 /* Private */,
      61,    1,  521,    2, 0x08 /* Private */,
      63,    0,  524,    2, 0x08 /* Private */,
      64,    1,  525,    2, 0x08 /* Private */,
      66,    1,  528,    2, 0x08 /* Private */,
      68,    0,  531,    2, 0x08 /* Private */,
      69,    0,  532,    2, 0x08 /* Private */,
      70,    0,  533,    2, 0x08 /* Private */,
      71,    0,  534,    2, 0x08 /* Private */,
      72,    0,  535,    2, 0x08 /* Private */,
      73,    0,  536,    2, 0x08 /* Private */,
      74,    0,  537,    2, 0x08 /* Private */,
      75,    1,  538,    2, 0x08 /* Private */,
      75,    0,  541,    2, 0x28 /* Private | MethodCloned */,
      77,    0,  542,    2, 0x08 /* Private */,
      78,    0,  543,    2, 0x08 /* Private */,
      79,    1,  544,    2, 0x08 /* Private */,
      81,    0,  547,    2, 0x08 /* Private */,
      82,    0,  548,    2, 0x08 /* Private */,
      83,    0,  549,    2, 0x08 /* Private */,
      84,    0,  550,    2, 0x08 /* Private */,
      85,    1,  551,    2, 0x08 /* Private */,
      86,    1,  554,    2, 0x08 /* Private */,
      87,    1,  557,    2, 0x08 /* Private */,
      89,    0,  560,    2, 0x08 /* Private */,
      90,    1,  561,    2, 0x08 /* Private */,
      92,    0,  564,    2, 0x08 /* Private */,
      93,    1,  565,    2, 0x08 /* Private */,
      94,    1,  568,    2, 0x08 /* Private */,
      95,    0,  571,    2, 0x08 /* Private */,
      96,    1,  572,    2, 0x08 /* Private */,
      97,    1,  575,    2, 0x08 /* Private */,
      98,    1,  578,    2, 0x08 /* Private */,
      99,    0,  581,    2, 0x08 /* Private */,
     100,    0,  582,    2, 0x08 /* Private */,
     101,    0,  583,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Bool, QMetaType::QByteArray,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,    8,
    QMetaType::Void, 0x80000000 | 10,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QByteArray,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   28,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::QByteArray, QMetaType::Float,   32,
    QMetaType::QByteArray,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void, QMetaType::Float,   30,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::QStringList,   41,
    QMetaType::Bool, QMetaType::QByteArray,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Bool, QMetaType::Float,   49,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Float,   51,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 57,   58,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   62,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,   65,
    QMetaType::Void, 0x80000000 | 57,   67,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   76,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   80,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void, QMetaType::Double,   30,
    QMetaType::Void, QMetaType::Int,   88,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   91,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   76,
    QMetaType::Void, QMetaType::Int,   76,
    QMetaType::Void, QMetaType::Int,   76,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->hideAdvanceMenu(); break;
        case 1: _t->ventilationStarted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: { bool _r = _t->parseInformation((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 4: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->disableAlarmButton(); break;
        case 7: _t->on_newConnection((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->readTCPData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 9: _t->write_TCP_Data(); break;
        case 10: _t->inicialState(); break;
        case 11: _t->hideMenu(); break;
        case 12: _t->on_l_power_clicked(); break;
        case 13: _t->on_l_menu_clicked(); break;
        case 14: _t->on_l_p_max_clicked(); break;
        case 15: _t->on_l_ie_clicked(); break;
        case 16: _t->on_l_bpm_clicked(); break;
        case 17: _t->on_l_modo_clicked(); break;
        case 18: _t->on_l_volumen_clicked(); break;
        case 19: _t->on_l_alarma_clicked(); break;
        case 20: _t->readSerialPort((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 21: _t->setPmax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: { QByteArray _r = _t->sendData((*reinterpret_cast< float(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = std::move(_r); }  break;
        case 23: { QByteArray _r = _t->sendData();
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = std::move(_r); }  break;
        case 24: _t->testGraphFunction(); break;
        case 25: _t->setVolumen_Tidal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->setBPM((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->on_l_hide_menu_clicked(); break;
        case 28: _t->setMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->setRelacionIE((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 30: _t->setTi((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 31: _t->conexion_encontrada((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 32: { bool _r = _t->decodificarInformacion((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 33: _t->onTimeOutAlarm(); break;
        case 34: _t->comunicacionCaida(); break;
        case 35: _t->on_close_Alarm(); break;
        case 36: _t->afterMinutesAlarmCheck(); break;
        case 37: _t->setPmin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: { bool _r = _t->decodeAlarm((*reinterpret_cast< float(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 39: { bool _r = _t->decodeAlarm();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 40: _t->showMessageAlarm((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 41: _t->closeMessageAlarm(); break;
        case 42: _t->setFechaHora(); break;
        case 43: _t->on_closed_Screen_logo(); break;
        case 44: _t->on_close_Screen_Calibration(); break;
        case 45: _t->on_close_Screen_Pacient_Data((*reinterpret_cast< PacientClass(*)>(_a[1]))); break;
        case 46: _t->readSerialPortStandby((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 47: _t->setStandByState(); break;
        case 48: _t->readTempSensor((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 49: _t->menuClosed(); break;
        case 50: _t->setFechaHoraReceived((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 51: _t->setPacient((*reinterpret_cast< PacientClass(*)>(_a[1]))); break;
        case 52: _t->on_l_background_blur_clicked(); break;
        case 53: _t->soundBuzzer(); break;
        case 54: _t->turnOffBuzzer(); break;
        case 55: _t->resetGPIO(); break;
        case 56: _t->turnOffMotor(); break;
        case 57: _t->enableMotor(); break;
        case 58: _t->closeApplication(); break;
        case 59: _t->turnOffRaspi((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 60: _t->turnOffRaspi(); break;
        case 61: _t->questionTurnOff(); break;
        case 62: _t->updateDateTime(); break;
        case 63: _t->write_LOG((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 64: _t->requestPauseGraph(); break;
        case 65: _t->errorDeCalibracion(); break;
        case 66: _t->changeCalibrationState(); break;
        case 67: _t->sendDataWithDelay(); break;
        case 68: _t->setTriggerAsistido((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 69: _t->setTplateau((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 70: _t->on_accept_Calibation_Error((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 71: { bool _r = _t->clearAlarmsNotifications();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 72: _t->alarmMenuShown((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 73: _t->disconnectSignalsWidgetOptions(); break;
        case 74: _t->setFiO2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 75: _t->setETCO2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 76: _t->requestOxygenCalibration(); break;
        case 77: _t->startOxygenCalibration((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 78: _t->startOxygenCalibration21Porcentyle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 79: _t->startOxygenCalibration100Porcentyle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 80: _t->requestOxygenCalibration100Porcentyle(); break;
        case 81: _t->successOxygenCalibration(); break;
        case 82: _t->errorOxygenCalibration(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::hideAdvanceMenu)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::ventilationStarted)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 83)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 83;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 83)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 83;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::hideAdvanceMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::ventilationStarted(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
