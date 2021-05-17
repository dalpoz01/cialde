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

class catalog : public QWidget{
    Q_OBJECT
private:
    SearchInventory *ricercaProdotto;
    QVBoxLayout *mainLayout;
    QPushButton *btnSearch;
    QPushButton *btnSee;
public:
    explicit catalog(QWidget * = nullptr);
    void showSearch() const;
    QPushButton* getBtnSearch() const;
    QPushButton* getBtnSee() const;
    SearchInventory* getRicercaProdotto() const;
};

#endif // CATALOG_H
