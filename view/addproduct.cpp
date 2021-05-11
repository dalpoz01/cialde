#include "addproduct.h"

addproduct::addproduct(QWidget(*parent)):QWidget(parent),

    itemComboBox(new QComboBox(this)),
    imgLabel(new QLabel(this)),
    tipoLabel(new QLabel("TIPO",this)),
    nomeLabel(new QLabel("NOME",this)),
    idLabel(new QLabel("ID",this)),
    nPezziLabel(new QLabel("NUMERO PEZZI",this)),
    prezzoLabel(new QLabel("PREZZO",this)),
    addPhoto(new QPushButton("Aggiungi foto")),
    addButton(new QPushButton("Aggiungi")),
    cancelButton(new QPushButton("Annulla")),
    nomeLine(new QLineEdit(this)),
    idLine(new QLineEdit(this)),
    npezziLine(new QLineEdit(this)),
    prezzoLine(new QLineEdit(this))
{

    QHBoxLayout* base = new QHBoxLayout(this);
    QVBoxLayout* left = new QVBoxLayout();
    QVBoxLayout* right = new QVBoxLayout();
    QFormLayout* form=new QFormLayout();

    itemComboBox->addItem("Cialda");
    itemComboBox->addItem("Cono");

    imgLabel->setPixmap(QPixmap(QString::fromStdString(":/MyRes/Photo/image-not-found.jpg")).scaled(QSize(400, 400)));

    form->addRow(tipoLabel,itemComboBox);
    form->addRow(nomeLabel,nomeLine);
    form->addRow(idLabel,idLine);
    form->addRow(nPezziLabel,npezziLine);
    form->addRow(prezzoLabel,prezzoLine);

    right->addLayout(form);
    right->addWidget(addButton);
    right->addWidget(cancelButton);
    left->addWidget(imgLabel);
    left->addWidget(addPhoto);

    base->addLayout(left);
    base->addLayout(right);
}

QPushButton* addproduct::getAdd(){
    return addButton;
}
