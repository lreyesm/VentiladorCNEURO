/****************************************************************************
** Meta object code from reading C++ file 'plot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "plot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Plot_t {
    QByteArrayData data[17];
    char stringdata0[221];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Plot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Plot_t qt_meta_stringdata_Plot = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Plot"
QT_MOC_LITERAL(1, 5, 10), // "pressEvent"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 12), // "QMouseEvent*"
QT_MOC_LITERAL(4, 30, 12), // "releaseEvent"
QT_MOC_LITERAL(5, 43, 12), // "pressAndHold"
QT_MOC_LITERAL(6, 56, 17), // "shiftStateChanged"
QT_MOC_LITERAL(7, 74, 21), // "maximize_graph_signal"
QT_MOC_LITERAL(8, 96, 21), // "minimize_graph_signal"
QT_MOC_LITERAL(9, 118, 15), // "mousePressEvent"
QT_MOC_LITERAL(10, 134, 5), // "event"
QT_MOC_LITERAL(11, 140, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(12, 158, 10), // "pauseGraph"
QT_MOC_LITERAL(13, 169, 9), // "playGraph"
QT_MOC_LITERAL(14, 179, 11), // "updateGraph"
QT_MOC_LITERAL(15, 191, 12), // "force_replot"
QT_MOC_LITERAL(16, 204, 16) // "emitPressAndHold"

    },
    "Plot\0pressEvent\0\0QMouseEvent*\0"
    "releaseEvent\0pressAndHold\0shiftStateChanged\0"
    "maximize_graph_signal\0minimize_graph_signal\0"
    "mousePressEvent\0event\0mouseReleaseEvent\0"
    "pauseGraph\0playGraph\0updateGraph\0"
    "force_replot\0emitPressAndHold"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Plot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       5,    0,   85,    2, 0x06 /* Public */,
       6,    1,   86,    2, 0x06 /* Public */,
       7,    1,   89,    2, 0x06 /* Public */,
       8,    1,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   95,    2, 0x09 /* Protected */,
      11,    1,   98,    2, 0x09 /* Protected */,
      12,    0,  101,    2, 0x0a /* Public */,
      13,    0,  102,    2, 0x0a /* Public */,
      14,    1,  103,    2, 0x0a /* Public */,
      14,    0,  106,    2, 0x2a /* Public | MethodCloned */,
      16,    0,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,   10,
    QMetaType::Void, 0x80000000 | 3,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Plot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Plot *_t = static_cast<Plot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->releaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->pressAndHold(); break;
        case 3: _t->shiftStateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->maximize_graph_signal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->minimize_graph_signal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 8: _t->pauseGraph(); break;
        case 9: _t->playGraph(); break;
        case 10: _t->updateGraph((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->updateGraph(); break;
        case 12: _t->emitPressAndHold(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Plot::*)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Plot::pressEvent)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Plot::*)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Plot::releaseEvent)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Plot::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Plot::pressAndHold)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Plot::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Plot::shiftStateChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Plot::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Plot::maximize_graph_signal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Plot::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Plot::minimize_graph_signal)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Plot::staticMetaObject = {
    { &QCustomPlot::staticMetaObject, qt_meta_stringdata_Plot.data,
      qt_meta_data_Plot,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Plot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Plot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Plot.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QOpenGLFunctions"))
        return static_cast< QOpenGLFunctions*>(this);
    return QCustomPlot::qt_metacast(_clname);
}

int Plot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCustomPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Plot::pressEvent(QMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Plot::releaseEvent(QMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Plot::pressAndHold()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Plot::shiftStateChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Plot::maximize_graph_signal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Plot::minimize_graph_signal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
