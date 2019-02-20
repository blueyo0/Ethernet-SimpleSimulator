/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CellWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      28,   11,   11,   11, 0x08,
      46,   11,   11,   11, 0x08,
      62,   11,   11,   11, 0x08,
      72,   11,   11,   11, 0x08,
      84,   11,   11,   11, 0x08,
      94,   11,   11,   11, 0x08,
     106,   11,   11,   11, 0x08,
     116,   11,   11,   11, 0x08,
     128,   11,   11,   11, 0x08,
     138,   11,   11,   11, 0x08,
     150,   11,   11,   11, 0x08,
     160,   11,   11,   11, 0x08,
     172,   11,   11,   11, 0x08,
     182,   11,   11,   11, 0x08,
     194,   11,   11,   11, 0x08,
     206,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CellWidget[] = {
    "CellWidget\0\0start_clicked()\0"
    "confirm_clicked()\0pause_clicked()\0"
    "PC1_add()\0PC1_minus()\0PC2_add()\0"
    "PC2_minus()\0PC3_add()\0PC3_minus()\0"
    "PC4_add()\0PC4_minus()\0PC5_add()\0"
    "PC5_minus()\0PC6_add()\0PC6_minus()\0"
    "onTimeout()\0onSendTimeout()\0"
};

void CellWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CellWidget *_t = static_cast<CellWidget *>(_o);
        switch (_id) {
        case 0: _t->start_clicked(); break;
        case 1: _t->confirm_clicked(); break;
        case 2: _t->pause_clicked(); break;
        case 3: _t->PC1_add(); break;
        case 4: _t->PC1_minus(); break;
        case 5: _t->PC2_add(); break;
        case 6: _t->PC2_minus(); break;
        case 7: _t->PC3_add(); break;
        case 8: _t->PC3_minus(); break;
        case 9: _t->PC4_add(); break;
        case 10: _t->PC4_minus(); break;
        case 11: _t->PC5_add(); break;
        case 12: _t->PC5_minus(); break;
        case 13: _t->PC6_add(); break;
        case 14: _t->PC6_minus(); break;
        case 15: _t->onTimeout(); break;
        case 16: _t->onSendTimeout(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CellWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CellWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CellWidget,
      qt_meta_data_CellWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CellWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CellWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CellWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CellWidget))
        return static_cast<void*>(const_cast< CellWidget*>(this));
    if (!strcmp(_clname, "Ui::Widget"))
        return static_cast< Ui::Widget*>(const_cast< CellWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CellWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
