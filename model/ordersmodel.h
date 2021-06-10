#ifndef ORDERSMODEL_H
#define ORDERSMODEL_H

#include <QAbstractTableModel>
#include <QPushButton>
#include "model.h"
#include "model/wafflebox.h"

class OrdersModel : public QAbstractTableModel {
private:
    Model* model;
    WaffleBox* wbToInsert;
    Container<unsigned int>* quantity; //tengo conto del moltiplicatore

public:
    OrdersModel(QObject * = nullptr);
    ~OrdersModel();

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;     //Metodo di QAbstractTableModel che ritorna numero di righe per la view
    int columnCount(const QModelIndex& = QModelIndex()) const override;         //Metodo di QAbstractTableModel che ritorna numero di colonne per la view
    QVariant data(const QModelIndex&, int = Qt::DisplayRole) const override;    //Metodo di QAbstractTableModel che serve per rappresentare i dati nella cella
    QVariant headerData(int, Qt::Orientation, int) const override;              //Metodo di QAbstractTableModel che inserisce i giusti nomi nelle colonne della tabella
    bool insertRows(int, int = 1, const QModelIndex& = QModelIndex()) override; //Metodo di QAbstractTableModel che inserisce una riga sulla tabella
    bool removeRows(int, int = 1, const QModelIndex& = QModelIndex()) override; //Metodo di QAbstractTableModel che rimuove una riga dalla tabella

    void setWBToinsert(WaffleBox*);
    WaffleBox* getWbToInsert() const;
    WaffleBox* getItemByIndex(unsigned int) const;
    Model* getModel() const;
    void setModel(Model *);
    Container<unsigned int>* getQuantity() const;
    double getTotPrice() const;
};

#endif // ORDERSMODEL_H
