/****************************************************************************
** Meta object code from reading C++ file 'mypointanimated.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mypointanimated.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mypointanimated.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyPointAnimated_t {
    QByteArrayData data[11];
    char stringdata0[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyPointAnimated_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyPointAnimated_t qt_meta_stringdata_MyPointAnimated = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MyPointAnimated"
QT_MOC_LITERAL(1, 16, 18), // "doubleClickedLabel"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 17), // "mouseRightClicked"
QT_MOC_LITERAL(4, 54, 16), // "mouseLeftClicked"
QT_MOC_LITERAL(5, 71, 7), // "clicked"
QT_MOC_LITERAL(6, 79, 12), // "mouseEntered"
QT_MOC_LITERAL(7, 92, 15), // "setAnimationEnd"
QT_MOC_LITERAL(8, 108, 19), // "finalizadaAnimacion"
QT_MOC_LITERAL(9, 128, 11), // "setFotoInit"
QT_MOC_LITERAL(10, 140, 13) // "emitirClicked"

    },
    "MyPointAnimated\0doubleClickedLabel\0\0"
    "mouseRightClicked\0mouseLeftClicked\0"
    "clicked\0mouseEntered\0setAnimationEnd\0"
    "finalizadaAnimacion\0setFotoInit\0"
    "emitirClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyPointAnimated[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    1,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   66,    2, 0x08 /* Private */,
       8,    0,   67,    2, 0x08 /* Private */,
       9,    1,   68,    2, 0x08 /* Private */,
      10,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void MyPointAnimated::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyPointAnimated *_t = static_cast<MyPointAnimated *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doubleClickedLabel(); break;
        case 1: _t->mouseRightClicked(); break;
        case 2: _t->mouseLeftClicked(); break;
        case 3: _t->clicked(); break;
        case 4: _t->mouseEntered((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: _t->setAnimationEnd(); break;
        case 6: _t->finalizadaAnimacion(); break;
        case 7: _t->setFotoInit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->emitirClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyPointAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyPointAnimated::doubleClickedLabel)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyPointAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyPointAnimated::mouseRightClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyPointAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyPointAnimated::mouseLeftClicked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyPointAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyPointAnimated::clicked)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MyPointAnimated::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyPointAnimated::mouseEntered)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyPointAnimated::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_MyPointAnimated.data,
      qt_meta_data_MyPointAnimated,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyPointAnimated::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyPointAnimated::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyPointAnimated.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int MyPointAnimated::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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
void MyPointAnimated::doubleClickedLabel()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MyPointAnimated::mouseRightClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MyPointAnimated::mouseLeftClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MyPointAnimated::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MyPointAnimated::mouseEntered(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
