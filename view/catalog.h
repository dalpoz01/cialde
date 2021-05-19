#ifndef CATALOG_H
#define CATALOG_H

#include <QComboBox>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <QLineEdit>
#include "view/searchinventory.h"
#include "view/table.h"

class catalog : public QWidget{
    Q_OBJECT
private:
    SearchInventory *ricercaProdotto;
    Table* table;
    QPushButton *btnSearch;
    QPushButton *btnSee;
public:
    explicit catalog(QWidget * = nullptr);
    void showSearch() const;
    QPushButton* getBtnSearch() const;
    QPushButton* getBtnSee() const;
    SearchInventory* getRicercaProdotto() const;
    Table* getTable() const;
};

#endif // CATALOG_H
