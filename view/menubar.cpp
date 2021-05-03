#include "menubar.h"

MenuBar::MenuBar(QWidget *parent) :
    QMenuBar(parent),
    menu(new QMenu("File",this)),
    load(new QAction("Carica", menu)),
    save(new QAction("Salva", menu)),
    catalog(new QAction("Catalogo", this)),
    addProduct(new QAction("Aggiungi Prodotto", this)),
    carrello(new QAction("Carrello", this)){
    menu->addAction(load);
    menu->addAction(save);
    addMenu(menu);
    addAction(catalog);
    addAction(addProduct);
    addAction(carrello);
}
QAction* MenuBar::getCarrello(){
    return carrello;
}
