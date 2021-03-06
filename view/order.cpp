#include "order.h"

Order::Order(QWidget *parent) :
    QWidget(parent),
    tableProduct(new Table(this)),
    om(new OrdersModel(this)),
    title(new QLabel("Nuovo ordine",this)),
    cancelBtn(new QPushButton("Annulla",this)),
    sendOrderBtn(new QPushButton("Invia ordine",this))
{
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    QVBoxLayout* tableLayout = new QVBoxLayout();
    QHBoxLayout* bottomLayout = new QHBoxLayout();

    tableProduct->setModel(om);
    tableProduct->setSortingEnabled(false);

    tableLayout->addWidget(title);
    tableLayout->addWidget(tableProduct);
    bottomLayout->addWidget(sendOrderBtn);
    bottomLayout->addWidget(cancelBtn);
    tableLayout->addLayout(bottomLayout);

    mainLayout->addLayout(tableLayout);
}

Table* Order::getTableProduct() const { return tableProduct; }

OrdersModel* Order::getOm() const { return om; }

QPushButton* Order::getCancBtn() const { return cancelBtn; }

QPushButton* Order::getSendOrderBtn() const { return sendOrderBtn; }
