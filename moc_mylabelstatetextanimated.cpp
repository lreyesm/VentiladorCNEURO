/****************************************************************************
** Meta object code from reading C++ file 'mylabelstatetextanimated.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mylabelstatetextanimated.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mylabelstatetextanimated.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyLabelStateTextAnimated_t {
    QByteArrayData data[16];
    char stringdata0[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyLabelStateTextAnimated_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyLabelStateTextAnimated_t qt_meta_stringdata_MyLabelStateTextAnimated = {
    {
QT_MOC_LITERAL(0, 0, 24), // "MyLabelStateTextAnimated"
QT_MOC_LITERAL(1, 25, 18), // "doubleClickedLabel"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 17), // "mouseRightClicked"
QT_MOC_LITERAL(4, 63, 16), // "mouseLeftClicked"
QT_MOC_LITERAL(5, 80, 7), // "clicked"
QT_MOC_LITERAL(6, 88, 12), // "mouseEntered"
QT_MOC_LITERAL(7, 101, 10), // "pressEvent"
QT_MOC_LITERAL(8, 112, 12), // "QMouseEvent*"
QT_MOC_LITERAL(9, 125, 2), // "ev"
QT_MOC_LITERAL(10, 128, 15), // "setAnimationEnd"
QT_MOC_LITERAL(11, 144, 19), // "finalizadaAnimacion"
QT_MOC_LITERAL(12, 164, 11), // "setFotoInit"
QT_MOC_LITERAL(13, 176, 23), // "startAnimationFromChild"
QT_MOC_LITERAL(14, 200, 13), // "emitirClicked"
QT_MOC_LITERAL(15, 214, 17) // "setRadioButtonPos"

    },
    "MyLabelStateTextAnimated\0doubleClickedLabel\0"
    "\0mouseRightClicked\0mouseLeftClicked\0"
    "clicked\0mouseEntered\0pressEvent\0"
    "QMouseEvent*\0ev\0setAnimationEnd\0"
    "finalizadaAnimacion\0setFotoInit\0"
    "startAnimationFromChild\0emitirClicked\0"
    "setRadioButtonPos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyLabelStateTextAnimated[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,
       6,    1,   78,    2, 0x06 /* Public */,
       7,    1,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   84,    2, 0x08 /* Private */,
      11,    0,   85,    2, 0x08 /* Private */,
      12,    1,   86,    2, 0x08 /* Private */,
      13,    0,   89,    2, 0x08 /* Private */,
      14,    0,   90,    2, 0x08 /* Private */,
      15,    0,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, 0x80000000 | 8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyLabelStateTextAnimated::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyLabelStateTextAnimated *_t = static_cast<MyLabelStateTextAnimated *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doubleClickedLabel(); break;
        case 1: _t->mouseRightClicked(); break;
        case 2: _t->mouseLeftClicked(); break;
        case 3: _t->clicked(); break;
        case 4: _t->mouseEntered((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: _t->pressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->setAnimationEnd(); break;
        case 7: _t->finalizadaAnimacion(); break;
        case 8: _t->setFotoInit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->startAnimationFromChild(); break;
        case 10: _t->emitirClicked(); break;
        case 11: _t->setRadioButtonPos(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyLabelStateTextAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabelStateTextAnimated::doubleClickedLabel)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyLabelStateTextAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabelStateTextAnimated::mouseRightClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyLabelStateTextAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabelStateTextAnimated::mouseLeftClicked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyLabelStateTextAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabelStateTextAnimated::clicked)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MyLabelStateTextAnimated::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabelStateTextAnimated::mouseEntered)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MyLabelStateTextAnimated::*)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabelStateTextAnimated::pressEvent)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyLabelStateTextAnimated::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_MyLabelStateTextAnimated.data,
      qt_meta_data_MyLabelStateTextAnimated,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyLabelStateTextAnimated::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyLabelStateTextAnimated::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyLabelStateTextAnimated.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int MyLabelStateTextAnimated::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void MyLabelStateTextAnimated::doubleClickedLabel()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MyLabelStateTextAnimated::mouseRightClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MyLabelStateTextAnimated::mouseLeftClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MyLabelStateTextAnimated::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MyLabelStateTextAnimated::mouseEntered(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyLabelStateTextAnimated::pressEvent(QMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
