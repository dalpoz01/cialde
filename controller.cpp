#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent){}

void Controller::setView(MainWindow *v){
    view=v;

    //Menu
    connect(view->getMenu()->getCatalog(),SIGNAL(triggered()),this,SLOT(showCatalogo()));   //connessione per visualizzare Catalogo selezionando la voce dal menubar
    connect(view->getMenu()->getAddProduct(),SIGNAL(triggered()),this,SLOT(showAddProduct()));  //connessione per visualizzare Aggiungi prodotto selezionando la voce dal menubar
    connect(view->getMenu()->getLoad(),SIGNAL(triggered()),this,SLOT(loadingXmlController()));  //connessione per caricare i dati da un file.xml selezionando la voce dal menubar
    connect(view->getMenu()->getSave(),SIGNAL(triggered()),this,SLOT(savingXmlController()));   //connessione per salvare i dati in un file.xml selezionando la voce dal menubar
    connect(view->getMenu()->getOrderTab(),SIGNAL(triggered()),this,SLOT(showOrdini()));   //connessione per visualizzare Ordini selezionando la voce dal menubar

    //Aggiungi Prodotto
    connect(view->getAddProduct()->getItemCombo(),SIGNAL(currentIndexChanged(const QString&)),view->getAddProduct(),SLOT(showItemTypeField(const QString&))); //connessione alla QComboBox del tipo di box da inserire, per visualizzare i campi corretti
    connect(view->getAddProduct()->getCancel(),SIGNAL(clicked()),view->getAddProduct(),SLOT(resetFields())); //connessione per bottone Cancella, che resetta i campi di inserimento
    connect(view->getAddProduct()->getAddPhoto(),SIGNAL(clicked()),view->getAddProduct(),SLOT(addFoto()));  //connessione per bottone Aggiungi foto, che inserisce una foto al prodotto
    connect(view->getAddProduct()->getAdd(),SIGNAL(clicked()),this,SLOT(existItem())); //Connessione per bottone Aggiungi, richiama il metodo insert() che preleva i dati dai campi e crea l'oggetto
    connect(view->getAddProduct(),SIGNAL(signalToInsert(WaffleBox*)),this,SLOT(insertItemController(WaffleBox*))); //Connessione per il segnale emesso da insert(), se l'inserimento avviene correttamente lo aggiunge al container

    //Catalogo
    connect(view->getCatalog()->getTypeCombobox(), SIGNAL(currentIndexChanged(const QString &)), this, SLOT(changeType(const QString &)));
    connect(view->getCatalog()->getSearchEdit(), SIGNAL(textChanged(const QString &)),this,SLOT(search()));
    connect(view->getCatalog()->getSearchEdit(), SIGNAL(returnPressed()),this,SLOT(search()));
    connect(view->getCatalog()->getDetailsCombobox(), SIGNAL(currentIndexChanged(const QString &)), this, SLOT(setCurrectColumnFpm(const QString &)));
    //connect(view->getCatalog()->getTable()->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(enableBtnTableController()));  //connessione per bottone Visualizza prodotto nella parte inferiore
    connect(view->getCatalog()->getBtnRemove(),SIGNAL(clicked()),this,SLOT(removeItem()));
    connect(view->getCatalog()->getTable()->getHeader(),SIGNAL(sectionClicked(int)),this,SLOT(headerClicked(int)));
    connect(view->getCatalog()->getTable()->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(enableBtnBuy())); //Attiva il bottone di acquisto
    connect(view->getCatalog()->getBtnBuy(),SIGNAL(clicked()), this, SLOT(enableOrder()));  //attiva la tab sul menubar dell'ordine


    //Visualizza dettagli
    connect(view->getCatalog()->getBtnViewItem(),SIGNAL(clicked()),this,SLOT(showDetails())); //connessione per mostrare un oggetto in dettaglio

    //Modifica prodotto
    connect(view->getCatalog()->getBtnModifiy(),SIGNAL(clicked()),this,SLOT(modificaProdotto())); //connessione per il bottone Modifica in catalogo, che apre una finestra di modifica dell'oggetto selezionato dalla tabella.

    //Ordini
    connect(view->getOrder()->getSendOrderBtn(),SIGNAL(clicked()),this, SLOT(confirmOrder()));
    //connect(view->getOrder()->getCancBtn(),SIGNAL(clicked()),);

}

void Controller::setModel(Model *m){ model = m; }

Model* Controller::getModel() const{return model;}

void Controller::showCatalogo() const{
    view->getAddProduct()->hide();
    view->getOrder()->hide();
    view->getCatalog()->show();
}

void Controller::showAddProduct() const{
    view->getCatalog()->hide();
    view->getOrder()->hide();
    view->getAddProduct()->show();
}

void Controller::existItem() const{
    if(model->findItem(view->getAddProduct()->getIdLineString())==true){
        QMessageBox::warning(nullptr, "Attenzione", "Tipo di WaffleBox già esistente con questo ID, si consiglia di cambiare ID", QMessageBox::Ok);
    }else{
        view->getAddProduct()->insert();
    }
}

void Controller::showOrdini(){
    view->getCatalog()->hide();
    view->getAddProduct()->hide();
    view->getOrder()->show();

}

