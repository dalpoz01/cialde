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
class AddProduct;
using namespace std;


class MainWindow : public QWidget{
    Q_OBJECT
private:
    MenuBar *menu;
    catalog *catalogo;
    AddProduct* aggiungiProdotto;
    modifyProduct *modificaProdotto;
    TableModel* absModel;
    TableZone* tabella;
    Controller* controller;

public:
    explicit MainWindow(QWidget * = nullptr);
    ~MainWindow() override = default;
    virtual QSize sizeHint() const override;
    void setController(Controller *c);
    AddProduct* getAddProduct() const;
    catalog* getCatalog() const;
    modifyProduct* getModifyProduct() const;
    MenuBar *getMenu() const;
public slots:
      void insertItemInfo();
      void loadingXmlInfo();
      void savingXmlInfo();
      void seeInfo();

};

#endif // MAINWINDOW_H
