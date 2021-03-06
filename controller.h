#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QModelIndexList>
#include <QString>
#include <QItemSelectionModel>
#include <QInputDialog>
#include <QDateTime>
#include "view/mainwindow.h"
#include "model/model.h"
#include "model/container.h"
#include "view/details.h"
#include "view/modifyproduct.h"

class MainWindow;

class Controller : public QObject {
    Q_OBJECT
private:
    MainWindow *view;
    Model *model;
public:
    explicit Controller(QObject *parent = nullptr);
    void setView(MainWindow*);
    void setModel(Model*);
public slots:
    //Menubar
    void showCatalogo() const;      //slot per visualizzare la scheda catalogo e nascondere le altre
    void showAddProduct() const;    //slot per visualizzare la scheda aggiungi prodotto nascondendo le altre
    void loadingXmlController();    //slot che carica i dati da .xml
    void savingXmlController();     //slot che salva i dati in .xml

    //Aggiungi prodotto
    void existItem() const;
    void insertItemController(WaffleBox*); //Inserisce un nuovo oggetto nel modello e nella tabella, dopo aver preso i dati dalla vista

    //Catalogo
    void changeType(const QString &);
    void search() const;
    void removeItem();
    void setCurrectColumnFpm(const QString &) const;
    void headerClicked(int);
    void enableBtnBuy();

    //Visualizza dettagli
    void showDetails();         //Visualizza la finestra con un oggetto preselezionato da tabella in dettaglio

    //Modifica
    void modificaProdotto();    //Visualizza la finestra per modificare un oggetto preseleionato in tabella

    //Ordini
    void showOrdini();
    void enableOrder();
    void confirmOrder();
    void cancOrder();
};

#endif // CONTROLLER_H
