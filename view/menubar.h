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
public:
    explicit MenuBar(QWidget * = nullptr);
    QAction *getCarrello();
    QAction *getCatalog() const;
    QAction *getAddProduct() const;
    QAction *getModProduct() const;
};

#endif // MENUBAR_H
