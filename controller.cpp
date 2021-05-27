#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent){}

void Controller::setView(MainWindow *v){
    view=v;

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
    connect(view->getCatalog()->getTypeCombobox(), SIGNAL(currentIndexChanged(const QString &)), this, SLOT(changeType(const QString &)));
    connect(view->getCatalog()->getSearchEdit(), SIGNAL(textChanged(const QString &)),this,SLOT(search()));
    connect(view->getCatalog()->getSearchEdit(), SIGNAL(returnPressed()),this,SLOT(search()));
    connect(view->getCatalog()->getDetailsCombobox(), SIGNAL(currentIndexChanged(const QString &)), this, SLOT(setCurrectColumnFpm(const QString &)));
    //connect(view->getCatalog()->getBtnSearch(),SIGNAL(clicked()),this,SLOT(showSearch()));  //connessione per bottone in Catalogo per mostrare la view di Ricerca
    //connect(view->getCatalog()->getRicercaProdotto()->getSearchButton(),SIGNAL(clicked()),this,SLOT(showSearch())); //connessione per il bottone Cerca in Ricerca
    //connect(view->getCatalog()->getRicercaProdotto()->getAnnullaButton(),SIGNAL(clicked()),this,SLOT(avoidSearch()));
    //connect(view->getCatalog()->getRicercaProdotto()->getRitornaButton(),SIGNAL(clicked()),this,SLOT(hideSearch()));//connessione per il bottone Annulla in Ricerca, che nasconde la scheda
    //connect(view->getCatalog()->getBtnSee(),SIGNAL(clicked()),this,SLOT(seeTableItem()));   //connessione per bottone Visualizza in Catalogo per visualizzare la tabella.
    connect(view->getCatalog()->getTable()->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(enableBtnTableController()));  //connessione per bottone Visualizza prodotto nella parte inferiore
    connect(view->getCatalog()->getBtnRemove(),SIGNAL(clicked()),this,SLOT(removeItem()));

    //Ricerca
    //connect(view->getCatalog()->getRicercaProdotto()->getSearchButton(), SIGNAL(clicked()), this, SLOT(showSearchTable())); //connessione per mostrare i risultati della ricerca sottoforma di tabella

    //Visualizza dettagli
    connect(view->getCatalog()->getBtnViewItem(),SIGNAL(clicked()),this,SLOT(showDetails())); //connessione per mostrare un oggetto in dettaglio

    //Modifica prodotto
    connect(view->getCatalog()->getBtnModifiy(),SIGNAL(clicked()),this,SLOT(modificaProdotto())); //connessione per il bottone Modifica in catalogo, che apre una finestra di modifica dell'oggetto selezionato dalla tabella.
}

void Controller::setModel(Model *m){ model = m; }

Model* Controller::getModel() const{return model;}

void Controller::showCatalogo() const{
    view->getCatalog()->show();
   // view->getCatalog()->showSearch();
    /*view->getCatalog()->getTable()->hide();
    view->getCatalog()->getBtnModifiy()->hide();
    view->getCatalog()->getBtnViewItem()->hide();
    view->getCatalog()->getBtnRemove()->hide();*/
    view->getAddProduct()->hide();
}

void Controller::showAddProduct() const{
    //view->getCatalog()->getRicercaProdotto()->hide();
    view->getCatalog()->hide();    
    view->getAddProduct()->show();
}

void Controller::insertItemController(WaffleBox* wb){
    model->addBox(wb);  //Aggiunge al model dell'applicazione dopo aver preso i dati dalla view
    view->getCatalog()->getTable()->getMyModel()->setWBToinsert(wb);    //Aggiorna l'oggetto da inserire nel model della tabella, perchè è stato appena inserito
    view->getCatalog()->getTable()->getMyModel()->insertRows(view->getCatalog()->getTable()->getMyModel()->rowCount(), 1);  //Inserisce la riga per il nuovo oggetto, partendo dall'ultima riga inserita.
    view->insertItemInfo(); //Stampa finestra di successo
}

