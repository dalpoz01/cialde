#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDesktopWidget>
#include <QApplication>
#include "view/menubar.h"
#include "view/catalog.h"
#include "view/addproduct.h"
#include "view/modifyproduct.h"
#include "view/searchinventory.h"
#include "view/tablezone.h"
#include "model/tablemodel.h"

class Controller;
using namespace std;


class MainWindow : public QWidget{
    Q_OBJECT
private:
    MenuBar *menu;
    catalog *catalogo;
    addproduct *aggiungiProdotto;
    modifyProduct *modificaProdotto;
    SearchInventory* ricercaProdotto;

   /* TableModel* absModel;
    TableZone* tabella;*/

    Controller *controller;

public:
    explicit MainWindow(QWidget * = nullptr);
    ~MainWindow() override = default;
    virtual QSize sizeHint() const override;
    void setController(Controller *c);
    void showAddProduct() const;
    void showCatalog() const;
    void showModifyProduct() const;

    MenuBar *getMenu() const;
};

#endif // MAINWINDOW_H
