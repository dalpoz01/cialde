#include "table.h"

Table::Table(QWidget* parent) : QTableView(parent), header(new QHeaderView(Qt::Horizontal)){
    setHorizontalHeader(header);
}
