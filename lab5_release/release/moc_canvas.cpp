/****************************************************************************
** Meta object code from reading C++ file 'canvas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../POOP_Lab5_Shutiak/canvas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Canvas_t {
    QByteArrayData data[13];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Canvas_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Canvas_t qt_meta_stringdata_Canvas = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Canvas"
QT_MOC_LITERAL(1, 7, 10), // "undoSignal"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 10), // "redoSignal"
QT_MOC_LITERAL(4, 30, 11), // "pasteSignal"
QT_MOC_LITERAL(5, 42, 12), // "selectSignal"
QT_MOC_LITERAL(6, 55, 17), // "colorPickedSignal"
QT_MOC_LITERAL(7, 73, 5), // "clear"
QT_MOC_LITERAL(8, 79, 4), // "redo"
QT_MOC_LITERAL(9, 84, 4), // "undo"
QT_MOC_LITERAL(10, 89, 3), // "cut"
QT_MOC_LITERAL(11, 93, 4), // "copy"
QT_MOC_LITERAL(12, 98, 5) // "paste"

    },
    "Canvas\0undoSignal\0\0redoSignal\0pasteSignal\0"
    "selectSignal\0colorPickedSignal\0clear\0"
    "redo\0undo\0cut\0copy\0paste"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Canvas[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       3,    1,   72,    2, 0x06 /* Public */,
       4,    0,   75,    2, 0x06 /* Public */,
       5,    1,   76,    2, 0x06 /* Public */,
       6,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   80,    2, 0x0a /* Public */,
       8,    0,   81,    2, 0x0a /* Public */,
       9,    0,   82,    2, 0x0a /* Public */,
      10,    0,   83,    2, 0x0a /* Public */,
      11,    0,   84,    2, 0x0a /* Public */,
      12,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Canvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Canvas *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->undoSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->redoSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->pasteSignal(); break;
        case 3: _t->selectSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->colorPickedSignal(); break;
        case 5: _t->clear(); break;
        case 6: _t->redo(); break;
        case 7: _t->undo(); break;
        case 8: _t->cut(); break;
        case 9: _t->copy(); break;
        case 10: _t->paste(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Canvas::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::undoSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Canvas::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::redoSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Canvas::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::pasteSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Canvas::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::selectSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Canvas::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::colorPickedSignal)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Canvas::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Canvas.data,
    qt_meta_data_Canvas,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Canvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Canvas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Canvas.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Canvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Canvas::undoSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Canvas::redoSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Canvas::pasteSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Canvas::selectSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Canvas::colorPickedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
