/****************************************************************************
** Meta object code from reading C++ file 'manager_widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../manager_widget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manager_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
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
struct qt_meta_stringdata_CLASSManager_widgetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSManager_widgetENDCLASS = QtMocHelpers::stringData(
    "Manager_widget",
    "when_pushButtonDoSqlQuery_clicked",
    "",
    "when_Retrieving_User_Information_clicked",
    "when_New_User_Registration_clicked",
    "when_All_Car_Information_clicked",
    "when_Available_Car_Information_clicked",
    "when_Rent_the_car_clicked",
    "when_Return_the_car_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSManager_widgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

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

Q_CONSTINIT const QMetaObject Manager_widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSManager_widgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSManager_widgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSManager_widgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Manager_widget, std::true_type>,
        // method 'when_pushButtonDoSqlQuery_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'when_Retrieving_User_Information_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'when_New_User_Registration_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'when_All_Car_Information_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'when_Available_Car_Information_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'when_Rent_the_car_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'when_Return_the_car_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Manager_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Manager_widget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->when_pushButtonDoSqlQuery_clicked(); break;
        case 1: _t->when_Retrieving_User_Information_clicked(); break;
        case 2: _t->when_New_User_Registration_clicked(); break;
        case 3: _t->when_All_Car_Information_clicked(); break;
        case 4: _t->when_Available_Car_Information_clicked(); break;
        case 5: _t->when_Rent_the_car_clicked(); break;
        case 6: _t->when_Return_the_car_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Manager_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Manager_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSManager_widgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Manager_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
