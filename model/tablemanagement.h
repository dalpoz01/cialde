#ifndef TABLEMANAGEMENT_H
#define TABLEMANAGEMENT_H
#include<QAbstractTableModel>
#include"model.h"
class TableManagement : public QAbstractTableModel{
private:
    std::string path;
    std::string fileName;
    Model* model;
public:
    TableManagement(QObject * = nullptr,const std::string& = "../cialde-test/Data/Xml/", const std::string& = "product.xml");
    ~TableManagement();

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& = QModelIndex()) const override;
    QVariant data(const QModelIndex&, int = Qt::DisplayRole) const override;
    QVariant headerData(int, Qt::Orientation, int) const override;
};

#endif // TABLEMANAGEMENT_H
