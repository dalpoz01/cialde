#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "view/mainwindow.h"
#include "model/model.h"
#include "model/container.h"


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
    Model* getModel() const;
public slots:
    void showCatalogo() const;
    void showAddProduct() const;
    void showModProduct() const;
    void showSearch() const;
    void hideSearch() const;
    void seeItems() const;
    void avoidSearch() const;
    void insertItemController(WaffleBox*);
    void loadingXmlController();
    void savingXmlController();
};

#endif // CONTROLLER_H
