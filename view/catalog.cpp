#include "catalog.h"

catalog::catalog(QWidget(*parent)):QWidget(parent),
    ricercaProdotto(new SearchInventory(this)),
    table(new Table(this)),
    btnSearch(new QPushButton("Cerca prodotto",this)),
    btnSee(new QPushButton("Visualizza prodotti",this)),
    btnModify(new QPushButton("Modifica",this)),
    btnViewItem(new QPushButton("Visualizza prodotto",this))
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QVBoxLayout* topHalf = new QVBoxLayout();
    QHBoxLayout* bottomHalf = new QHBoxLayout();

    ricercaProdotto->hide();
    table->hide();
    btnModify->setEnabled(false);
    btnViewItem->setEnabled(false);
    btnModify->hide();
    btnViewItem->hide();

    //Parte superiore della view, con i due bottoni in layout verticale
    topHalf->addWidget(btnSearch);
    topHalf->addWidget(btnSee);

    //Parte inferiore della view in layout orizzontale, con a sinistra la tabella e a destra due bottoni, "Visualizza" e "Modifica" (rispettivamente in layout verticale)
    bottomHalf->addWidget(table);
    bottomHalf->addWidget(btnModify);
    bottomHalf->addWidget(btnViewItem);

    mainLayout->addLayout(topHalf);
    mainLayout->addLayout(bottomHalf);
    mainLayout->addWidget(ricercaProdotto);

    topHalf->setAlignment(Qt::AlignTop);
    bottomHalf->setAlignment(Qt::AlignTop);
    setLayout(mainLayout);

}
QPushButton* catalog::getBtnSearch() const{return btnSearch;}

QPushButton* catalog::getBtnSee() const{ return btnSee; }

QPushButton* catalog::getBtnModifiy() const{ return btnModify; }

QPushButton* catalog::getBtnViewItem() const{ return btnViewItem; }

SearchInventory* catalog::getRicercaProdotto() const{ return ricercaProdotto; }

Table* catalog::getTable() const{ return table; }

void catalog::showSearch() const{
    if(ricercaProdotto->isVisible()){
        ricercaProdotto->show();
        btnSearch->hide();
        btnSee->hide();
        table->hide();
        btnViewItem->hide();
        btnModify->hide();

    }else{
        ricercaProdotto->hide();
        btnSearch->show();
        btnSee->show();
        table->hide();
        btnViewItem->hide();
        btnModify->hide();

    }
}
