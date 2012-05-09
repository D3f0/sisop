/****************************************************************************
** Meta object code from reading C++ file 'receptormensajes.h'
**
** Created: Thu May 3 22:38:54 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "receptormensajes.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'receptormensajes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ReceptorMensajes[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   18,   17,   17, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ReceptorMensajes[] = {
    "ReceptorMensajes\0\0quien,tipo\0"
    "recepcionMensaje(int,int)\0"
};

void ReceptorMensajes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ReceptorMensajes *_t = static_cast<ReceptorMensajes *>(_o);
        switch (_id) {
        case 0: _t->recepcionMensaje((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ReceptorMensajes::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ReceptorMensajes::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ReceptorMensajes,
      qt_meta_data_ReceptorMensajes, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ReceptorMensajes::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ReceptorMensajes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ReceptorMensajes::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ReceptorMensajes))
        return static_cast<void*>(const_cast< ReceptorMensajes*>(this));
    return QThread::qt_metacast(_clname);
}

int ReceptorMensajes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ReceptorMensajes::recepcionMensaje(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
