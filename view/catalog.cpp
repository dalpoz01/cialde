#include "catalog.h"

catalog::catalog(QWidget(*parent)):QWidget(parent),
    ricercaProdotto(new SearchInventory(this)),
    table(new Table(this)),
    btnSearch(new QPushButton("Cerca prodotto",this)),
    btnSee(new QPushButton("Visualizza prodotti",this))
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    ricercaProdotto->hide();
    table->hide();
    mainLayout->addWidget(btnSearch);
    mainLayout->addWidget(btnSee);
    mainLayout->addWidget(ricercaProdotto);
    mainLayout->addWidget(table);
    mainLayout->setAlignment(Qt::AlignTop);
    setLayout(mainLayout);

}
QPushButton* catalog::getBtnSearch() const{
    return btnSearch;
}
QPushButton* catalog::getBtnSee() const{
    return btnSee;
}
SearchInventory* catalog::getRicercaProdotto() const{
    return ricercaProdotto;
}

Table* catalog::getTable() const{return table;}

void catalog::showSearch() const{
    if(ricercaProdotto->isVisible()){
        ricercaProdotto->show();
        btnSearch->hide();
        btnSee->hide();
        table->hide();
    }else{
        ricercaProdotto->hide();
        btnSearch->show();
        btnSee->show();
        table->hide();
    }
}
