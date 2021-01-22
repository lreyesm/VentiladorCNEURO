/****************************************************************************
** Meta object code from reading C++ file 'vt_communication_interface_wrapper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "vt_communication_interface_wrapper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vt_communication_interface_wrapper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_vt_communication_interface_wrapper_t {
    QByteArrayData data[10];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vt_communication_interface_wrapper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vt_communication_interface_wrapper_t qt_meta_stringdata_vt_communication_interface_wrapper = {
    {
QT_MOC_LITERAL(0, 0, 34), // "vt_communication_interface_wr..."
QT_MOC_LITERAL(1, 35, 12), // "packageReady"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 14), // "commanExecuted"
QT_MOC_LITERAL(4, 64, 19), // "allPackagesReceived"
QT_MOC_LITERAL(5, 84, 13), // "timeoutSignal"
QT_MOC_LITERAL(6, 98, 15), // "onDataAvailable"
QT_MOC_LITERAL(7, 114, 14), // "processPackage"
QT_MOC_LITERAL(8, 129, 21), // "clearReceivedPackages"
QT_MOC_LITERAL(9, 151, 16) // "receptiontimeout"

    },
    "vt_communication_interface_wrapper\0"
    "packageReady\0\0commanExecuted\0"
    "allPackagesReceived\0timeoutSignal\0"
    "onDataAvailable\0processPackage\0"
    "clearReceivedPackages\0receptiontimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vt_communication_interface_wrapper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    1,   57,    2, 0x06 /* Public */,
       4,    0,   60,    2, 0x06 /* Public */,
       5,    1,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   64,    2, 0x08 /* Private */,
       7,    1,   65,    2, 0x08 /* Private */,
       8,    0,   68,    2, 0x08 /* Private */,
       9,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void vt_communication_interface_wrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vt_communication_interface_wrapper *_t = static_cast<vt_communication_interface_wrapper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->packageReady((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->commanExecuted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->allPackagesReceived(); break;
        case 3: _t->timeoutSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onDataAvailable(); break;
        case 5: _t->processPackage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: _t->clearReceivedPackages(); break;
        case 7: _t->receptiontimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (vt_communication_interface_wrapper::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&vt_communication_interface_wrapper::packageReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (vt_communication_interface_wrapper::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&vt_communication_interface_wrapper::commanExecuted)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (vt_communication_interface_wrapper::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&vt_communication_interface_wrapper::allPackagesReceived)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (vt_communication_interface_wrapper::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&vt_communication_interface_wrapper::timeoutSignal)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject vt_communication_interface_wrapper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_vt_communication_interface_wrapper.data,
      qt_meta_data_vt_communication_interface_wrapper,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *vt_communication_interface_wrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vt_communication_interface_wrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_vt_communication_interface_wrapper.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int vt_communication_interface_wrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void vt_communication_interface_wrapper::packageReady(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void vt_communication_interface_wrapper::commanExecuted(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void vt_communication_interface_wrapper::allPackagesReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void vt_communication_interface_wrapper::timeoutSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
