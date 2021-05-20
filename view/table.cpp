#include "table.h"



Table::Table(QWidget *parent) : QTableView(parent), mymodel(new TableModel()), sf(new SortFilterProxyModel()) {

    sf->setSourceModel(mymodel);
    sf->setSortRole(Qt::UserRole);
    setModel(sf);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    //setWordWrap(false);
    //horizontalHeader()->ResizeMode(QHeaderView::Stretch);
}

TableModel* Table::getMyModel() const{ return mymodel; }

SortFilterProxyModel *Table::getSf() const{ return sf; }
