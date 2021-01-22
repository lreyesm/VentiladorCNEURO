/****************************************************************************
** Meta object code from reading C++ file 'screen_logo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "screen_logo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'screen_logo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Screen_Logo_t {
    QByteArrayData data[7];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Screen_Logo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Screen_Logo_t qt_meta_stringdata_Screen_Logo = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Screen_Logo"
QT_MOC_LITERAL(1, 12, 18), // "closed_screen_logo"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 20), // "setFechaHoraReceived"
QT_MOC_LITERAL(4, 53, 18), // "startLogoAnimation"
QT_MOC_LITERAL(5, 72, 17), // "close_screen_logo"
QT_MOC_LITERAL(6, 90, 17) // "on_l_logo_clicked"

    },
    "Screen_Logo\0closed_screen_logo\0\0"
    "setFechaHoraReceived\0startLogoAnimation\0"
    "close_screen_logo\0on_l_logo_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Screen_Logo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   43,    2, 0x0a /* Public */,
       5,    0,   44,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Screen_Logo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Screen_Logo *_t = static_cast<Screen_Logo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closed_screen_logo(); break;
        case 1: _t->setFechaHoraReceived((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 2: _t->startLogoAnimation(); break;
        case 3: _t->close_screen_logo(); break;
        case 4: _t->on_l_logo_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Screen_Logo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Screen_Logo::closed_screen_logo)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Screen_Logo::*)(QDateTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Screen_Logo::setFechaHoraReceived)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Screen_Logo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Screen_Logo.data,
      qt_meta_data_Screen_Logo,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Screen_Logo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Screen_Logo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Screen_Logo.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Screen_Logo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Screen_Logo::closed_screen_logo()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Screen_Logo::setFechaHoraReceived(QDateTime _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
