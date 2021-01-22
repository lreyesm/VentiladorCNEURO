/****************************************************************************
** Meta object code from reading C++ file 'screen_pacient_data.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "screen_pacient_data.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'screen_pacient_data.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Screen_Pacient_Data_t {
    QByteArrayData data[18];
    char stringdata0[354];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Screen_Pacient_Data_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Screen_Pacient_Data_t qt_meta_stringdata_Screen_Pacient_Data = {
    {
QT_MOC_LITERAL(0, 0, 19), // "Screen_Pacient_Data"
QT_MOC_LITERAL(1, 20, 26), // "closed_Screen_Pacient_Data"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 13), // "PacientClass&"
QT_MOC_LITERAL(4, 62, 15), // "settedFechaHora"
QT_MOC_LITERAL(5, 78, 25), // "close_Screen_Pacient_Data"
QT_MOC_LITERAL(6, 104, 21), // "on_pb_aceptar_clicked"
QT_MOC_LITERAL(7, 126, 32), // "on_pb_ajustar_fecha_hora_clicked"
QT_MOC_LITERAL(8, 159, 12), // "showKeyBoard"
QT_MOC_LITERAL(9, 172, 10), // "QLineEdit*"
QT_MOC_LITERAL(10, 183, 6), // "widget"
QT_MOC_LITERAL(11, 190, 27), // "showKeyBoardonPlainTextEdit"
QT_MOC_LITERAL(12, 218, 15), // "QPlainTextEdit*"
QT_MOC_LITERAL(13, 234, 21), // "moveDownPlaintextEdit"
QT_MOC_LITERAL(14, 256, 12), // "setFechaHora"
QT_MOC_LITERAL(15, 269, 28), // "on_le_height_editingFinished"
QT_MOC_LITERAL(16, 298, 26), // "on_le_edad_editingFinished"
QT_MOC_LITERAL(17, 325, 28) // "on_le_weight_editingFinished"

    },
    "Screen_Pacient_Data\0closed_Screen_Pacient_Data\0"
    "\0PacientClass&\0settedFechaHora\0"
    "close_Screen_Pacient_Data\0"
    "on_pb_aceptar_clicked\0"
    "on_pb_ajustar_fecha_hora_clicked\0"
    "showKeyBoard\0QLineEdit*\0widget\0"
    "showKeyBoardonPlainTextEdit\0QPlainTextEdit*\0"
    "moveDownPlaintextEdit\0setFechaHora\0"
    "on_le_height_editingFinished\0"
    "on_le_edad_editingFinished\0"
    "on_le_weight_editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Screen_Pacient_Data[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   80,    2, 0x08 /* Private */,
       6,    0,   81,    2, 0x08 /* Private */,
       7,    0,   82,    2, 0x08 /* Private */,
       8,    1,   83,    2, 0x08 /* Private */,
      11,    1,   86,    2, 0x08 /* Private */,
      13,    0,   89,    2, 0x08 /* Private */,
      14,    1,   90,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,
      16,    0,   94,    2, 0x08 /* Private */,
      17,    0,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QDateTime,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Screen_Pacient_Data::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Screen_Pacient_Data *_t = static_cast<Screen_Pacient_Data *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closed_Screen_Pacient_Data((*reinterpret_cast< PacientClass(*)>(_a[1]))); break;
        case 1: _t->settedFechaHora((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 2: _t->close_Screen_Pacient_Data(); break;
        case 3: _t->on_pb_aceptar_clicked(); break;
        case 4: _t->on_pb_ajustar_fecha_hora_clicked(); break;
        case 5: _t->showKeyBoard((*reinterpret_cast< QLineEdit*(*)>(_a[1]))); break;
        case 6: _t->showKeyBoardonPlainTextEdit((*reinterpret_cast< QPlainTextEdit*(*)>(_a[1]))); break;
        case 7: _t->moveDownPlaintextEdit(); break;
        case 8: _t->setFechaHora((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 9: _t->on_le_height_editingFinished(); break;
        case 10: _t->on_le_edad_editingFinished(); break;
        case 11: _t->on_le_weight_editingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QPlainTextEdit* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Screen_Pacient_Data::*)(PacientClass & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Screen_Pacient_Data::closed_Screen_Pacient_Data)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Screen_Pacient_Data::*)(QDateTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Screen_Pacient_Data::settedFechaHora)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Screen_Pacient_Data::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Screen_Pacient_Data.data,
      qt_meta_data_Screen_Pacient_Data,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Screen_Pacient_Data::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Screen_Pacient_Data::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Screen_Pacient_Data.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Screen_Pacient_Data::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Screen_Pacient_Data::closed_Screen_Pacient_Data(PacientClass & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Screen_Pacient_Data::settedFechaHora(QDateTime _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
