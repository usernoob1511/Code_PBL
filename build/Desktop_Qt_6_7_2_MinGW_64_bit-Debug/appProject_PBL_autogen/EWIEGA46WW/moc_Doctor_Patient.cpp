/****************************************************************************
** Meta object code from reading C++ file 'Doctor_Patient.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Doctor_Patient.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Doctor_Patient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSDoctorModelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSDoctorModelENDCLASS = QtMocHelpers::stringData(
    "DoctorModel",
    "printDoctors",
    ""
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDoctorModelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x02,    1 /* Public */,

 // methods: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject DoctorModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_CLASSDoctorModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDoctorModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDoctorModelENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DoctorModel, std::true_type>,
        // method 'printDoctors'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void DoctorModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DoctorModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->printDoctors(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *DoctorModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DoctorModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDoctorModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int DoctorModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSDoctorENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSDoctorENDCLASS = QtMocHelpers::stringData(
    "Doctor",
    "getDoctorData",
    "",
    "I_doctorId",
    "I_department",
    "I_phone",
    "I_name",
    "I_address",
    "I_email",
    "I_date",
    "I_CCCD",
    "I_sex",
    "days",
    "I_NoD",
    "I_shift1",
    "I_shift2",
    "addDoctorData",
    "showDoctorDataFromFile",
    "searchDoctorData",
    "Doctor*",
    "model",
    "DoctorModel*"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDoctorENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       1,   70, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,   13,   38,    2, 0x02,    2 /* Public */,
      16,    0,   65,    2, 0x02,   16 /* Public */,
      17,    0,   66,    2, 0x02,   17 /* Public */,
      18,    1,   67,    2, 0x02,   18 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QStringList, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 19, QMetaType::QString,    3,

 // properties: name, type, flags
      20, 0x80000000 | 21, 0x0001510a, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Doctor::staticMetaObject = { {
    QMetaObject::SuperData::link<Person::staticMetaObject>(),
    qt_meta_stringdata_CLASSDoctorENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDoctorENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDoctorENDCLASS_t,
        // property 'model'
        QtPrivate::TypeAndForceComplete<DoctorModel*, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Doctor, std::true_type>,
        // method 'getDoctorData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'addDoctorData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showDoctorDataFromFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'searchDoctorData'
        QtPrivate::TypeAndForceComplete<Doctor *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void Doctor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Doctor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->getDoctorData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[13]))); break;
        case 1: _t->addDoctorData(); break;
        case 2: _t->showDoctorDataFromFile(); break;
        case 3: { Doctor* _r = _t->searchDoctorData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< Doctor**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DoctorModel* >(); break;
        }
    }  else if (_c == QMetaObject::ReadProperty) {
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Doctor *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setModel(*reinterpret_cast< DoctorModel**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Doctor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Doctor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDoctorENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Available"))
        return static_cast< Available*>(this);
    return Person::qt_metacast(_clname);
}

int Doctor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Person::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
