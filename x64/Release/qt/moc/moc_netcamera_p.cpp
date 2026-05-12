/****************************************************************************
** Meta object code from reading C++ file 'netcamera_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../camera/netcamera_p.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'netcamera_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN16NetCameraPrivateE_t {};
} // unnamed namespace

template <> constexpr inline auto NetCameraPrivate::qt_create_metaobjectdata<qt_meta_tag_ZN16NetCameraPrivateE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "NetCameraPrivate",
        "initCamera",
        "",
        "NetCameraConf",
        "conf",
        "open",
        "close",
        "getRequest",
        "QJsonObject",
        "requestJson",
        "setRequest",
        "videoFrameData",
        "QVideoFrame",
        "videoFrame",
        "zoomIn",
        "zoomOut",
        "zoom",
        "focusOnce",
        "manualFocusMode",
        "isMode",
        "manualFocusAdd",
        "manualFocusSub",
        "manualFocusSet",
        "focus",
        "setFlipLR",
        "setFlipUD",
        "mInitCamera",
        "mOpen",
        "mClose",
        "mGetRequest",
        "mSetRequest",
        "mGetVideoFrameData",
        "mQuit"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'initCamera'
        QtMocHelpers::SignalData<bool(NetCameraConf)>(1, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'open'
        QtMocHelpers::SignalData<bool()>(5, 2, QMC::AccessPublic, QMetaType::Bool),
        // Signal 'close'
        QtMocHelpers::SignalData<bool()>(6, 2, QMC::AccessPublic, QMetaType::Bool),
        // Signal 'getRequest'
        QtMocHelpers::SignalData<QJsonObject(const QJsonObject &)>(7, 2, QMC::AccessPublic, 0x80000000 | 8, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Signal 'setRequest'
        QtMocHelpers::SignalData<bool(const QJsonObject &)>(10, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Signal 'videoFrameData'
        QtMocHelpers::SignalData<void(QVideoFrame)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 12, 13 },
        }}),
        // Slot 'zoomIn'
        QtMocHelpers::SlotData<bool()>(14, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'zoomOut'
        QtMocHelpers::SlotData<bool()>(15, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'zoom'
        QtMocHelpers::SlotData<bool(int)>(16, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 16 },
        }}),
        // Slot 'focusOnce'
        QtMocHelpers::SlotData<bool()>(17, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'manualFocusMode'
        QtMocHelpers::SlotData<bool(bool)>(18, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Bool, 19 },
        }}),
        // Slot 'manualFocusAdd'
        QtMocHelpers::SlotData<bool()>(20, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'manualFocusSub'
        QtMocHelpers::SlotData<bool()>(21, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'manualFocusSet'
        QtMocHelpers::SlotData<bool(int)>(22, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 23 },
        }}),
        // Slot 'setFlipLR'
        QtMocHelpers::SlotData<bool()>(24, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'setFlipUD'
        QtMocHelpers::SlotData<bool()>(25, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'mInitCamera'
        QtMocHelpers::SlotData<bool(NetCameraConf)>(26, 2, QMC::AccessPrivate, QMetaType::Bool, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'mOpen'
        QtMocHelpers::SlotData<bool()>(27, 2, QMC::AccessPrivate, QMetaType::Bool),
        // Slot 'mClose'
        QtMocHelpers::SlotData<bool()>(28, 2, QMC::AccessPrivate, QMetaType::Bool),
        // Slot 'mGetRequest'
        QtMocHelpers::SlotData<QJsonObject(const QJsonObject &)>(29, 2, QMC::AccessPrivate, 0x80000000 | 8, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Slot 'mSetRequest'
        QtMocHelpers::SlotData<bool(const QJsonObject &)>(30, 2, QMC::AccessPrivate, QMetaType::Bool, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Slot 'mGetVideoFrameData'
        QtMocHelpers::SlotData<void()>(31, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'mQuit'
        QtMocHelpers::SlotData<void()>(32, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<NetCameraPrivate, qt_meta_tag_ZN16NetCameraPrivateE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject NetCameraPrivate::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16NetCameraPrivateE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16NetCameraPrivateE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16NetCameraPrivateE_t>.metaTypes,
    nullptr
} };

void NetCameraPrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<NetCameraPrivate *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { bool _r = _t->initCamera((*reinterpret_cast<std::add_pointer_t<NetCameraConf>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->open();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->close();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { QJsonObject _r = _t->getRequest((*reinterpret_cast<std::add_pointer_t<QJsonObject>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QJsonObject*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->setRequest((*reinterpret_cast<std::add_pointer_t<QJsonObject>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->videoFrameData((*reinterpret_cast<std::add_pointer_t<QVideoFrame>>(_a[1]))); break;
        case 6: { bool _r = _t->zoomIn();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->zoomOut();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->zoom((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->focusOnce();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->manualFocusMode((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->manualFocusAdd();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->manualFocusSub();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->manualFocusSet((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->setFlipLR();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->setFlipUD();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->mInitCamera((*reinterpret_cast<std::add_pointer_t<NetCameraConf>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 17: { bool _r = _t->mOpen();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 18: { bool _r = _t->mClose();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 19: { QJsonObject _r = _t->mGetRequest((*reinterpret_cast<std::add_pointer_t<QJsonObject>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QJsonObject*>(_a[0]) = std::move(_r); }  break;
        case 20: { bool _r = _t->mSetRequest((*reinterpret_cast<std::add_pointer_t<QJsonObject>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 21: _t->mGetVideoFrameData(); break;
        case 22: _t->mQuit(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QVideoFrame >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<bool (NetCameraPrivate::*)(NetCameraConf )>(_a, &NetCameraPrivate::initCamera, 0))
            return;
        if (QtMocHelpers::indexOfMethod<bool (NetCameraPrivate::*)()>(_a, &NetCameraPrivate::open, 1))
            return;
        if (QtMocHelpers::indexOfMethod<bool (NetCameraPrivate::*)()>(_a, &NetCameraPrivate::close, 2))
            return;
        if (QtMocHelpers::indexOfMethod<QJsonObject (NetCameraPrivate::*)(const QJsonObject & )>(_a, &NetCameraPrivate::getRequest, 3))
            return;
        if (QtMocHelpers::indexOfMethod<bool (NetCameraPrivate::*)(const QJsonObject & )>(_a, &NetCameraPrivate::setRequest, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (NetCameraPrivate::*)(QVideoFrame )>(_a, &NetCameraPrivate::videoFrameData, 5))
            return;
    }
}

const QMetaObject *NetCameraPrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetCameraPrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16NetCameraPrivateE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NetCameraPrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
bool NetCameraPrivate::initCamera(NetCameraConf _t1)
{
    bool _t0{};
    QMetaObject::activate<bool>(this, &staticMetaObject, 0, std::addressof(_t0), _t1);
    return _t0;
}

// SIGNAL 1
bool NetCameraPrivate::open()
{
    bool _t0{};
    QMetaObject::activate<bool>(this, &staticMetaObject, 1, std::addressof(_t0));
    return _t0;
}

// SIGNAL 2
bool NetCameraPrivate::close()
{
    bool _t0{};
    QMetaObject::activate<bool>(this, &staticMetaObject, 2, std::addressof(_t0));
    return _t0;
}

// SIGNAL 3
QJsonObject NetCameraPrivate::getRequest(const QJsonObject & _t1)
{
    QJsonObject _t0{};
    QMetaObject::activate<QJsonObject>(this, &staticMetaObject, 3, std::addressof(_t0), _t1);
    return _t0;
}

// SIGNAL 4
bool NetCameraPrivate::setRequest(const QJsonObject & _t1)
{
    bool _t0{};
    QMetaObject::activate<bool>(this, &staticMetaObject, 4, std::addressof(_t0), _t1);
    return _t0;
}

// SIGNAL 5
void NetCameraPrivate::videoFrameData(QVideoFrame _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}
QT_WARNING_POP
