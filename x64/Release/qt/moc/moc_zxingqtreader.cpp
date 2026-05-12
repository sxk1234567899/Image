/****************************************************************************
** Meta object code from reading C++ file 'zxingqtreader.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../zxing/zxingqtreader.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zxingqtreader.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN7ZXingQt8PositionE_t {};
} // unnamed namespace

template <> constexpr inline auto ZXingQt::Position::qt_create_metaobjectdata<qt_meta_tag_ZN7ZXingQt8PositionE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ZXingQt::Position",
        "topLeft",
        "QPoint",
        "topRight",
        "bottomRight",
        "bottomLeft"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'topLeft'
        QtMocHelpers::PropertyData<QPoint>(1, 0x80000000 | 2, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'topRight'
        QtMocHelpers::PropertyData<QPoint>(3, 0x80000000 | 2, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'bottomRight'
        QtMocHelpers::PropertyData<QPoint>(4, 0x80000000 | 2, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'bottomLeft'
        QtMocHelpers::PropertyData<QPoint>(5, 0x80000000 | 2, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Position, qt_meta_tag_ZN7ZXingQt8PositionE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ZXingQt::Position::staticMetaObject = { {
    QtPrivate::MetaObjectForType<ZXing::Quadrilateral<QPoint>>::value,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7ZXingQt8PositionE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7ZXingQt8PositionE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7ZXingQt8PositionE_t>.metaTypes,
    nullptr
} };

void ZXingQt::Position::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<Position *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QPoint*>(_v) = _t->topLeft(); break;
        case 1: *reinterpret_cast<QPoint*>(_v) = _t->topRight(); break;
        case 2: *reinterpret_cast<QPoint*>(_v) = _t->bottomRight(); break;
        case 3: *reinterpret_cast<QPoint*>(_v) = _t->bottomLeft(); break;
        default: break;
        }
    }
}
namespace {
struct qt_meta_tag_ZN7ZXingQt7BarcodeE_t {};
} // unnamed namespace

template <> constexpr inline auto ZXingQt::Barcode::qt_create_metaobjectdata<qt_meta_tag_ZN7ZXingQt7BarcodeE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ZXingQt::Barcode",
        "format",
        "BarcodeFormat",
        "formatName",
        "text",
        "bytes",
        "isValid",
        "contentType",
        "ContentType",
        "contentTypeName",
        "position",
        "Position"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'format'
        QtMocHelpers::PropertyData<BarcodeFormat>(1, 0x80000000 | 2, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'formatName'
        QtMocHelpers::PropertyData<QString>(3, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'text'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'bytes'
        QtMocHelpers::PropertyData<QByteArray>(5, QMetaType::QByteArray, QMC::DefaultPropertyFlags),
        // property 'isValid'
        QtMocHelpers::PropertyData<bool>(6, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'contentType'
        QtMocHelpers::PropertyData<ContentType>(7, 0x80000000 | 8, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'contentTypeName'
        QtMocHelpers::PropertyData<QString>(9, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'position'
        QtMocHelpers::PropertyData<Position>(10, 0x80000000 | 11, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Barcode, qt_meta_tag_ZN7ZXingQt7BarcodeE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ZXingQt::Barcode::staticMetaObject = { {
    QtPrivate::MetaObjectForType<ZXing::Barcode>::value,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7ZXingQt7BarcodeE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7ZXingQt7BarcodeE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7ZXingQt7BarcodeE_t>.metaTypes,
    nullptr
} };

void ZXingQt::Barcode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<Barcode *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<BarcodeFormat*>(_v) = _t->format(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->formatName(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->text(); break;
        case 3: *reinterpret_cast<QByteArray*>(_v) = _t->bytes(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->isValid(); break;
        case 5: *reinterpret_cast<ContentType*>(_v) = _t->contentType(); break;
        case 6: *reinterpret_cast<QString*>(_v) = _t->contentTypeName(); break;
        case 7: *reinterpret_cast<Position*>(_v) = _t->position(); break;
        default: break;
        }
    }
}
namespace {
struct qt_meta_tag_ZN7ZXingQt13BarcodeReaderE_t {};
} // unnamed namespace

template <> constexpr inline auto ZXingQt::BarcodeReader::qt_create_metaobjectdata<qt_meta_tag_ZN7ZXingQt13BarcodeReaderE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ZXingQt::BarcodeReader",
        "formatsChanged",
        "",
        "textModeChanged",
        "tryRotateChanged",
        "tryHarderChanged",
        "tryInvertChanged",
        "tryDownscaleChanged",
        "isPureChanged",
        "failedRead",
        "foundBarcode",
        "ZXingQt::Barcode",
        "barcode",
        "setFormats",
        "newVal",
        "setTextMode",
        "TextMode",
        "setTryRotate",
        "setTryHarder",
        "setTryInvert",
        "setTryDownscale",
        "setIsPure",
        "process",
        "QVideoFrame",
        "image",
        "formats",
        "textMode",
        "tryRotate",
        "tryHarder",
        "tryInvert",
        "tryDownscale",
        "isPure",
        "runTime",
        "videoSink",
        "QVideoSink*"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'formatsChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'textModeChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'tryRotateChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'tryHarderChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'tryInvertChanged'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'tryDownscaleChanged'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isPureChanged'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'failedRead'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'foundBarcode'
        QtMocHelpers::SignalData<void(ZXingQt::Barcode)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 11, 12 },
        }}),
        // Slot 'setFormats'
        QtMocHelpers::SlotData<void(int)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Slot 'setTextMode'
        QtMocHelpers::SlotData<void(TextMode)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 16, 14 },
        }}),
        // Slot 'setTryRotate'
        QtMocHelpers::SlotData<void(const bool &)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 14 },
        }}),
        // Slot 'setTryHarder'
        QtMocHelpers::SlotData<void(const bool &)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 14 },
        }}),
        // Slot 'setTryInvert'
        QtMocHelpers::SlotData<void(const bool &)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 14 },
        }}),
        // Slot 'setTryDownscale'
        QtMocHelpers::SlotData<void(const bool &)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 14 },
        }}),
        // Slot 'setIsPure'
        QtMocHelpers::SlotData<void(const bool &)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 14 },
        }}),
        // Slot 'process'
        QtMocHelpers::SlotData<ZXingQt::Barcode(const QVideoFrame &)>(22, 2, QMC::AccessPublic, 0x80000000 | 11, {{
            { 0x80000000 | 23, 24 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'formats'
        QtMocHelpers::PropertyData<int>(25, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'textMode'
        QtMocHelpers::PropertyData<TextMode>(26, 0x80000000 | 16, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 1),
        // property 'tryRotate'
        QtMocHelpers::PropertyData<bool>(27, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'tryHarder'
        QtMocHelpers::PropertyData<bool>(28, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'tryInvert'
        QtMocHelpers::PropertyData<bool>(29, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'tryDownscale'
        QtMocHelpers::PropertyData<bool>(30, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
        // property 'isPure'
        QtMocHelpers::PropertyData<bool>(31, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 6),
        // property 'runTime'
        QtMocHelpers::PropertyData<int>(32, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'videoSink'
        QtMocHelpers::PropertyData<QVideoSink*>(33, 0x80000000 | 34, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<BarcodeReader, qt_meta_tag_ZN7ZXingQt13BarcodeReaderE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ZXingQt::BarcodeReader::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7ZXingQt13BarcodeReaderE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7ZXingQt13BarcodeReaderE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7ZXingQt13BarcodeReaderE_t>.metaTypes,
    nullptr
} };

void ZXingQt::BarcodeReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<BarcodeReader *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->formatsChanged(); break;
        case 1: _t->textModeChanged(); break;
        case 2: _t->tryRotateChanged(); break;
        case 3: _t->tryHarderChanged(); break;
        case 4: _t->tryInvertChanged(); break;
        case 5: _t->tryDownscaleChanged(); break;
        case 6: _t->isPureChanged(); break;
        case 7: _t->failedRead(); break;
        case 8: _t->foundBarcode((*reinterpret_cast<std::add_pointer_t<ZXingQt::Barcode>>(_a[1]))); break;
        case 9: _t->setFormats((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->setTextMode((*reinterpret_cast<std::add_pointer_t<TextMode>>(_a[1]))); break;
        case 11: _t->setTryRotate((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->setTryHarder((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 13: _t->setTryInvert((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 14: _t->setTryDownscale((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 15: _t->setIsPure((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 16: { ZXingQt::Barcode _r = _t->process((*reinterpret_cast<std::add_pointer_t<QVideoFrame>>(_a[1])));
            if (_a[0]) *reinterpret_cast<ZXingQt::Barcode*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ZXingQt::Barcode >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QVideoFrame >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (BarcodeReader::*)()>(_a, &BarcodeReader::formatsChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (BarcodeReader::*)()>(_a, &BarcodeReader::textModeChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (BarcodeReader::*)()>(_a, &BarcodeReader::tryRotateChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (BarcodeReader::*)()>(_a, &BarcodeReader::tryHarderChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (BarcodeReader::*)()>(_a, &BarcodeReader::tryInvertChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (BarcodeReader::*)()>(_a, &BarcodeReader::tryDownscaleChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (BarcodeReader::*)()>(_a, &BarcodeReader::isPureChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (BarcodeReader::*)()>(_a, &BarcodeReader::failedRead, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (BarcodeReader::*)(ZXingQt::Barcode )>(_a, &BarcodeReader::foundBarcode, 8))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVideoSink* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->formats(); break;
        case 1: *reinterpret_cast<TextMode*>(_v) = _t->textMode(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->tryRotate(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->tryHarder(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->tryInvert(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->tryDownscale(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->isPure(); break;
        case 7: *reinterpret_cast<int*>(_v) = _t->runTime; break;
        case 8: *reinterpret_cast<QVideoSink**>(_v) = _t->_sink; break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFormats(*reinterpret_cast<int*>(_v)); break;
        case 1: _t->setTextMode(*reinterpret_cast<TextMode*>(_v)); break;
        case 2: _t->setTryRotate(*reinterpret_cast<bool*>(_v)); break;
        case 3: _t->setTryHarder(*reinterpret_cast<bool*>(_v)); break;
        case 4: _t->setTryInvert(*reinterpret_cast<bool*>(_v)); break;
        case 5: _t->setTryDownscale(*reinterpret_cast<bool*>(_v)); break;
        case 6: _t->setIsPure(*reinterpret_cast<bool*>(_v)); break;
        case 7: QtMocHelpers::setProperty(_t->runTime, *reinterpret_cast<int*>(_v)); break;
        case 8: _t->setVideoSink(*reinterpret_cast<QVideoSink**>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *ZXingQt::BarcodeReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZXingQt::BarcodeReader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7ZXingQt13BarcodeReaderE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ZXingQt::BarcodeReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ZXingQt::BarcodeReader::formatsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ZXingQt::BarcodeReader::textModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ZXingQt::BarcodeReader::tryRotateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ZXingQt::BarcodeReader::tryHarderChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ZXingQt::BarcodeReader::tryInvertChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ZXingQt::BarcodeReader::tryDownscaleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ZXingQt::BarcodeReader::isPureChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void ZXingQt::BarcodeReader::failedRead()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void ZXingQt::BarcodeReader::foundBarcode(ZXingQt::Barcode _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN7ZXingQtE_t {};
} // unnamed namespace

template <> constexpr inline auto ZXingQt::qt_create_metaobjectdata<qt_meta_tag_ZN7ZXingQtE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ZXingQt"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN7ZXingQtE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}

static constexpr auto qt_staticMetaObjectContent_ZN7ZXingQtE =
    ZXingQt::qt_create_metaobjectdata<qt_meta_tag_ZN7ZXingQtE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN7ZXingQtE =
    qt_staticMetaObjectContent_ZN7ZXingQtE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN7ZXingQtE =
    qt_staticMetaObjectContent_ZN7ZXingQtE.relocatingData;

Q_CONSTINIT const QMetaObject ZXingQt::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN7ZXingQtE.stringdata,
    qt_staticMetaObjectStaticContent_ZN7ZXingQtE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN7ZXingQtE.metaTypes,
    nullptr
} };

QT_WARNING_POP
