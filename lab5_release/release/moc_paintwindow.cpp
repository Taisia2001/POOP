/****************************************************************************
** Meta object code from reading C++ file 'paintwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../POOP_Lab5_Shutiak/paintwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paintwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PaintWindow_t {
    QByteArrayData data[24];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PaintWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PaintWindow_t qt_meta_stringdata_PaintWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "PaintWindow"
QT_MOC_LITERAL(1, 12, 6), // "pencil"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "spray"
QT_MOC_LITERAL(4, 26, 4), // "fill"
QT_MOC_LITERAL(5, 31, 6), // "rubber"
QT_MOC_LITERAL(6, 38, 4), // "rect"
QT_MOC_LITERAL(7, 43, 6), // "circle"
QT_MOC_LITERAL(8, 50, 4), // "pick"
QT_MOC_LITERAL(9, 55, 6), // "select"
QT_MOC_LITERAL(10, 62, 4), // "font"
QT_MOC_LITERAL(11, 67, 4), // "text"
QT_MOC_LITERAL(12, 72, 4), // "help"
QT_MOC_LITERAL(13, 77, 4), // "line"
QT_MOC_LITERAL(14, 82, 4), // "open"
QT_MOC_LITERAL(15, 87, 4), // "save"
QT_MOC_LITERAL(16, 92, 6), // "color1"
QT_MOC_LITERAL(17, 99, 6), // "color2"
QT_MOC_LITERAL(18, 106, 5), // "width"
QT_MOC_LITERAL(19, 112, 11), // "enablePaste"
QT_MOC_LITERAL(20, 124, 13), // "enableCutCopy"
QT_MOC_LITERAL(21, 138, 9), // "hasColor1"
QT_MOC_LITERAL(22, 148, 9), // "hasColor2"
QT_MOC_LITERAL(23, 158, 11) // "colorPicked"

    },
    "PaintWindow\0pencil\0\0spray\0fill\0rubber\0"
    "rect\0circle\0pick\0select\0font\0text\0"
    "help\0line\0open\0save\0color1\0color2\0"
    "width\0enablePaste\0enableCutCopy\0"
    "hasColor1\0hasColor2\0colorPicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PaintWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  124,    2, 0x08 /* Private */,
       3,    0,  125,    2, 0x08 /* Private */,
       4,    0,  126,    2, 0x08 /* Private */,
       5,    0,  127,    2, 0x08 /* Private */,
       6,    0,  128,    2, 0x08 /* Private */,
       7,    0,  129,    2, 0x08 /* Private */,
       8,    0,  130,    2, 0x08 /* Private */,
       9,    0,  131,    2, 0x08 /* Private */,
      10,    0,  132,    2, 0x08 /* Private */,
      11,    0,  133,    2, 0x08 /* Private */,
      12,    0,  134,    2, 0x08 /* Private */,
      13,    0,  135,    2, 0x08 /* Private */,
      14,    0,  136,    2, 0x08 /* Private */,
      15,    0,  137,    2, 0x08 /* Private */,
      16,    0,  138,    2, 0x08 /* Private */,
      17,    0,  139,    2, 0x08 /* Private */,
      18,    0,  140,    2, 0x08 /* Private */,
      19,    0,  141,    2, 0x08 /* Private */,
      20,    1,  142,    2, 0x08 /* Private */,
      21,    0,  145,    2, 0x08 /* Private */,
      22,    0,  146,    2, 0x08 /* Private */,
      23,    0,  147,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PaintWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PaintWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pencil(); break;
        case 1: _t->spray(); break;
        case 2: _t->fill(); break;
        case 3: _t->rubber(); break;
        case 4: _t->rect(); break;
        case 5: _t->circle(); break;
        case 6: _t->pick(); break;
        case 7: _t->select(); break;
        case 8: _t->font(); break;
        case 9: _t->text(); break;
        case 10: _t->help(); break;
        case 11: _t->line(); break;
        case 12: _t->open(); break;
        case 13: { bool _r = _t->save();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->color1(); break;
        case 15: _t->color2(); break;
        case 16: _t->width(); break;
        case 17: _t->enablePaste(); break;
        case 18: _t->enableCutCopy((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->hasColor1(); break;
        case 20: _t->hasColor2(); break;
        case 21: _t->colorPicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PaintWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_PaintWindow.data,
    qt_meta_data_PaintWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PaintWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PaintWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PaintWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int PaintWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
