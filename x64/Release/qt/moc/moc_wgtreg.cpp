/****************************************************************************
** Meta object code from reading C++ file 'wgtreg.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../wgt/wgtreg.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wgtreg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.0. It"
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
struct qt_meta_tag_ZN6WgtRegE_t {};
} // unnamed namespace

template <> constexpr inline auto WgtReg::qt_create_metaobjectdata<qt_meta_tag_ZN6WgtRegE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "WgtReg",
        "on_pushButtonGoReg2_clicked",
        "",
        "isNoSave",
        "on_pushButtonGoReg3_clicked",
        "on_pushButtonSkipSampling_clicked",
        "on_pushButtonGoReg4_clicked",
        "on_pushButtonGoReg5_clicked",
        "on_pushButtonGoReg6_clicked",
        "on_pushButtonRegDelete_clicked",
        "on_pushButtonBackHome_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_pushButtonGoReg2_clicked'
        QtMocHelpers::SlotData<void(bool)>(1, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_pushButtonGoReg2_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate | QMC::MethodCloned, QMetaType::Void),
        // Slot 'on_pushButtonGoReg3_clicked'
        QtMocHelpers::SlotData<void(bool)>(4, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_pushButtonGoReg3_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate | QMC::MethodCloned, QMetaType::Void),
        // Slot 'on_pushButtonSkipSampling_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonGoReg4_clicked'
        QtMocHelpers::SlotData<void(bool)>(6, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_pushButtonGoReg4_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate | QMC::MethodCloned, QMetaType::Void),
        // Slot 'on_pushButtonGoReg5_clicked'
        QtMocHelpers::SlotData<void(bool)>(7, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_pushButtonGoReg5_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate | QMC::MethodCloned, QMetaType::Void),
        // Slot 'on_pushButtonGoReg6_clicked'
        QtMocHelpers::SlotData<void(bool)>(8, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'on_pushButtonGoReg6_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate | QMC::MethodCloned, QMetaType::Void),
        // Slot 'on_pushButtonRegDelete_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonBackHome_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<WgtReg, qt_meta_tag_ZN6WgtRegE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject WgtReg::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6WgtRegE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6WgtRegE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN6WgtRegE_t>.metaTypes,
    nullptr
} };

void WgtReg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<WgtReg *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_pushButtonGoReg2_clicked((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->on_pushButtonGoReg2_clicked(); break;
        case 2: _t->on_pushButtonGoReg3_clicked((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->on_pushButtonGoReg3_clicked(); break;
        case 4: _t->on_pushButtonSkipSampling_clicked(); break;
        case 5: _t->on_pushButtonGoReg4_clicked((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->on_pushButtonGoReg4_clicked(); break;
        case 7: _t->on_pushButtonGoReg5_clicked((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->on_pushButtonGoReg5_clicked(); break;
        case 9: _t->on_pushButtonGoReg6_clicked((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 10: _t->on_pushButtonGoReg6_clicked(); break;
        case 11: _t->on_pushButtonRegDelete_clicked(); break;
        case 12: _t->on_pushButtonBackHome_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *WgtReg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WgtReg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6WgtRegE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WgtReg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
