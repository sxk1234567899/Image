/****************************************************************************
** Meta object code from reading C++ file 'wgtregno1.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../wgt/reg/wgtregno1.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wgtregno1.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9WgtRegNo1E_t {};
} // unnamed namespace

template <> constexpr inline auto WgtRegNo1::qt_create_metaobjectdata<qt_meta_tag_ZN9WgtRegNo1E_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "WgtRegNo1",
        "on_pushButtonSCode_clicked",
        "",
        "on_pushButtonMode_clicked",
        "on_toolButtonBatchUpPage_clicked",
        "on_toolButtonBatchNextPage_clicked",
        "on_toolButtonListUpPage_clicked",
        "on_toolButtonListNextPage_clicked",
        "tableWidgetListCellClicked",
        "row",
        "column",
        "buttonListBackClicked",
        "Artifact::BatchInfo",
        "batchInfo",
        "buttonClicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_pushButtonSCode_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonMode_clicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_toolButtonBatchUpPage_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_toolButtonBatchNextPage_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_toolButtonListUpPage_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_toolButtonListNextPage_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'tableWidgetListCellClicked'
        QtMocHelpers::SlotData<void(int, int)>(8, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 9 }, { QMetaType::Int, 10 },
        }}),
        // Slot 'buttonListBackClicked'
        QtMocHelpers::SlotData<void(Artifact::BatchInfo)>(11, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 12, 13 },
        }}),
        // Slot 'buttonClicked'
        QtMocHelpers::SlotData<void(Artifact::BatchInfo)>(14, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 12, 13 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<WgtRegNo1, qt_meta_tag_ZN9WgtRegNo1E_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject WgtRegNo1::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9WgtRegNo1E_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9WgtRegNo1E_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9WgtRegNo1E_t>.metaTypes,
    nullptr
} };

void WgtRegNo1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<WgtRegNo1 *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_pushButtonSCode_clicked(); break;
        case 1: _t->on_pushButtonMode_clicked(); break;
        case 2: _t->on_toolButtonBatchUpPage_clicked(); break;
        case 3: _t->on_toolButtonBatchNextPage_clicked(); break;
        case 4: _t->on_toolButtonListUpPage_clicked(); break;
        case 5: _t->on_toolButtonListNextPage_clicked(); break;
        case 6: _t->tableWidgetListCellClicked((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 7: _t->buttonListBackClicked((*reinterpret_cast<std::add_pointer_t<Artifact::BatchInfo>>(_a[1]))); break;
        case 8: _t->buttonClicked((*reinterpret_cast<std::add_pointer_t<Artifact::BatchInfo>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *WgtRegNo1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WgtRegNo1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9WgtRegNo1E_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WgtRegNo1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
