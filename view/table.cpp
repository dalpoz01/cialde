#include "table.h"



Table::Table(QWidget *parent) : QTableView(parent), mymodel(new TableModel()) {
    setModel(mymodel);
    //setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    verticalHeader()->setMaximumHeight(300);
    //setWordWrap(false);
    //horizontalHeader()->ResizeMode(QHeaderView::Stretch);
}

TableModel* Table::getMyModel() const{ return mymodel; }
