/****************************************************************************
** Meta object code from reading C++ file 'regthread.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../artifact/regthread.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'regthread.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9RegThreadE_t {};
} // unnamed namespace

template <> constexpr inline auto RegThread::qt_create_metaobjectdata<qt_meta_tag_ZN9RegThreadE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "RegThread",
        "regDataAdded",
        "",
        "number",
        "regDataUpdated",
        "regDataDeleted",
        "imageAdded",
        "name",
        "imageDeleted",
        "deleteRegDB",
        "addNewRegData",
        "BaseInfo",
        "info",
        "BatchInfo",
        "batchInfo",
        "startNewRegData",
        "updateRegData",
        "getBaseInfo",
        "getBatchInfo",
        "regFinished",
        "setRegNo",
        "regNo",
        "getRegNo",
        "getRegNumber",
        "setRegNumber",
        "getRegNumberList",
        "getRegData",
        "const RegData*",
        "bool*",
        "isOk",
        "addMainImage",
        "getMainImage",
        "QImage",
        "globalImageName",
        "index",
        "markedImageName",
        "lowImageName",
        "markImageName",
        "isUnique",
        "highImageName",
        "deleteRegData",
        "addGlobalImage",
        "image",
        "addMarkedImage",
        "addLowImage",
        "addHighImage",
        "deleteGlobalImage",
        "deleteMarkedImage",
        "deleteLowImage",
        "deleteHighImage",
        "deleteAllMarkImage",
        "updateImageInfo",
        "imageName",
        "ImageInfo",
        "getImageInfo",
        "ImageInfo*",
        "uploadFinished",
        "Artifact::ImageInfo",
        "imageInfo"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'regDataAdded'
        QtMocHelpers::SignalData<void(QString)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'regDataUpdated'
        QtMocHelpers::SignalData<void(QString)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'regDataDeleted'
        QtMocHelpers::SignalData<void(QString)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'imageAdded'
        QtMocHelpers::SignalData<void(QString, QString)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 },
        }}),
        // Signal 'imageDeleted'
        QtMocHelpers::SignalData<void(QString, QString)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 },
        }}),
        // Signal 'deleteRegDB'
        QtMocHelpers::SignalData<void(QString)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'addNewRegData'
        QtMocHelpers::SlotData<bool(BaseInfo, BatchInfo)>(10, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 11, 12 }, { 0x80000000 | 13, 14 },
        }}),
        // Slot 'startNewRegData'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'updateRegData'
        QtMocHelpers::SlotData<bool(QString, BaseInfo, BatchInfo)>(16, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { 0x80000000 | 11, 12 }, { 0x80000000 | 13, 14 },
        }}),
        // Slot 'updateRegData'
        QtMocHelpers::SlotData<bool(BaseInfo, BatchInfo)>(16, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 11, 12 }, { 0x80000000 | 13, 14 },
        }}),
        // Slot 'updateRegData'
        QtMocHelpers::SlotData<bool(QString)>(16, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'updateRegData'
        QtMocHelpers::SlotData<bool()>(16, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Bool),
        // Slot 'getBaseInfo'
        QtMocHelpers::SlotData<BaseInfo(QString)>(17, 2, QMC::AccessPublic, 0x80000000 | 11, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'getBaseInfo'
        QtMocHelpers::SlotData<BaseInfo()>(17, 2, QMC::AccessPublic, 0x80000000 | 11),
        // Slot 'getBatchInfo'
        QtMocHelpers::SlotData<BatchInfo(QString)>(18, 2, QMC::AccessPublic, 0x80000000 | 13, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'getBatchInfo'
        QtMocHelpers::SlotData<BatchInfo()>(18, 2, QMC::AccessPublic, 0x80000000 | 13),
        // Slot 'regFinished'
        QtMocHelpers::SlotData<bool(QString)>(19, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'regFinished'
        QtMocHelpers::SlotData<bool()>(19, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'setRegNo'
        QtMocHelpers::SlotData<bool(QString, int)>(20, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::Int, 21 },
        }}),
        // Slot 'setRegNo'
        QtMocHelpers::SlotData<bool(int)>(20, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 21 },
        }}),
        // Slot 'getRegNo'
        QtMocHelpers::SlotData<int(QString)>(22, 2, QMC::AccessPublic, QMetaType::Int, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'getRegNo'
        QtMocHelpers::SlotData<int()>(22, 2, QMC::AccessPublic, QMetaType::Int),
        // Slot 'getRegNumber'
        QtMocHelpers::SlotData<QString()>(23, 2, QMC::AccessPublic, QMetaType::QString),
        // Slot 'setRegNumber'
        QtMocHelpers::SlotData<bool(QString)>(24, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'getRegNumberList'
        QtMocHelpers::SlotData<QStringList()>(25, 2, QMC::AccessPublic, QMetaType::QStringList),
        // Slot 'getRegData'
        QtMocHelpers::SlotData<const RegData *(QString, bool *) const>(26, 2, QMC::AccessPublic, 0x80000000 | 27, {{
            { QMetaType::QString, 3 }, { 0x80000000 | 28, 29 },
        }}),
        // Slot 'getRegData'
        QtMocHelpers::SlotData<const RegData *(QString) const>(26, 2, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 27, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'getRegData'
        QtMocHelpers::SlotData<const RegData *(bool *) const>(26, 2, QMC::AccessPublic, 0x80000000 | 27, {{
            { 0x80000000 | 28, 29 },
        }}),
        // Slot 'getRegData'
        QtMocHelpers::SlotData<const RegData *() const>(26, 2, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 27),
        // Slot 'addMainImage'
        QtMocHelpers::SlotData<bool(QString, QString)>(30, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 },
        }}),
        // Slot 'addMainImage'
        QtMocHelpers::SlotData<bool(QString)>(30, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'getMainImage'
        QtMocHelpers::SlotData<QImage(QString)>(31, 2, QMC::AccessPublic, 0x80000000 | 32, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'getMainImage'
        QtMocHelpers::SlotData<QImage()>(31, 2, QMC::AccessPublic, 0x80000000 | 32),
        // Slot 'globalImageName'
        QtMocHelpers::SlotData<QString(QString, int)>(33, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 3 }, { QMetaType::Int, 34 },
        }}),
        // Slot 'globalImageName'
        QtMocHelpers::SlotData<QString(int)>(33, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::Int, 34 },
        }}),
        // Slot 'markedImageName'
        QtMocHelpers::SlotData<QString(QString, QString)>(35, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 33 },
        }}),
        // Slot 'markedImageName'
        QtMocHelpers::SlotData<QString(QString)>(35, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 33 },
        }}),
        // Slot 'lowImageName'
        QtMocHelpers::SlotData<QString(QString, QString, bool)>(36, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 37 }, { QMetaType::Bool, 38 },
        }}),
        // Slot 'lowImageName'
        QtMocHelpers::SlotData<QString(QString, QString)>(36, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::QString, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 37 },
        }}),
        // Slot 'lowImageName'
        QtMocHelpers::SlotData<QString(QString, bool)>(36, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 37 }, { QMetaType::Bool, 38 },
        }}),
        // Slot 'lowImageName'
        QtMocHelpers::SlotData<QString(QString)>(36, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::QString, {{
            { QMetaType::QString, 37 },
        }}),
        // Slot 'highImageName'
        QtMocHelpers::SlotData<QString(QString, QString, bool)>(39, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 36 }, { QMetaType::Bool, 38 },
        }}),
        // Slot 'highImageName'
        QtMocHelpers::SlotData<QString(QString, QString)>(39, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::QString, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 36 },
        }}),
        // Slot 'highImageName'
        QtMocHelpers::SlotData<QString(QString, bool)>(39, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 36 }, { QMetaType::Bool, 38 },
        }}),
        // Slot 'highImageName'
        QtMocHelpers::SlotData<QString(QString)>(39, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::QString, {{
            { QMetaType::QString, 36 },
        }}),
        // Slot 'deleteRegData'
        QtMocHelpers::SlotData<bool(QString)>(40, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'deleteRegData'
        QtMocHelpers::SlotData<bool()>(40, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'addGlobalImage'
        QtMocHelpers::SlotData<bool(QString, QString, QImage)>(41, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 }, { 0x80000000 | 32, 42 },
        }}),
        // Slot 'addGlobalImage'
        QtMocHelpers::SlotData<bool(QString, QImage)>(41, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 }, { 0x80000000 | 32, 42 },
        }}),
        // Slot 'addMarkedImage'
        QtMocHelpers::SlotData<bool(QString, QString, QImage)>(43, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 }, { 0x80000000 | 32, 42 },
        }}),
        // Slot 'addMarkedImage'
        QtMocHelpers::SlotData<bool(QString, QImage)>(43, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 }, { 0x80000000 | 32, 42 },
        }}),
        // Slot 'addLowImage'
        QtMocHelpers::SlotData<bool(QString, QString, QImage)>(44, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 }, { 0x80000000 | 32, 42 },
        }}),
        // Slot 'addLowImage'
        QtMocHelpers::SlotData<bool(QString, QImage)>(44, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 }, { 0x80000000 | 32, 42 },
        }}),
        // Slot 'addHighImage'
        QtMocHelpers::SlotData<bool(QString, QString, QImage)>(45, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 }, { 0x80000000 | 32, 42 },
        }}),
        // Slot 'addHighImage'
        QtMocHelpers::SlotData<bool(QString, QImage)>(45, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 }, { 0x80000000 | 32, 42 },
        }}),
        // Slot 'deleteGlobalImage'
        QtMocHelpers::SlotData<bool(QString, QString)>(46, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteGlobalImage'
        QtMocHelpers::SlotData<bool(QString)>(46, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteMarkedImage'
        QtMocHelpers::SlotData<bool(QString, QString)>(47, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteMarkedImage'
        QtMocHelpers::SlotData<bool(QString)>(47, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteLowImage'
        QtMocHelpers::SlotData<bool(QString, QString)>(48, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteLowImage'
        QtMocHelpers::SlotData<bool(QString)>(48, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteHighImage'
        QtMocHelpers::SlotData<bool(QString, QString)>(49, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteHighImage'
        QtMocHelpers::SlotData<bool(QString)>(49, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteAllMarkImage'
        QtMocHelpers::SlotData<bool(QString)>(50, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'deleteAllMarkImage'
        QtMocHelpers::SlotData<bool()>(50, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'updateImageInfo'
        QtMocHelpers::SlotData<bool(QString, QString, ImageInfo)>(51, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 52 }, { 0x80000000 | 53, 12 },
        }}),
        // Slot 'updateImageInfo'
        QtMocHelpers::SlotData<bool(QString, ImageInfo)>(51, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 52 }, { 0x80000000 | 53, 12 },
        }}),
        // Slot 'getImageInfo'
        QtMocHelpers::SlotData<bool(QString, QString, ImageInfo *) const>(54, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 52 }, { 0x80000000 | 55, 12 },
        }}),
        // Slot 'getImageInfo'
        QtMocHelpers::SlotData<bool(QString, ImageInfo *) const>(54, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 52 }, { 0x80000000 | 55, 12 },
        }}),
        // Slot 'uploadFinished'
        QtMocHelpers::SlotData<void(Artifact::ImageInfo)>(56, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 57, 58 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<RegThread, qt_meta_tag_ZN9RegThreadE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject RegThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9RegThreadE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9RegThreadE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9RegThreadE_t>.metaTypes,
    nullptr
} };

void RegThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<RegThread *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->regDataAdded((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->regDataUpdated((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->regDataDeleted((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->imageAdded((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->imageDeleted((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 5: _t->deleteRegDB((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: { bool _r = _t->addNewRegData((*reinterpret_cast<std::add_pointer_t<BaseInfo>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<BatchInfo>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->startNewRegData(); break;
        case 8: { bool _r = _t->updateRegData((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<BaseInfo>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<BatchInfo>>(_a[3])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->updateRegData((*reinterpret_cast<std::add_pointer_t<BaseInfo>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<BatchInfo>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->updateRegData((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->updateRegData();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { BaseInfo _r = _t->getBaseInfo((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<BaseInfo*>(_a[0]) = std::move(_r); }  break;
        case 13: { BaseInfo _r = _t->getBaseInfo();
            if (_a[0]) *reinterpret_cast<BaseInfo*>(_a[0]) = std::move(_r); }  break;
        case 14: { BatchInfo _r = _t->getBatchInfo((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<BatchInfo*>(_a[0]) = std::move(_r); }  break;
        case 15: { BatchInfo _r = _t->getBatchInfo();
            if (_a[0]) *reinterpret_cast<BatchInfo*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->regFinished((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 17: { bool _r = _t->regFinished();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 18: { bool _r = _t->setRegNo((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 19: { bool _r = _t->setRegNo((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 20: { int _r = _t->getRegNo((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<int*>(_a[0]) = std::move(_r); }  break;
        case 21: { int _r = _t->getRegNo();
            if (_a[0]) *reinterpret_cast<int*>(_a[0]) = std::move(_r); }  break;
        case 22: { QString _r = _t->getRegNumber();
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 23: { bool _r = _t->setRegNumber((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 24: { QStringList _r = _t->getRegNumberList();
            if (_a[0]) *reinterpret_cast<QStringList*>(_a[0]) = std::move(_r); }  break;
        case 25: { const RegData* _r = _t->getRegData((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool*>>(_a[2])));
            if (_a[0]) *reinterpret_cast<const RegData**>(_a[0]) = std::move(_r); }  break;
        case 26: { const RegData* _r = _t->getRegData((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<const RegData**>(_a[0]) = std::move(_r); }  break;
        case 27: { const RegData* _r = _t->getRegData((*reinterpret_cast<std::add_pointer_t<bool*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<const RegData**>(_a[0]) = std::move(_r); }  break;
        case 28: { const RegData* _r = _t->getRegData();
            if (_a[0]) *reinterpret_cast<const RegData**>(_a[0]) = std::move(_r); }  break;
        case 29: { bool _r = _t->addMainImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 30: { bool _r = _t->addMainImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 31: { QImage _r = _t->getMainImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QImage*>(_a[0]) = std::move(_r); }  break;
        case 32: { QImage _r = _t->getMainImage();
            if (_a[0]) *reinterpret_cast<QImage*>(_a[0]) = std::move(_r); }  break;
        case 33: { QString _r = _t->globalImageName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 34: { QString _r = _t->globalImageName((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 35: { QString _r = _t->markedImageName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 36: { QString _r = _t->markedImageName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 37: { QString _r = _t->lowImageName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[3])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 38: { QString _r = _t->lowImageName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 39: { QString _r = _t->lowImageName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 40: { QString _r = _t->lowImageName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 41: { QString _r = _t->highImageName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[3])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 42: { QString _r = _t->highImageName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 43: { QString _r = _t->highImageName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 44: { QString _r = _t->highImageName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 45: { bool _r = _t->deleteRegData((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 46: { bool _r = _t->deleteRegData();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 47: { bool _r = _t->addGlobalImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[3])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 48: { bool _r = _t->addGlobalImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 49: { bool _r = _t->addMarkedImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[3])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 50: { bool _r = _t->addMarkedImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 51: { bool _r = _t->addLowImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[3])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 52: { bool _r = _t->addLowImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 53: { bool _r = _t->addHighImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[3])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 54: { bool _r = _t->addHighImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 55: { bool _r = _t->deleteGlobalImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 56: { bool _r = _t->deleteGlobalImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 57: { bool _r = _t->deleteMarkedImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 58: { bool _r = _t->deleteMarkedImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 59: { bool _r = _t->deleteLowImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 60: { bool _r = _t->deleteLowImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 61: { bool _r = _t->deleteHighImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 62: { bool _r = _t->deleteHighImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 63: { bool _r = _t->deleteAllMarkImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 64: { bool _r = _t->deleteAllMarkImage();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 65: { bool _r = _t->updateImageInfo((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<ImageInfo>>(_a[3])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 66: { bool _r = _t->updateImageInfo((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<ImageInfo>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 67: { bool _r = _t->getImageInfo((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<ImageInfo*>>(_a[3])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 68: { bool _r = _t->getImageInfo((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<ImageInfo*>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 69: _t->uploadFinished((*reinterpret_cast<std::add_pointer_t<Artifact::ImageInfo>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (RegThread::*)(QString )>(_a, &RegThread::regDataAdded, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (RegThread::*)(QString )>(_a, &RegThread::regDataUpdated, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (RegThread::*)(QString )>(_a, &RegThread::regDataDeleted, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (RegThread::*)(QString , QString )>(_a, &RegThread::imageAdded, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (RegThread::*)(QString , QString )>(_a, &RegThread::imageDeleted, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (RegThread::*)(QString )>(_a, &RegThread::deleteRegDB, 5))
            return;
    }
}

const QMetaObject *RegThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RegThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9RegThreadE_t>.strings))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int RegThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 70)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 70;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 70)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 70;
    }
    return _id;
}

// SIGNAL 0
void RegThread::regDataAdded(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void RegThread::regDataUpdated(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void RegThread::regDataDeleted(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void RegThread::imageAdded(QString _t1, QString _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}

// SIGNAL 4
void RegThread::imageDeleted(QString _t1, QString _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2);
}

// SIGNAL 5
void RegThread::deleteRegDB(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}
QT_WARNING_POP
