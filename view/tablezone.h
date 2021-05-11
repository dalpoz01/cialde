#ifndef TABLEZONE_H
#define TABLEZONE_H

#include <QObject>
#include <QWidget>

#include "table.h"
#include "model/tablemodel.h"

class TableZone : public QWidget{
    Q_OBJECT
private:
    Table* table;
    TableModel* absModel;
public:
    explicit TableZone(QWidget *parent = nullptr, TableModel* = nullptr);

signals:

public slots:
};

#endif // TABLEZONE_H
