#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent){

}

void Controller::setView(MainWindow *v){
    view=v;

    //Menu
    connect(view->getMenu()->getCatalog(),SIGNAL(triggered()),this,SLOT(showCatalogo()));
    connect(view->getMenu()->getAddProduct(),SIGNAL(triggered()),this,SLOT(showAddProduct()));
    connect(view->getMenu()->getModProduct(),SIGNAL(triggered()),this,SLOT(showModProduct()));
    connect(view->getMenu()->getLoad(),SIGNAL(triggered()),this,SLOT(loadingXmlController()));
    connect(view->getMenu()->getSave(),SIGNAL(triggered()),this,SLOT(savingXmlController()));

    //Aggiungi Prodotto
    connect(view->getAddProduct()->getItemCombo(),SIGNAL(currentIndexChanged(const QString&)),view->getAddProduct(),SLOT(showItemTypeField(const QString&)));
    connect(view->getAddProduct()->getCancel(),SIGNAL(clicked()),view->getAddProduct(),SLOT(resetFields()));
    connect(view->getAddProduct()->getAddPhoto(),SIGNAL(clicked()),view->getAddProduct(),SLOT(addFoto()));
    connect(view->getAddProduct()->getAdd(),SIGNAL(clicked()),view->getAddProduct(),SLOT(insert())); //Connessione per aggiungiProdotto
    connect(view->getAddProduct(),SIGNAL(signalToInsert(WaffleBox*)),this,SLOT(insertItemController(WaffleBox*))); //Connessione per il segnale emesso da aggiuniProdotto

    //Catalogo
    connect(view->getCatalog()->getBtnSearch(),SIGNAL(clicked()),this,SLOT(showSearch()));
    connect(view->getCatalog()->getRicercaProdotto()->getSearchButton(),SIGNAL(clicked()),this,SLOT(showSearch()));
    connect(view->getCatalog()->getRicercaProdotto()->getAnnullaButton(),SIGNAL(clicked()),this,SLOT(hideSearch()));
    connect(view->getCatalog()->getBtnSee(),SIGNAL(clicked()),this,SLOT(seeItems()));

}

void Controller::setModel(Model *m){
    model = m;
}

Model* Controller::getModel() const{return model;}

void Controller::showCatalogo() const{
    view->getCatalog()->show();
    view->getTabella()->show();
    view->getAddProduct()->hide();
    view->getModifyProduct()->hide();
}

void Controller::showAddProduct() const{
    view->getCatalog()->hide();
    view->getTabella()->hide();
    view->getAddProduct()->show();
    view->getModifyProduct()->hide();
}

void Controller::showModProduct() const{
    view->getCatalog()->hide();
    view->getTabella()->hide();
    view->getAddProduct()->hide();
    view->getModifyProduct()->show();
}
void Controller::insertItemController(WaffleBox* wb){
    //cout << to_string(model->getSize()) << endl;
    model->addBox(wb);
    view->insertItemInfo();
}
void Controller::loadingXmlController(){
    model->loadXml();
    view->loadingXmlInfo();
}

void Controller::savingXmlController(){
    model->writeXml();
    view->savingXmlInfo();
}
void Controller::showSearch() const{
    view->getCatalog()->getRicercaProdotto()->show();
    view->getCatalog()->showSearch();
    view->getTabella()->show();
}
void Controller::hideSearch() const{
    view->getCatalog()->getRicercaProdotto()->hide();
    view->getCatalog()->showSearch();

}

void Controller::seeItems() const{
    model->printAll();
    view->seeInfo();
}

void Controller::avoidSearch() const{
    //std:cout<<"In inplementazione..."<<endl;
    //view->getCatalog()->getRicercaProdotto()->show();
}
