#ifndef TABLE_H
#define TABLE_H
#include <QWidget>
#include <QHeaderView>
#include <QTableView>
#include <QBoxLayout>
#include <QHeaderView>

#include "model/tablemodel.h"
#include "model/filterproxymodel.h"

class Table : public QTableView {
    Q_OBJECT
public:
    explicit Table(QWidget* = nullptr);
    QHeaderView *getHeader() const;
};

#endif // TABLE_H
