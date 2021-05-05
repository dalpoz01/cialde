#include "catalog.h"

catalog::catalog(QWidget(*parent)):QWidget(parent),
    mainLayout(new QVBoxLayout(this)),
    itemTypeCombobox(new QComboBox(this)),
    search(new QPushButton("Cerca",this)),
    imgLabel(new QLabel(this)),
    nome(new QLabel("NOME",this)),
    disponibilita(new QLabel("DISPONIBILITA'",this)),
    editNome(new QLineEdit(this)),
    editDisponibilta(new QLineEdit(this)),
    acquista(new QPushButton("Acquista")),
    prec(new QPushButton("Precedente")),
    succ(new QPushButton("Successivo")),
    formLayout(new QFormLayout())
{
    itemTypeCombobox->addItem("Cialda");
    itemTypeCombobox->addItem("Cono");

    imgLabel->setPixmap(QPixmap(QString::fromStdString(":/MyRes/Photo/image-not-found.jpg")).scaled(QSize(400, 400)));

    QHBoxLayout *base = new QHBoxLayout();
    QHBoxLayout *ricerca = new QHBoxLayout();
    QVBoxLayout *left = new QVBoxLayout();
    QVBoxLayout *right = new QVBoxLayout();
    QHBoxLayout *button = new QHBoxLayout();

    ricerca->addWidget(itemTypeCombobox);
    ricerca->addWidget(search);
    left->addWidget(imgLabel);
    left->setAlignment(Qt::AlignLeft);

    formLayout->addRow(nome,editNome);
    formLayout->addRow(disponibilita,editDisponibilta);

    prec->setEnabled(false);
    button->addWidget(prec);
    button->addWidget(succ);
    right->addLayout(formLayout);
    right->addWidget(acquista);    
    right->addLayout(button);

    base->addLayout(left);
    base->addLayout(right);

    mainLayout->addLayout(ricerca);
    mainLayout->addLayout(base);
}
