/****************************************************************************
** Meta object code from reading C++ file 'mapa.h'
**
** Created: Mon May 4 19:50:03 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mapa.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapa.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_mapa[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x08,
      28,    5,    5,    5, 0x08,
      53,    5,    5,    5, 0x08,
      74,    5,    5,    5, 0x08,
     101,    5,    5,    5, 0x08,
     188,  131,    5,    5, 0x08,
     249,  223,  219,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_mapa[] = {
    "mapa\0\0on_Amplitud_clicked()\0"
    "on_A_Asterisco_clicked()\0on_btSalir_clicked()\0"
    "on_paso_amplitud_clicked()\0"
    "on_paso_A_Asterisco_clicked()\0"
    "nodos_creados,nodos_expandidos,costo,factor_ramificacion\0"
    "crear_archivo(int,int,int,int)\0int\0"
    "profundidad,nodos_creados\0"
    "ramificacion(int,int)\0"
};

void mapa::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        mapa *_t = static_cast<mapa *>(_o);
        switch (_id) {
        case 0: _t->on_Amplitud_clicked(); break;
        case 1: _t->on_A_Asterisco_clicked(); break;
        case 2: _t->on_btSalir_clicked(); break;
        case 3: _t->on_paso_amplitud_clicked(); break;
        case 4: _t->on_paso_A_Asterisco_clicked(); break;
        case 5: _t->crear_archivo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 6: { int _r = _t->ramificacion((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData mapa::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject mapa::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_mapa,
      qt_meta_data_mapa, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &mapa::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *mapa::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *mapa::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mapa))
        return static_cast<void*>(const_cast< mapa*>(this));
    return QWidget::qt_metacast(_clname);
}

int mapa::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
