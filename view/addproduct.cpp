#include "addproduct.h"

addproduct::addproduct(QWidget(*parent)):QWidget(parent),
    base(new QHBoxLayout(this)),
    left(new QVBoxLayout()),
    right(new QVBoxLayout()),
    item(new QComboBox(this)),
    imgLabel(new QLabel(this)),
    tipo(new QLabel("TIPO",this)),
    nome(new QLabel("NOME",this)),
    id(new QLabel("ID",this)),
    nPezzi(new QLabel("NUMERO PEZZI",this)),
    prezzo(new QLabel("PREZZO",this)),
    addPhoto(new QPushButton("Aggiungi foto")),
    add(new QPushButton("Aggiungi")),
    cancel(new QPushButton("Annulla")),
    editNome(new QLineEdit(this)),
    editID(new QLineEdit(this)),
    editNPezzi(new QLineEdit(this)),
    editPrezzo(new QLineEdit(this))
{
    item->addItem("Cialda");
    item->addItem("Cono");

    imgLabel->setPixmap(QPixmap(QString::fromStdString(":/MyRes/Photo/image-not-found.jpg")).scaled(QSize(400, 400)));

    QFormLayout *form=new QFormLayout();
    form->addRow(tipo,item);
    form->addRow(nome,editNome);
    form->addRow(id,editID);
    form->addRow(nPezzi,editNPezzi);
    form->addRow(prezzo,editPrezzo);

    right->addLayout(form);
    right->addWidget(add);
    right->addWidget(cancel);
    left->addWidget(imgLabel);
    left->addWidget(addPhoto);

    base->addLayout(left);
    base->addLayout(right);
}
