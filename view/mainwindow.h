#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDesktopWidget>
#include <QApplication>
#include <QCloseEvent>
#include "view/menubar.h"
#include "view/catalog.h"
#include "view/addproduct.h"
#include "view/modifyproduct.h"
#include "view/table.h"
#include "view/order.h"
#include "model/tablemodel.h"
#include "model/filterproxymodel.h"

class Controller;
class AddProduct;

class MainWindow : public QWidget{
    Q_OBJECT
private:
    MenuBar *menu;
    AddProduct* aggiungiProdotto;
    Controller* controller;
    TableModel *tm;
    FilterProxyModel *fpm;
    Catalog *catalogo;
    Order* ordini;
public:
    explicit MainWindow(QWidget * = nullptr);
    ~MainWindow() override = default;
    virtual QSize sizeHint() const override;
    void setController(Controller *);
    AddProduct* getAddProduct() const;
    Catalog* getCatalog() const;
    MenuBar *getMenu() const;
    TableModel* getTM() const;
    FilterProxyModel* getFPM() const;
    Order* getOrder() const;
public slots:
    virtual void closeEvent(QCloseEvent*) override; //Chiusura finestra
};

#endif // MAINWINDOW_H
