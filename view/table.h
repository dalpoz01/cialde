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
/*private:
    bool ord;*/
public:
    explicit Table(QWidget* = nullptr);
    QHeaderView *getHeader() const;
    void orderTable(int);
    //bool getOrd() const;
    //void setOrd(bool);
};

#endif // TABLE_H
