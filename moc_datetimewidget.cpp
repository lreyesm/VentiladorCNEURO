/****************************************************************************
** Meta object code from reading C++ file 'datetimewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "datetimewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datetimewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DateTimeWidget_t {
    QByteArrayData data[21];
    char stringdata0[352];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DateTimeWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DateTimeWidget_t qt_meta_stringdata_DateTimeWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DateTimeWidget"
QT_MOC_LITERAL(1, 15, 9), // "fechaHora"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11), // "settedFecha"
QT_MOC_LITERAL(4, 38, 10), // "showCenter"
QT_MOC_LITERAL(5, 49, 11), // "setDateTime"
QT_MOC_LITERAL(6, 61, 2), // "dt"
QT_MOC_LITERAL(7, 64, 20), // "on_l_up_hour_clicked"
QT_MOC_LITERAL(8, 85, 22), // "on_l_down_hour_clicked"
QT_MOC_LITERAL(9, 108, 23), // "on_l_up_minutes_clicked"
QT_MOC_LITERAL(10, 132, 25), // "on_l_down_minutes_clicked"
QT_MOC_LITERAL(11, 158, 21), // "on_l_up_am_pm_clicked"
QT_MOC_LITERAL(12, 180, 23), // "on_l_down_am_pm_clicked"
QT_MOC_LITERAL(13, 204, 21), // "on_l_up_month_clicked"
QT_MOC_LITERAL(14, 226, 23), // "on_l_down_month_clicked"
QT_MOC_LITERAL(15, 250, 20), // "on_l_up_year_clicked"
QT_MOC_LITERAL(16, 271, 22), // "on_l_down_year_clicked"
QT_MOC_LITERAL(17, 294, 12), // "onClickedDay"
QT_MOC_LITERAL(18, 307, 8), // "day_text"
QT_MOC_LITERAL(19, 316, 18), // "on_l_am_pm_clicked"
QT_MOC_LITERAL(20, 335, 16) // "on_pb_ok_clicked"

    },
    "DateTimeWidget\0fechaHora\0\0settedFecha\0"
    "showCenter\0setDateTime\0dt\0"
    "on_l_up_hour_clicked\0on_l_down_hour_clicked\0"
    "on_l_up_minutes_clicked\0"
    "on_l_down_minutes_clicked\0"
    "on_l_up_am_pm_clicked\0on_l_down_am_pm_clicked\0"
    "on_l_up_month_clicked\0on_l_down_month_clicked\0"
    "on_l_up_year_clicked\0on_l_down_year_clicked\0"
    "onClickedDay\0day_text\0on_l_am_pm_clicked\0"
    "on_pb_ok_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DateTimeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       3,    0,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  103,    2, 0x0a /* Public */,
       5,    1,  104,    2, 0x0a /* Public */,
       7,    0,  107,    2, 0x08 /* Private */,
       8,    0,  108,    2, 0x08 /* Private */,
       9,    0,  109,    2, 0x08 /* Private */,
      10,    0,  110,    2, 0x08 /* Private */,
      11,    0,  111,    2, 0x08 /* Private */,
      12,    0,  112,    2, 0x08 /* Private */,
      13,    0,  113,    2, 0x08 /* Private */,
      14,    0,  114,    2, 0x08 /* Private */,
      15,    0,  115,    2, 0x08 /* Private */,
      16,    0,  116,    2, 0x08 /* Private */,
      17,    1,  117,    2, 0x08 /* Private */,
      19,    0,  120,    2, 0x08 /* Private */,
      20,    0,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDateTime,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,    6,
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
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DateTimeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DateTimeWidget *_t = static_cast<DateTimeWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fechaHora((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 1: _t->settedFecha(); break;
        case 2: _t->showCenter(); break;
        case 3: _t->setDateTime((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 4: _t->on_l_up_hour_clicked(); break;
        case 5: _t->on_l_down_hour_clicked(); break;
        case 6: _t->on_l_up_minutes_clicked(); break;
        case 7: _t->on_l_down_minutes_clicked(); break;
        case 8: _t->on_l_up_am_pm_clicked(); break;
        case 9: _t->on_l_down_am_pm_clicked(); break;
        case 10: _t->on_l_up_month_clicked(); break;
        case 11: _t->on_l_down_month_clicked(); break;
        case 12: _t->on_l_up_year_clicked(); break;
        case 13: _t->on_l_down_year_clicked(); break;
        case 14: _t->onClickedDay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->on_l_am_pm_clicked(); break;
        case 16: _t->on_pb_ok_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DateTimeWidget::*)(QDateTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateTimeWidget::fechaHora)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DateTimeWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateTimeWidget::settedFecha)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DateTimeWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DateTimeWidget.data,
      qt_meta_data_DateTimeWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DateTimeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DateTimeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DateTimeWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DateTimeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void DateTimeWidget::fechaHora(QDateTime _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DateTimeWidget::settedFecha()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
