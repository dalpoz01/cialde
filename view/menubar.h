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
    QAction *searchProduct;
public:
    explicit MenuBar(QWidget * = nullptr);
};

#endif // MENUBAR_H
