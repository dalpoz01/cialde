#include <QApplication>
#include "view/mainwindow.h"
#include "controller.h"
#include "model/model.h"
#include "model/xmlmanagement.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Controller c;
    Model* m = new Model();

    m->loadXMl();
    c.setModel(m);

    c.setView(&w);
    w.setController(&c);
    w.show();

    return a.exec();
}
