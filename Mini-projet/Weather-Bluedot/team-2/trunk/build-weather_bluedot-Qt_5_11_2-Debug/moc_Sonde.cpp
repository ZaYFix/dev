/****************************************************************************
** Meta object code from reading C++ file 'Sonde.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../weather_bluedot/Sonde.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Sonde.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Sonde_t {
    QByteArrayData data[24];
    char stringdata0[346];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Sonde_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Sonde_t qt_meta_stringdata_Sonde = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Sonde"
QT_MOC_LITERAL(1, 6, 19), // "nouvelleTemperature"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "temperature"
QT_MOC_LITERAL(4, 39, 16), // "uniteTemperature"
QT_MOC_LITERAL(5, 56, 28), // "nouvelleTemperatureRessentie"
QT_MOC_LITERAL(6, 85, 20), // "temperatureRessentie"
QT_MOC_LITERAL(7, 106, 25), // "uniteTemperatureRessentie"
QT_MOC_LITERAL(8, 132, 16), // "nouvelleHumidite"
QT_MOC_LITERAL(9, 149, 8), // "humidite"
QT_MOC_LITERAL(10, 158, 13), // "uniteHumidite"
QT_MOC_LITERAL(11, 172, 18), // "nouvelleLuminosite"
QT_MOC_LITERAL(12, 191, 10), // "luminosite"
QT_MOC_LITERAL(13, 202, 15), // "uniteLuminosite"
QT_MOC_LITERAL(14, 218, 16), // "nouvellePression"
QT_MOC_LITERAL(15, 235, 8), // "pression"
QT_MOC_LITERAL(16, 244, 13), // "unitePression"
QT_MOC_LITERAL(17, 258, 16), // "nouvelleAltitude"
QT_MOC_LITERAL(18, 275, 8), // "altitude"
QT_MOC_LITERAL(19, 284, 13), // "uniteAltitude"
QT_MOC_LITERAL(20, 298, 15), // "nouvelleEtatLED"
QT_MOC_LITERAL(21, 314, 9), // "trameBrut"
QT_MOC_LITERAL(22, 324, 15), // "extraireMesures"
QT_MOC_LITERAL(23, 340, 5) // "trame"

    },
    "Sonde\0nouvelleTemperature\0\0temperature\0"
    "uniteTemperature\0nouvelleTemperatureRessentie\0"
    "temperatureRessentie\0uniteTemperatureRessentie\0"
    "nouvelleHumidite\0humidite\0uniteHumidite\0"
    "nouvelleLuminosite\0luminosite\0"
    "uniteLuminosite\0nouvellePression\0"
    "pression\0unitePression\0nouvelleAltitude\0"
    "altitude\0uniteAltitude\0nouvelleEtatLED\0"
    "trameBrut\0extraireMesures\0trame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Sonde[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       5,    2,   59,    2, 0x06 /* Public */,
       8,    2,   64,    2, 0x06 /* Public */,
      11,    2,   69,    2, 0x06 /* Public */,
      14,    2,   74,    2, 0x06 /* Public */,
      17,    2,   79,    2, 0x06 /* Public */,
      20,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      22,    1,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Double, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::Double, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::Double, QMetaType::QString,   12,   13,
    QMetaType::Void, QMetaType::Double, QMetaType::QString,   15,   16,
    QMetaType::Void, QMetaType::Double, QMetaType::QString,   18,   19,
    QMetaType::Void, QMetaType::QString,   21,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   23,

       0        // eod
};

void Sonde::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Sonde *_t = static_cast<Sonde *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nouvelleTemperature((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->nouvelleTemperatureRessentie((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->nouvelleHumidite((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->nouvelleLuminosite((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->nouvellePression((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->nouvelleAltitude((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->nouvelleEtatLED((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->extraireMesures((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Sonde::*)(double , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sonde::nouvelleTemperature)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Sonde::*)(double , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sonde::nouvelleTemperatureRessentie)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Sonde::*)(double , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sonde::nouvelleHumidite)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Sonde::*)(double , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sonde::nouvelleLuminosite)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Sonde::*)(double , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sonde::nouvellePression)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Sonde::*)(double , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sonde::nouvelleAltitude)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Sonde::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sonde::nouvelleEtatLED)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Sonde::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Sonde.data,
      qt_meta_data_Sonde,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Sonde::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Sonde::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Sonde.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Sonde::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Sonde::nouvelleTemperature(double _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Sonde::nouvelleTemperatureRessentie(double _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Sonde::nouvelleHumidite(double _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Sonde::nouvelleLuminosite(double _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Sonde::nouvellePression(double _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Sonde::nouvelleAltitude(double _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Sonde::nouvelleEtatLED(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
