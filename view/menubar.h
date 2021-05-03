#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>
#include <QAction>

class MenuBar:public QMenuBar{
    Q_OBJECT
private:
    QMenu *menu;
    QAction *load;
    QAction *save;
    QAction *catalog;
    QAction *addProduct;
    QAction *carrello;
public:
    explicit MenuBar(QWidget * = nullptr);
    QAction *getCarrello();
};

#endif // MENUBAR_H
