/****************************************************************************
** Meta object code from reading C++ file 'mylabellongpressanimated.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mylabellongpressanimated.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mylabellongpressanimated.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyLabelLongPressAnimated_t {
    QByteArrayData data[14];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyLabelLongPressAnimated_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyLabelLongPressAnimated_t qt_meta_stringdata_MyLabelLongPressAnimated = {
    {
QT_MOC_LITERAL(0, 0, 24), // "MyLabelLongPressAnimated"
QT_MOC_LITERAL(1, 25, 18), // "doubleClickedLabel"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 16), // "mouseLeftClicked"
QT_MOC_LITERAL(4, 62, 7), // "pressed"
QT_MOC_LITERAL(5, 70, 7), // "release"
QT_MOC_LITERAL(6, 78, 7), // "clicked"
QT_MOC_LITERAL(7, 86, 9), // "send_text"
QT_MOC_LITERAL(8, 96, 12), // "mouseEntered"
QT_MOC_LITERAL(9, 109, 10), // "hideChilds"
QT_MOC_LITERAL(10, 120, 15), // "setAnimationEnd"
QT_MOC_LITERAL(11, 136, 19), // "finalizadaAnimacion"
QT_MOC_LITERAL(12, 156, 11), // "setFotoInit"
QT_MOC_LITERAL(13, 168, 13) // "emitirClicked"

    },
    "MyLabelLongPressAnimated\0doubleClickedLabel\0"
    "\0mouseLeftClicked\0pressed\0release\0"
    "clicked\0send_text\0mouseEntered\0"
    "hideChilds\0setAnimationEnd\0"
    "finalizadaAnimacion\0setFotoInit\0"
    "emitirClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyLabelLongPressAnimated[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    1,   75,    2, 0x06 /* Public */,
       4,    0,   78,    2, 0x06 /* Public */,
       5,    0,   79,    2, 0x06 /* Public */,
       6,    0,   80,    2, 0x06 /* Public */,
       7,    1,   81,    2, 0x06 /* Public */,
       8,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   87,    2, 0x0a /* Public */,
      10,    0,   88,    2, 0x08 /* Private */,
      11,    0,   89,    2, 0x08 /* Private */,
      12,    1,   90,    2, 0x08 /* Private */,
      13,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QPoint,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void MyLabelLongPressAnimated::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyLabelLongPressAnimated *_t = static_cast<MyLabelLongPressAnimated *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doubleClickedLabel(); break;
        case 1: _t->mouseLeftClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->pressed(); break;
        case 3: _t->release(); break;
        case 4: _t->clicked(); break;
        case 5: _t->send_text((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->mouseEntered((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 7: _t->hideChilds(); break;
        case 8: _t->setAnimationEnd(); break;
        case 9: _t->finalizadaAnimacion(); break;
        case 10: _t->setFotoInit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->emitirClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyLabelLongPressAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabelLongPressAnimated::doubleClickedLabel)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyLabelLongPressAnimated::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabelLongPressAnimated::mouseLeftClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyLabelLongPressAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabelLongPressAnimated::pressed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyLabelLongPressAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabelLongPressAnimated::release)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MyLabelLongPressAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabelLongPressAnimated::clicked)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MyLabelLongPressAnimated::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabelLongPressAnimated::send_text)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MyLabelLongPressAnimated::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabelLongPressAnimated::mouseEntered)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyLabelLongPressAnimated::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_MyLabelLongPressAnimated.data,
      qt_meta_data_MyLabelLongPressAnimated,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyLabelLongPressAnimated::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyLabelLongPressAnimated::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyLabelLongPressAnimated.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int MyLabelLongPressAnimated::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MyLabelLongPressAnimated::doubleClickedLabel()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MyLabelLongPressAnimated::mouseLeftClicked(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyLabelLongPressAnimated::pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MyLabelLongPressAnimated::release()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MyLabelLongPressAnimated::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MyLabelLongPressAnimated::send_text(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MyLabelLongPressAnimated::mouseEntered(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
