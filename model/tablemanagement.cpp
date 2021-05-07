#include "tablemanagement.h"

TableManagement::TableManagement(QObject *parent,const std::string& path, const std::string& file) :
    QAbstractTableModel(parent),
    model(new Model(path,file)) {

    model->loadXMl();
}

TableManagement::~TableManagement() {
    if(model)
        delete model;
}

int TableManagement::rowCount(const QModelIndex&) const{return model->getSize();}

int TableManagement::columnCount(const QModelIndex&) const{return 12;}

QVariant TableManagement::data(const QModelIndex &modelIndex, int role) const{
    if(role != Qt::DisplayRole) return QVariant();
    switch(modelIndex.column())
}
