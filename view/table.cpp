#include "table.h"

Table::Table(QWidget* parent) : QTableView(parent), header(new QHeaderView(Qt::Horizontal)){

    setSelectionBehavior(QAbstractItemView::SelectRows);
    header->setSectionResizeMode(QHeaderView::Stretch);
    setHorizontalHeader(header);
}
