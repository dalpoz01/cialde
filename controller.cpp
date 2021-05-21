#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent){}

void Controller::setView(MainWindow *v){
    view=v;
    //view->getCatalog()->getTable()->getMyModel()->setModel(model);
    //Menu
    connect(view->getMenu()->getCatalog(),SIGNAL(triggered()),this,SLOT(showCatalogo()));   //connessione per visualizzare Catalogo selezionando la voce dal menubar
    connect(view->getMenu()->getAddProduct(),SIGNAL(triggered()),this,SLOT(showAddProduct()));  //connessione per visualizzare Aggiungi prodotto selezionando la voce dal menubar
    connect(view->getMenu()->getLoad(),SIGNAL(triggered()),this,SLOT(loadingXmlController()));  //connessione per caricare i dati da un file.xml selezionando la voce dal menubar
    connect(view->getMenu()->getSave(),SIGNAL(triggered()),this,SLOT(savingXmlController()));   //connessione per salvare i dati in un file.xml selezionando la voce dal menubar

    //Aggiungi Prodotto
    connect(view->getAddProduct()->getItemCombo(),SIGNAL(currentIndexChanged(const QString&)),view->getAddProduct(),SLOT(showItemTypeField(const QString&))); //connessione alla QComboBox del tipo di box da inserire, per visualizzare i campi corretti
    connect(view->getAddProduct()->getCancel(),SIGNAL(clicked()),view->getAddProduct(),SLOT(resetFields())); //connessione per bottone Cancella, che resetta i campi di inserimento
    connect(view->getAddProduct()->getAddPhoto(),SIGNAL(clicked()),view->getAddProduct(),SLOT(addFoto()));  //connessione per bottone Aggiungi foto, che inserisce una foto al prodotto
    connect(view->getAddProduct()->getAdd(),SIGNAL(clicked()),view->getAddProduct(),SLOT(insert())); //Connessione per bottone Aggiungi, richiama il metodo insert() che preleva i dati dai campi e crea l'oggetto
    connect(view->getAddProduct(),SIGNAL(signalToInsert(WaffleBox*)),this,SLOT(insertItemController(WaffleBox*))); //Connessione per il segnale emesso da insert(), se l'inserimento avviene correttamente lo aggiunge al container

    //Catalogo
    connect(view->getCatalog()->getBtnSearch(),SIGNAL(clicked()),this,SLOT(showSearch()));  //connessione per bottone in Catalogo per mostrare la view di Ricerca
    connect(view->getCatalog()->getRicercaProdotto()->getSearchButton(),SIGNAL(clicked()),this,SLOT(showSearch())); //connessione per il bottone Cerca in Ricerca
    connect(view->getCatalog()->getRicercaProdotto()->getAnnullaButton(),SIGNAL(clicked()),this,SLOT(hideSearch()));    //connessione per il bottone Annulla in Ricerca, che nasconde la scheda
    connect(view->getCatalog()->getBtnSee(),SIGNAL(clicked()),this,SLOT(seeTableItem()));   //connessione per bottone Visualizza in Catalogo per visualizzare la tabella.
    connect(view->getCatalog()->getTable()->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(enableBtnTableController()));  //connessione per bottone Visualizza prodotto nella parte inferiore
    connect(view->getCatalog()->getBtnRemove(),SIGNAL(clicked()),this,SLOT(removeItem()));
    //connect(view->getCatalog()->getBtnSee(),SIGNAL(clicked()),this,SLOT(seeItems()));

    //Ricerca
    connect(view->getCatalog()->getRicercaProdotto()->getSearchButton(), SIGNAL(clicked()), this, SLOT(showSearchTable()));

    //Visualizza dettagli
    connect(view->getCatalog()->getBtnViewItem(),SIGNAL(clicked()),this,SLOT(showDetails())); //connessione per mostrare un oggetto in dettaglio

    //Modifica prodotto
    connect(view->getCatalog()->getBtnModifiy(),SIGNAL(clicked()),this,SLOT(modificaProdotto()));
}

void Controller::setModel(Model *m){
    model = m;
}

