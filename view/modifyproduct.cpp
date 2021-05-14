#include "modifyproduct.h"

modifyProduct::modifyProduct(QWidget(*parent)):QWidget(parent),

    editNameProduct(new QLineEdit(this)),
    itemTypeCombobox(new QComboBox(this)),
    search(new QPushButton("Cerca",this)),
    imgLabel(new QLabel(this)) {

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *ricerca = new QHBoxLayout();

    itemTypeCombobox->addItem("Cialda");
    itemTypeCombobox->addItem("Cono");

    editNameProduct->setPlaceholderText("Nome prodotto");

    ricerca->addWidget(editNameProduct);
    ricerca->addWidget(itemTypeCombobox);
    ricerca->addWidget(search);
    ricerca->setAlignment(Qt::AlignTop);

    mainLayout->addLayout(ricerca);

}
