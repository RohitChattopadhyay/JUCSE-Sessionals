/****************************************************************************
** Meta object code from reading C++ file 'graph.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../assignment73/sources/graph.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graph.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Graph_t {
    QByteArrayData data[12];
    char stringdata[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Graph_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Graph_t qt_meta_stringdata_Graph = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 11),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 13),
QT_MOC_LITERAL(4, 33, 10),
QT_MOC_LITERAL(5, 44, 13),
QT_MOC_LITERAL(6, 58, 1),
QT_MOC_LITERAL(7, 60, 1),
QT_MOC_LITERAL(8, 62, 18),
QT_MOC_LITERAL(9, 81, 14),
QT_MOC_LITERAL(10, 96, 1),
QT_MOC_LITERAL(11, 98, 1)
    },
    "Graph\0pointSelect\0\0pair<int,int>\0"
    "pointHover\0GraphPlotSlot\0x\0y\0"
    "GraphPlotColorSlot\0GraphResetSlot\0p\0"
    "n\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Graph[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x05,
       4,    1,   42,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       5,    2,   45,    2, 0x0a,
       8,    1,   50,    2, 0x0a,
       9,    2,   53,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,

       0        // eod
};

void Graph::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Graph *_t = static_cast<Graph *>(_o);
        switch (_id) {
        case 0: _t->pointSelect((*reinterpret_cast< pair<int,int>(*)>(_a[1]))); break;
        case 1: _t->pointHover((*reinterpret_cast< pair<int,int>(*)>(_a[1]))); break;
        case 2: _t->GraphPlotSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->GraphPlotColorSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->GraphResetSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Graph::*_t)(pair<int,int> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Graph::pointSelect)) {
                *result = 0;
            }
        }
        {
            typedef void (Graph::*_t)(pair<int,int> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Graph::pointHover)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject Graph::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_Graph.data,
      qt_meta_data_Graph,  qt_static_metacall, 0, 0}
};


const QMetaObject *Graph::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Graph::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Graph.stringdata))
        return static_cast<void*>(const_cast< Graph*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int Graph::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Graph::pointSelect(pair<int,int> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Graph::pointHover(pair<int,int> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE