#include "filterproxymodel.h"
#include "tablemodel.h"

//Costruttore
TableModel::TableModel(QObject *parent, const std::string& path, const std::string& file) :
    QAbstractTableModel(parent),
    model(new Model(path,file)) {

    model->loadXml();   //Carico i dati da Xml
}

//Distruttore
TableModel::~TableModel() {
    if(model)
        delete model;
}

//Metodo che ritorna la dimensione del model, cioè il numero di righe della tabella
int TableModel::rowCount(const QModelIndex&) const { return model->getSize(); }

//Metodo che ritorna il numero di colonne (attributi del WaffleBox)
int TableModel::columnCount(const QModelIndex&) const { return 7; } //7 con la foto e senza gli specifici

//Metodo che ritorna uno degli attributi di un WaffleBox
QVariant TableModel::data(const QModelIndex &modelIndex, int role) const {
    if(role != Qt::DisplayRole) return QVariant(); //Qt::DisplayRole è una costante == 0, indica che i dati vengono presi in QString
    switch(modelIndex.column()){
        case 0: return QString::fromStdString(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getID()); //getItem() ritorna l'obj ad un determinato indice
                break;
        case 1: return QString::fromStdString(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getItemType());
                break;
        case 2: return QString::fromStdString(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getName());
                break;
        case 3: return model->getItem(static_cast<unsigned int>(modelIndex.row()))->getCapacity();
                break;
        case 4: return model->getItem(static_cast<unsigned int>(modelIndex.row()))->getWeight();
                break;
        case 5: if(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getDiscount() != 0){
                    return (QString::number(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getRealPrice()))
                            + QString(" €")
                            + QString(" (-")
                            + QString::number(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getDiscount()) + QString("%)");
                }else{
                    return QString::number(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getPrice()) + QString(" €");
                }
                break;
        case 6: return model->getItem(static_cast<unsigned int>(modelIndex.row()))->getStockAvailability();
                break;
        //Ho definito le colonne
        default: return QVariant();
    }
    return QVariant();
}

//Metodo per definire le colonne della tabella
QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role != Qt::DisplayRole) return QVariant();
    if(orientation == Qt::Horizontal){
        switch(section){
        case 0: return QString("ID");
                break;
        case 1: return QString("Tipo");
                break;
        case 2: return QString("Nome");
                break;
        case 3: return QString("Capacità");
                break;
        case 4: return QString("Peso");
                break;
        case 5: return QString("Prezzo");
                break;
        case 6: return QString("Disponibilità");
                break;
        default: return QVariant();
                break;
        }
    }
    return QVariant();
}

//Metodo per inserire n righe nella tabella dopo la riga afterRow
bool TableModel::insertRows(int afterRow, int n, const QModelIndex &modelIndex) {
    beginInsertRows(modelIndex,afterRow,(afterRow+n-1));
    model->addBox(wbToInsert);
    endInsertRows();
    return true;
}

//Metodo per rimuovere n righe dalla tabella dopo la riga afterRow
bool TableModel::removeRows(int startRow, int n, const QModelIndex &modelIndex) {
    beginRemoveRows(modelIndex,startRow,(startRow+n-1));
    model->removeBox(startRow);
    endRemoveRows();
    return true;
}

void TableModel::setWBToinsert(WaffleBox* wb) { wbToInsert = wb; }

WaffleBox* TableModel::getWbToInsert() const { return wbToInsert; }

WaffleBox* TableModel::getItemByIndex(unsigned int index) const { return model->getItem(index); }

Model* TableModel::getModel() const { return model; }

void TableModel::setModel(Model *value) { model = value; }
