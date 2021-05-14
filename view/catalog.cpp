#include "catalog.h"

catalog::catalog(QWidget(*parent)):QWidget(parent),

    itemTypeCombobox(new QComboBox(this)),
    search(new QPushButton("Cerca",this)),
    imgLabel(new QLabel(this)),
    nome(new QLabel("NOME",this)),
    disponibilita(new QLabel("DISPONIBILITA'",this)),
    mainLayout(new QVBoxLayout(this)),
    itemCombobox(new QComboBox(this)),
    btnSearch(new QPushButton("Cerca prodotto",this)),
    btnSee(new QPushButton("Visualizza prodotto",this)),
    btnGo(new QPushButton("Vai",this)),
    tipoLabel(new QLabel("TIPO",this)),
    nomeLabel(new QLabel("NOME")),
    editNome(new QLineEdit(this)),
    formLayout(new QFormLayout()){
    QVBoxLayout *mainLayout=new QVBoxLayout(this);

    itemTypeCombobox->addItem("Cialda");
    itemTypeCombobox->addItem("Cono");
    itemCombobox->addItem(" - ");
    itemCombobox->addItem("Circle Box");
    itemCombobox->addItem("Ventaglio Box");
    itemCombobox->addItem("Cannolo Box");
    itemCombobox->addItem("Cone Box");
    itemCombobox->addItem("Covered Box");
    itemCombobox->addItem("Branded Box");

    QWidget* p=new QWidget();
    p->sizeHint();
    QHBoxLayout *first=new QHBoxLayout();
    QHBoxLayout *btn=new QHBoxLayout();
    QVBoxLayout *left=new QVBoxLayout();
    QVBoxLayout *right=new QVBoxLayout();



    formLayout->addRow(tipoLabel,itemCombobox);
    formLayout->addRow(nomeLabel,editNome);

    btn->addWidget(btnGo);
    btn->setAlignment(Qt::AlignTop);
    left->setAlignment(Qt::AlignTop);
    right->setAlignment(Qt::AlignTop);

    btnSearch->maximumSize();
    btnSee->maximumSize();

    left->addWidget(btnSearch);
    left->addWidget(btnSee);
    right->addLayout(formLayout);
    right->addLayout(btn);

    left->setMargin(50);
    right->setMargin(50);

    QPushButton *prova=new QPushButton("Prova");
    QHBoxLayout *pr=new QHBoxLayout();
    pr->setAlignment(Qt::AlignTop);
    pr->addWidget(prova);

    p->setLayout(left);
    first->addWidget(p);
    first->addLayout(right);

    mainLayout->addLayout(first);
    mainLayout->addLayout(pr);
}
QPushButton* catalog::getBtnSearch(){
    return btnSearch;
}
void catalog::showSearch() const{
    bool f=!(tipoLabel->isVisible());
    tipoLabel->setVisible(f);
    itemCombobox->setVisible(f);
    nomeLabel->setVisible(f);
    editNome->setVisible(f);
    btnGo->setVisible(f);

}
QSize catalog::sizeHint() const{
    return QSize(50, 100);
}
