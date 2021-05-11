#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "view/mainwindow.h"
#include "model/model.h"

class Controller : public QObject
{
    Q_OBJECT
private:
    MainWindow *view;
    Model *model;
public:
    explicit Controller(QObject *parent = nullptr);
    void setView(MainWindow* m);
    void setModel(Model *m);
public slots:
    void showCatalogo() const;
    void showAddProduct() const;
    void showModProduct() const;
    void Aggiungi() const;
};

#endif // CONTROLLER_H
