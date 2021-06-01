#include "ordersmodel.h"

//Costruttore
OrdersModel::OrdersModel(QObject *parent) :
    QAbstractTableModel(parent),
    model(new Model("","",0)),
    quantity(new Container<u_int>()) {}

//Distruttore
OrdersModel::~OrdersModel() {
    if(model)
        delete model;
}

//Metodo che ritorna la dimensione del model, cioè il numero di righe della tabella
int OrdersModel::rowCount(const QModelIndex&) const{return model->getSize();}

//Metodo che ritorna il numero di colonne (attributi del WaffleBox)
int OrdersModel::columnCount(const QModelIndex&) const{return 5;}

//Metodo che ritorna uno degli attributi di un WaffleBox
QVariant OrdersModel::data(const QModelIndex &modelIndex, int role) const{
if(model->getItem(0) != nullptr){
    if(role != Qt::DisplayRole) return QVariant(); //Qt::DisplayRole è una costante == 0, indica che i dati vengono presi in QString
    switch(modelIndex.column()){
        case 0: return QString::fromStdString(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getID()); //getItem() ritorna l'obj ad un determinato indice
                break;
        case 1: return QString::fromStdString(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getName());
                break;
        case 2: return QString::number(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getCapacity());
                break;
        case 3: if(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getDiscount() != 0){
                    return (QString::number(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getRealPrice()))
                            + QString(" €")
                            + QString(" (-")
                            + QString::number(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getDiscount()) + QString("%)");
                }else{
                    return QString::number(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getPrice()) + QString(" €");
                }
                break;
    case 4: return QString::number(quantity->operator [](modelIndex.row()));
                break;

        default: return QVariant();
     }
}
    return QVariant();
}

//Metodo
QVariant OrdersModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if(role != Qt::DisplayRole) return QVariant();
    if(orientation == Qt::Horizontal){
        switch(section){
        case 0: return QString("ID");
                break;
        case 1: return QString("Nome");
                break;
        case 2: return QString("Capacità");
                break;
        case 3: return QString("Prezzo");
                break;
        case 4: return QString("Quantità");
                break;
        default: return QVariant();
                break;
        }
    }
    return QVariant();
}

//Metodo per inserire n righe nella tabella dopo la riga afterRow
bool OrdersModel::insertRows(int afterRow, int n, const QModelIndex &modelIndex){
    beginInsertRows(modelIndex,afterRow,(afterRow+n-1));
    model->addBox(wbToInsert);
    endInsertRows();
    return true;
}

//Metodo per rimuovere n righe dalla tabella dopo la riga afterRow
bool OrdersModel::removeRows(int startRow, int n, const QModelIndex &modelIndex){
    beginRemoveRows(modelIndex,startRow,(startRow+n-1));
    model->removeBox(startRow);
    //model->removeBox(static_cast<unsigned int>(startRow));
    endRemoveRows();
    return true;
}

void OrdersModel::setWBToinsert(WaffleBox* wb){ wbToInsert = wb; }

WaffleBox* OrdersModel::getWbToInsert() const { return wbToInsert;}

WaffleBox* OrdersModel::getItemByIndex(u_int index) const{ return model->getItem(index); }

Model* OrdersModel::getModel() const{ return model;}

Container<u_int>* OrdersModel::getQuantity() const{ return quantity; }

void OrdersModel::setModel(Model *value){ model = value; }

void OrdersModel::clearQuantity(){ quantity->clear();}
