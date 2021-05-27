#include "catalog.h"

catalog::catalog(QWidget(*parent), TableModel *TM, filterProxyModel *FPM):QWidget(parent),
    table(new Table()),
    btnModify(new QPushButton("Modifica")),
    btnViewItem(new QPushButton("Visualizza prodotto")),
    btnRemove(new QPushButton("Elimina")),
    searchEdit(new QLineEdit()),
    typeCombobox(new QComboBox()),
    detailsCombobox(new QComboBox()),
    Tm(TM),
    fpm(FPM)
{
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* topHalf = new QHBoxLayout();
    QVBoxLayout* bottomHalf = new QVBoxLayout();
    QHBoxLayout* btnBottom = new QHBoxLayout();

    QLabel *textSearch=new QLabel("Ricerca: ");
    QLabel *textType=new QLabel("Tipo: ");
    QLabel *textDetails=new QLabel("Campo: ");

    typeCombobox->addItem("Tutti");
    typeCombobox->addItem("Circle Box");
    typeCombobox->addItem("Ventaglio Box");
    typeCombobox->addItem("Cannolo Box");
    typeCombobox->addItem("Cone Box");
    typeCombobox->addItem("Covered Box");
    typeCombobox->addItem("Branded");

    detailsCombobox->addItem("ID");
    detailsCombobox->addItem("Nome");
    detailsCombobox->addItem("Capacità");
    detailsCombobox->addItem("Peso");
    detailsCombobox->addItem("Prezzo");
    detailsCombobox->addItem("Disponibilità");

    searchEdit->setPlaceholderText("Parole o numeri chiave da cercare...");

    fpm->setSourceModel(Tm);
    fpm->setSortRole(Qt::UserRole);
    table->setModel(fpm);

    topHalf->addWidget(textSearch);
    topHalf->addWidget(searchEdit);
    topHalf->addWidget(textType);
    topHalf->addWidget(typeCombobox);
    topHalf->addWidget(textDetails);
    topHalf->addWidget(detailsCombobox);
    topHalf->setAlignment(Qt::AlignTop);

    //Parte inferiore della view in layout orizzontale, con a sinistra la tabella e a destra due bottoni, "Visualizza" e "Modifica" (rispettivamente in layout verticale)
    bottomHalf->addWidget(table);
    btnBottom->addWidget(btnModify);
    btnBottom->addWidget(btnViewItem);
    btnBottom->addWidget(btnRemove);
    btnBottom->setAlignment(Qt::AlignBottom);

    mainLayout->addLayout(topHalf);
    mainLayout->addLayout(bottomHalf);
    mainLayout->addLayout(btnBottom);

    setLayout(mainLayout);

}

QPushButton *catalog::getBtnModifiy() const{ return btnModify; }

QPushButton *catalog::getBtnViewItem() const{ return btnViewItem; }

QPushButton *catalog::getBtnRemove() const{ return btnRemove; }

//SearchInventory *catalog::getRicercaProdotto() const{ return ricercaProdotto; }

Table *catalog::getTable() const{ return table; }

QComboBox *catalog::getTypeCombobox() const { return typeCombobox; }

QComboBox *catalog::getDetailsCombobox() const { return detailsCombobox; }

QLineEdit *catalog::getSearchEdit() const { return searchEdit; }

TableModel *catalog::getTm() const { return Tm; }

filterProxyModel *catalog::getFpm() const { return fpm; }
