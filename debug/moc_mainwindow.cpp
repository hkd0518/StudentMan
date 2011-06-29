/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Jun 30 06:01:13 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      24,   11,   11,   11, 0x0a,
      32,   11,   11,   11, 0x0a,
      40,   11,   11,   11, 0x0a,
      65,   11,   11,   11, 0x0a,
      80,   11,   11,   11, 0x0a,
      92,   11,   11,   11, 0x0a,
     106,   11,   11,   11, 0x0a,
     119,   11,   11,   11, 0x0a,
     132,   11,   11,   11, 0x0a,
     143,   11,   11,   11, 0x0a,
     155,   11,   11,   11, 0x0a,
     189,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0getDBInfo()\0login()\0reset()\0"
    "loadCurriculumSchedule()\0loadElective()\0"
    "loadScore()\0loadProfile()\0loadRecord()\0"
    "loadStatic()\0loadPlan()\0changePwd()\0"
    "saveProfileChange(QStandardItem*)\0"
    "saveElectiveChange(QStandardItem*)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: getDBInfo(); break;
        case 1: login(); break;
        case 2: reset(); break;
        case 3: loadCurriculumSchedule(); break;
        case 4: loadElective(); break;
        case 5: loadScore(); break;
        case 6: loadProfile(); break;
        case 7: loadRecord(); break;
        case 8: loadStatic(); break;
        case 9: loadPlan(); break;
        case 10: changePwd(); break;
        case 11: saveProfileChange((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 12: saveElectiveChange((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
