#include "mainwindow.h"
#include "controller.h"

MainWindow::MainWindow(QWidget *parent):
    QWidget(parent),
    menu(new MenuBar(this)),
    catalogo(new catalog(this)),
    aggiungiProdotto(new AddProduct(this)),
    modificaProdotto(new modifyProduct(this))
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

    QVBoxLayout* qv=new QVBoxLayout();

    qv->setMenuBar(menu);
    qv->addWidget(catalogo);
    qv->addWidget(aggiungiProdotto);
    qv->addWidget(modificaProdotto);

    aggiungiProdotto->hide();
    modificaProdotto->hide();

    setLayout(qv);

}

QSize MainWindow::sizeHint() const {return QSize(1024, 468);}

void MainWindow::setController(Controller *c){controller=c;}

AddProduct* MainWindow::getAddProduct() const{return aggiungiProdotto;}

void MainWindow::insertItemInfo(){QMessageBox::information(this,"DONE IT!", "Inserimento avvenuto con successo");}

void MainWindow::loadingXmlInfo(){QMessageBox::information(this,"DONE IT!", "Caricamento avvenuto con successo");}

void MainWindow::savingXmlInfo(){QMessageBox::information(this,"DONE IT!", "XML creato con successo");}

void MainWindow::seeInfo(){catalogo->getTable()->show();}

catalog* MainWindow::getCatalog() const{return catalogo;}

modifyProduct* MainWindow::getModifyProduct() const{return modificaProdotto;}

MenuBar *MainWindow::getMenu() const{return menu;}

