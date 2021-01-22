/****************************************************************************
** Meta object code from reading C++ file 'pacient_data_in_menu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pacient_data_in_menu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pacient_data_in_menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Pacient_Data_in_Menu_t {
    QByteArrayData data[17];
    char stringdata0[295];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Pacient_Data_in_Menu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Pacient_Data_in_Menu_t qt_meta_stringdata_Pacient_Data_in_Menu = {
    {
QT_MOC_LITERAL(0, 0, 20), // "Pacient_Data_in_Menu"
QT_MOC_LITERAL(1, 21, 14), // "aceptedChanges"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 11), // "sendPacient"
QT_MOC_LITERAL(4, 49, 13), // "PacientClass&"
QT_MOC_LITERAL(5, 63, 14), // "setPacientData"
QT_MOC_LITERAL(6, 78, 12), // "PacientClass"
QT_MOC_LITERAL(7, 91, 27), // "showKeyBoardonPlainTextEdit"
QT_MOC_LITERAL(8, 119, 15), // "QPlainTextEdit*"
QT_MOC_LITERAL(9, 135, 6), // "widget"
QT_MOC_LITERAL(10, 142, 12), // "showKeyBoard"
QT_MOC_LITERAL(11, 155, 10), // "QLineEdit*"
QT_MOC_LITERAL(12, 166, 21), // "moveDownPlaintextEdit"
QT_MOC_LITERAL(13, 188, 21), // "on_pb_aceptar_clicked"
QT_MOC_LITERAL(14, 210, 26), // "on_le_edad_editingFinished"
QT_MOC_LITERAL(15, 237, 28), // "on_le_height_editingFinished"
QT_MOC_LITERAL(16, 266, 28) // "on_le_weight_editingFinished"

    },
    "Pacient_Data_in_Menu\0aceptedChanges\0"
    "\0sendPacient\0PacientClass&\0setPacientData\0"
    "PacientClass\0showKeyBoardonPlainTextEdit\0"
    "QPlainTextEdit*\0widget\0showKeyBoard\0"
    "QLineEdit*\0moveDownPlaintextEdit\0"
    "on_pb_aceptar_clicked\0on_le_edad_editingFinished\0"
    "on_le_height_editingFinished\0"
    "on_le_weight_editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Pacient_Data_in_Menu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   68,    2, 0x0a /* Public */,
       7,    1,   71,    2, 0x08 /* Private */,
      10,    1,   74,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,
      13,    0,   78,    2, 0x08 /* Private */,
      14,    0,   79,    2, 0x08 /* Private */,
      15,    0,   80,    2, 0x08 /* Private */,
      16,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Pacient_Data_in_Menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Pacient_Data_in_Menu *_t = static_cast<Pacient_Data_in_Menu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->aceptedChanges(); break;
        case 1: _t->sendPacient((*reinterpret_cast< PacientClass(*)>(_a[1]))); break;
        case 2: _t->setPacientData((*reinterpret_cast< const PacientClass(*)>(_a[1]))); break;
        case 3: _t->showKeyBoardonPlainTextEdit((*reinterpret_cast< QPlainTextEdit*(*)>(_a[1]))); break;
        case 4: _t->showKeyBoard((*reinterpret_cast< QLineEdit*(*)>(_a[1]))); break;
        case 5: _t->moveDownPlaintextEdit(); break;
        case 6: _t->on_pb_aceptar_clicked(); break;
        case 7: _t->on_le_edad_editingFinished(); break;
        case 8: _t->on_le_height_editingFinished(); break;
        case 9: _t->on_le_weight_editingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QPlainTextEdit* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Pacient_Data_in_Menu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Pacient_Data_in_Menu::aceptedChanges)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Pacient_Data_in_Menu::*)(PacientClass & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Pacient_Data_in_Menu::sendPacient)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Pacient_Data_in_Menu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Pacient_Data_in_Menu.data,
      qt_meta_data_Pacient_Data_in_Menu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Pacient_Data_in_Menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pacient_Data_in_Menu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Pacient_Data_in_Menu.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Pacient_Data_in_Menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Pacient_Data_in_Menu::aceptedChanges()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Pacient_Data_in_Menu::sendPacient(PacientClass & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
