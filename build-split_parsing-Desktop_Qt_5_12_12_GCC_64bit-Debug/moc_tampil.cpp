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
    QByteArrayData data[19];
    char stringdata0[325];
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
QT_MOC_LITERAL(11, 157, 1), // "a"
QT_MOC_LITERAL(12, 159, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(13, 181, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(14, 205, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(15, 229, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(16, 253, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(17, 277, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(18, 301, 23) // "on_pushButton_7_clicked"

    },
    "Tampil\0on_treeView_clicked\0\0QModelIndex\0"
    "index\0on_treeView_expanded\0"
    "on_treeView_activated\0on_tableView_clicked\0"
    "hapus_data\0on_tableView_2_pressed\0"
    "refresh_data\0a\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_4_clicked\0"
    "on_pushButton_3_clicked\0on_pushButton_5_clicked\0"
    "on_pushButton_6_clicked\0on_pushButton_7_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tampil[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x0a /* Public */,
       5,    1,   87,    2, 0x0a /* Public */,
       6,    1,   90,    2, 0x0a /* Public */,
       7,    1,   93,    2, 0x08 /* Private */,
       8,    0,   96,    2, 0x08 /* Private */,
       9,    1,   97,    2, 0x08 /* Private */,
      10,    1,  100,    2, 0x08 /* Private */,
      12,    0,  103,    2, 0x08 /* Private */,
      13,    0,  104,    2, 0x08 /* Private */,
      14,    0,  105,    2, 0x08 /* Private */,
      15,    0,  106,    2, 0x08 /* Private */,
      16,    0,  107,    2, 0x08 /* Private */,
      17,    0,  108,    2, 0x08 /* Private */,
      18,    0,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

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
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->on_pushButton_2_clicked(); break;
        case 9: _t->on_pushButton_4_clicked(); break;
        case 10: _t->on_pushButton_3_clicked(); break;
        case 11: _t->on_pushButton_5_clicked(); break;
        case 12: _t->on_pushButton_6_clicked(); break;
        case 13: _t->on_pushButton_7_clicked(); break;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
