#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>

class MenuBar:public QMenuBar{
    Q_OBJECT
private:
    QMenu *menu;
    QAction *load;
    QAction *save;
    QAction *catalog;
    QAction *addProduct;
    QAction *modProduct;
    QAction *carrello;
    QAction *showCatalog;
    QAction *showAddProduct;
    QAction *showModProduct;
    QAction *showCarrello;
public:
    explicit MenuBar(QWidget * = nullptr);
    QAction *getCarrello();
signals:
    void showCatalogSig() const;
    void showAddProductSig() const;
    void showModProductSig() const;
    void showCarrelloSig() const;
};

#endif // MENUBAR_H
