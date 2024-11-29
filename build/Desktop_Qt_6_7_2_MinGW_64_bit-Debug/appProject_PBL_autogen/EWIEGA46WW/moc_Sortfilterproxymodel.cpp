/****************************************************************************
** Meta object code from reading C++ file 'Sortfilterproxymodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Sortfilterproxymodel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Sortfilterproxymodel.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSortFilterProxyModelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSortFilterProxyModelENDCLASS = QtMocHelpers::stringData(
    "SortFilterProxyModel",
    "filterTextChanged",
    "",
    "filterRoleNameChanged",
    "filterCallbackChanged",
    "filterText",
    "filterRoleName",
    "filterCallback",
    "QJSValue"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSortFilterProxyModelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       3,   35, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x06,    4 /* Public */,
       3,    0,   33,    2, 0x06,    5 /* Public */,
       4,    0,   34,    2, 0x06,    6 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       5, QMetaType::QString, 0x00015103, uint(0), 0,
       6, QMetaType::QString, 0x00015103, uint(1), 0,
       7, 0x80000000 | 8, 0x0001510b, uint(2), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject SortFilterProxyModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QSortFilterProxyModel::staticMetaObject>(),
    qt_meta_stringdata_CLASSSortFilterProxyModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSortFilterProxyModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSortFilterProxyModelENDCLASS_t,
        // property 'filterText'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'filterRoleName'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'filterCallback'
        QtPrivate::TypeAndForceComplete<QJSValue, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SortFilterProxyModel, std::true_type>,
        // method 'filterTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'filterRoleNameChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'filterCallbackChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SortFilterProxyModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SortFilterProxyModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->filterTextChanged(); break;
        case 1: _t->filterRoleNameChanged(); break;
        case 2: _t->filterCallbackChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SortFilterProxyModel::*)();
            if (_t _q_method = &SortFilterProxyModel::filterTextChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SortFilterProxyModel::*)();
            if (_t _q_method = &SortFilterProxyModel::filterRoleNameChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SortFilterProxyModel::*)();
            if (_t _q_method = &SortFilterProxyModel::filterCallbackChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QJSValue >(); break;
        }
    }  else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SortFilterProxyModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->filterText(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->filterRoleName(); break;
        case 2: *reinterpret_cast< QJSValue*>(_v) = _t->filterCallback(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SortFilterProxyModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFilterText(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setFilterRoleName(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setFilterCallback(*reinterpret_cast< QJSValue*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *SortFilterProxyModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SortFilterProxyModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSortFilterProxyModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QSortFilterProxyModel::qt_metacast(_clname);
}

int SortFilterProxyModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSortFilterProxyModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SortFilterProxyModel::filterTextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SortFilterProxyModel::filterRoleNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SortFilterProxyModel::filterCallbackChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
