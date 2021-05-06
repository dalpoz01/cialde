#include "mainwindow.h"
#include "controller.h"

MainWindow::MainWindow(QWidget *parent): QWidget(parent) ,menu(new MenuBar(this)), catalogo(new catalog(this)), aggiungiProdotto(new addproduct(this)), modificaProdotto(new modifyProduct(this)), ricercaProdotto(new SearchInventory(this)) {
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

    QVBoxLayout* qv=new QVBoxLayout;

    qv->setMenuBar(menu);
    menu->getCarrello()->setVisible(false);
    aggiungiProdotto->hide();
    catalogo->hide();
    qv->addWidget(ricercaProdotto);
    qv->addWidget(catalogo);
    qv->addWidget(aggiungiProdotto);
    qv->addWidget(modificaProdotto);

    //qv->addWidget(ricercaProdotto);

    setLayout(qv);

    connect(menu, SIGNAL(showCatalogSig()), this, SLOT(showCatalog()));
}
QSize MainWindow::sizeHint() const {
    return QSize(1024, 468);
}

void MainWindow::setController(Controller *c)
{
    controller=c;
}
void MainWindow::showAddProduct() const{
    aggiungiProdotto->show();
    catalogo->hide();
    modificaProdotto->hide();
}
void MainWindow::showCatalog() const{
    std::cout<<"Mostra catalogo"<<endl;
    aggiungiProdotto->hide();
    catalogo->show();
    modificaProdotto->hide();
}
void MainWindow::showModifyProduct() const{
    aggiungiProdotto->hide();
    catalogo->hide();
    modificaProdotto->show();
}
