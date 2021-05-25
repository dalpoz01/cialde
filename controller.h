#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QModelIndexList>
#include <QString>
#include <QItemSelectionModel>
#include "view/mainwindow.h"
#include "model/model.h"
#include "model/container.h"
#include "view/details.h"
#include "view/modifyproduct.h"

class MainWindow;

class Controller : public QObject
{
    Q_OBJECT
private:
    MainWindow *view;
    Model *model;
public:
    explicit Controller(QObject *parent = nullptr);
    void setView(MainWindow*);
    void setModel(Model*);
    Model *getModel() const;
    void refreshSearchTable();

public slots:
    //Menubar
    void showCatalogo() const;
    void showAddProduct() const;
    void loadingXmlController();
    void savingXmlController();

    //Aggiungi prodotto
    void insertItemController(WaffleBox*); //Inserisce un nuovo oggetto nel modello e nella tabella, dopo aver preso i dati dalla vista

    //Catalogo
    void showSearch() const;
    void hideSearch() const;
    void avoidSearch() const;
    void seeTableItem() const;  //Visualizza o meno la tabella e i suoi bottoni in Catalogo
    void enableBtnTableController();
    void disableBtnTableController();
    void removeItem();

    //Ricerca
    void showSearchTable();

    //Visualizza dettagli
    void showDetails(); //Visualizza la finestra con un oggetto preselezionato da tabella in dettaglio

    //Modifica
    void modificaProdotto();    //Visualizza la finestra per modificare un oggetto preseleionato in tabella
    void modifyItemController(WaffleBox*); //Aggiorna il modello e la vista per una modifica effettuata




};

#endif // CONTROLLER_H
