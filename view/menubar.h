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
    QAction* orderTab;

public:
    explicit MenuBar(QWidget * = nullptr);
    QAction* getLoad() const;
    QAction* getSave() const;
    QAction *getCatalog() const;
    QAction *getAddProduct() const;
    QAction *getOrderTab() const;


private slots:
    void loadXmlFile();
    void saveXmlFile();

signals:
    void signalToLoad() const;
    void signalToSave() const;
};

#endif // MENUBAR_H
