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
int TableModel::rowCount(const QModelIndex&) const{return model->getSize();}

//Metodo che ritorna il numero di colonne (attributi del WaffleBox)
int TableModel::columnCount(const QModelIndex&) const{return 6;} //7 con la foto e senza gli specifici

//Metodo che ritorna uno degli attributi di un WaffleBox
QVariant TableModel::data(const QModelIndex &modelIndex, int role) const{
    if(role != Qt::DisplayRole) return QVariant(); //Qt::DisplayRole è una costante == 0, indica che i dati vengono presi in QString
    switch(modelIndex.column()){
    case 0: return QString::fromStdString(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getID()); //getItem() ritorna l'obj ad un determinato indice
            break;
    case 1: return QString::fromStdString(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getName());
            break;
    case 2: return model->getItem(static_cast<unsigned int>(modelIndex.row()))->getCapacity();
            break;
    case 3: return model->getItem(static_cast<unsigned int>(modelIndex.row()))->getWeight();
            break;
    case 4: if(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getDiscount() != 0){
                return (QString::number(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getRealPrice()))
                        + QString(" €")
                        + QString(" (-")
                        + QString::number(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getDiscount()) + QString("%)");
            }else{
                return QString::number(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getPrice()) + QString(" €");
            }
            break;
    case 5: return model->getItem(static_cast<unsigned int>(modelIndex.row()))->getStockAvailability();
            break;
    //CASI SPECIFICI
    /*case 7: if(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getItemType() == "CircleBox")
                return QString::number(static_cast<CircleBox*>(model->getItem(static_cast<unsigned int>(modelIndex.row())))->getRadius()) + QString(" mm");
            break;
    case 8: //Ci sono 5 casi --> Ventaglio, Cannolo, Cono, Cono ricoperto, Cono brandizzato
        if(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getItemType() == "VentaglioBox")
            return static_cast<VentaglioBox*>(model->getItem(static_cast<unsigned int>(modelIndex.row())))->getHeight() + QString(" mm");
        if(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getItemType() == "CannoloBox")
            return static_cast<CannoloBox*>(model->getItem(static_cast<unsigned int>(modelIndex.row())))->getHeight()+ QString(" mm");
        if(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getItemType() == "ConeBox")
            return static_cast<ConeBox*>(model->getItem(static_cast<unsigned int>(modelIndex.row())))->getHeight()+ QString(" mm");
        if(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getItemType() == "CoveredBox")
            return static_cast<Covered*>(model->getItem(static_cast<unsigned int>(modelIndex.row())))->getHeight()+ QString(" mm");
        if(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getItemType() == "BrandedBox")
            return static_cast<Branded*>(model->getItem(static_cast<unsigned int>(modelIndex.row())))->getHeight()+ QString(" mm");
        return QString("Non disponibile");
            break;
    case 9: if(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getItemType() == "VentaglioBox")
                return static_cast<VentaglioBox*>(model->getItem(static_cast<unsigned int>(modelIndex.row())))->getWidth()+ QString(" mm");
            break;
    case 10: if(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getItemType() == "CannoloBox")
                return static_cast<CannoloBox*>(model->getItem(static_cast<unsigned int>(modelIndex.row())))->getIntDiameter()+ QString(" mm");
             break;
    case 11: //Ci sono 3 casi --> Cono, Cono ricoperto, Cono brandizzato
             if(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getItemType() == "ConeBox")
                return static_cast<ConeBox*>(model->getItem(static_cast<unsigned int>(modelIndex.row())))->getExtDiameter()+ QString(" mm");
             if(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getItemType() == "CoveredBox")
                return static_cast<Covered*>(model->getItem(static_cast<unsigned int>(modelIndex.row())))->getExtDiameter()+ QString(" mm");
             if(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getItemType() == "BrandedBox")
                return static_cast<Branded*>(model->getItem(static_cast<unsigned int>(modelIndex.row())))->getExtDiameter()+ QString(" mm");
             break;
    case 12: if(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getItemType() == "CoveredBox")
                return QString::fromStdString(static_cast<Covered*>(model->getItem(static_cast<unsigned int>(modelIndex.row())))->getTaste());
             break;
    case 13: if(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getItemType() == "BrandedBox")
                return QString::fromStdString(static_cast<Branded*>(model->getItem(static_cast<unsigned int>(modelIndex.row())))->getPrincipalColor());
             break;
    case 14: if(model->getItem(static_cast<unsigned int>(modelIndex.row()))->getItemType() == "BrandedBox")
                return QString::fromStdString(static_cast<Branded*>(model->getItem(static_cast<unsigned int>(modelIndex.row())))->getSecundaryColor());
             break;*/
    //Ho definito le colonne
    default: return QVariant();
    }
    return QVariant();
}

//Metodo 
QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if(role != Qt::DisplayRole) return QVariant();
    if(orientation == Qt::Horizontal){
        switch(section){
        case 0: return QString("ID");
                break;
        case 1: return QString("Nome");
                break;
        case 2: return QString("Capacità");
                break;
        case 3: return QString("Peso");
                break;
        case 4: return QString("Prezzo");
                break;
        case 5: return QString("Disponibilità");
                break;
        /*case 7: return QString("Raggio");
                break;
        case 8: return QString("Altezza");
                break;
        case 9: return QString("Larghezza");
                break;
        case 10: return QString("Diametro interno");
                break;
        case 11: return QString("Diametro esterno");
                break;
        case 12: return QString("Gusto");
                break;
        case 13: return QString("Colore principale");
                break;
        case 14: return QString("Colore secondario");
                break;*/
        default: return QVariant();
                break;
        }
    }
    return QVariant();
}

//Metodo per inserire n righe nella tabella dopo la riga afterRow
bool TableModel::insertRows(int afterRow, int n, const QModelIndex &modelIndex){
    beginInsertRows(modelIndex,afterRow,(afterRow+n-1));
    model->addBox(wbToInsert);
    endInsertRows();
    return true;
}

//Metodo per rimuovere n righe dalla tabella dopo la riga afterRow
bool TableModel::removeRows(int startRow, int n, const QModelIndex &modelIndex){
    beginRemoveRows(modelIndex,startRow,(startRow+n-1));
    //model->removeBox(static_cast<unsigned int>(startRow));
    endRemoveRows();
    return true;
}

void TableModel::setWBToinsert(WaffleBox* wb){ wbToInsert = wb; }
