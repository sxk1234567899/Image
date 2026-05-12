/****************************************************************************
** Meta object code from reading C++ file 'regdb.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../artifact/regdb.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'regdb.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN5REGDBE_t {};
} // unnamed namespace

template <> constexpr inline auto REGDB::qt_create_metaobjectdata<qt_meta_tag_ZN5REGDBE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "REGDB",
        "addInfoData",
        "",
        "QHash<QString,QString>",
        "infoData",
        "addImageData",
        "updateInfoData",
        "number",
        "updateImageData",
        "name",
        "deleteInfoData",
        "deleteImageData",
        "getInfoData",
        "QList<QHash<QString,QVariant>>&",
        "getImageData",
        "imageData",
        "creatInfoDataTable",
        "creatImageDataTable"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'addInfoData'
        QtMocHelpers::SlotData<bool(QHash<QString,QString>)>(1, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'addImageData'
        QtMocHelpers::SlotData<bool(QHash<QString,QString>)>(5, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'updateInfoData'
        QtMocHelpers::SlotData<bool(QHash<QString,QString>, QString)>(6, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 3, 4 }, { QMetaType::QString, 7 },
        }}),
        // Slot 'updateImageData'
        QtMocHelpers::SlotData<bool(QHash<QString,QString>, QString, QString)>(8, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 3, 4 }, { QMetaType::QString, 7 }, { QMetaType::QString, 9 },
        }}),
        // Slot 'deleteInfoData'
        QtMocHelpers::SlotData<bool(QString)>(10, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteImageData'
        QtMocHelpers::SlotData<bool(QString, QString)>(11, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 }, { QMetaType::QString, 9 },
        }}),
        // Slot 'getInfoData'
        QtMocHelpers::SlotData<bool(QList<QHash<QString,QVariant>> &)>(12, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 13, 4 },
        }}),
        // Slot 'getImageData'
        QtMocHelpers::SlotData<bool(QList<QHash<QString,QVariant>> &, QString)>(14, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 13, 15 }, { QMetaType::QString, 7 },
        }}),
        // Slot 'creatInfoDataTable'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'creatImageDataTable'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<REGDB, qt_meta_tag_ZN5REGDBE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject REGDB::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5REGDBE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5REGDBE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN5REGDBE_t>.metaTypes,
    nullptr
} };

void REGDB::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<REGDB *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { bool _r = _t->addInfoData((*reinterpret_cast<std::add_pointer_t<QHash<QString,QString>>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->addImageData((*reinterpret_cast<std::add_pointer_t<QHash<QString,QString>>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->updateInfoData((*reinterpret_cast<std::add_pointer_t<QHash<QString,QString>>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->updateImageData((*reinterpret_cast<std::add_pointer_t<QHash<QString,QString>>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->deleteInfoData((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->deleteImageData((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->getInfoData((*reinterpret_cast<std::add_pointer_t<QList<QHash<QString,QVariant>>&>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->getImageData((*reinterpret_cast<std::add_pointer_t<QList<QHash<QString,QVariant>>&>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->creatInfoDataTable(); break;
        case 9: _t->creatImageDataTable(); break;
        default: ;
        }
    }
}

const QMetaObject *REGDB::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *REGDB::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5REGDBE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int REGDB::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
