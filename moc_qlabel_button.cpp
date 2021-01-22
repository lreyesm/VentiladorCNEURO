/****************************************************************************
** Meta object code from reading C++ file 'qlabel_button.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qlabel_button.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlabel_button.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QLabel_Button_t {
    QByteArrayData data[15];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QLabel_Button_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QLabel_Button_t qt_meta_stringdata_QLabel_Button = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QLabel_Button"
QT_MOC_LITERAL(1, 14, 7), // "clicked"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 13), // "doubleClicked"
QT_MOC_LITERAL(4, 37, 12), // "rightClicked"
QT_MOC_LITERAL(5, 50, 11), // "leftClicked"
QT_MOC_LITERAL(6, 62, 9), // "send_text"
QT_MOC_LITERAL(7, 72, 10), // "setChecked"
QT_MOC_LITERAL(8, 83, 5), // "check"
QT_MOC_LITERAL(9, 89, 20), // "setCheckedBackground"
QT_MOC_LITERAL(10, 110, 5), // "color"
QT_MOC_LITERAL(11, 116, 21), // "mouseDoubleClickEvent"
QT_MOC_LITERAL(12, 138, 12), // "QMouseEvent*"
QT_MOC_LITERAL(13, 151, 15), // "mousePressEvent"
QT_MOC_LITERAL(14, 167, 1) // "e"

    },
    "QLabel_Button\0clicked\0\0doubleClicked\0"
    "rightClicked\0leftClicked\0send_text\0"
    "setChecked\0check\0setCheckedBackground\0"
    "color\0mouseDoubleClickEvent\0QMouseEvent*\0"
    "mousePressEvent\0e"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QLabel_Button[] = {

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
       7,    1,   66,    2, 0x0a /* Public */,
       9,    1,   69,    2, 0x0a /* Public */,
      11,    1,   72,    2, 0x09 /* Protected */,
      13,    1,   75,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::QColor,   10,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, 0x80000000 | 12,   14,

       0        // eod
};

void QLabel_Button::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QLabel_Button *_t = static_cast<QLabel_Button *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked(); break;
        case 1: _t->doubleClicked(); break;
        case 2: _t->rightClicked(); break;
        case 3: _t->leftClicked(); break;
        case 4: _t->send_text((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->setCheckedBackground((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 7: _t->mouseDoubleClickEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 8: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QLabel_Button::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabel_Button::clicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QLabel_Button::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabel_Button::doubleClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QLabel_Button::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabel_Button::rightClicked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QLabel_Button::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabel_Button::leftClicked)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QLabel_Button::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabel_Button::send_text)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QLabel_Button::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_QLabel_Button.data,
      qt_meta_data_QLabel_Button,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QLabel_Button::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QLabel_Button::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QLabel_Button.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int QLabel_Button::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QLabel_Button::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QLabel_Button::doubleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QLabel_Button::rightClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QLabel_Button::leftClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QLabel_Button::send_text(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
