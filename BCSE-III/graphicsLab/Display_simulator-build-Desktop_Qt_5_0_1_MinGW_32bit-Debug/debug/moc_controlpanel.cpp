/****************************************************************************
** Meta object code from reading C++ file 'controlpanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../assignment73/sources/controlpanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controlpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ControlPanel_t {
    QByteArrayData data[16];
    char stringdata[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ControlPanel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ControlPanel_t qt_meta_stringdata_ControlPanel = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 16),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 15),
QT_MOC_LITERAL(4, 47, 20),
QT_MOC_LITERAL(5, 68, 20),
QT_MOC_LITERAL(6, 89, 12),
QT_MOC_LITERAL(7, 102, 15),
QT_MOC_LITERAL(8, 118, 17),
QT_MOC_LITERAL(9, 136, 18),
QT_MOC_LITERAL(10, 155, 14),
QT_MOC_LITERAL(11, 170, 13),
QT_MOC_LITERAL(12, 184, 13),
QT_MOC_LITERAL(13, 198, 5),
QT_MOC_LITERAL(14, 204, 14),
QT_MOC_LITERAL(15, 219, 7)
    },
    "ControlPanel\0GraphResetSignal\0\0"
    "GraphPlotSignal\0GraphPlotColorSignal\0"
    "GraphCheckPixelColor\0handleButton\0"
    "drawLineHandler\0drawCircleHandler\0"
    "drawEllipseHandler\0fillingHandler\0"
    "getPointHover\0pair<int,int>\0point\0"
    "getPointSelect\0ResetUI\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ControlPanel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x05,
       3,    2,   79,    2, 0x05,
       4,    1,   84,    2, 0x05,
       5,    2,   87,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    0,   92,    2, 0x0a,
       7,    0,   93,    2, 0x0a,
       8,    0,   94,    2, 0x0a,
       9,    0,   95,    2, 0x0a,
      10,    0,   96,    2, 0x0a,
      11,    1,   97,    2, 0x0a,
      14,    1,  100,    2, 0x0a,
      15,    0,  103,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Bool, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,

       0        // eod
};

void ControlPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ControlPanel *_t = static_cast<ControlPanel *>(_o);
        switch (_id) {
        case 0: _t->GraphResetSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->GraphPlotSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->GraphPlotColorSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { bool _r = _t->GraphCheckPixelColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: _t->handleButton(); break;
        case 5: _t->drawLineHandler(); break;
        case 6: _t->drawCircleHandler(); break;
        case 7: _t->drawEllipseHandler(); break;
        case 8: _t->fillingHandler(); break;
        case 9: _t->getPointHover((*reinterpret_cast< pair<int,int>(*)>(_a[1]))); break;
        case 10: _t->getPointSelect((*reinterpret_cast< pair<int,int>(*)>(_a[1]))); break;
        case 11: _t->ResetUI(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ControlPanel::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ControlPanel::GraphResetSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (ControlPanel::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ControlPanel::GraphPlotSignal)) {
                *result = 1;
            }
        }
        {
            typedef void (ControlPanel::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ControlPanel::GraphPlotColorSignal)) {
                *result = 2;
            }
        }
        {
            typedef bool (ControlPanel::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ControlPanel::GraphCheckPixelColor)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject ControlPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ControlPanel.data,
      qt_meta_data_ControlPanel,  qt_static_metacall, 0, 0}
};


const QMetaObject *ControlPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControlPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ControlPanel.stringdata))
        return static_cast<void*>(const_cast< ControlPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int ControlPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ControlPanel::GraphResetSignal(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ControlPanel::GraphPlotSignal(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ControlPanel::GraphPlotColorSignal(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
bool ControlPanel::GraphCheckPixelColor(int _t1, int _t2)
{
    bool _t0 = bool();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
