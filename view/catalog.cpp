#include "catalog.h"

catalog::catalog(QWidget(*parent)):QWidget(parent),
    mainLayout(new QVBoxLayout(this)),
    itemTypeCombobox(new QComboBox(this)),
    btnSearch(new QPushButton("Cerca prodotto",this)),
    btnSee(new QPushButton("Visualizza prodotto",this)),
    btnGo(new QPushButton("Vai",this)),
    tipoLabel(new QLabel("TIPO",this)),
    nomeLabel(new QLabel("NOME")),
    editNome(new QLineEdit(this)),
    formLayout(new QFormLayout())
{
    QHBoxLayout *first=new QHBoxLayout();
    QHBoxLayout *btn=new QHBoxLayout();
    QVBoxLayout *left=new QVBoxLayout();
    QVBoxLayout *right=new QVBoxLayout();

    itemTypeCombobox->addItem(" - ");
    itemTypeCombobox->addItem("Circle Box");
    itemTypeCombobox->addItem("Ventaglio Box");
    itemTypeCombobox->addItem("Cannolo Box");
    itemTypeCombobox->addItem("Cone Box");
    itemTypeCombobox->addItem("Covered Box");
    itemTypeCombobox->addItem("Branded Box");

    formLayout->addRow(tipoLabel,itemTypeCombobox);
    formLayout->addRow(nomeLabel,editNome);

    btn->addWidget(btnGo);
    btn->setAlignment(Qt::AlignTop);
    left->setAlignment(Qt::AlignTop);
    right->setAlignment(Qt::AlignTop);

    this->showSearch();

    left->addWidget(btnSearch);
    left->addWidget(btnSee);
    right->addLayout(formLayout);
    right->addLayout(btn);

    first->addLayout(left);
    first->addLayout(right);

    mainLayout->addLayout(first);
}
QPushButton* catalog::getBtnSearch(){
    return btnSearch;
}
void catalog::showSearch() const{
    bool f=!(tipoLabel->isVisible());
    tipoLabel->setVisible(f);
    itemTypeCombobox->setVisible(f);
    nomeLabel->setVisible(f);
    editNome->setVisible(f);
    btnGo->setVisible(f);
    btnSee->setVisible(!f);
    if(f){
        btnSearch->setText("Annulla");
    }else{
        btnSearch->setText("Cerca prodotto");
    }

}
QSize catalog::sizeHint() const{
    return QSize(500, 300);
}
