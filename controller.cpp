#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent){
    //connect(view->getMenu()->getCatalog(),SIGNAL(triggered()),this,SLOT(showCatalogo()));
}

void Controller::setView(MainWindow *v){ view=v; }

void Controller::setModel(Model *m){ model=m; }

void Controller::showCatalogo() const{
    view->showCatalog();
}

void Controller::showAddProduct() const{
    view->showAddProduct();
}

void Controller::showModProduct() const{
    view->showModifyProduct();
}
void Controller::Aggiungi() const{
    view->Aggiungi();
}
