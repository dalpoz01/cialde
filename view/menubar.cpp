#include "menubar.h"
#include <iostream>

MenuBar::MenuBar(QWidget *parent) :
    QMenuBar(parent),
    menu(new QMenu("File",this)),
    load(new QAction("Carica", menu)),
    save(new QAction("Salva", menu)),
    catalog(new QAction("Catalogo", this)),
    addProduct(new QAction("Aggiungi Prodotto", this)),
    modProduct(new QAction("Modifica prodotto",this)),
    carrello(new QAction("Carrello", this)){
    menu->addAction(load);
    menu->addAction(save);
    addMenu(menu);
    addAction(catalog);
    addAction(addProduct);
    addAction(modProduct);
    addAction(carrello);

}
QAction* MenuBar::getCarrello(){
    return carrello;
}
QAction* MenuBar::getCatalog() const{
    return catalog;
}
QAction *MenuBar::getAddProduct() const{
    return addProduct;
}

QAction *MenuBar::getModProduct() const{
    return modProduct;
}
