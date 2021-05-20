#include "sortfilterproxymodel.h"

SortFilterProxyModel::SortFilterProxyModel(QObject *parent):QSortFilterProxyModel(parent){

}
unsigned int SortFilterProxyModel::getIndexByQIndex(const QModelIndex & qm) const{
    QModelIndex index = mapToSource(qm);
    return static_cast<unsigned int>(index.row());
}
