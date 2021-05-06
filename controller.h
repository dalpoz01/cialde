#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "view/mainwindow.h"

class Controller : public QObject
{
    Q_OBJECT
private:
    MainWindow *view;
    /*Manca collegamento al Model e metodo setModel
    Model *model;*/
public:
    explicit Controller(QObject *parent = nullptr);
    void setView(MainWindow* m);
    /*void setModel(Model *m);*/
signals:

public slots:

};

#endif // CONTROLLER_H
