#include "table.h"

Table::Table(QWidget *parent) : QTableView(parent)
{
    setSelectionBehavior(QAbstractItemView::SelectRows);
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    horizontalHeader()->setSectionsClickable(true);
    horizontalHeader()->setToolTip(tr("Clicca per ordinare"));
    setSortingEnabled(true);
    horizontalHeader()->sortIndicatorOrder();
}

QHeaderView *Table::getHeader() const{ return horizontalHeader(); }
