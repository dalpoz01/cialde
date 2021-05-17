#include "table.h"

Table::Table(QWidget *parent) : QTableView(parent), mymodel(new TableModel()) {
    setModel(mymodel);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //horizontalHeader()->setResizeMode(QHeaderView::Stretch);
}

TableModel* Table::getMyModel() const{ return mymodel; }
