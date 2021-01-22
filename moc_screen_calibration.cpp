/****************************************************************************
** Meta object code from reading C++ file 'screen_calibration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "screen_calibration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'screen_calibration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Screen_Calibration_t {
    QByteArrayData data[12];
    char stringdata0[274];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Screen_Calibration_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Screen_Calibration_t qt_meta_stringdata_Screen_Calibration = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Screen_Calibration"
QT_MOC_LITERAL(1, 19, 25), // "closed_screen_calibration"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 22), // "initPresureCalibration"
QT_MOC_LITERAL(4, 69, 20), // "incrementProgressBar"
QT_MOC_LITERAL(5, 90, 5), // "value"
QT_MOC_LITERAL(6, 96, 39), // "on_progressBar_calibracion_va..."
QT_MOC_LITERAL(7, 136, 24), // "close_Screen_Calibration"
QT_MOC_LITERAL(8, 161, 22), // "on_pb_continue_clicked"
QT_MOC_LITERAL(9, 184, 32), // "updateProgresBarCalibrationMotor"
QT_MOC_LITERAL(10, 217, 34), // "updateProgresBarCalibrationPr..."
QT_MOC_LITERAL(11, 252, 21) // "on_pb_modo_at_clicked"

    },
    "Screen_Calibration\0closed_screen_calibration\0"
    "\0initPresureCalibration\0incrementProgressBar\0"
    "value\0on_progressBar_calibracion_valueChanged\0"
    "close_Screen_Calibration\0"
    "on_pb_continue_clicked\0"
    "updateProgresBarCalibrationMotor\0"
    "updateProgresBarCalibrationPresion\0"
    "on_pb_modo_at_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Screen_Calibration[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x0a /* Public */,
       4,    1,   61,    2, 0x0a /* Public */,
       6,    1,   64,    2, 0x08 /* Private */,
       7,    0,   67,    2, 0x08 /* Private */,
       8,    0,   68,    2, 0x08 /* Private */,
       9,    0,   69,    2, 0x08 /* Private */,
      10,    0,   70,    2, 0x08 /* Private */,
      11,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Screen_Calibration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Screen_Calibration *_t = static_cast<Screen_Calibration *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closed_screen_calibration(); break;
        case 1: _t->initPresureCalibration(); break;
        case 2: _t->incrementProgressBar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_progressBar_calibracion_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->close_Screen_Calibration(); break;
        case 5: _t->on_pb_continue_clicked(); break;
        case 6: _t->updateProgresBarCalibrationMotor(); break;
        case 7: _t->updateProgresBarCalibrationPresion(); break;
        case 8: _t->on_pb_modo_at_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Screen_Calibration::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Screen_Calibration::closed_screen_calibration)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Screen_Calibration::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Screen_Calibration.data,
      qt_meta_data_Screen_Calibration,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Screen_Calibration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Screen_Calibration::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Screen_Calibration.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Screen_Calibration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Screen_Calibration::closed_screen_calibration()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
