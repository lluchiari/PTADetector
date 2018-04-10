/****************************************************************************
** Meta object code from reading C++ file 'ptawindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/ptawindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ptawindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PTAWindow_t {
    QByteArrayData data[10];
    char stringdata0[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PTAWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PTAWindow_t qt_meta_stringdata_PTAWindow = {
    {
QT_MOC_LITERAL(0, 0, 9), // "PTAWindow"
QT_MOC_LITERAL(1, 10, 15), // "callCalibration"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 28), // "on_ConfirmPushButton_clicked"
QT_MOC_LITERAL(4, 56, 35), // "on_LoadConfigFilePushButton_c..."
QT_MOC_LITERAL(5, 92, 35), // "on_StackImageFilePushButton_c..."
QT_MOC_LITERAL(6, 128, 31), // "on_OutputFilePushButton_clicked"
QT_MOC_LITERAL(7, 160, 48), // "on_ControlSelector_ImageStack..."
QT_MOC_LITERAL(8, 209, 44), // "on_ControlSelector_CameraRadi..."
QT_MOC_LITERAL(9, 254, 43) // "on_ControlSelector_VideoRadio..."

    },
    "PTAWindow\0callCalibration\0\0"
    "on_ConfirmPushButton_clicked\0"
    "on_LoadConfigFilePushButton_clicked\0"
    "on_StackImageFilePushButton_clicked\0"
    "on_OutputFilePushButton_clicked\0"
    "on_ControlSelector_ImageStackRadioButton_clicked\0"
    "on_ControlSelector_CameraRadioButton_clicked\0"
    "on_ControlSelector_VideoRadioButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PTAWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PTAWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PTAWindow *_t = static_cast<PTAWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->callCalibration(); break;
        case 1: _t->on_ConfirmPushButton_clicked(); break;
        case 2: _t->on_LoadConfigFilePushButton_clicked(); break;
        case 3: _t->on_StackImageFilePushButton_clicked(); break;
        case 4: _t->on_OutputFilePushButton_clicked(); break;
        case 5: _t->on_ControlSelector_ImageStackRadioButton_clicked(); break;
        case 6: _t->on_ControlSelector_CameraRadioButton_clicked(); break;
        case 7: _t->on_ControlSelector_VideoRadioButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PTAWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PTAWindow::callCalibration)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject PTAWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PTAWindow.data,
      qt_meta_data_PTAWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PTAWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PTAWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PTAWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PTAWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void PTAWindow::callCalibration()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
