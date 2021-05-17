#include "catalog.h"

catalog::catalog(QWidget(*parent)):QWidget(parent),
    ricercaProdotto(new SearchInventory(this)),
    mainLayout(new QVBoxLayout(this)),
    btnSearch(new QPushButton("Cerca prodotto",this)),
    btnSee(new QPushButton("Visualizza prodotti",this))
{
    ricercaProdotto->hide();
    mainLayout->addWidget(btnSearch);
    mainLayout->addWidget(btnSee);
    mainLayout->addWidget(ricercaProdotto);
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
void catalog::showSearch() const{
    if(ricercaProdotto->isVisible()){
        ricercaProdotto->show();
        btnSearch->hide();
        btnSee->hide();
    }else{
        ricercaProdotto->hide();
        btnSearch->show();
        btnSee->show();
    }
}
