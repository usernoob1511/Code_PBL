/****************************************************************************
** Meta object code from reading C++ file 'Medicine.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Medicine.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Medicine.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMedicineModelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMedicineModelENDCLASS = QtMocHelpers::stringData(
    "MedicineModel",
    "printMedicines",
    "",
    "data",
    "QModelIndex",
    "index",
    "role",
    "get_medicineCode",
    "get_medicineName",
    "editMedicineModel",
    "name",
    "quantity",
    "usageInstructions",
    "expiryDate",
    "clear",
    "removeAt"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMedicineModelENDCLASS[] = {

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
       9,    5,   77,    2, 0x02,   11 /* Public */,
      14,    0,   88,    2, 0x02,   17 /* Public */,
      15,    1,   89,    2, 0x02,   18 /* Public */,

 // methods: parameters
    QMetaType::Void,
    QMetaType::QVariant, 0x80000000 | 4, QMetaType::Int,    5,    6,
    QMetaType::QVariant, 0x80000000 | 4,    5,
    QMetaType::QString, QMetaType::Int,    5,
    QMetaType::QString, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,   10,   11,   12,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject MedicineModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_CLASSMedicineModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMedicineModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMedicineModelENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MedicineModel, std::true_type>,
        // method 'printMedicines'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'data'
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'data'
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'get_medicineCode'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'get_medicineName'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'editMedicineModel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
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

void MedicineModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MedicineModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->printMedicines(); break;
        case 1: { QVariant _r = _t->data((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 2: { QVariant _r = _t->data((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->get_medicineCode((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->get_medicineName((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->editMedicineModel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 6: _t->clear(); break;
        case 7: _t->removeAt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MedicineModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MedicineModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMedicineModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int MedicineModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_CLASSMedicineENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMedicineENDCLASS = QtMocHelpers::stringData(
    "Medicine",
    "getMedicineData",
    "",
    "I_medicineCode",
    "I_medicineName",
    "I_quantity",
    "I_usageInstructions",
    "I_expiryDate",
    "addMedicineData",
    "showMedicineDataFromFile",
    "searchMedicineData",
    "editMedicineData",
    "deleteMedicineData",
    "showSearchMedicine",
    "name",
    "showSearchMedicineNotUsed",
    "get_medicineCode",
    "get_medicineName",
    "get_quantity",
    "get_usageInstructions",
    "get_expiryDate",
    "set_medicineCode",
    "code",
    "set_medicineName",
    "set_quantity",
    "qty",
    "set_usageInstructions",
    "instructions",
    "set_expiryDate",
    "date",
    "model",
    "MedicineModel*"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMedicineENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       1,  166, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,    5,  122,    2, 0x02,    2 /* Public */,
       8,    0,  133,    2, 0x02,    8 /* Public */,
       9,    0,  134,    2, 0x02,    9 /* Public */,
      10,    1,  135,    2, 0x02,   10 /* Public */,
      11,    0,  138,    2, 0x02,   12 /* Public */,
      12,    1,  139,    2, 0x02,   13 /* Public */,
      13,    1,  142,    2, 0x02,   15 /* Public */,
      15,    0,  145,    2, 0x02,   17 /* Public */,
      16,    0,  146,    2, 0x102,   18 /* Public | MethodIsConst  */,
      17,    0,  147,    2, 0x102,   19 /* Public | MethodIsConst  */,
      18,    0,  148,    2, 0x102,   20 /* Public | MethodIsConst  */,
      19,    0,  149,    2, 0x102,   21 /* Public | MethodIsConst  */,
      20,    0,  150,    2, 0x102,   22 /* Public | MethodIsConst  */,
      21,    1,  151,    2, 0x02,   23 /* Public */,
      23,    1,  154,    2, 0x02,   25 /* Public */,
      24,    1,  157,    2, 0x02,   27 /* Public */,
      26,    1,  160,    2, 0x02,   29 /* Public */,
      28,    1,  163,    2, 0x02,   31 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void, QMetaType::QString,   29,

 // properties: name, type, flags
      30, 0x80000000 | 31, 0x0001510a, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Medicine::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSMedicineENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMedicineENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMedicineENDCLASS_t,
        // property 'model'
        QtPrivate::TypeAndForceComplete<MedicineModel*, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Medicine, std::true_type>,
        // method 'getMedicineData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'addMedicineData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showMedicineDataFromFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'searchMedicineData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'editMedicineData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteMedicineData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'showSearchMedicine'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'showSearchMedicineNotUsed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'get_medicineCode'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_medicineName'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_quantity'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_usageInstructions'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_expiryDate'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'set_medicineCode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_medicineName'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_quantity'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_usageInstructions'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_expiryDate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void Medicine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Medicine *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->getMedicineData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 1: _t->addMedicineData(); break;
        case 2: _t->showMedicineDataFromFile(); break;
        case 3: _t->searchMedicineData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->editMedicineData(); break;
        case 5: _t->deleteMedicineData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->showSearchMedicine((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->showSearchMedicineNotUsed(); break;
        case 8: { QString _r = _t->get_medicineCode();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->get_medicineName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->get_quantity();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { QString _r = _t->get_usageInstructions();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 12: { QString _r = _t->get_expiryDate();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->set_medicineCode((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->set_medicineName((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 15: _t->set_quantity((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->set_usageInstructions((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->set_expiryDate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MedicineModel* >(); break;
        }
    }  else if (_c == QMetaObject::ReadProperty) {
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Medicine *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setModel(*reinterpret_cast< MedicineModel**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Medicine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Medicine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMedicineENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Medicine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 18;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
