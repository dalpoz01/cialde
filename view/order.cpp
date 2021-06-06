#include "order.h"

Order::Order(QWidget *parent, FilterProxyModel* FPM) :
    QWidget(parent),
    tableProduct(new Table(this)),
    om(new OrdersModel(this)),
    mainFpm(FPM),
    title(new QLabel("Nuovo ordine",this)),
    cancelBtn(new QPushButton("Annulla",this)),
    emptyLabel(new QLabel("Nessun ordine..")),
    sendOrderBtn(new QPushButton("Invia ordine",this))

{
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    QVBoxLayout* tableLayout = new QVBoxLayout();
    QHBoxLayout* bottomLayout = new QHBoxLayout();

//    fpm->setSourceModel(om);
    tableProduct->setModel(om);

    tableLayout->addWidget(title);
    tableLayout->addWidget(tableProduct);
    bottomLayout->addWidget(sendOrderBtn);
    bottomLayout->addWidget(cancelBtn);
    tableLayout->addLayout(bottomLayout);

    mainLayout->addLayout(tableLayout);
}

Table* Order::getTableProduct() const{ return tableProduct; }

OrdersModel* Order::getOm() const { return om; }

FilterProxyModel* Order::getMainFpm() const { return mainFpm; }

QPushButton* Order::getCancBtn() const {return cancelBtn;}

QPushButton* Order::getSendOrderBtn() const {return sendOrderBtn;}
