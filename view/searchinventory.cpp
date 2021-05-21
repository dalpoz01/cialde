#include "searchinventory.h"

SearchInventory::SearchInventory(QWidget *parent) :
    QWidget(parent),
    form(new QFormLayout()),
    title(new QLabel("Ricerca prodotto",this)),
    idLabel(new QLabel("ID",this)),
    idLine(new QLineEdit(this)),
    nameLabel(new QLabel("Nome",this)),
    nameLine(new QLineEdit(this)),
    itemtypeLabel(new QLabel("Tipo",this)),
    itemtypeComboBox(new QComboBox(this)),
    capacityLabel(new QLabel("Capacità",this)),
    capacityLine(new QLineEdit(this)),
    priceLabel(new QLabel("Prezzo",this)),
    priceLine(new QLineEdit(this)),
    searchButton(new QPushButton("Cerca",this)),
    annullaButton(new QPushButton("Annulla",this)),
    table(new Table(this))
{
    QVBoxLayout* main = new QVBoxLayout(this);
    QHBoxLayout* bottom = new QHBoxLayout();
    QVBoxLayout* srcLayout = new QVBoxLayout();

    priceLine->setValidator(new QDoubleValidator(0.00, 999.00,2,this));
    itemtypeComboBox->addItem(" - ");
    itemtypeComboBox->addItem("Circle Box");
    itemtypeComboBox->addItem("Ventaglio Box");
    itemtypeComboBox->addItem("Cannolo Box");
    itemtypeComboBox->addItem("Cone Box");
    itemtypeComboBox->addItem("Covered Box");
    itemtypeComboBox->addItem("Branded Box");

    form->addRow(title);
    form->addRow(idLabel,idLine);   //Da impl. controlli per ID
    form->addRow(nameLabel,nameLine);
    form->addRow(itemtypeLabel,itemtypeComboBox);
    form->addRow(capacityLabel,capacityLine);
    form->addRow(priceLabel,priceLine);

    srcLayout->addLayout(form);
    bottom->addWidget(searchButton);
    bottom->addWidget(annullaButton);
    bottom->setAlignment(Qt::AlignTop);
    main->addLayout(srcLayout);
    main->addLayout(bottom);
    main->addWidget(table);
}
QPushButton* SearchInventory::getSearchButton() const{
    return searchButton;
}
QPushButton* SearchInventory::getAnnullaButton() const{
    return annullaButton;
}

Table* SearchInventory::getTable() const{ return table; }

void SearchInventory::setTable(Table *tab){ table = tab; }
