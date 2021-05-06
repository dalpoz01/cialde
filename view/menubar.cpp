#include "menubar.h"

MenuBar::MenuBar(QWidget *parent) :
    QMenuBar(parent),
    menu(new QMenu("File",this)),
    load(new QAction("Carica", menu)),
    save(new QAction("Salva", menu)),
    catalog(new QAction("Catalogo", this)),
    addProduct(new QAction("Aggiungi Prodotto", this)),
    modProduct(new QAction("Modifica prodotto",this)),
    carrello(new QAction("Carrello", this)),
    showCatalog(new QAction("showCatalog",this)),
    showAddProduct(new QAction("showAddProduct",this)),
    showModProduct(new QAction("showModProduct",this)),
    showCarrello(new QAction("showCarrello",this)){
    menu->addAction(load);
    menu->addAction(save);
    addMenu(menu);
    addAction(catalog);
    addAction(addProduct);
    addAction(modProduct);
    addAction(carrello);

    connect(showCatalog, SIGNAL(triggered()), this, SIGNAL(showCatalogSig()));
}
QAction* MenuBar::getCarrello(){
    return carrello;
}
