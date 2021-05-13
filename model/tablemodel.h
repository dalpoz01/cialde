#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include<QAbstractTableModel>
#include"model.h"

class TableModel : public QAbstractTableModel{
private:
    Model* model;
    WaffleBox* wbToInsert;

public:
    TableModel(QObject * = nullptr, const std::string& = "../cialde-test/Data/Xml/", const std::string& = "products.xml");
    ~TableModel();

    int rowCount(const QModelIndex& parent = QModelIndex()) const override; //Metodo di QAbstractTableModel che ritorna numero di righe per la view
    int columnCount(const QModelIndex& = QModelIndex()) const override; //Metodo di QAbstractTableModel che ritorna numero di colonne per la view
    QVariant data(const QModelIndex&, int = Qt::DisplayRole) const override; //Metodo di QAbstractTableModel che serve per rappresentare i dati nella cella
    QVariant headerData(int, Qt::Orientation, int) const override;  //Metodo di QAbstractTableModel che inserisce i giusti nomi nelle colonne della tabella
    bool insertRows(int, int, const QModelIndex&);  //Metodo di QAbstractTableModel che inserisce una riga sulla tabella
    bool removeRows(int, int, const QModelIndex&); //Metodo di QAbstractTableModel che rimuove una riga dalla tabella
};

#endif // TABLEMODEL_H
