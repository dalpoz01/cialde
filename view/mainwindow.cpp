#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QWidget(parent),
    menu(new MenuBar(this)){
    setWindowTitle("Cialde Pro");

    QVBoxLayout* qv=new QVBoxLayout;
    qv->addWidget(menu);

    setLayout(qv);
}
