/****************************************************************************
** Meta object code from reading C++ file 'Patient.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Patient.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Patient.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSInpatientModelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSInpatientModelENDCLASS = QtMocHelpers::stringData(
    "InpatientModel",
    "printInpatients",
    "",
    "data",
    "QModelIndex",
    "index",
    "role",
    "get_patientId",
    "get_name",
    "editInpatientModel",
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

Q_CONSTINIT static const uint qt_meta_data_CLASSInpatientModelENDCLASS[] = {

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

Q_CONSTINIT const QMetaObject InpatientModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_CLASSInpatientModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSInpatientModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSInpatientModelENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<InpatientModel, std::true_type>,
        // method 'printInpatients'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'data'
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'data'
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'get_patientId'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'get_name'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'editInpatientModel'
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

void InpatientModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InpatientModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->printInpatients(); break;
        case 1: { QVariant _r = _t->data((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 2: { QVariant _r = _t->data((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->get_patientId((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->get_name((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->editInpatientModel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 6: _t->clear(); break;
        case 7: _t->removeAt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *InpatientModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InpatientModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSInpatientModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int InpatientModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_CLASSInpatientENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSInpatientENDCLASS = QtMocHelpers::stringData(
    "Inpatient",
    "checkInpatientId",
    "",
    "I_patientId",
    "showIn_PatientBefore",
    "I_date",
    "getIn_PatientData",
    "I_phone",
    "I_name",
    "I_address",
    "I_CCCD",
    "I_sex",
    "I_diseaseName",
    "I_symptoms",
    "I_treatment",
    "I_department",
    "I_BHYT",
    "I_weight",
    "I_height",
    "I_appointDate",
    "I_dischargeDate",
    "I_roomNumber",
    "addIn_PatientData",
    "showIn_PatientDataFromFile",
    "searchInpatientData",
    "editInpatientData",
    "deleteInpatientData",
    "I_inpatientId",
    "showSearchInpatient",
    "searchName",
    "get_name",
    "get_address",
    "get_phone",
    "get_date",
    "get_CCCD",
    "get_sex",
    "get_age",
    "get_diseasename",
    "get_symptoms",
    "get_treatment",
    "get_department",
    "get_patientId",
    "get_BHYT",
    "get_weight",
    "get_height",
    "get_appointDate",
    "get_dischargeDate",
    "get_roomNumber",
    "set_name",
    "value",
    "set_address",
    "set_phone",
    "set_date",
    "set_CCCD",
    "set_sex",
    "set_age",
    "set_diseasename",
    "set_symptoms",
    "set_treatment",
    "set_department",
    "set_patientId",
    "set_BHYT",
    "set_weight",
    "set_height",
    "set_appointDate",
    "set_dischargeDate",
    "set_roomNumber",
    "model",
    "InpatientModel*"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSInpatientENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      45,   14, // methods
       1,  409, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  284,    2, 0x02,    2 /* Public */,
       4,    1,  287,    2, 0x02,    4 /* Public */,
       6,   17,  290,    2, 0x02,    6 /* Public */,
      22,    0,  325,    2, 0x02,   24 /* Public */,
      23,    0,  326,    2, 0x02,   25 /* Public */,
      24,    1,  327,    2, 0x02,   26 /* Public */,
      25,    0,  330,    2, 0x02,   28 /* Public */,
      26,    1,  331,    2, 0x02,   29 /* Public */,
      28,    1,  334,    2, 0x02,   31 /* Public */,
      30,    0,  337,    2, 0x102,   33 /* Public | MethodIsConst  */,
      31,    0,  338,    2, 0x102,   34 /* Public | MethodIsConst  */,
      32,    0,  339,    2, 0x102,   35 /* Public | MethodIsConst  */,
      33,    0,  340,    2, 0x102,   36 /* Public | MethodIsConst  */,
      34,    0,  341,    2, 0x102,   37 /* Public | MethodIsConst  */,
      35,    0,  342,    2, 0x102,   38 /* Public | MethodIsConst  */,
      36,    0,  343,    2, 0x102,   39 /* Public | MethodIsConst  */,
      37,    0,  344,    2, 0x102,   40 /* Public | MethodIsConst  */,
      38,    0,  345,    2, 0x102,   41 /* Public | MethodIsConst  */,
      39,    0,  346,    2, 0x102,   42 /* Public | MethodIsConst  */,
      40,    0,  347,    2, 0x102,   43 /* Public | MethodIsConst  */,
      41,    0,  348,    2, 0x102,   44 /* Public | MethodIsConst  */,
      42,    0,  349,    2, 0x102,   45 /* Public | MethodIsConst  */,
      43,    0,  350,    2, 0x102,   46 /* Public | MethodIsConst  */,
      44,    0,  351,    2, 0x102,   47 /* Public | MethodIsConst  */,
      45,    0,  352,    2, 0x102,   48 /* Public | MethodIsConst  */,
      46,    0,  353,    2, 0x102,   49 /* Public | MethodIsConst  */,
      47,    0,  354,    2, 0x102,   50 /* Public | MethodIsConst  */,
      48,    1,  355,    2, 0x02,   51 /* Public */,
      50,    1,  358,    2, 0x02,   53 /* Public */,
      51,    1,  361,    2, 0x02,   55 /* Public */,
      52,    1,  364,    2, 0x02,   57 /* Public */,
      53,    1,  367,    2, 0x02,   59 /* Public */,
      54,    1,  370,    2, 0x02,   61 /* Public */,
      55,    1,  373,    2, 0x02,   63 /* Public */,
      56,    1,  376,    2, 0x02,   65 /* Public */,
      57,    1,  379,    2, 0x02,   67 /* Public */,
      58,    1,  382,    2, 0x02,   69 /* Public */,
      59,    1,  385,    2, 0x02,   71 /* Public */,
      60,    1,  388,    2, 0x02,   73 /* Public */,
      61,    1,  391,    2, 0x02,   75 /* Public */,
      62,    1,  394,    2, 0x02,   77 /* Public */,
      63,    1,  397,    2, 0x02,   79 /* Public */,
      64,    1,  400,    2, 0x02,   81 /* Public */,
      65,    1,  403,    2, 0x02,   83 /* Public */,
      66,    1,  406,    2, 0x02,   85 /* Public */,

 // methods: parameters
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    7,    8,    9,    5,   10,   11,   12,   13,   14,   15,    3,   16,   17,   18,   19,   20,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void, QMetaType::QString,   29,
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
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,

 // properties: name, type, flags
      67, 0x80000000 | 68, 0x0001510a, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Inpatient::staticMetaObject = { {
    QMetaObject::SuperData::link<Patient::staticMetaObject>(),
    qt_meta_stringdata_CLASSInpatientENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSInpatientENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSInpatientENDCLASS_t,
        // property 'model'
        QtPrivate::TypeAndForceComplete<InpatientModel*, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Inpatient, std::true_type>,
        // method 'checkInpatientId'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'showIn_PatientBefore'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'getIn_PatientData'
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
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'addIn_PatientData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showIn_PatientDataFromFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'searchInpatientData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'editInpatientData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteInpatientData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'showSearchInpatient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'get_name'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_address'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_phone'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_date'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_CCCD'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_sex'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_age'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_diseasename'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_symptoms'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_treatment'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_department'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_patientId'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_BHYT'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_weight'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_height'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_appointDate'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_dischargeDate'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_roomNumber'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'set_name'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_address'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_phone'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_date'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_CCCD'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_sex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_age'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_diseasename'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_symptoms'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_treatment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_department'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_patientId'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_BHYT'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_weight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_height'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_appointDate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_dischargeDate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_roomNumber'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void Inpatient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Inpatient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { bool _r = _t->checkInpatientId((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->showIn_PatientBefore((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->getIn_PatientData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[13])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[14])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[15])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[16])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[17]))); break;
        case 3: _t->addIn_PatientData(); break;
        case 4: _t->showIn_PatientDataFromFile(); break;
        case 5: _t->searchInpatientData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->editInpatientData(); break;
        case 7: _t->deleteInpatientData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->showSearchInpatient((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: { QString _r = _t->get_name();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->get_address();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { QString _r = _t->get_phone();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 12: { QString _r = _t->get_date();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 13: { QString _r = _t->get_CCCD();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 14: { QString _r = _t->get_sex();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 15: { QString _r = _t->get_age();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 16: { QString _r = _t->get_diseasename();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 17: { QString _r = _t->get_symptoms();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 18: { QString _r = _t->get_treatment();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 19: { QString _r = _t->get_department();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 20: { QString _r = _t->get_patientId();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 21: { QString _r = _t->get_BHYT();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 22: { QString _r = _t->get_weight();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 23: { QString _r = _t->get_height();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 24: { QString _r = _t->get_appointDate();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 25: { QString _r = _t->get_dischargeDate();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 26: { QString _r = _t->get_roomNumber();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 27: _t->set_name((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 28: _t->set_address((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 29: _t->set_phone((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 30: _t->set_date((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 31: _t->set_CCCD((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 32: _t->set_sex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 33: _t->set_age((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 34: _t->set_diseasename((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 35: _t->set_symptoms((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 36: _t->set_treatment((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 37: _t->set_department((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 38: _t->set_patientId((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 39: _t->set_BHYT((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 40: _t->set_weight((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 41: _t->set_height((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 42: _t->set_appointDate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 43: _t->set_dischargeDate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 44: _t->set_roomNumber((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< InpatientModel* >(); break;
        }
    }  else if (_c == QMetaObject::ReadProperty) {
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Inpatient *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setModel(*reinterpret_cast< InpatientModel**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Inpatient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Inpatient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSInpatientENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return Patient::qt_metacast(_clname);
}

int Inpatient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Patient::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 45)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 45;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 45)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 45;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSOutpatientModelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSOutpatientModelENDCLASS = QtMocHelpers::stringData(
    "OutpatientModel",
    "printOutpatients",
    "",
    "data",
    "QModelIndex",
    "index",
    "role",
    "get_patientId",
    "get_name",
    "editOutpatientModel",
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

Q_CONSTINIT static const uint qt_meta_data_CLASSOutpatientModelENDCLASS[] = {

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

Q_CONSTINIT const QMetaObject OutpatientModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_CLASSOutpatientModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSOutpatientModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSOutpatientModelENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<OutpatientModel, std::true_type>,
        // method 'printOutpatients'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'data'
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'data'
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'get_patientId'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'get_name'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'editOutpatientModel'
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

void OutpatientModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OutpatientModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->printOutpatients(); break;
        case 1: { QVariant _r = _t->data((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 2: { QVariant _r = _t->data((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->get_patientId((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->get_name((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->editOutpatientModel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 6: _t->clear(); break;
        case 7: _t->removeAt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *OutpatientModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OutpatientModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSOutpatientModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int OutpatientModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_CLASSOutpatientENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSOutpatientENDCLASS = QtMocHelpers::stringData(
    "Outpatient",
    "checkOutpatientId",
    "",
    "I_patientId",
    "showOut_PatientBefore",
    "I_date",
    "getOut_PatientData",
    "I_phone",
    "I_name",
    "I_address",
    "I_CCCD",
    "I_sex",
    "I_diseaseName",
    "I_symptoms",
    "I_treatment",
    "I_department",
    "I_BHYT",
    "I_weight",
    "I_height",
    "I_appointDate",
    "I_numberOfFollowUps",
    "I_daysBetweenVisits",
    "addOut_PatientData",
    "showOut_PatientDataFromFile",
    "searchOutpatientData",
    "editOutpatientData",
    "deleteOutpatientData",
    "I_outpatientId",
    "showSearchOutpatient",
    "searchName",
    "get_name",
    "get_address",
    "get_phone",
    "get_date",
    "get_CCCD",
    "get_sex",
    "get_age",
    "get_diseasename",
    "get_symptoms",
    "get_treatment",
    "get_department",
    "get_patientId",
    "get_BHYT",
    "get_weight",
    "get_height",
    "get_appointDate",
    "get_numberOfFollowUps",
    "get_daysBetweenVisits",
    "set_name",
    "value",
    "set_address",
    "set_phone",
    "set_date",
    "set_CCCD",
    "set_sex",
    "set_age",
    "set_diseasename",
    "set_symptoms",
    "set_treatment",
    "set_department",
    "set_patientId",
    "set_BHYT",
    "set_weight",
    "set_height",
    "set_appointDate",
    "set_numberOfFollowUps",
    "set_daysBetweenVisits",
    "model",
    "OutpatientModel*"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSOutpatientENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      45,   14, // methods
       1,  409, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  284,    2, 0x02,    2 /* Public */,
       4,    1,  287,    2, 0x02,    4 /* Public */,
       6,   17,  290,    2, 0x02,    6 /* Public */,
      22,    0,  325,    2, 0x02,   24 /* Public */,
      23,    0,  326,    2, 0x02,   25 /* Public */,
      24,    1,  327,    2, 0x02,   26 /* Public */,
      25,    0,  330,    2, 0x02,   28 /* Public */,
      26,    1,  331,    2, 0x02,   29 /* Public */,
      28,    1,  334,    2, 0x02,   31 /* Public */,
      30,    0,  337,    2, 0x102,   33 /* Public | MethodIsConst  */,
      31,    0,  338,    2, 0x102,   34 /* Public | MethodIsConst  */,
      32,    0,  339,    2, 0x102,   35 /* Public | MethodIsConst  */,
      33,    0,  340,    2, 0x102,   36 /* Public | MethodIsConst  */,
      34,    0,  341,    2, 0x102,   37 /* Public | MethodIsConst  */,
      35,    0,  342,    2, 0x102,   38 /* Public | MethodIsConst  */,
      36,    0,  343,    2, 0x102,   39 /* Public | MethodIsConst  */,
      37,    0,  344,    2, 0x102,   40 /* Public | MethodIsConst  */,
      38,    0,  345,    2, 0x102,   41 /* Public | MethodIsConst  */,
      39,    0,  346,    2, 0x102,   42 /* Public | MethodIsConst  */,
      40,    0,  347,    2, 0x102,   43 /* Public | MethodIsConst  */,
      41,    0,  348,    2, 0x102,   44 /* Public | MethodIsConst  */,
      42,    0,  349,    2, 0x102,   45 /* Public | MethodIsConst  */,
      43,    0,  350,    2, 0x102,   46 /* Public | MethodIsConst  */,
      44,    0,  351,    2, 0x102,   47 /* Public | MethodIsConst  */,
      45,    0,  352,    2, 0x102,   48 /* Public | MethodIsConst  */,
      46,    0,  353,    2, 0x102,   49 /* Public | MethodIsConst  */,
      47,    0,  354,    2, 0x102,   50 /* Public | MethodIsConst  */,
      48,    1,  355,    2, 0x02,   51 /* Public */,
      50,    1,  358,    2, 0x02,   53 /* Public */,
      51,    1,  361,    2, 0x02,   55 /* Public */,
      52,    1,  364,    2, 0x02,   57 /* Public */,
      53,    1,  367,    2, 0x02,   59 /* Public */,
      54,    1,  370,    2, 0x02,   61 /* Public */,
      55,    1,  373,    2, 0x02,   63 /* Public */,
      56,    1,  376,    2, 0x02,   65 /* Public */,
      57,    1,  379,    2, 0x02,   67 /* Public */,
      58,    1,  382,    2, 0x02,   69 /* Public */,
      59,    1,  385,    2, 0x02,   71 /* Public */,
      60,    1,  388,    2, 0x02,   73 /* Public */,
      61,    1,  391,    2, 0x02,   75 /* Public */,
      62,    1,  394,    2, 0x02,   77 /* Public */,
      63,    1,  397,    2, 0x02,   79 /* Public */,
      64,    1,  400,    2, 0x02,   81 /* Public */,
      65,    1,  403,    2, 0x02,   83 /* Public */,
      66,    1,  406,    2, 0x02,   85 /* Public */,

 // methods: parameters
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    7,    8,    9,    5,   10,   11,   12,   13,   14,   15,    3,   16,   17,   18,   19,   20,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void, QMetaType::QString,   29,
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
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,

 // properties: name, type, flags
      67, 0x80000000 | 68, 0x0001510a, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Outpatient::staticMetaObject = { {
    QMetaObject::SuperData::link<Patient::staticMetaObject>(),
    qt_meta_stringdata_CLASSOutpatientENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSOutpatientENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSOutpatientENDCLASS_t,
        // property 'model'
        QtPrivate::TypeAndForceComplete<OutpatientModel*, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Outpatient, std::true_type>,
        // method 'checkOutpatientId'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'showOut_PatientBefore'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'getOut_PatientData'
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
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'addOut_PatientData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showOut_PatientDataFromFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'searchOutpatientData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'editOutpatientData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteOutpatientData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'showSearchOutpatient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'get_name'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_address'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_phone'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_date'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_CCCD'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_sex'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_age'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_diseasename'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_symptoms'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_treatment'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_department'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_patientId'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_BHYT'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_weight'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_height'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_appointDate'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_numberOfFollowUps'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_daysBetweenVisits'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'set_name'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_address'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_phone'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_date'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_CCCD'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_sex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_age'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_diseasename'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_symptoms'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_treatment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_department'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_patientId'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_BHYT'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_weight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_height'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_appointDate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_numberOfFollowUps'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_daysBetweenVisits'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void Outpatient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Outpatient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { bool _r = _t->checkOutpatientId((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->showOut_PatientBefore((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->getOut_PatientData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[13])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[14])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[15])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[16])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[17]))); break;
        case 3: _t->addOut_PatientData(); break;
        case 4: _t->showOut_PatientDataFromFile(); break;
        case 5: _t->searchOutpatientData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->editOutpatientData(); break;
        case 7: _t->deleteOutpatientData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->showSearchOutpatient((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: { QString _r = _t->get_name();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->get_address();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { QString _r = _t->get_phone();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 12: { QString _r = _t->get_date();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 13: { QString _r = _t->get_CCCD();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 14: { QString _r = _t->get_sex();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 15: { QString _r = _t->get_age();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 16: { QString _r = _t->get_diseasename();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 17: { QString _r = _t->get_symptoms();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 18: { QString _r = _t->get_treatment();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 19: { QString _r = _t->get_department();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 20: { QString _r = _t->get_patientId();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 21: { QString _r = _t->get_BHYT();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 22: { QString _r = _t->get_weight();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 23: { QString _r = _t->get_height();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 24: { QString _r = _t->get_appointDate();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 25: { QString _r = _t->get_numberOfFollowUps();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 26: { QString _r = _t->get_daysBetweenVisits();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 27: _t->set_name((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 28: _t->set_address((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 29: _t->set_phone((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 30: _t->set_date((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 31: _t->set_CCCD((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 32: _t->set_sex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 33: _t->set_age((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 34: _t->set_diseasename((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 35: _t->set_symptoms((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 36: _t->set_treatment((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 37: _t->set_department((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 38: _t->set_patientId((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 39: _t->set_BHYT((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 40: _t->set_weight((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 41: _t->set_height((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 42: _t->set_appointDate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 43: _t->set_numberOfFollowUps((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 44: _t->set_daysBetweenVisits((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< OutpatientModel* >(); break;
        }
    }  else if (_c == QMetaObject::ReadProperty) {
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Outpatient *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setModel(*reinterpret_cast< OutpatientModel**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Outpatient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Outpatient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSOutpatientENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return Patient::qt_metacast(_clname);
}

int Outpatient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Patient::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 45)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 45;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 45)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 45;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
