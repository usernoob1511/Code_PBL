/****************************************************************************
** Meta object code from reading C++ file 'Doctor.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Doctor.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Doctor.h' doesn't include <QObject>."
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
    "",
    "data",
    "QModelIndex",
    "index",
    "role",
    "get_doctorId",
    "get_name",
    "editDoctorModel",
    "name",
    "cccd",
    "phone",
    "clear",
    "removeAt"
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
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x02,    1 /* Public */,
       3,    2,   63,    2, 0x102,    2 /* Public | MethodIsConst  */,
       3,    1,   68,    2, 0x122,    5 /* Public | MethodCloned | MethodIsConst  */,
       7,    1,   71,    2, 0x02,    7 /* Public */,
       8,    1,   74,    2, 0x02,    9 /* Public */,
       9,    4,   77,    2, 0x02,   11 /* Public */,
      13,    0,   86,    2, 0x02,   16 /* Public */,
      14,    1,   87,    2, 0x02,   17 /* Public */,

 // methods: parameters
    QMetaType::Void,
    QMetaType::QVariant, 0x80000000 | 4, QMetaType::Int,    5,    6,
    QMetaType::QVariant, 0x80000000 | 4,    5,
    QMetaType::QString, QMetaType::Int,    5,
    QMetaType::QString, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,   10,   11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,

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
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'data'
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'data'
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'get_doctorId'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'get_name'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'editDoctorModel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'clear'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeAt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
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
        case 1: { QVariant _r = _t->data((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 2: { QVariant _r = _t->data((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->get_doctorId((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->get_name((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->editDoctorModel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 6: _t->clear(); break;
        case 7: _t->removeAt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSDoctorENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSDoctorENDCLASS = QtMocHelpers::stringData(
    "Doctor",
    "checkDoctorId",
    "",
    "I_doctorId",
    "getDoctorData",
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
    "editDoctorData",
    "deleteDoctorData",
    "showSearchDoctor",
    "name",
    "showDoctorOnline",
    "get_doctorId",
    "get_department",
    "get_CCCD",
    "get_name",
    "get_address",
    "get_phone",
    "get_mail",
    "get_date",
    "get_sex",
    "get_age",
    "get_days",
    "get_shift1",
    "get_shift2",
    "get_NoD",
    "set_doctorId",
    "id",
    "set_department",
    "dep",
    "set_CCCD",
    "cccd",
    "set_name",
    "n",
    "set_address",
    "addr",
    "set_phone",
    "ph",
    "set_mail",
    "m",
    "set_date",
    "d",
    "set_sex",
    "s",
    "set_age",
    "a",
    "set_days",
    "set_shift1",
    "shift",
    "set_shift2",
    "set_NoD",
    "noD",
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
      37,   14, // methods
       1,  335, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  236,    2, 0x02,    2 /* Public */,
       4,   13,  239,    2, 0x02,    4 /* Public */,
      17,    0,  266,    2, 0x02,   18 /* Public */,
      18,    0,  267,    2, 0x02,   19 /* Public */,
      19,    1,  268,    2, 0x02,   20 /* Public */,
      20,    0,  271,    2, 0x02,   22 /* Public */,
      21,    1,  272,    2, 0x02,   23 /* Public */,
      22,    1,  275,    2, 0x02,   25 /* Public */,
      24,    0,  278,    2, 0x02,   27 /* Public */,
      25,    0,  279,    2, 0x102,   28 /* Public | MethodIsConst  */,
      26,    0,  280,    2, 0x102,   29 /* Public | MethodIsConst  */,
      27,    0,  281,    2, 0x102,   30 /* Public | MethodIsConst  */,
      28,    0,  282,    2, 0x102,   31 /* Public | MethodIsConst  */,
      29,    0,  283,    2, 0x102,   32 /* Public | MethodIsConst  */,
      30,    0,  284,    2, 0x102,   33 /* Public | MethodIsConst  */,
      31,    0,  285,    2, 0x102,   34 /* Public | MethodIsConst  */,
      32,    0,  286,    2, 0x102,   35 /* Public | MethodIsConst  */,
      33,    0,  287,    2, 0x102,   36 /* Public | MethodIsConst  */,
      34,    0,  288,    2, 0x102,   37 /* Public | MethodIsConst  */,
      35,    0,  289,    2, 0x102,   38 /* Public | MethodIsConst  */,
      36,    0,  290,    2, 0x102,   39 /* Public | MethodIsConst  */,
      37,    0,  291,    2, 0x102,   40 /* Public | MethodIsConst  */,
      38,    0,  292,    2, 0x102,   41 /* Public | MethodIsConst  */,
      39,    1,  293,    2, 0x02,   42 /* Public */,
      41,    1,  296,    2, 0x02,   44 /* Public */,
      43,    1,  299,    2, 0x02,   46 /* Public */,
      45,    1,  302,    2, 0x02,   48 /* Public */,
      47,    1,  305,    2, 0x02,   50 /* Public */,
      49,    1,  308,    2, 0x02,   52 /* Public */,
      51,    1,  311,    2, 0x02,   54 /* Public */,
      53,    1,  314,    2, 0x02,   56 /* Public */,
      55,    1,  317,    2, 0x02,   58 /* Public */,
      57,    1,  320,    2, 0x02,   60 /* Public */,
      59,    1,  323,    2, 0x02,   62 /* Public */,
      60,    1,  326,    2, 0x02,   64 /* Public */,
      62,    1,  329,    2, 0x02,   66 /* Public */,
      63,    1,  332,    2, 0x02,   68 /* Public */,

 // methods: parameters
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QStringList, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    5,    6,    7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QStringList,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   40,
    QMetaType::Void, QMetaType::QString,   42,
    QMetaType::Void, QMetaType::QString,   44,
    QMetaType::Void, QMetaType::QString,   46,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Void, QMetaType::QString,   50,
    QMetaType::Void, QMetaType::QString,   52,
    QMetaType::Void, QMetaType::QString,   54,
    QMetaType::Void, QMetaType::QString,   56,
    QMetaType::Void, QMetaType::QString,   58,
    QMetaType::Void, QMetaType::QStringList,   13,
    QMetaType::Void, QMetaType::QString,   61,
    QMetaType::Void, QMetaType::QString,   61,
    QMetaType::Void, QMetaType::QString,   64,

 // properties: name, type, flags
      65, 0x80000000 | 66, 0x0001510a, uint(-1), 0,

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
        // method 'checkDoctorId'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
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
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'editDoctorData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteDoctorData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'showSearchDoctor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'showDoctorOnline'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'get_doctorId'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_department'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_CCCD'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_name'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_address'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_phone'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_mail'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_date'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_sex'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_age'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_days'
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'get_shift1'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_shift2'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_NoD'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'set_doctorId'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_department'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_CCCD'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_name'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_address'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_phone'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_mail'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_date'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_sex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_age'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_days'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        // method 'set_shift1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_shift2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_NoD'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
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
        case 0: { bool _r = _t->checkDoctorId((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->getDoctorData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[13]))); break;
        case 2: _t->addDoctorData(); break;
        case 3: _t->showDoctorDataFromFile(); break;
        case 4: _t->searchDoctorData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->editDoctorData(); break;
        case 6: _t->deleteDoctorData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->showSearchDoctor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->showDoctorOnline(); break;
        case 9: { QString _r = _t->get_doctorId();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->get_department();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { QString _r = _t->get_CCCD();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 12: { QString _r = _t->get_name();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 13: { QString _r = _t->get_address();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 14: { QString _r = _t->get_phone();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 15: { QString _r = _t->get_mail();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 16: { QString _r = _t->get_date();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 17: { QString _r = _t->get_sex();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 18: { QString _r = _t->get_age();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 19: { QStringList _r = _t->get_days();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 20: { QString _r = _t->get_shift1();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 21: { QString _r = _t->get_shift2();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 22: { QString _r = _t->get_NoD();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 23: _t->set_doctorId((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 24: _t->set_department((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 25: _t->set_CCCD((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 26: _t->set_name((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 27: _t->set_address((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 28: _t->set_phone((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 29: _t->set_mail((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 30: _t->set_date((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 31: _t->set_sex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 32: _t->set_age((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 33: _t->set_days((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 34: _t->set_shift1((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 35: _t->set_shift2((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 36: _t->set_NoD((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
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
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 37)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 37;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