void Controller::changeType(const QString & tipo){
    std::cout<<"Tipo cambiato"<<tipo.toStdString()<<endl;
    view->getCatalog()->getFpm()->setItemType(tipo);
    emit view->getCatalog()->getSearchEdit()->returnPressed();
}

void Controller::search() const{
    //view->getCatalog()->getFpm()->setSearchType(fieldNameComboBox->currentText());
    view->getCatalog()->getFpm()->setDetailsToSearch(view->getCatalog()->getSearchEdit()->text());
    view->getCatalog()->getFpm()->setFilterRegExp(QRegExp(view->getCatalog()->getSearchEdit()->text(), Qt::CaseInsensitive, QRegExp::Wildcard));
}

void Controller::modifyItemController(WaffleBox* wb){
    //Aggiorno l'oggetto nel modello dell'applicazione
    model->updateItem(view->getCatalog()->getTable()->selectionModel()->currentIndex().row(), wb);
    //Aggiorno il model della vista (in Catalog e Ricerca)
    view->getCatalog()->getTable()->getMyModel()->getModel()->updateItem(view->getCatalog()->getTable()->selectionModel()->currentIndex().row(), wb);
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
    //view->getCatalog()->getRicercaProdotto()->show();
    //view->getCatalog()->showSearch();
}

void Controller::hideSearch() const{
   // view->getCatalog()->getRicercaProdotto()->hide();
    //view->getCatalog()->showSearch();
}

void Controller::seeTableItem() const{
    view->getCatalog()->getTable()->show();
    view->getCatalog()->getBtnModifiy()->show();
    view->getCatalog()->getBtnViewItem()->show();
    view->getCatalog()->getBtnRemove()->show();
    view->enableBtnTable(false);
    view->seeInfo();
}

void Controller::showDetails(){
    const QModelIndexList selection = view->getCatalog()->getTable()->selectionModel()->selectedIndexes();
    if(selection.size()>0){
        details *d=new details(nullptr, view->getCatalog()->getTm()->getItemByIndex(view->getCatalog()->getFpm()->getIndexByQIndex(selection.at(0))));
        d->setAttribute(Qt::WA_DeleteOnClose);
        d->show();
    }else{
        QMessageBox::warning(nullptr, "Attenzione", "Selezionare una riga per vedere in dettaglio un prodotto!", QMessageBox::Ok);
    }
}

void Controller::modificaProdotto(){
    const QModelIndexList selection = view->getCatalog()->getTable()->selectionModel()->selectedIndexes();
    if(selection.size()>0){
        modifyProduct *mp=new modifyProduct(nullptr, view->getCatalog()->getTm()->getItemByIndex(view->getCatalog()->getFpm()->getIndexByQIndex(selection.at(0))));
        mp->setAttribute(Qt::WA_DeleteOnClose);
        connect(mp->getModifyPhotoButton(),SIGNAL(clicked()),mp,SLOT(changePhoto()));
        connect(mp->getOkButton(),SIGNAL(clicked()),mp,SLOT(modifica()));
        connect(mp->getCancelButton(),SIGNAL(clicked()),mp,SLOT(noModify()));
        mp->show(); //prendo l'oggetto modificato dalla tabella //aggiungo la riga aggiornata
    }else{
         QMessageBox::warning(nullptr, "Attenzione", "Selezionare una riga per procedere con la modifica!", QMessageBox::Ok);
    }

}

void Controller::enableBtnTableController(){ view->enableBtnTable(true); }

void Controller::disableBtnTableController(){ view->enableBtnTable(false); }

void Controller::removeItem(){
    const QModelIndexList selection = view->getCatalog()->getTable()->selectionModel()->selectedIndexes();
    if(selection.size()>0){
        if(QMessageBox::question(nullptr, "Attenzione", "Sei sicuro di voler eliminare questo prodotto?", QMessageBox::Yes, QMessageBox::No)==QMessageBox::Yes){
            //ELIMINAZIONE DALLA TABELLA
            view->getCatalog()->getFpm()->removeRows(selection.at(0).row(), 1);
            QMessageBox::information(nullptr, "Messaggio", "Eliminazione effettuata con successo", QMessageBox::Ok);
        }else{
            QMessageBox::warning(nullptr, "Attenzione", "Operazione annullata", QMessageBox::Ok);
        }
    }else{
        QMessageBox::warning(nullptr, "Attenzione", "Selezionare una riga per procedere con l'eliminazione!", QMessageBox::Ok);
    }
}

