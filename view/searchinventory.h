#ifndef SEARCHINVENTORY_H
#define SEARCHINVENTORY_H

#include <QWidget>
#include <QLabel>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "view/table.h"
#include "view/catalog.h"

class SearchInventory: public QWidget{
     Q_OBJECT
private:
    QFormLayout* form;
    QLabel* title;
    QLabel* idLabel;
    QLineEdit* idLine;
    QLabel* nameLabel;
    QLineEdit* nameLine;
    QLabel* itemtypeLabel;
    QComboBox* itemtypeComboBox;
    QLabel* capacityLabel;
    QLineEdit* capacityLine;
    QLabel* priceLabel;
    QLineEdit* priceLine;
    QPushButton* searchButton;
    QPushButton* annullaButton;
    QPushButton* ritornaButton;
    Table* table;

public:
    explicit SearchInventory(QWidget * = nullptr);
    QPushButton* getSearchButton() const;
    QPushButton* getAnnullaButton() const;
    QPushButton* getRitornaButton() const;
    Table* getTable() const;
    void setTable(Table*);
    QLineEdit* getIdLine() const;
    QLineEdit* getNameLine() const;
    QComboBox* getItemTypeComboBox() const;
    QLineEdit* getCapacityLine() const;
    QLineEdit* getPriceLine() const;
    void resetField();
};

#endif // SEARCHINVENTORY_H
