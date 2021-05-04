#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QWidget(parent),
    menu(new MenuBar(this)),
    catalogo(new catalog(this)),
    aggiungiProdotto(new addproduct(this))
{
    setWindowTitle("Cialde Pro");
    //Centro la finestra sullo schermo
    QSize size = sizeHint();
    QDesktopWidget* desktop = QApplication::desktop();
    int width = desktop->width();
    int height = desktop->height();
    int mw = size.width();
    int mh = size.height();
    int centerW = (width/2) - (mw/2);
    int centerH = (height/2) - (mh/2);
    move(centerW, centerH);

    QHBoxLayout* qv=new QHBoxLayout;
    menu->getCarrello()->setVisible(false);
    qv->setMenuBar(menu);
    catalogo->hide();
    qv->addWidget(catalogo);
    qv->addWidget(aggiungiProdotto);

    setLayout(qv);
}
QSize MainWindow::sizeHint() const {
    return QSize(1024, 468);
}
