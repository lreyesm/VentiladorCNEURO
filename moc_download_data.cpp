/****************************************************************************
** Meta object code from reading C++ file 'download_data.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "download_data.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'download_data.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Download_Data_t {
    QByteArrayData data[14];
    char stringdata0[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Download_Data_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Download_Data_t qt_meta_stringdata_Download_Data = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Download_Data"
QT_MOC_LITERAL(1, 14, 21), // "on_listWidget_pressed"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 11), // "QModelIndex"
QT_MOC_LITERAL(4, 49, 5), // "index"
QT_MOC_LITERAL(5, 55, 28), // "on_l_descargar_todos_clicked"
QT_MOC_LITERAL(6, 84, 31), // "on_l_descargar_paciente_clicked"
QT_MOC_LITERAL(7, 116, 25), // "on_l_eject_memory_clicked"
QT_MOC_LITERAL(8, 142, 25), // "on_l_down_trigger_clicked"
QT_MOC_LITERAL(9, 168, 23), // "on_l_up_trigger_clicked"
QT_MOC_LITERAL(10, 192, 17), // "onScrollerChanged"
QT_MOC_LITERAL(11, 210, 5), // "value"
QT_MOC_LITERAL(12, 216, 13), // "selectedDrive"
QT_MOC_LITERAL(13, 230, 5) // "drive"

    },
    "Download_Data\0on_listWidget_pressed\0"
    "\0QModelIndex\0index\0on_l_descargar_todos_clicked\0"
    "on_l_descargar_paciente_clicked\0"
    "on_l_eject_memory_clicked\0"
    "on_l_down_trigger_clicked\0"
    "on_l_up_trigger_clicked\0onScrollerChanged\0"
    "value\0selectedDrive\0drive"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Download_Data[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,
      10,    1,   62,    2, 0x08 /* Private */,
      12,    1,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString,   13,

       0        // eod
};

void Download_Data::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Download_Data *_t = static_cast<Download_Data *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_listWidget_pressed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_l_descargar_todos_clicked(); break;
        case 2: _t->on_l_descargar_paciente_clicked(); break;
        case 3: _t->on_l_eject_memory_clicked(); break;
        case 4: _t->on_l_down_trigger_clicked(); break;
        case 5: _t->on_l_up_trigger_clicked(); break;
        case 6: _t->onScrollerChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->selectedDrive((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Download_Data::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Download_Data.data,
      qt_meta_data_Download_Data,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Download_Data::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Download_Data::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Download_Data.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Download_Data::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
