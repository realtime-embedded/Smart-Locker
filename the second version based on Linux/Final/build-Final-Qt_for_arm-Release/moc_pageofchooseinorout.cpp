/****************************************************************************
** Meta object code from reading C++ file 'pageofchooseinorout.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Final/pageofchooseinorout.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pageofchooseinorout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_pageofchooseinorout_t {
    QByteArrayData data[5];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pageofchooseinorout_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pageofchooseinorout_t qt_meta_stringdata_pageofchooseinorout = {
    {
QT_MOC_LITERAL(0, 0, 19), // "pageofchooseinorout"
QT_MOC_LITERAL(1, 20, 23), // "on_chuqinbutton_clicked"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 23), // "on_tuiqinbutton_clicked"
QT_MOC_LITERAL(4, 69, 23) // "on_cancelbutton_clicked"

    },
    "pageofchooseinorout\0on_chuqinbutton_clicked\0"
    "\0on_tuiqinbutton_clicked\0"
    "on_cancelbutton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pageofchooseinorout[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void pageofchooseinorout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pageofchooseinorout *_t = static_cast<pageofchooseinorout *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_chuqinbutton_clicked(); break;
        case 1: _t->on_tuiqinbutton_clicked(); break;
        case 2: _t->on_cancelbutton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject pageofchooseinorout::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_pageofchooseinorout.data,
      qt_meta_data_pageofchooseinorout,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pageofchooseinorout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pageofchooseinorout::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pageofchooseinorout.stringdata0))
        return static_cast<void*>(const_cast< pageofchooseinorout*>(this));
    return QWidget::qt_metacast(_clname);
}

int pageofchooseinorout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
