#include "table.h"
#include <iostream>
using namespace std;

Table::Table(QWidget *parent) : QTableView(parent)/*, ord(false)*/
{
    setSelectionBehavior(QAbstractItemView::SelectRows);
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    horizontalHeader()->setSectionsClickable(true);
    horizontalHeader()->setToolTip(tr("Clicca per ordinare"));
    setSortingEnabled(true);
    horizontalHeader()->sortIndicatorOrder();
    //horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    verticalHeader()->setMaximumHeight(300);
}

//TableModel* Table::getMyModel() const{ return mymodel; }

QHeaderView *Table::getHeader() const{ return horizontalHeader(); }

/*bool Table::getOrd() const{ return ord; }

void Table::setOrd(bool b){ ord=b; }*/

void Table::orderTable(int n){
    sortByColumn(n);
}
