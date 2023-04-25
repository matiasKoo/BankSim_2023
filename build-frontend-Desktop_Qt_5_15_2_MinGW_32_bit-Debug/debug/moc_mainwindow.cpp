/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../frontend/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 6), // "pinNum"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 7), // "cardNum"
QT_MOC_LITERAL(4, 27, 12), // "clickhandler"
QT_MOC_LITERAL(5, 40, 15), // "pinSgnalHandler"
QT_MOC_LITERAL(6, 56, 14), // "nosta20Handler"
QT_MOC_LITERAL(7, 71, 14), // "nosta40Handler"
QT_MOC_LITERAL(8, 86, 14), // "nosta50Handler"
QT_MOC_LITERAL(9, 101, 15), // "nosta100Handler"
QT_MOC_LITERAL(10, 117, 16), // "nostaPageHandler"
QT_MOC_LITERAL(11, 134, 25), // "tiliTapahtumatPageHandler"
QT_MOC_LITERAL(12, 160, 15), // "menuPageHandler"
QT_MOC_LITERAL(13, 176, 5), // "testi"
QT_MOC_LITERAL(14, 182, 15), // "cardNumReceiver"
QT_MOC_LITERAL(15, 198, 13), // "loginReceiver"
QT_MOC_LITERAL(16, 212, 13), // "nostoReceiver"
QT_MOC_LITERAL(17, 226, 13) // "saldoReceiver"

    },
    "MainWindow\0pinNum\0\0cardNum\0clickhandler\0"
    "pinSgnalHandler\0nosta20Handler\0"
    "nosta40Handler\0nosta50Handler\0"
    "nosta100Handler\0nostaPageHandler\0"
    "tiliTapahtumatPageHandler\0menuPageHandler\0"
    "testi\0cardNumReceiver\0loginReceiver\0"
    "nostoReceiver\0saldoReceiver"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       3,    1,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  100,    2, 0x0a /* Public */,
       5,    1,  101,    2, 0x0a /* Public */,
       6,    0,  104,    2, 0x0a /* Public */,
       7,    0,  105,    2, 0x0a /* Public */,
       8,    0,  106,    2, 0x0a /* Public */,
       9,    0,  107,    2, 0x0a /* Public */,
      10,    0,  108,    2, 0x0a /* Public */,
      11,    0,  109,    2, 0x0a /* Public */,
      12,    0,  110,    2, 0x0a /* Public */,
      13,    0,  111,    2, 0x0a /* Public */,
      14,    1,  112,    2, 0x0a /* Public */,
      15,    1,  115,    2, 0x0a /* Public */,
      16,    1,  118,    2, 0x0a /* Public */,
      17,    1,  121,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Short,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pinNum((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->cardNum((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->clickhandler(); break;
        case 3: _t->pinSgnalHandler((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 4: _t->nosta20Handler(); break;
        case 5: _t->nosta40Handler(); break;
        case 6: _t->nosta50Handler(); break;
        case 7: _t->nosta100Handler(); break;
        case 8: _t->nostaPageHandler(); break;
        case 9: _t->tiliTapahtumatPageHandler(); break;
        case 10: _t->menuPageHandler(); break;
        case 11: _t->testi(); break;
        case 12: _t->cardNumReceiver((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->loginReceiver((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->nostoReceiver((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->saldoReceiver((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::pinNum)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::cardNum)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::pinNum(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::cardNum(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
