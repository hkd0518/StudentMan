/****************************************************************************
** Meta object code from reading C++ file 'infowidget.h'
**
** Created: Mon Jun 27 22:02:18 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../infowidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'infowidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_InfoWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      37,   11,   11,   11, 0x05,
      52,   11,   11,   11, 0x05,
      64,   11,   11,   11, 0x05,
      78,   11,   11,   11, 0x05,
      91,   11,   11,   11, 0x05,
     104,   11,   11,   11, 0x05,
     115,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     126,  124,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_InfoWidget[] = {
    "InfoWidget\0\0loadCurriculumSchedule()\0"
    "loadElective()\0loadScore()\0loadProfile()\0"
    "loadRecord()\0loadStatic()\0loadPlan()\0"
    "chgPwd()\0,\0dispatchView(QTreeWidgetItem*,int)\0"
};

const QMetaObject InfoWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_InfoWidget,
      qt_meta_data_InfoWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &InfoWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *InfoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *InfoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InfoWidget))
        return static_cast<void*>(const_cast< InfoWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int InfoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: loadCurriculumSchedule(); break;
        case 1: loadElective(); break;
        case 2: loadScore(); break;
        case 3: loadProfile(); break;
        case 4: loadRecord(); break;
        case 5: loadStatic(); break;
        case 6: loadPlan(); break;
        case 7: chgPwd(); break;
        case 8: dispatchView((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void InfoWidget::loadCurriculumSchedule()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void InfoWidget::loadElective()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void InfoWidget::loadScore()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void InfoWidget::loadProfile()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void InfoWidget::loadRecord()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void InfoWidget::loadStatic()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void InfoWidget::loadPlan()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void InfoWidget::chgPwd()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}
QT_END_MOC_NAMESPACE
