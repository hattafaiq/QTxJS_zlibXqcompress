/****************************************************************************
** Meta object code from reading C++ file 'tampil.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../split_parsing/tampil.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tampil.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tampil_t {
    QByteArrayData data[12];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tampil_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tampil_t qt_meta_stringdata_Tampil = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Tampil"
QT_MOC_LITERAL(1, 7, 19), // "on_treeView_clicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "QModelIndex"
QT_MOC_LITERAL(4, 40, 5), // "index"
QT_MOC_LITERAL(5, 46, 20), // "on_treeView_expanded"
QT_MOC_LITERAL(6, 67, 21), // "on_treeView_activated"
QT_MOC_LITERAL(7, 89, 20), // "on_tableView_clicked"
QT_MOC_LITERAL(8, 110, 10), // "hapus_data"
QT_MOC_LITERAL(9, 121, 22), // "on_tableView_2_pressed"
QT_MOC_LITERAL(10, 144, 12), // "refresh_data"
QT_MOC_LITERAL(11, 157, 1) // "a"

    },
    "Tampil\0on_treeView_clicked\0\0QModelIndex\0"
    "index\0on_treeView_expanded\0"
    "on_treeView_activated\0on_tableView_clicked\0"
    "hapus_data\0on_tableView_2_pressed\0"
    "refresh_data\0a"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tampil[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       5,    1,   52,    2, 0x0a /* Public */,
       6,    1,   55,    2, 0x0a /* Public */,
       7,    1,   58,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    1,   62,    2, 0x08 /* Private */,
      10,    1,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,   11,

       0        // eod
};

void Tampil::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Tampil *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_treeView_clicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_treeView_expanded((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_treeView_activated((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_tableView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->hapus_data(); break;
        case 5: _t->on_tableView_2_pressed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->refresh_data((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Tampil::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Tampil.data,
    qt_meta_data_Tampil,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Tampil::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tampil::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tampil.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Tampil::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