void Controller::setCurrectColumnFpm(const QString &a) const{
    if(a.toStdString()=="ID"){
        view->getCatalog()->getFpm()->setColumnCount(0);
    }else{
        if (a.toStdString()=="Nome") {
            view->getCatalog()->getFpm()->setColumnCount(2);
        } else {
            if (a.toStdString()=="Capacità") {
                view->getCatalog()->getFpm()->setColumnCount(3);
            } else {
                if (a.toStdString()=="Peso") {
                    view->getCatalog()->getFpm()->setColumnCount(4);
                } else {
                    if(a.toStdString()=="Prezzo"){
                        view->getCatalog()->getFpm()->setColumnCount(5);
                    }else{
                         view->getCatalog()->getFpm()->setColumnCount(6);
                    }
                }
            }
        }
    }
}

void Controller::refreshSearchTable(){
    /*if(view->getCatalog()->getRicercaProdotto()->getTable()->getMyModel()->getModel()->getSize() != 0){ //Se il modello di TableModel della tabella in ricerca non è vuoto
        //Rimuovo tutte le righe perchè in costruzione il modello è uguale al principale presente in Catalog.
        view->getCatalog()->getRicercaProdotto()->getTable()->getMyModel()->removeRows(0, view->getCatalog()->getRicercaProdotto()->getTable()->getMyModel()->rowCount());
        //Rimuovo tutti gli oggetti presenti nel modello presente in Ricerca.
        for(u_int i = 0; i<  view->getCatalog()->getRicercaProdotto()->getTable()->getMyModel()->getModel()->getSize(); ++i){
            view->getCatalog()->getRicercaProdotto()->getTable()->getMyModel()->getModel()->removeBox(i);
        }
    }*/
}

void Controller::showSearchTable(){
    refreshSearchTable(); //Metodo per resettare la tabella come se fosse vuota
    /*for(u_int i=0; i<model->getSize(); ++i){
        if(model->getItem(i)->getID() == view->getCatalog()->getRicercaProdotto()->getIdLine()->text().toStdString() ||
           model->getItem(i)->getName() == view->getCatalog()->getRicercaProdotto()->getNameLine()->text().toStdString()  ||
           model->getItem(i)->getItemType() == view->getCatalog()->getRicercaProdotto()->getItemTypeComboBox()->currentText().toStdString() ||
           model->getItem(i)->getCapacity() == view->getCatalog()->getRicercaProdotto()->getCapacityLine()->text().toUInt()  ||
           model->getItem(i)->getPrice() == view->getCatalog()->getRicercaProdotto()->getPriceLine()->text().toDouble()){

            view->getCatalog()->getRicercaProdotto()->getTable()->getMyModel()->setWBToinsert(model->getItem(i)); //Setto l'oggetto da inserire nel modello della tabella per l'inserimento come riga

            view->getCatalog()->getRicercaProdotto()->getTable()->getMyModel()->insertRows(view->getCatalog()->getRicercaProdotto()->getTable()->getMyModel()->rowCount(), 1); //Aggiungo la riga con l'oggetto filtrato
        }
    }
    if(view->getCatalog()->getRicercaProdotto()->getTable()->getMyModel()->getModel()->getSize() != 0)
        view->getCatalog()->getRicercaProdotto()->getTable()->show();
    else
        QMessageBox::information(nullptr, "Sorry", "Non è stato trovato nessun prodotto con le caratteristiche inserite", QMessageBox::Ok);
        */
}

void Controller::avoidSearch() const{
    //if(QMessageBox::question(nullptr, "Attenzione", "Annullare la ricerca?", QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes)
       // view->getCatalog()->getRicercaProdotto()->resetField();
}
