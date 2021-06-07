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
    c.setModel(w.getTM()->getModel());
    c.setView(&w);
    w.setController(&c);
    w.show();
    return a.exec();
}
