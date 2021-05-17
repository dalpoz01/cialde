#ifndef TABLE_H
#define TABLE_H
#include <QWidget>
#include<QTableView>
#include <QBoxLayout>

#include "model/tablemodel.h"

class Table : public QTableView {
    Q_OBJECT
private:
    TableModel* mymodel;
public:
    explicit Table(QWidget* = nullptr);

    TableModel* getMyModel() const;
};

#endif // TABLE_H
