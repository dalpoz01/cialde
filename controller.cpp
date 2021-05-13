#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent){
    //connect(view->getMenu()->getCatalog(),SIGNAL(triggered()),this,SLOT(showCatalogo()));
}

void Controller::setView(MainWindow *v){ view=v; }

void Controller::setModel(Model *m){ model=m; }

Model* Controller::getModel() const{return model;}

void Controller::showCatalogo() const{
    view->showCatalog();
}

void Controller::showAddProduct() const{
    view->showAddProduct();
}

void Controller::showModProduct() const{
    view->showModifyProduct();
}
void Controller::insertItemController(WaffleBox* wb){
    //cout << to_string(model->getSize()) << endl;
    model->addBox(wb);
    view->insertItemInfo();
}
