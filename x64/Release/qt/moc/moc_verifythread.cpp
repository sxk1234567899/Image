/****************************************************************************
** Meta object code from reading C++ file 'verifythread.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../artifact/verifythread.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'verifythread.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12VerifyThreadE_t {};
} // unnamed namespace

template <> constexpr inline auto VerifyThread::qt_create_metaobjectdata<qt_meta_tag_ZN12VerifyThreadE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "VerifyThread",
        "verifyDataAdded",
        "",
        "number",
        "verifyDataUpdated",
        "verifyDataDeleted",
        "imageAdded",
        "name",
        "imageDeleted",
        "showVerifyResult",
        "sigDeletedVerifyData",
        "sigUpDataFinished",
        "sigWaitEnd",
        "BaseInfo",
        "baseInfo",
        "addNewVerifyData",
        "info",
        "BatchInfo",
        "batchInfo",
        "startNewVerifyData",
        "updateVerifyData",
        "updateVerifyResult",
        "getBaseInfo",
        "getBatchInfo",
        "loadRawImageFinished",
        "verifyFinished",
        "setVerifyNo",
        "verifyNo",
        "getVerifyNo",
        "getVerifyNumber",
        "setVerifyNumber",
        "getVerifyDataList",
        "getVerifyData",
        "const VerifyData*",
        "bool*",
        "isOk",
        "addMainImage",
        "getMainImage",
        "QImage",
        "globalImageName",
        "index",
        "lowImageName",
        "markImageName",
        "isUnique",
        "highImageName",
        "deleteVerifyData",
        "addGlobalImage",
        "image",
        "id",
        "addLowImage",
        "addHighImage",
        "deleteGlobalImage",
        "deleteLowImage",
        "deleteHighImage",
        "deleteAllMarkImage",
        "updateImageInfo",
        "imageName",
        "ImageInfo",
        "getImageInfo",
        "ImageInfo*",
        "addRawGlobalImage",
        "addRawMarkedImage",
        "addRawLowImage",
        "addRawHighImage",
        "deleteRawGlobalImage",
        "deleteRawMarkedImage",
        "deleteRawLowImage",
        "deleteRawHighImage",
        "deleteAllRawMarkImage",
        "updateRawImageInfo",
        "getRawImageInfo",
        "uploadFinished",
        "Artifact::ImageInfo",
        "imageInfo",
        "upDataFinished",
        "waitEnd"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'verifyDataAdded'
        QtMocHelpers::SignalData<void(QString)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'verifyDataUpdated'
        QtMocHelpers::SignalData<void(QString)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'verifyDataDeleted'
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
        // Signal 'showVerifyResult'
        QtMocHelpers::SignalData<void(QString)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'sigDeletedVerifyData'
        QtMocHelpers::SignalData<void(QString)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'sigUpDataFinished'
        QtMocHelpers::SignalData<void(QString)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'sigWaitEnd'
        QtMocHelpers::SignalData<void(QString, BaseInfo)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { 0x80000000 | 13, 14 },
        }}),
        // Slot 'addNewVerifyData'
        QtMocHelpers::SlotData<bool(BaseInfo, BatchInfo)>(15, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 13, 16 }, { 0x80000000 | 17, 18 },
        }}),
        // Slot 'startNewVerifyData'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'updateVerifyData'
        QtMocHelpers::SlotData<bool(QString, BaseInfo, BatchInfo)>(20, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { 0x80000000 | 13, 16 }, { 0x80000000 | 17, 18 },
        }}),
        // Slot 'updateVerifyData'
        QtMocHelpers::SlotData<bool(BaseInfo, BatchInfo)>(20, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 13, 16 }, { 0x80000000 | 17, 18 },
        }}),
        // Slot 'updateVerifyData'
        QtMocHelpers::SlotData<bool(QString)>(20, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'updateVerifyData'
        QtMocHelpers::SlotData<bool()>(20, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Bool),
        // Slot 'updateVerifyResult'
        QtMocHelpers::SlotData<bool(QString)>(21, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'getBaseInfo'
        QtMocHelpers::SlotData<BaseInfo(QString)>(22, 2, QMC::AccessPublic, 0x80000000 | 13, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'getBaseInfo'
        QtMocHelpers::SlotData<BaseInfo()>(22, 2, QMC::AccessPublic, 0x80000000 | 13),
        // Slot 'getBatchInfo'
        QtMocHelpers::SlotData<BatchInfo(QString)>(23, 2, QMC::AccessPublic, 0x80000000 | 17, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'getBatchInfo'
        QtMocHelpers::SlotData<BatchInfo()>(23, 2, QMC::AccessPublic, 0x80000000 | 17),
        // Slot 'loadRawImageFinished'
        QtMocHelpers::SlotData<bool(QString)>(24, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'loadRawImageFinished'
        QtMocHelpers::SlotData<bool()>(24, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'verifyFinished'
        QtMocHelpers::SlotData<bool(QString)>(25, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'verifyFinished'
        QtMocHelpers::SlotData<bool()>(25, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'setVerifyNo'
        QtMocHelpers::SlotData<bool(QString, int)>(26, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::Int, 27 },
        }}),
        // Slot 'setVerifyNo'
        QtMocHelpers::SlotData<bool(int)>(26, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 27 },
        }}),
        // Slot 'getVerifyNo'
        QtMocHelpers::SlotData<int(QString)>(28, 2, QMC::AccessPublic, QMetaType::Int, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'getVerifyNo'
        QtMocHelpers::SlotData<int()>(28, 2, QMC::AccessPublic, QMetaType::Int),
        // Slot 'getVerifyNumber'
        QtMocHelpers::SlotData<QString()>(29, 2, QMC::AccessPublic, QMetaType::QString),
        // Slot 'setVerifyNumber'
        QtMocHelpers::SlotData<bool(QString)>(30, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'getVerifyDataList'
        QtMocHelpers::SlotData<QStringList()>(31, 2, QMC::AccessPublic, QMetaType::QStringList),
        // Slot 'getVerifyData'
        QtMocHelpers::SlotData<const VerifyData *(QString, bool *) const>(32, 2, QMC::AccessPublic, 0x80000000 | 33, {{
            { QMetaType::QString, 3 }, { 0x80000000 | 34, 35 },
        }}),
        // Slot 'getVerifyData'
        QtMocHelpers::SlotData<const VerifyData *(QString) const>(32, 2, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 33, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'getVerifyData'
        QtMocHelpers::SlotData<const VerifyData *(bool *) const>(32, 2, QMC::AccessPublic, 0x80000000 | 33, {{
            { 0x80000000 | 34, 35 },
        }}),
        // Slot 'getVerifyData'
        QtMocHelpers::SlotData<const VerifyData *() const>(32, 2, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 33),
        // Slot 'addMainImage'
        QtMocHelpers::SlotData<bool(QString, QString)>(36, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 },
        }}),
        // Slot 'addMainImage'
        QtMocHelpers::SlotData<bool(QString)>(36, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'getMainImage'
        QtMocHelpers::SlotData<QImage(QString)>(37, 2, QMC::AccessPublic, 0x80000000 | 38, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'getMainImage'
        QtMocHelpers::SlotData<QImage()>(37, 2, QMC::AccessPublic, 0x80000000 | 38),
        // Slot 'globalImageName'
        QtMocHelpers::SlotData<QString(QString, int)>(39, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 3 }, { QMetaType::Int, 40 },
        }}),
        // Slot 'globalImageName'
        QtMocHelpers::SlotData<QString(int)>(39, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::Int, 40 },
        }}),
        // Slot 'lowImageName'
        QtMocHelpers::SlotData<QString(QString, QString, bool)>(41, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 42 }, { QMetaType::Bool, 43 },
        }}),
        // Slot 'lowImageName'
        QtMocHelpers::SlotData<QString(QString, QString)>(41, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::QString, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 42 },
        }}),
        // Slot 'lowImageName'
        QtMocHelpers::SlotData<QString(QString, bool)>(41, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 42 }, { QMetaType::Bool, 43 },
        }}),
        // Slot 'lowImageName'
        QtMocHelpers::SlotData<QString(QString)>(41, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::QString, {{
            { QMetaType::QString, 42 },
        }}),
        // Slot 'highImageName'
        QtMocHelpers::SlotData<QString(QString, QString, bool)>(44, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 41 }, { QMetaType::Bool, 43 },
        }}),
        // Slot 'highImageName'
        QtMocHelpers::SlotData<QString(QString, QString)>(44, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::QString, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 41 },
        }}),
        // Slot 'highImageName'
        QtMocHelpers::SlotData<QString(QString, bool)>(44, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 41 }, { QMetaType::Bool, 43 },
        }}),
        // Slot 'highImageName'
        QtMocHelpers::SlotData<QString(QString)>(44, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::QString, {{
            { QMetaType::QString, 41 },
        }}),
        // Slot 'deleteVerifyData'
        QtMocHelpers::SlotData<bool(QString)>(45, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'deleteVerifyData'
        QtMocHelpers::SlotData<bool()>(45, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'addGlobalImage'
        QtMocHelpers::SlotData<bool(QString, QString, QImage, int)>(46, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 }, { 0x80000000 | 38, 47 }, { QMetaType::Int, 48 },
        }}),
        // Slot 'addGlobalImage'
        QtMocHelpers::SlotData<bool(QString, QImage, int)>(46, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 }, { 0x80000000 | 38, 47 }, { QMetaType::Int, 48 },
        }}),
        // Slot 'addLowImage'
        QtMocHelpers::SlotData<bool(QString, QString, QImage, int)>(49, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 }, { 0x80000000 | 38, 47 }, { QMetaType::Int, 48 },
        }}),
        // Slot 'addLowImage'
        QtMocHelpers::SlotData<bool(QString, QImage, int)>(49, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 }, { 0x80000000 | 38, 47 }, { QMetaType::Int, 48 },
        }}),
        // Slot 'addHighImage'
        QtMocHelpers::SlotData<bool(QString, QString, QImage, int)>(50, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 }, { 0x80000000 | 38, 47 }, { QMetaType::Int, 48 },
        }}),
        // Slot 'addHighImage'
        QtMocHelpers::SlotData<bool(QString, QImage, int)>(50, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 }, { 0x80000000 | 38, 47 }, { QMetaType::Int, 48 },
        }}),
        // Slot 'deleteGlobalImage'
        QtMocHelpers::SlotData<bool(QString, QString)>(51, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteGlobalImage'
        QtMocHelpers::SlotData<bool(QString)>(51, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteLowImage'
        QtMocHelpers::SlotData<bool(QString, QString)>(52, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteLowImage'
        QtMocHelpers::SlotData<bool(QString)>(52, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteHighImage'
        QtMocHelpers::SlotData<bool(QString, QString)>(53, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteHighImage'
        QtMocHelpers::SlotData<bool(QString)>(53, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteAllMarkImage'
        QtMocHelpers::SlotData<bool(QString)>(54, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'deleteAllMarkImage'
        QtMocHelpers::SlotData<bool()>(54, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'updateImageInfo'
        QtMocHelpers::SlotData<bool(QString, QString, ImageInfo)>(55, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 56 }, { 0x80000000 | 57, 16 },
        }}),
        // Slot 'updateImageInfo'
        QtMocHelpers::SlotData<bool(QString, ImageInfo)>(55, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 56 }, { 0x80000000 | 57, 16 },
        }}),
        // Slot 'getImageInfo'
        QtMocHelpers::SlotData<bool(QString, QString, ImageInfo *) const>(58, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 56 }, { 0x80000000 | 59, 16 },
        }}),
        // Slot 'getImageInfo'
        QtMocHelpers::SlotData<bool(QString, ImageInfo *) const>(58, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 56 }, { 0x80000000 | 59, 16 },
        }}),
        // Slot 'addRawGlobalImage'
        QtMocHelpers::SlotData<bool(QString, QString, QImage, ImageInfo)>(60, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 }, { 0x80000000 | 38, 47 }, { 0x80000000 | 57, 16 },
        }}),
        // Slot 'addRawGlobalImage'
        QtMocHelpers::SlotData<bool(QString, QImage, ImageInfo)>(60, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 }, { 0x80000000 | 38, 47 }, { 0x80000000 | 57, 16 },
        }}),
        // Slot 'addRawMarkedImage'
        QtMocHelpers::SlotData<bool(QString, QString, QImage, ImageInfo)>(61, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 }, { 0x80000000 | 38, 47 }, { 0x80000000 | 57, 16 },
        }}),
        // Slot 'addRawMarkedImage'
        QtMocHelpers::SlotData<bool(QString, QImage, ImageInfo)>(61, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 }, { 0x80000000 | 38, 47 }, { 0x80000000 | 57, 16 },
        }}),
        // Slot 'addRawLowImage'
        QtMocHelpers::SlotData<bool(QString, QString, QImage, ImageInfo)>(62, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 }, { 0x80000000 | 38, 47 }, { 0x80000000 | 57, 16 },
        }}),
        // Slot 'addRawLowImage'
        QtMocHelpers::SlotData<bool(QString, QImage, ImageInfo)>(62, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 }, { 0x80000000 | 38, 47 }, { 0x80000000 | 57, 16 },
        }}),
        // Slot 'addRawHighImage'
        QtMocHelpers::SlotData<bool(QString, QString, QImage, ImageInfo)>(63, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 }, { 0x80000000 | 38, 47 }, { 0x80000000 | 57, 16 },
        }}),
        // Slot 'addRawHighImage'
        QtMocHelpers::SlotData<bool(QString, QImage, ImageInfo)>(63, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 }, { 0x80000000 | 38, 47 }, { 0x80000000 | 57, 16 },
        }}),
        // Slot 'deleteRawGlobalImage'
        QtMocHelpers::SlotData<bool(QString, QString)>(64, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteRawGlobalImage'
        QtMocHelpers::SlotData<bool(QString)>(64, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteRawMarkedImage'
        QtMocHelpers::SlotData<bool(QString, QString)>(65, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteRawMarkedImage'
        QtMocHelpers::SlotData<bool(QString)>(65, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteRawLowImage'
        QtMocHelpers::SlotData<bool(QString, QString)>(66, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteRawLowImage'
        QtMocHelpers::SlotData<bool(QString)>(66, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteRawHighImage'
        QtMocHelpers::SlotData<bool(QString, QString)>(67, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteRawHighImage'
        QtMocHelpers::SlotData<bool(QString)>(67, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'deleteAllRawMarkImage'
        QtMocHelpers::SlotData<bool(QString)>(68, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'deleteAllRawMarkImage'
        QtMocHelpers::SlotData<bool()>(68, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'updateRawImageInfo'
        QtMocHelpers::SlotData<bool(QString, QString, ImageInfo)>(69, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 56 }, { 0x80000000 | 57, 16 },
        }}),
        // Slot 'updateRawImageInfo'
        QtMocHelpers::SlotData<bool(QString, ImageInfo)>(69, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 56 }, { 0x80000000 | 57, 16 },
        }}),
        // Slot 'getRawImageInfo'
        QtMocHelpers::SlotData<bool(QString, QString, ImageInfo *) const>(70, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 56 }, { 0x80000000 | 59, 16 },
        }}),
        // Slot 'getRawImageInfo'
        QtMocHelpers::SlotData<bool(QString, ImageInfo *) const>(70, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 56 }, { 0x80000000 | 59, 16 },
        }}),
        // Slot 'uploadFinished'
        QtMocHelpers::SlotData<void(Artifact::ImageInfo)>(71, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 72, 73 },
        }}),
        // Slot 'upDataFinished'
        QtMocHelpers::SlotData<void(QString)>(74, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'waitEnd'
        QtMocHelpers::SlotData<void(QString, BaseInfo)>(75, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { 0x80000000 | 13, 14 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<VerifyThread, qt_meta_tag_ZN12VerifyThreadE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject VerifyThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12VerifyThreadE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12VerifyThreadE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12VerifyThreadE_t>.metaTypes,
    nullptr
} };

void VerifyThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<VerifyThread *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->verifyDataAdded((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->verifyDataUpdated((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->verifyDataDeleted((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->imageAdded((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->imageDeleted((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 5: _t->showVerifyResult((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->sigDeletedVerifyData((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->sigUpDataFinished((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->sigWaitEnd((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<BaseInfo>>(_a[2]))); break;
        case 9: { bool _r = _t->addNewVerifyData((*reinterpret_cast<std::add_pointer_t<BaseInfo>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<BatchInfo>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->startNewVerifyData(); break;
        case 11: { bool _r = _t->updateVerifyData((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<BaseInfo>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<BatchInfo>>(_a[3])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->updateVerifyData((*reinterpret_cast<std::add_pointer_t<BaseInfo>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<BatchInfo>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->updateVerifyData((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->updateVerifyData();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->updateVerifyResult((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 16: { BaseInfo _r = _t->getBaseInfo((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<BaseInfo*>(_a[0]) = std::move(_r); }  break;
        case 17: { BaseInfo _r = _t->getBaseInfo();
            if (_a[0]) *reinterpret_cast<BaseInfo*>(_a[0]) = std::move(_r); }  break;
        case 18: { BatchInfo _r = _t->getBatchInfo((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<BatchInfo*>(_a[0]) = std::move(_r); }  break;
        case 19: { BatchInfo _r = _t->getBatchInfo();
            if (_a[0]) *reinterpret_cast<BatchInfo*>(_a[0]) = std::move(_r); }  break;
        case 20: { bool _r = _t->loadRawImageFinished((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 21: { bool _r = _t->loadRawImageFinished();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 22: { bool _r = _t->verifyFinished((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 23: { bool _r = _t->verifyFinished();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 24: { bool _r = _t->setVerifyNo((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 25: { bool _r = _t->setVerifyNo((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 26: { int _r = _t->getVerifyNo((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<int*>(_a[0]) = std::move(_r); }  break;
        case 27: { int _r = _t->getVerifyNo();
            if (_a[0]) *reinterpret_cast<int*>(_a[0]) = std::move(_r); }  break;
        case 28: { QString _r = _t->getVerifyNumber();
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 29: { bool _r = _t->setVerifyNumber((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 30: { QStringList _r = _t->getVerifyDataList();
            if (_a[0]) *reinterpret_cast<QStringList*>(_a[0]) = std::move(_r); }  break;
        case 31: { const VerifyData* _r = _t->getVerifyData((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool*>>(_a[2])));
            if (_a[0]) *reinterpret_cast<const VerifyData**>(_a[0]) = std::move(_r); }  break;
        case 32: { const VerifyData* _r = _t->getVerifyData((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<const VerifyData**>(_a[0]) = std::move(_r); }  break;
        case 33: { const VerifyData* _r = _t->getVerifyData((*reinterpret_cast<std::add_pointer_t<bool*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<const VerifyData**>(_a[0]) = std::move(_r); }  break;
        case 34: { const VerifyData* _r = _t->getVerifyData();
            if (_a[0]) *reinterpret_cast<const VerifyData**>(_a[0]) = std::move(_r); }  break;
        case 35: { bool _r = _t->addMainImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 36: { bool _r = _t->addMainImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 37: { QImage _r = _t->getMainImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QImage*>(_a[0]) = std::move(_r); }  break;
        case 38: { QImage _r = _t->getMainImage();
            if (_a[0]) *reinterpret_cast<QImage*>(_a[0]) = std::move(_r); }  break;
        case 39: { QString _r = _t->globalImageName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 40: { QString _r = _t->globalImageName((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 41: { QString _r = _t->lowImageName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[3])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 42: { QString _r = _t->lowImageName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 43: { QString _r = _t->lowImageName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 44: { QString _r = _t->lowImageName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 45: { QString _r = _t->highImageName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[3])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 46: { QString _r = _t->highImageName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 47: { QString _r = _t->highImageName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 48: { QString _r = _t->highImageName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 49: { bool _r = _t->deleteVerifyData((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 50: { bool _r = _t->deleteVerifyData();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 51: { bool _r = _t->addGlobalImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[4])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 52: { bool _r = _t->addGlobalImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[3])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 53: { bool _r = _t->addLowImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[4])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 54: { bool _r = _t->addLowImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[3])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 55: { bool _r = _t->addHighImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[4])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 56: { bool _r = _t->addHighImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[3])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 57: { bool _r = _t->deleteGlobalImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 58: { bool _r = _t->deleteGlobalImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
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
        case 69: { bool _r = _t->addRawGlobalImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<ImageInfo>>(_a[4])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 70: { bool _r = _t->addRawGlobalImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<ImageInfo>>(_a[3])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 71: { bool _r = _t->addRawMarkedImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<ImageInfo>>(_a[4])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 72: { bool _r = _t->addRawMarkedImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<ImageInfo>>(_a[3])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 73: { bool _r = _t->addRawLowImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<ImageInfo>>(_a[4])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 74: { bool _r = _t->addRawLowImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<ImageInfo>>(_a[3])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 75: { bool _r = _t->addRawHighImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<ImageInfo>>(_a[4])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 76: { bool _r = _t->addRawHighImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QImage>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<ImageInfo>>(_a[3])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 77: { bool _r = _t->deleteRawGlobalImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 78: { bool _r = _t->deleteRawGlobalImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 79: { bool _r = _t->deleteRawMarkedImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 80: { bool _r = _t->deleteRawMarkedImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 81: { bool _r = _t->deleteRawLowImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 82: { bool _r = _t->deleteRawLowImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 83: { bool _r = _t->deleteRawHighImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 84: { bool _r = _t->deleteRawHighImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 85: { bool _r = _t->deleteAllRawMarkImage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 86: { bool _r = _t->deleteAllRawMarkImage();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 87: { bool _r = _t->updateRawImageInfo((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<ImageInfo>>(_a[3])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 88: { bool _r = _t->updateRawImageInfo((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<ImageInfo>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 89: { bool _r = _t->getRawImageInfo((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<ImageInfo*>>(_a[3])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 90: { bool _r = _t->getRawImageInfo((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<ImageInfo*>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 91: _t->uploadFinished((*reinterpret_cast<std::add_pointer_t<Artifact::ImageInfo>>(_a[1]))); break;
        case 92: _t->upDataFinished((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 93: _t->waitEnd((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<BaseInfo>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (VerifyThread::*)(QString )>(_a, &VerifyThread::verifyDataAdded, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (VerifyThread::*)(QString )>(_a, &VerifyThread::verifyDataUpdated, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (VerifyThread::*)(QString )>(_a, &VerifyThread::verifyDataDeleted, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (VerifyThread::*)(QString , QString )>(_a, &VerifyThread::imageAdded, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (VerifyThread::*)(QString , QString )>(_a, &VerifyThread::imageDeleted, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (VerifyThread::*)(QString )>(_a, &VerifyThread::showVerifyResult, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (VerifyThread::*)(QString )>(_a, &VerifyThread::sigDeletedVerifyData, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (VerifyThread::*)(QString )>(_a, &VerifyThread::sigUpDataFinished, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (VerifyThread::*)(QString , BaseInfo )>(_a, &VerifyThread::sigWaitEnd, 8))
            return;
    }
}

const QMetaObject *VerifyThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VerifyThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12VerifyThreadE_t>.strings))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int VerifyThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 94)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 94;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 94)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 94;
    }
    return _id;
}

// SIGNAL 0
void VerifyThread::verifyDataAdded(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void VerifyThread::verifyDataUpdated(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void VerifyThread::verifyDataDeleted(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void VerifyThread::imageAdded(QString _t1, QString _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}

// SIGNAL 4
void VerifyThread::imageDeleted(QString _t1, QString _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2);
}

// SIGNAL 5
void VerifyThread::showVerifyResult(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void VerifyThread::sigDeletedVerifyData(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void VerifyThread::sigUpDataFinished(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void VerifyThread::sigWaitEnd(QString _t1, BaseInfo _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1, _t2);
}
QT_WARNING_POP
