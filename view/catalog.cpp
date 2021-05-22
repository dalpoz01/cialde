#include "catalog.h"

catalog::catalog(QWidget(*parent)):QWidget(parent),
    ricercaProdotto(new SearchInventory()),
    table(new Table()),
    btnSearch(new QPushButton("Cerca prodotto")),
    btnSee(new QPushButton("Visualizza prodotti")),
    btnModify(new QPushButton("Modifica")),
    btnViewItem(new QPushButton("Visualizza prodotto")),
    btnRemove(new QPushButton("Elimina"))
{
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QVBoxLayout* topHalf = new QVBoxLayout();
    QVBoxLayout* bottomHalf = new QVBoxLayout();
    QHBoxLayout* btnBottom = new QHBoxLayout();



    ricercaProdotto->hide();
    table->hide();
    btnModify->setEnabled(false);
    btnViewItem->setEnabled(false);
    btnRemove->setEnabled(false);
    btnModify->hide();
    btnViewItem->hide();
    btnRemove->hide();

    //Parte superiore della view, con i due bottoni in layout verticale
    topHalf->addWidget(btnSearch);
    topHalf->addWidget(btnSee);

    //Parte inferiore della view in layout orizzontale, con a sinistra la tabella e a destra due bottoni, "Visualizza" e "Modifica" (rispettivamente in layout verticale)
    mainLayout->addWidget(ricercaProdotto);
    bottomHalf->addWidget(table);
    btnBottom->addWidget(btnModify);
    btnBottom->addWidget(btnViewItem);
    btnBottom->addWidget(btnRemove);
    bottomHalf->addLayout(btnBottom);
    ricercaProdotto->getTable()->setModel(table->getMyModel());

    mainLayout->addLayout(topHalf);
    mainLayout->addLayout(bottomHalf);

    topHalf->setAlignment(Qt::AlignTop);
    bottomHalf->setAlignment(Qt::AlignTop);
    setLayout(mainLayout);

}

QPushButton *catalog::getBtnSearch() const{ return btnSearch; }

QPushButton *catalog::getBtnSee() const{ return btnSee; }

QPushButton *catalog::getBtnModifiy() const{ return btnModify; }

QPushButton *catalog::getBtnViewItem() const{ return btnViewItem; }

QPushButton *catalog::getBtnRemove() const{ return btnRemove; }

SearchInventory *catalog::getRicercaProdotto() const{ return ricercaProdotto; }

Table *catalog::getTable() const{ return table; }

void catalog::showSearch() const{
    if(ricercaProdotto->isVisible()){
        ricercaProdotto->show();
        btnSearch->hide();
        btnSee->hide();
        table->hide();
        btnViewItem->hide();
        btnModify->hide();
        btnRemove->hide();

    }else{
        ricercaProdotto->hide();
        btnSearch->show();
        btnSee->show();
        table->hide();
        btnViewItem->hide();
        btnModify->hide();
        btnRemove->hide();

    }
}
