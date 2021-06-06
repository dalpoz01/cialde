#ifndef ORDER_H
#define ORDER_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "view/table.h"
#include "model/model.h"
#include "model/ordersmodel.h"
#include "model/tablemodel.h"
#include "model/filterproxymodel.h"
#include "model/wafflebox.h"
#include "model/deepptr.h"
#include "model/container.h"

class Order : public QWidget {
    Q_OBJECT
private:

    Table* tableProduct;
    OrdersModel* om;
    FilterProxyModel *mainFpm;

    QLabel* title;
    QPushButton* cancelBtn;
    QLabel* emptyLabel;
    QPushButton* sendOrderBtn;



public:
    explicit Order(QWidget *parent = nullptr, FilterProxyModel* = nullptr);

    Table* getTableProduct() const;
    OrdersModel* getOm() const;
    FilterProxyModel *getMainFpm() const;
    QPushButton* getCancBtn() const;
    QPushButton* getSendOrderBtn() const;


signals:

public slots:
};

#endif // ORDER_H
