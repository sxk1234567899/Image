/****************************************************************************
** Meta object code from reading C++ file 'dbpage.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../sqlite/dbpage/dbpage.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dbpage.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13DbCountThreadE_t {};
} // unnamed namespace

template <> constexpr inline auto DbCountThread::qt_create_metaobjectdata<qt_meta_tag_ZN13DbCountThreadE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "DbCountThread",
        "receiveCount",
        "",
        "count",
        "msec",
        "setConnName",
        "connName",
        "setSql",
        "sql",
        "select"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'receiveCount'
        QtMocHelpers::SignalData<void(quint32, double)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 3 }, { QMetaType::Double, 4 },
        }}),
        // Slot 'setConnName'
        QtMocHelpers::SlotData<void(const QString &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 6 },
        }}),
        // Slot 'setSql'
        QtMocHelpers::SlotData<void(const QString &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 8 },
        }}),
        // Slot 'select'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<DbCountThread, qt_meta_tag_ZN13DbCountThreadE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject DbCountThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13DbCountThreadE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13DbCountThreadE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13DbCountThreadE_t>.metaTypes,
    nullptr
} };

void DbCountThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<DbCountThread *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->receiveCount((*reinterpret_cast<std::add_pointer_t<quint32>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[2]))); break;
        case 1: _t->setConnName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->setSql((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->select(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (DbCountThread::*)(quint32 , double )>(_a, &DbCountThread::receiveCount, 0))
            return;
    }
}

const QMetaObject *DbCountThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DbCountThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13DbCountThreadE_t>.strings))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int DbCountThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void DbCountThread::receiveCount(quint32 _t1, double _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}
namespace {
struct qt_meta_tag_ZN6DbPageE_t {};
} // unnamed namespace

template <> constexpr inline auto DbPage::qt_create_metaobjectdata<qt_meta_tag_ZN6DbPageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "DbPage",
        "receivePage",
        "",
        "pageCurrent",
        "pageTotal",
        "recordsTotal",
        "recordsPerpage",
        "receiveCount",
        "count",
        "msec",
        "bindData",
        "sql",
        "getPageSql",
        "slot_receiveCount",
        "setControl",
        "QTableView*",
        "tableView",
        "QLabel*",
        "labPageTotal",
        "labPageCurrent",
        "labRecordsTotal",
        "labRecordsPerpage",
        "labSelectTime",
        "labSelectInfo",
        "QAbstractButton*",
        "btnFirst",
        "btnPrevious",
        "btnNext",
        "btnLast",
        "countName",
        "connName",
        "setConnName",
        "setDbType",
        "DbType",
        "dbType",
        "setTableName",
        "tableName",
        "setSelectColumn",
        "selectColumn",
        "setOrderSql",
        "orderSql",
        "setWhereSql",
        "whereSql",
        "setRecordsPerpage",
        "setColumnNames",
        "columnNames",
        "setColumnWidths",
        "QList<int>",
        "columnWidths",
        "setAllCenter",
        "allCenter",
        "setAlignCenterColumn",
        "alignCenterColumn",
        "setAlignRightColumn",
        "alignRightColumn",
        "setInsertColumnIndex",
        "insertColumnIndex",
        "setInsertColumnName",
        "insertColumnName",
        "setInsertColumnWidth",
        "insertColumnWidth",
        "changeBtnEnable",
        "select",
        "selectPage",
        "page",
        "first",
        "previous",
        "next",
        "last"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'receivePage'
        QtMocHelpers::SignalData<void(quint32, quint32, quint32, quint32)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 3 }, { QMetaType::UInt, 4 }, { QMetaType::UInt, 5 }, { QMetaType::UInt, 6 },
        }}),
        // Signal 'receiveCount'
        QtMocHelpers::SignalData<void(quint32, double)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 8 }, { QMetaType::Double, 9 },
        }}),
        // Slot 'bindData'
        QtMocHelpers::SlotData<void(const QString &)>(10, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 11 },
        }}),
        // Slot 'getPageSql'
        QtMocHelpers::SlotData<QString()>(12, 2, QMC::AccessPrivate, QMetaType::QString),
        // Slot 'slot_receiveCount'
        QtMocHelpers::SlotData<void(quint32, double)>(13, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::UInt, 8 }, { QMetaType::Double, 9 },
        }}),
        // Slot 'setControl'
        QtMocHelpers::SlotData<void(QTableView *, QLabel *, QLabel *, QLabel *, QLabel *, QLabel *, QLabel *, QAbstractButton *, QAbstractButton *, QAbstractButton *, QAbstractButton *, const QString &, const QString &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 15, 16 }, { 0x80000000 | 17, 18 }, { 0x80000000 | 17, 19 }, { 0x80000000 | 17, 20 },
            { 0x80000000 | 17, 21 }, { 0x80000000 | 17, 22 }, { 0x80000000 | 17, 23 }, { 0x80000000 | 24, 25 },
            { 0x80000000 | 24, 26 }, { 0x80000000 | 24, 27 }, { 0x80000000 | 24, 28 }, { QMetaType::QString, 29 },
            { QMetaType::QString, 30 },
        }}),
        // Slot 'setControl'
        QtMocHelpers::SlotData<void(QTableView *, QLabel *, QLabel *, QLabel *, QLabel *, QLabel *, QLabel *, QAbstractButton *, QAbstractButton *, QAbstractButton *, QAbstractButton *, const QString &)>(14, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 15, 16 }, { 0x80000000 | 17, 18 }, { 0x80000000 | 17, 19 }, { 0x80000000 | 17, 20 },
            { 0x80000000 | 17, 21 }, { 0x80000000 | 17, 22 }, { 0x80000000 | 17, 23 }, { 0x80000000 | 24, 25 },
            { 0x80000000 | 24, 26 }, { 0x80000000 | 24, 27 }, { 0x80000000 | 24, 28 }, { QMetaType::QString, 29 },
        }}),
        // Slot 'setControl'
        QtMocHelpers::SlotData<void(QTableView *, QLabel *, QLabel *, QLabel *, QLabel *, QLabel *, QLabel *, const QString &, const QString &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 15, 16 }, { 0x80000000 | 17, 18 }, { 0x80000000 | 17, 19 }, { 0x80000000 | 17, 20 },
            { 0x80000000 | 17, 21 }, { 0x80000000 | 17, 22 }, { 0x80000000 | 17, 23 }, { QMetaType::QString, 29 },
            { QMetaType::QString, 30 },
        }}),
        // Slot 'setControl'
        QtMocHelpers::SlotData<void(QTableView *, QLabel *, QLabel *, QLabel *, QLabel *, QLabel *, QLabel *, const QString &)>(14, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 15, 16 }, { 0x80000000 | 17, 18 }, { 0x80000000 | 17, 19 }, { 0x80000000 | 17, 20 },
            { 0x80000000 | 17, 21 }, { 0x80000000 | 17, 22 }, { 0x80000000 | 17, 23 }, { QMetaType::QString, 29 },
        }}),
        // Slot 'setControl'
        QtMocHelpers::SlotData<void(QTableView *, QAbstractButton *, QAbstractButton *, QAbstractButton *, QAbstractButton *, const QString &, const QString &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 15, 16 }, { 0x80000000 | 24, 25 }, { 0x80000000 | 24, 26 }, { 0x80000000 | 24, 27 },
            { 0x80000000 | 24, 28 }, { QMetaType::QString, 29 }, { QMetaType::QString, 30 },
        }}),
        // Slot 'setControl'
        QtMocHelpers::SlotData<void(QTableView *, QAbstractButton *, QAbstractButton *, QAbstractButton *, QAbstractButton *, const QString &)>(14, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 15, 16 }, { 0x80000000 | 24, 25 }, { 0x80000000 | 24, 26 }, { 0x80000000 | 24, 27 },
            { 0x80000000 | 24, 28 }, { QMetaType::QString, 29 },
        }}),
        // Slot 'setControl'
        QtMocHelpers::SlotData<void(QTableView *, const QString &, const QString &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 15, 16 }, { QMetaType::QString, 29 }, { QMetaType::QString, 30 },
        }}),
        // Slot 'setControl'
        QtMocHelpers::SlotData<void(QTableView *, const QString &)>(14, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 15, 16 }, { QMetaType::QString, 29 },
        }}),
        // Slot 'setConnName'
        QtMocHelpers::SlotData<void(const QString &)>(31, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 },
        }}),
        // Slot 'setDbType'
        QtMocHelpers::SlotData<void(const DbType &)>(32, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 33, 34 },
        }}),
        // Slot 'setTableName'
        QtMocHelpers::SlotData<void(const QString &)>(35, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 36 },
        }}),
        // Slot 'setSelectColumn'
        QtMocHelpers::SlotData<void(const QString &)>(37, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 38 },
        }}),
        // Slot 'setOrderSql'
        QtMocHelpers::SlotData<void(const QString &)>(39, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 40 },
        }}),
        // Slot 'setWhereSql'
        QtMocHelpers::SlotData<void(const QString &)>(41, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 42 },
        }}),
        // Slot 'setRecordsPerpage'
        QtMocHelpers::SlotData<void(int)>(43, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
        // Slot 'setColumnNames'
        QtMocHelpers::SlotData<void(const QList<QString> &)>(44, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 45 },
        }}),
        // Slot 'setColumnWidths'
        QtMocHelpers::SlotData<void(const QList<int> &)>(46, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 47, 48 },
        }}),
        // Slot 'setAllCenter'
        QtMocHelpers::SlotData<void(bool)>(49, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 50 },
        }}),
        // Slot 'setAlignCenterColumn'
        QtMocHelpers::SlotData<void(const QList<int> &)>(51, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 47, 52 },
        }}),
        // Slot 'setAlignRightColumn'
        QtMocHelpers::SlotData<void(const QList<int> &)>(53, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 47, 54 },
        }}),
        // Slot 'setInsertColumnIndex'
        QtMocHelpers::SlotData<void(int)>(55, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 56 },
        }}),
        // Slot 'setInsertColumnName'
        QtMocHelpers::SlotData<void(const QString &)>(57, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 58 },
        }}),
        // Slot 'setInsertColumnWidth'
        QtMocHelpers::SlotData<void(int)>(59, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 60 },
        }}),
        // Slot 'changeBtnEnable'
        QtMocHelpers::SlotData<void()>(61, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'select'
        QtMocHelpers::SlotData<void()>(62, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'selectPage'
        QtMocHelpers::SlotData<void(quint32)>(63, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 64 },
        }}),
        // Slot 'first'
        QtMocHelpers::SlotData<void()>(65, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'previous'
        QtMocHelpers::SlotData<void()>(66, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'next'
        QtMocHelpers::SlotData<void()>(67, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'last'
        QtMocHelpers::SlotData<void()>(68, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<DbPage, qt_meta_tag_ZN6DbPageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject DbPage::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6DbPageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6DbPageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN6DbPageE_t>.metaTypes,
    nullptr
} };

void DbPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<DbPage *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->receivePage((*reinterpret_cast<std::add_pointer_t<quint32>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<quint32>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<quint32>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<quint32>>(_a[4]))); break;
        case 1: _t->receiveCount((*reinterpret_cast<std::add_pointer_t<quint32>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[2]))); break;
        case 2: _t->bindData((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: { QString _r = _t->getPageSql();
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->slot_receiveCount((*reinterpret_cast<std::add_pointer_t<quint32>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[2]))); break;
        case 5: _t->setControl((*reinterpret_cast<std::add_pointer_t<QTableView*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[7])),(*reinterpret_cast<std::add_pointer_t<QAbstractButton*>>(_a[8])),(*reinterpret_cast<std::add_pointer_t<QAbstractButton*>>(_a[9])),(*reinterpret_cast<std::add_pointer_t<QAbstractButton*>>(_a[10])),(*reinterpret_cast<std::add_pointer_t<QAbstractButton*>>(_a[11])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[12])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[13]))); break;
        case 6: _t->setControl((*reinterpret_cast<std::add_pointer_t<QTableView*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[7])),(*reinterpret_cast<std::add_pointer_t<QAbstractButton*>>(_a[8])),(*reinterpret_cast<std::add_pointer_t<QAbstractButton*>>(_a[9])),(*reinterpret_cast<std::add_pointer_t<QAbstractButton*>>(_a[10])),(*reinterpret_cast<std::add_pointer_t<QAbstractButton*>>(_a[11])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[12]))); break;
        case 7: _t->setControl((*reinterpret_cast<std::add_pointer_t<QTableView*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[7])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[9]))); break;
        case 8: _t->setControl((*reinterpret_cast<std::add_pointer_t<QTableView*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<QLabel*>>(_a[7])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[8]))); break;
        case 9: _t->setControl((*reinterpret_cast<std::add_pointer_t<QTableView*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QAbstractButton*>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QAbstractButton*>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QAbstractButton*>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<QAbstractButton*>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[7]))); break;
        case 10: _t->setControl((*reinterpret_cast<std::add_pointer_t<QTableView*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QAbstractButton*>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QAbstractButton*>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QAbstractButton*>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<QAbstractButton*>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[6]))); break;
        case 11: _t->setControl((*reinterpret_cast<std::add_pointer_t<QTableView*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3]))); break;
        case 12: _t->setControl((*reinterpret_cast<std::add_pointer_t<QTableView*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 13: _t->setConnName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->setDbType((*reinterpret_cast<std::add_pointer_t<enum DbType>>(_a[1]))); break;
        case 15: _t->setTableName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->setSelectColumn((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->setOrderSql((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 18: _t->setWhereSql((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 19: _t->setRecordsPerpage((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->setColumnNames((*reinterpret_cast<std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 21: _t->setColumnWidths((*reinterpret_cast<std::add_pointer_t<QList<int>>>(_a[1]))); break;
        case 22: _t->setAllCenter((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 23: _t->setAlignCenterColumn((*reinterpret_cast<std::add_pointer_t<QList<int>>>(_a[1]))); break;
        case 24: _t->setAlignRightColumn((*reinterpret_cast<std::add_pointer_t<QList<int>>>(_a[1]))); break;
        case 25: _t->setInsertColumnIndex((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 26: _t->setInsertColumnName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 27: _t->setInsertColumnWidth((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->changeBtnEnable(); break;
        case 29: _t->select(); break;
        case 30: _t->selectPage((*reinterpret_cast<std::add_pointer_t<quint32>>(_a[1]))); break;
        case 31: _t->first(); break;
        case 32: _t->previous(); break;
        case 33: _t->next(); break;
        case 34: _t->last(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 10:
            case 9:
            case 8:
            case 7:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractButton* >(); break;
            case 6:
            case 5:
            case 4:
            case 3:
            case 2:
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLabel* >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTableView* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 10:
            case 9:
            case 8:
            case 7:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractButton* >(); break;
            case 6:
            case 5:
            case 4:
            case 3:
            case 2:
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLabel* >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTableView* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 6:
            case 5:
            case 4:
            case 3:
            case 2:
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLabel* >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTableView* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 6:
            case 5:
            case 4:
            case 3:
            case 2:
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLabel* >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTableView* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 4:
            case 3:
            case 2:
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractButton* >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTableView* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 4:
            case 3:
            case 2:
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractButton* >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTableView* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTableView* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTableView* >(); break;
            }
            break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 23:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 24:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (DbPage::*)(quint32 , quint32 , quint32 , quint32 )>(_a, &DbPage::receivePage, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (DbPage::*)(quint32 , double )>(_a, &DbPage::receiveCount, 1))
            return;
    }
}

const QMetaObject *DbPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DbPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6DbPageE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DbPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    return _id;
}

// SIGNAL 0
void DbPage::receivePage(quint32 _t1, quint32 _t2, quint32 _t3, quint32 _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 1
void DbPage::receiveCount(quint32 _t1, double _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}
QT_WARNING_POP
