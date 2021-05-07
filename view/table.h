#ifndef TABLE_H
#define TABLE_H
#include <QWidget>
#include<QTableView>
#include<QHeaderView>

class Table : public QTableView {
    Q_OBJECT
private:
    QHeaderView* header;
public:
    Table(QWidget* = nullptr);
};

#endif // TABLE_H
