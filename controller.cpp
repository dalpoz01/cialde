#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent){

}

void Controller::setView(MainWindow *m){ view=m; }

/*void Controller::setModel(Model *m){ model=m}*/
