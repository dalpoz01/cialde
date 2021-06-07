#include "mainwindow.h"
#include "controller.h"

MainWindow::MainWindow(QWidget *parent):
    QWidget(parent),
    menu(new MenuBar(this)),
    aggiungiProdotto(new AddProduct(this)),
    tm(new TableModel(this)),
    fpm(new FilterProxyModel(this)),
    catalogo(new Catalog(this,tm,fpm)),
    ordini(new Order(this))
{
    setWindowTitle("Wafflebox Store");
    setWindowIcon(QIcon(QPixmap(":/MyRes/Photo/icon.png")));

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

    QHBoxLayout* main=new QHBoxLayout(this);

    main->setMenuBar(menu);
    aggiungiProdotto->hide();
    ordini->hide();
    main->addWidget(catalogo);
    main->addWidget(aggiungiProdotto);
    main->addWidget(ordini);

    setLayout(main);
}

QSize MainWindow::sizeHint() const { return QSize(1024, 500); }

void MainWindow::setController(Controller *c) { controller=c; }

AddProduct* MainWindow::getAddProduct() const { return aggiungiProdotto; }

Catalog* MainWindow::getCatalog() const { return catalogo; }

MenuBar *MainWindow::getMenu() const { return menu; }

TableModel* MainWindow::getTM() const { return tm; }

Order* MainWindow::getOrder() const { return ordini; }

FilterProxyModel* MainWindow::getFPM() const { return fpm; }

void MainWindow::closeEvent(QCloseEvent* event) {
    if(QMessageBox::question(this,"Sicuro?", "Salvare prima di uscire?", QMessageBox::Yes, QMessageBox::No, QMessageBox::Close) == QMessageBox::Yes){
        tm->getModel()->writeXml();
        event->accept();
    }
}
