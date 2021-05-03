#include "menubar.h"

MenuBar::MenuBar(QWidget *parent) :
    QMenuBar(parent),
    menu(new QMenu("File",this)),
    load(new QAction("Carica", menu)),
    save(new QAction("Salva", menu)),
    searchProduct(new QAction("Cerca prodotto", this)){
    menu->addAction(load);
    menu->addAction(save);
    addMenu(menu);
    addAction(searchProduct);
}
