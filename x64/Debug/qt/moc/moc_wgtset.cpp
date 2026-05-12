/****************************************************************************
** Meta object code from reading C++ file 'wgtset.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../wgt/wgtset.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wgtset.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN6WgtSetE_t {};
} // unnamed namespace

template <> constexpr inline auto WgtSet::qt_create_metaobjectdata<qt_meta_tag_ZN6WgtSetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "WgtSet",
        "wifiConnectStatus",
        "",
        "status",
        "name",
        "net4GConnectStatus",
        "updateUIShow",
        "tableWidgetWifiCellClicked",
        "row",
        "column",
        "buttonSetGroupClicked",
        "id",
        "buttonSetNetClicked",
        "on_sliderSysVolume_valueChanged",
        "value",
        "on_sliderBrightness_valueChanged",
        "on_pushButtonNetConn_clicked",
        "on_pushButtonUSBConn_clicked",
        "on_pushButtonNetCamSet_clicked",
        "on_pushButtonBtConnect_clicked",
        "on_pushButtonTestPrint_clicked",
        "on_checkBoxWifi_toggled",
        "checked",
        "on_pushButtonUpdateWifi_clicked",
        "on_pushButtonTestWifi_clicked",
        "on_checkBox4g_toggled",
        "on_pushButtonUpdate4G_clicked",
        "on_pushButtonCheckUpdates_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'wifiConnectStatus'
        QtMocHelpers::SignalData<void(bool, QString)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 3 }, { QMetaType::QString, 4 },
        }}),
        // Signal 'net4GConnectStatus'
        QtMocHelpers::SignalData<void(bool, QString)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 3 }, { QMetaType::QString, 4 },
        }}),
        // Slot 'updateUIShow'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'tableWidgetWifiCellClicked'
        QtMocHelpers::SlotData<void(int, int)>(7, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 8 }, { QMetaType::Int, 9 },
        }}),
        // Slot 'buttonSetGroupClicked'
        QtMocHelpers::SlotData<void(int)>(10, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 11 },
        }}),
        // Slot 'buttonSetNetClicked'
        QtMocHelpers::SlotData<void(int)>(12, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 11 },
        }}),
        // Slot 'on_sliderSysVolume_valueChanged'
        QtMocHelpers::SlotData<void(int)>(13, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Slot 'on_sliderBrightness_valueChanged'
        QtMocHelpers::SlotData<void(int)>(15, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Slot 'on_pushButtonNetConn_clicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonUSBConn_clicked'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonNetCamSet_clicked'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonBtConnect_clicked'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonTestPrint_clicked'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_checkBoxWifi_toggled'
        QtMocHelpers::SlotData<void(bool)>(21, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 22 },
        }}),
        // Slot 'on_pushButtonUpdateWifi_clicked'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonTestWifi_clicked'
        QtMocHelpers::SlotData<void(bool)>(24, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 22 },
        }}),
        // Slot 'on_checkBox4g_toggled'
        QtMocHelpers::SlotData<void(bool)>(25, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 22 },
        }}),
        // Slot 'on_pushButtonUpdate4G_clicked'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonCheckUpdates_clicked'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<WgtSet, qt_meta_tag_ZN6WgtSetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject WgtSet::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6WgtSetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6WgtSetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN6WgtSetE_t>.metaTypes,
    nullptr
} };

void WgtSet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<WgtSet *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->wifiConnectStatus((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->net4GConnectStatus((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 2: _t->updateUIShow(); break;
        case 3: _t->tableWidgetWifiCellClicked((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->buttonSetGroupClicked((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->buttonSetNetClicked((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->on_sliderSysVolume_valueChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->on_sliderBrightness_valueChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_pushButtonNetConn_clicked(); break;
        case 9: _t->on_pushButtonUSBConn_clicked(); break;
        case 10: _t->on_pushButtonNetCamSet_clicked(); break;
        case 11: _t->on_pushButtonBtConnect_clicked(); break;
        case 12: _t->on_pushButtonTestPrint_clicked(); break;
        case 13: _t->on_checkBoxWifi_toggled((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 14: _t->on_pushButtonUpdateWifi_clicked(); break;
        case 15: _t->on_pushButtonTestWifi_clicked((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 16: _t->on_checkBox4g_toggled((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 17: _t->on_pushButtonUpdate4G_clicked(); break;
        case 18: _t->on_pushButtonCheckUpdates_clicked(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (WgtSet::*)(bool , QString )>(_a, &WgtSet::wifiConnectStatus, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (WgtSet::*)(bool , QString )>(_a, &WgtSet::net4GConnectStatus, 1))
            return;
    }
}

const QMetaObject *WgtSet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WgtSet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6WgtSetE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WgtSet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void WgtSet::wifiConnectStatus(bool _t1, QString _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void WgtSet::net4GConnectStatus(bool _t1, QString _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}
QT_WARNING_POP
