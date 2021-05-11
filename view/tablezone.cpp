#include "tablezone.h"

TableZone::TableZone(QWidget *parent, TableModel* tbm) :
    QWidget(parent),
    table(new Table(this)),
    absModel(tbm)
{
    table->setModel(absModel);
}
