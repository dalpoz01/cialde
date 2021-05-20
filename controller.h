#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QModelIndexList>
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
public slots:
    void showCatalogo() const;
    void showAddProduct() const;
    void showSearch() const;
    void hideSearch() const;
    void seeTableItem() const;
    void showDetails();
    void modificaProdotto();
    void avoidSearch() const;
    void insertItemController(WaffleBox*);
    void loadingXmlController();
    void savingXmlController();
    void enableBtnTableController();
    void disableBtnTableController();
    void removeItem();
};

#endif // CONTROLLER_H
