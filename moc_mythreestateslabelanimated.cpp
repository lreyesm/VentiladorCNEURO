/****************************************************************************
** Meta object code from reading C++ file 'mythreestateslabelanimated.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mythreestateslabelanimated.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mythreestateslabelanimated.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyThreeStatesLabelAnimated_t {
    QByteArrayData data[15];
    char stringdata0[220];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyThreeStatesLabelAnimated_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyThreeStatesLabelAnimated_t qt_meta_stringdata_MyThreeStatesLabelAnimated = {
    {
QT_MOC_LITERAL(0, 0, 26), // "MyThreeStatesLabelAnimated"
QT_MOC_LITERAL(1, 27, 18), // "doubleClickedLabel"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 17), // "mouseRightClicked"
QT_MOC_LITERAL(4, 65, 16), // "mouseLeftClicked"
QT_MOC_LITERAL(5, 82, 7), // "clicked"
QT_MOC_LITERAL(6, 90, 9), // "send_text"
QT_MOC_LITERAL(7, 100, 12), // "mouseEntered"
QT_MOC_LITERAL(8, 113, 13), // "setThirdState"
QT_MOC_LITERAL(9, 127, 6), // "enable"
QT_MOC_LITERAL(10, 134, 15), // "setAnimationEnd"
QT_MOC_LITERAL(11, 150, 19), // "finalizadaAnimacion"
QT_MOC_LITERAL(12, 170, 11), // "setFotoInit"
QT_MOC_LITERAL(13, 182, 23), // "startAnimationFromChild"
QT_MOC_LITERAL(14, 206, 13) // "emitirClicked"

    },
    "MyThreeStatesLabelAnimated\0"
    "doubleClickedLabel\0\0mouseRightClicked\0"
    "mouseLeftClicked\0clicked\0send_text\0"
    "mouseEntered\0setThirdState\0enable\0"
    "setAnimationEnd\0finalizadaAnimacion\0"
    "setFotoInit\0startAnimationFromChild\0"
    "emitirClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyThreeStatesLabelAnimated[] = {

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
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,
       5,    0,   82,    2, 0x06 /* Public */,
       6,    1,   83,    2, 0x06 /* Public */,
       7,    1,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   89,    2, 0x0a /* Public */,
       8,    0,   92,    2, 0x2a /* Public | MethodCloned */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    1,   95,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QPoint,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyThreeStatesLabelAnimated::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyThreeStatesLabelAnimated *_t = static_cast<MyThreeStatesLabelAnimated *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doubleClickedLabel(); break;
        case 1: _t->mouseRightClicked(); break;
        case 2: _t->mouseLeftClicked(); break;
        case 3: _t->clicked(); break;
        case 4: _t->send_text((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->mouseEntered((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 6: _t->setThirdState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setThirdState(); break;
        case 8: _t->setAnimationEnd(); break;
        case 9: _t->finalizadaAnimacion(); break;
        case 10: _t->setFotoInit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->startAnimationFromChild(); break;
        case 12: _t->emitirClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyThreeStatesLabelAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyThreeStatesLabelAnimated::doubleClickedLabel)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyThreeStatesLabelAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyThreeStatesLabelAnimated::mouseRightClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyThreeStatesLabelAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyThreeStatesLabelAnimated::mouseLeftClicked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyThreeStatesLabelAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyThreeStatesLabelAnimated::clicked)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MyThreeStatesLabelAnimated::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyThreeStatesLabelAnimated::send_text)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MyThreeStatesLabelAnimated::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyThreeStatesLabelAnimated::mouseEntered)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyThreeStatesLabelAnimated::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_MyThreeStatesLabelAnimated.data,
      qt_meta_data_MyThreeStatesLabelAnimated,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyThreeStatesLabelAnimated::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyThreeStatesLabelAnimated::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyThreeStatesLabelAnimated.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int MyThreeStatesLabelAnimated::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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
void MyThreeStatesLabelAnimated::doubleClickedLabel()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MyThreeStatesLabelAnimated::mouseRightClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MyThreeStatesLabelAnimated::mouseLeftClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MyThreeStatesLabelAnimated::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MyThreeStatesLabelAnimated::send_text(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyThreeStatesLabelAnimated::mouseEntered(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
