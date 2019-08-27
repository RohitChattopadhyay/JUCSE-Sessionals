/****************************************************************************
** Meta object code from reading C++ file 'graph_qwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../assignment76/graph_qwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graph_qwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_graph_qWidget_t {
    QByteArrayData data[5];
    char stringdata[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_graph_qWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_graph_qWidget_t qt_meta_stringdata_graph_qWidget = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 13),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 9),
QT_MOC_LITERAL(4, 39, 10)
    },
    "graph_qWidget\0Mouse_Pressed\0\0Mouse_Pos\0"
    "Mouse_Left\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_graph_qWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x05,
       3,    0,   30,    2, 0x05,
       4,    0,   31,    2, 0x05,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void graph_qWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        graph_qWidget *_t = static_cast<graph_qWidget *>(_o);
        switch (_id) {
        case 0: _t->Mouse_Pressed(); break;
        case 1: _t->Mouse_Pos(); break;
        case 2: _t->Mouse_Left(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (graph_qWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&graph_qWidget::Mouse_Pressed)) {
                *result = 0;
            }
        }
        {
            typedef void (graph_qWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&graph_qWidget::Mouse_Pos)) {
                *result = 1;
            }
        }
        {
            typedef void (graph_qWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&graph_qWidget::Mouse_Left)) {
                *result = 2;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject graph_qWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_graph_qWidget.data,
      qt_meta_data_graph_qWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *graph_qWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *graph_qWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_graph_qWidget.stringdata))
        return static_cast<void*>(const_cast< graph_qWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int graph_qWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void graph_qWidget::Mouse_Pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void graph_qWidget::Mouse_Pos()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void graph_qWidget::Mouse_Left()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