void Controller::insertItemController(WaffleBox* wb){
    view->getTM()->setWBToinsert(wb); //Setto obj da inserire nel TableModel della vista, che verrà passato alla scheda catalogo
    view->getTM()->insertRows(view->getTM()->rowCount(), 1);    //inserisco l'obj nel TableModel, la vista lo notificherà aggiornandosi aggiungendo una riga in più
    view->insertItemInfo(); //Stampa finestra di successo
}

void Controller::changeType(const QString & tipo){
    view->getCatalog()->getFpm()->setItemType(tipo);
    emit view->getCatalog()->getSearchEdit()->returnPressed();
}

void Controller::search() const{
    view->getCatalog()->getFpm()->setDetailsToSearch(view->getCatalog()->getSearchEdit()->text());
    view->getCatalog()->getFpm()->setFilterRegExp(QRegExp(view->getCatalog()->getSearchEdit()->text(), Qt::CaseInsensitive, QRegExp::Wildcard));
}

void Controller::loadingXmlController(){
    view->getTM()->getModel()->loadXml();
    view->getFPM()->setSourceModel(view->getTM());
    view->getCatalog()->getTable()->setModel(view->getFPM());
    view->loadingXmlInfo();
}

void Controller::savingXmlController(){
    view->getTM()->getModel()->writeXml();
    view->savingXmlInfo();
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

void Controller::headerClicked(int n){ view->getCatalog()->sortHeaderClicked(n); }

void Controller::enableBtnBuy(){view->getCatalog()->getBtnBuy()->setEnabled(true);}

void Controller::enableOrder(){
    const QModelIndexList selection = view->getCatalog()->getTable()->selectionModel()->selectedIndexes();
    view->getMenu()->getOrderTab()->setVisible(true);
        if(selection.size()>0){
            if(view->getTM()->getModel()->getItem(view->getCatalog()->getFpm()->getIndexByQIndex(selection.at(0)))->getStockAvailability() == 1){
                if(QMessageBox::question(nullptr, "Attenzione", "Ultima rimanenza in magazzino! Continuare?", QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes){
//                    if(view->getOrder()->getOm()->getModel()->findItem(view->getTM()->getModel()->getItem(view->getCatalog()->getFpm()->getIndexByQIndex(selection.at(0)))->getID())){
//                          view->getTM()->getModel()->getItem(view->getCatalog()->getFpm()->getIndexByQIndex(selection.at(0)))->setStockAvailability(view->getTM()->getModel()->getItem(view->getCatalog()->getFpm()->getIndexByQIndex(selection.at(0)))->getStockAvailability()-1);
//                          view->getOrder()->getOm()->get
//                    }
                        view->getOrder()->getOm()->setWBToinsert(view->getTM()->getModel()->getItem(view->getCatalog()->getFpm()->getIndexByQIndex(selection.at(0))));
                        view->getOrder()->getOm()->insertRows(view->getOrder()->getOm()->rowCount(),1);
                        view->getCatalog()->getFpm()->removeRows(selection.at(0).row(), 1);
                        view->getOrder()->getOm()->getQuantity()->operator [](view->getOrder()->getOm()->rowCount())++;
                        QMessageBox::information(nullptr, "Messaggio", "Prodotto aggiunto all'ordine con successo", QMessageBox::Ok);
                }
            }else if(view->getTM()->getModel()->getItem(view->getCatalog()->getFpm()->getIndexByQIndex(selection.at(0)))->getStockAvailability() > 0){
                view->getOrder()->getOm()->getQuantity()->push_back(QInputDialog::getInt(nullptr, "Prima di procedere..", "Inserisci la quantità del prodotto selezionato: ", 0,1,view->getTM()->getModel()->getItem(view->getCatalog()->getFpm()->getIndexByQIndex(selection.at(0)))->getStockAvailability()));
                int count = view->getOrder()->getOm()->getQuantity()->operator [](view->getOrder()->getOm()->rowCount());
                view->getOrder()->getOm()->setWBToinsert(view->getTM()->getModel()->getItem(view->getCatalog()->getFpm()->getIndexByQIndex(selection.at(0))));
                view->getOrder()->getOm()->insertRows(view->getOrder()->getOm()->rowCount(),1);
                view->getTM()->getModel()->getItem(view->getCatalog()->getFpm()->getIndexByQIndex(selection.at(0)))->setStockAvailability(view->getTM()->getModel()->getItem(view->getCatalog()->getFpm()->getIndexByQIndex(selection.at(0)))->getStockAvailability() - count);
                QMessageBox::information(nullptr, "Messaggio", "Prodotto aggiunto all'ordine con successo", QMessageBox::Ok);
            }
        }else{
            QMessageBox::warning(nullptr, "Attenzione", "Selezionare una riga per procedere all'acquisto!", QMessageBox::Ok);
        }
}

void Controller::confirmOrder(){
    if(QMessageBox::question(nullptr, "Attenzione", "Sicuro di voler inoltrare l'ordine?", QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes){
        QMessageBox::information(nullptr, "Messaggio", "Stampato lo scontrino", QMessageBox::Ok);
    }
}