Model* Controller::getModel() const{return model;}

void Controller::showCatalogo() const{
    view->getCatalog()->show();
    view->getCatalog()->getTable()->hide();
    view->getCatalog()->getBtnModifiy()->hide();
    view->getCatalog()->getBtnViewItem()->hide();
    view->getCatalog()->getBtnRemove()->hide();
    view->getAddProduct()->hide();
}

void Controller::showAddProduct() const{
    view->getCatalog()->hide();
    view->getAddProduct()->show();
}

void Controller::insertItemController(WaffleBox* wb){
    model->addBox(wb);  //Aggiunge al model dell'applicazione dopo aver preso i dati dalla view
    view->getCatalog()->getTable()->getMyModel()->setWBToinsert(wb);    //Aggiorna l'oggetto da inserire nel model della tabella, perchè è stato appena inserito
    //view->getCatalog()->getTable()->getMyModel()->getModel()->addBox(wb);
    view->getCatalog()->getTable()->getMyModel()->insertRows(view->getCatalog()->getTable()->getMyModel()->rowCount(), 1);  //Inserisce la riga per il nuovo oggetto, partendo dall'ultima riga inserita.
    view->insertItemInfo(); //Stampa finestra di successo
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
}

void Controller::hideSearch() const{
    view->getCatalog()->getRicercaProdotto()->hide();
    view->getCatalog()->showSearch();
}
void Controller::seeTableItem() const{
    //model->printAll();
    view->getCatalog()->getTable()->show();
    view->getCatalog()->getBtnModifiy()->show();
    view->getCatalog()->getBtnViewItem()->show();
    view->getCatalog()->getBtnRemove()->show();
    view->enableBtnTable(false);
    view->seeInfo();
}

void Controller::showDetails(){

    //QItemSelectionModel *select = view->getCatalog()->getTable()->selectionModel();

    details *d=new details(nullptr,model->getItem(view->getCatalog()->getTable()->selectionModel()->currentIndex().row()));
    d->setAttribute(Qt::WA_DeleteOnClose);
    d->show();
}

void Controller::modificaProdotto(){
    modifyProduct *mp=new modifyProduct(nullptr, model->getItem(view->getCatalog()->getTable()->selectionModel()->currentIndex().row()));
    mp->setAttribute(Qt::WA_DeleteOnClose);
    connect(mp->getModifyPhotoButton(),SIGNAL(clicked()),mp,SLOT(changePhoto()));
    connect(mp->getOkButton(),SIGNAL(clicked()),mp,SLOT(modifica()));
    connect(mp->getCancelButton(),SIGNAL(clicked()),mp,SLOT(noModify()));
    mp->show(); //prendo l'oggetto modificato dalla tabella //aggiungo la riga aggiornata
}

void Controller::enableBtnTableController(){
    view->enableBtnTable(true);
}
void Controller::disableBtnTableController(){
    view->enableBtnTable(false);
}

void Controller::removeItem(){
    if(QMessageBox::question(nullptr, "Attenzione", "Sei sicuro di voler eliminare questo prodotto?", QMessageBox::Yes, QMessageBox::No)==QMessageBox::Yes){
        //ELIMINAZIONE DALLA TABELLA
        view->getCatalog()->getTable()->getMyModel()->removeRows(view->getCatalog()->getTable()->selectionModel()->currentIndex().row(),1);
        model->removeBox(view->getCatalog()->getTable()->selectionModel()->currentIndex().row());

        QMessageBox::information(nullptr, "Messaggio", "Eliminazione effettuata con successo", QMessageBox::Ok);
    }else{
        QMessageBox::warning(nullptr, "Attenzione", "Operazione annullata", QMessageBox::Ok);
    }
}

void Controller::showSearchTable(){
    view->getCatalog()->getRicercaProdotto()->getTable()->setModel(view->getCatalog()->getTable()->getMyModel());
}

void Controller::avoidSearch() const{
    //std:cout<<"In inplementazione..."<<endl;
    //view->getCatalog()->getRicercaProdotto()->show();
}
