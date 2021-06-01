#include "menubar.h"

MenuBar::MenuBar(QWidget *parent) :
    QMenuBar(parent),
    menu(new QMenu("File",this)),
    load(new QAction("Carica", menu)),
    save(new QAction("Salva", menu)),
    catalog(new QAction("Catalogo", this)),
    addProduct(new QAction("Aggiungi Prodotto", this)),
    orderTab(new QAction("Nuovo ordine", this))
{
    menu->addAction(load);
    menu->addAction(save);
    addMenu(menu);
    addAction(catalog);
    addAction(addProduct);

    orderTab->setVisible(false);
    addAction(orderTab);

    /*connect(load,SIGNAL(changed()),this,SLOT(loadXmlFile()));
    connect(save,SIGNAL(changed()),this,SLOT(saveXmlFile()));*/

}

QAction* MenuBar::getLoad() const { return load; }

QAction* MenuBar::getSave() const { return save; }

QAction *MenuBar::getOrderTab() const{ return orderTab; }

//void MenuBar::loadXmlFile(){ emit signalToLoad(); }

QAction* MenuBar::getCatalog() const { return catalog; }

QAction *MenuBar::getAddProduct() const { return addProduct; }
