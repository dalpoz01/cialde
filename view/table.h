#ifndef TABLE_H
#define TABLE_H
#include <QWidget>
#include <QHeaderView>
#include <QTableView>
#include <QBoxLayout>

#include "model/tablemodel.h"
#include "model/sortfilterproxymodel.h"

class Table : public QTableView {
    Q_OBJECT
private:
    TableModel* mymodel;
    SortFilterProxyModel* sf;
public:
    explicit Table(QWidget* = nullptr);

    TableModel* getMyModel() const;
    SortFilterProxyModel *getSf() const;
};

#endif // TABLE_H
