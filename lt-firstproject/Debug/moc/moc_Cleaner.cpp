/****************************************************************************
** Meta object code from reading C++ file 'Cleaner.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Cleaner.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Cleaner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Cleaner_t {
    QByteArrayData data[20];
    char stringdata0[327];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cleaner_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cleaner_t qt_meta_stringdata_Cleaner = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Cleaner"
QT_MOC_LITERAL(1, 8, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 22), // "on_stopButtton_clicked"
QT_MOC_LITERAL(4, 55, 10), // "updateTime"
QT_MOC_LITERAL(5, 66, 27), // "on_deleteFileButton_clicked"
QT_MOC_LITERAL(6, 94, 19), // "on_treeView_clicked"
QT_MOC_LITERAL(7, 114, 11), // "QModelIndex"
QT_MOC_LITERAL(8, 126, 5), // "index"
QT_MOC_LITERAL(9, 132, 15), // "treeItemChanged"
QT_MOC_LITERAL(10, 148, 14), // "QStandardItem*"
QT_MOC_LITERAL(11, 163, 4), // "item"
QT_MOC_LITERAL(12, 168, 22), // "treeItem_checkAllChild"
QT_MOC_LITERAL(13, 191, 5), // "check"
QT_MOC_LITERAL(14, 197, 32), // "treeItem_checkAllChild_recursion"
QT_MOC_LITERAL(15, 230, 26), // "treeItem_CheckChildChanged"
QT_MOC_LITERAL(16, 257, 12), // "checkSibling"
QT_MOC_LITERAL(17, 270, 14), // "Qt::CheckState"
QT_MOC_LITERAL(18, 285, 21), // "on_unfold_all_clicked"
QT_MOC_LITERAL(19, 307, 19) // "on_fold_all_clicked"

    },
    "Cleaner\0on_startButton_clicked\0\0"
    "on_stopButtton_clicked\0updateTime\0"
    "on_deleteFileButton_clicked\0"
    "on_treeView_clicked\0QModelIndex\0index\0"
    "treeItemChanged\0QStandardItem*\0item\0"
    "treeItem_checkAllChild\0check\0"
    "treeItem_checkAllChild_recursion\0"
    "treeItem_CheckChildChanged\0checkSibling\0"
    "Qt::CheckState\0on_unfold_all_clicked\0"
    "on_fold_all_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cleaner[] = {

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
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    1,   88,    2, 0x08 /* Private */,
       9,    1,   91,    2, 0x08 /* Private */,
      12,    2,   94,    2, 0x08 /* Private */,
      12,    1,   99,    2, 0x28 /* Private | MethodCloned */,
      14,    2,  102,    2, 0x08 /* Private */,
      14,    1,  107,    2, 0x28 /* Private | MethodCloned */,
      15,    1,  110,    2, 0x08 /* Private */,
      16,    1,  113,    2, 0x08 /* Private */,
      18,    0,  116,    2, 0x08 /* Private */,
      19,    0,  117,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Bool,   11,   13,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Bool,   11,   13,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    0x80000000 | 17, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Cleaner::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Cleaner *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_startButton_clicked(); break;
        case 1: _t->on_stopButtton_clicked(); break;
        case 2: _t->updateTime(); break;
        case 3: _t->on_deleteFileButton_clicked(); break;
        case 4: _t->on_treeView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->treeItemChanged((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 6: _t->treeItem_checkAllChild((*reinterpret_cast< QStandardItem*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: _t->treeItem_checkAllChild((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 8: _t->treeItem_checkAllChild_recursion((*reinterpret_cast< QStandardItem*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: _t->treeItem_checkAllChild_recursion((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 10: _t->treeItem_CheckChildChanged((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 11: { Qt::CheckState _r = _t->checkSibling((*reinterpret_cast< QStandardItem*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Qt::CheckState*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->on_unfold_all_clicked(); break;
        case 13: _t->on_fold_all_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Cleaner::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Cleaner.data,
    qt_meta_data_Cleaner,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Cleaner::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cleaner::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Cleaner.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "FirstGarbageClean"))
        return static_cast< FirstGarbageClean*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Cleaner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
