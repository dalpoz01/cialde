#include "mainwindow.h"
#include "controller.h"

MainWindow::MainWindow(QWidget *parent):
    QWidget(parent),
    menu(new MenuBar(this)),
    aggiungiProdotto(new AddProduct(this)),
    tm(new TableModel(this)),
    fpm(new FilterProxyModel(this)),
    catalogo(new Catalog(this,tm,fpm))
{
    setWindowTitle("Wafflebox Store");
    setWindowIcon(QIcon(QPixmap("../cialde-test/Data/Photo/icon.png")));

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
    main->addWidget(catalogo);
    main->addWidget(aggiungiProdotto);

    setLayout(main);
}

QSize MainWindow::sizeHint() const { return QSize(1024, 500); }

void MainWindow::setController(Controller *c){ controller=c; }

AddProduct* MainWindow::getAddProduct() const { return aggiungiProdotto; }

Catalog* MainWindow::getCatalog() const { return catalogo; }

MenuBar *MainWindow::getMenu() const { return menu; }

TableModel* MainWindow::getTM() const { return tm; }

FilterProxyModel* MainWindow::getFPM() const { return fpm; }

void MainWindow::insertItemInfo() { QMessageBox::information(this,"DONE IT!", "Inserimento avvenuto con successo"); }

void MainWindow::loadingXmlInfo() { QMessageBox::information(this,"DONE IT!", "Caricamento avvenuto con successo"); }

void MainWindow::savingXmlInfo() { QMessageBox::information(this,"DONE IT!", "XML creato con successo"); }

void MainWindow::enableBtnTable(bool flag) {
    catalogo->getBtnModifiy()->setEnabled(flag);
    catalogo->getBtnViewItem()->setEnabled(flag);
    catalogo->getBtnRemove()->setEnabled(flag);
}

void MainWindow::closeEvent(QCloseEvent* event) {
    if(QMessageBox::question(this,"Sicuro?", "Salvare prima di uscire?", QMessageBox::Yes, QMessageBox::No, QMessageBox::Close) == QMessageBox::Yes){
        tm->getModel()->writeXml();
        event->accept();
    }
}
