#include "catalog.h"

catalog::catalog(QWidget(*parent), TableModel *TM, filterProxyModel *FPM):QWidget(parent),
    table(new Table(this)),
    btnModify(new QPushButton("Modifica")),
    btnViewItem(new QPushButton("Visualizza prodotto")),
    btnRemove(new QPushButton("Elimina")),
    searchEdit(new QLineEdit()),
    typeCombobox(new QComboBox()),
    detailsCombobox(new QComboBox()),
    /*ordAsc(new QRadioButton("Crescente",this)),
    ordDesc(new QRadioButton("Decrescente",this)),*/
    Tm(TM),
    fpm(FPM)
{
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* topHalf = new QHBoxLayout();
    //QHBoxLayout* radioHalf = new QHBoxLayout();
    QVBoxLayout* bottomHalf = new QVBoxLayout();
    QHBoxLayout* btnBottom = new QHBoxLayout();

    QLabel *textSearch=new QLabel("Ricerca: ");
    QLabel *textType=new QLabel("Tipo: ");
    QLabel *textDetails=new QLabel("Campo: ");
    //QLabel *textOrder=new QLabel("Ordine di visualizzazione: ");

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
    //fpm->setSortRole(Qt::UserRole);
    table->setModel(fpm);

    topHalf->addWidget(textSearch);
    topHalf->addWidget(searchEdit);
    topHalf->addWidget(textType);
    topHalf->addWidget(typeCombobox);
    topHalf->addWidget(textDetails);
    topHalf->addWidget(detailsCombobox);
    topHalf->setAlignment(Qt::AlignTop);

    /*radioHalf->addWidget(textOrder);
    radioHalf->addWidget(ordAsc);
    radioHalf->addWidget(ordDesc);*/

    //Parte inferiore della view in layout orizzontale, con a sinistra la tabella e a destra due bottoni, "Visualizza" e "Modifica" (rispettivamente in layout verticale)
    bottomHalf->addWidget(table);
    btnBottom->addWidget(btnModify);
    btnBottom->addWidget(btnViewItem);
    btnBottom->addWidget(btnRemove);
    btnBottom->setAlignment(Qt::AlignBottom);

    mainLayout->addLayout(topHalf);
    //mainLayout->addLayout(radioHalf);
    mainLayout->addLayout(bottomHalf);
    mainLayout->addLayout(btnBottom);

    setLayout(mainLayout);

}

QPushButton *catalog::getBtnModifiy() const{ return btnModify; }

QPushButton *catalog::getBtnViewItem() const{ return btnViewItem; }

QPushButton *catalog::getBtnRemove() const{ return btnRemove; }

Table *catalog::getTable() const{ return table; }

QComboBox *catalog::getTypeCombobox() const { return typeCombobox; }

QComboBox *catalog::getDetailsCombobox() const { return detailsCombobox; }

QLineEdit *catalog::getSearchEdit() const { return searchEdit; }

TableModel *catalog::getTm() const { return Tm; }

filterProxyModel *catalog::getFpm() const { return fpm; }

/*QRadioButton *catalog::getOrdAsc() const { return ordAsc; }

QRadioButton *catalog::getOrdDesc() const { return ordDesc; }*/

/*void catalog::setOrder(){
    ordAsc->isChecked() ? table->setOrd(true) : table->setOrd(false);
}*/

void catalog::sortHeaderClicked(int a){
    table->orderTable(a);
}


