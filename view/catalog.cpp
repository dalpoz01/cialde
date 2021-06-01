#include "catalog.h"


catalog::catalog(QWidget(*parent), TableModel *TM, filterProxyModel *FPM):QWidget(parent),
    table(new Table(this)),
    btnModify(new QPushButton("Modifica",this)),
    btnViewItem(new QPushButton("Visualizza prodotto",this)),
    btnRemove(new QPushButton("Elimina",this)),
    btnBuy(new QPushButton("Acquista",this)),
    searchEdit(new QLineEdit(this)),
    typeCombobox(new QComboBox(this)),
    detailsCombobox(new QComboBox(this)),
    Tm(TM),
    fpm(FPM),
    ord(false)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* topHalf = new QHBoxLayout();
    QVBoxLayout* bottomHalf = new QVBoxLayout();
    QHBoxLayout* btnBottom = new QHBoxLayout();

    QLabel *textSearch=new QLabel("Ricerca: ",this);
    QLabel *textType=new QLabel("Tipo: ",this);
    QLabel *textDetails=new QLabel("Campo: ",this);

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
    table->setModel(fpm);

    topHalf->addWidget(textSearch);
    topHalf->addWidget(searchEdit);
    topHalf->addWidget(textType);
    topHalf->addWidget(typeCombobox);
    topHalf->addWidget(textDetails);
    topHalf->addWidget(detailsCombobox);
    topHalf->setAlignment(Qt::AlignTop);

    //Parte inferiore della view in layout orizzontale, con a sinistra la tabella e a destra due bottoni, "Visualizza" e "Modifica" (rispettivamente in layout verticale
    bottomHalf->addWidget(table);
    btnBuy->setEnabled(false);
    btnBottom->addWidget(btnBuy);
    btnBottom->addWidget(btnModify);
    btnBottom->addWidget(btnViewItem);
    btnBottom->addWidget(btnRemove);

    btnBottom->setAlignment(Qt::AlignBottom);

    mainLayout->addLayout(topHalf);
    mainLayout->addLayout(bottomHalf);
    mainLayout->addLayout(btnBottom);
    mainLayout->setAlignment(Qt::AlignTop);
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

void catalog::sortHeaderClicked(int a){
    if(ord){
        fpm->sort(a,Qt::DescendingOrder);
        ord=false;
    }else{
        fpm->sort(a,Qt::AscendingOrder);
        ord=true;
    }

}


QPushButton *catalog::getBtnBuy() const
{
    return btnBuy;
}


