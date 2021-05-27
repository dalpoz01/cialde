#include "filterproxymodel.h"

filterProxyModel::filterProxyModel(QObject *parent):
    QSortFilterProxyModel(parent),
    itemType("Tutti"),
    columnCount(0)
{
}

void filterProxyModel::setItemType(const QString &value){ itemType = value; }

void filterProxyModel::setColumnCount(int value){ columnCount = value; }

unsigned int filterProxyModel::getIndexByQIndex(const QModelIndex &i) const {
    QModelIndex index = mapToSource(i);
    return static_cast<unsigned int>(index.row());
}

bool filterProxyModel::filterAcceptsRow(int sr, const QModelIndex &sp) const {
    QModelIndex fieldDataModelIndex = sourceModel()->index(sr, columnCount, sp);
    QModelIndex itemTypeModelIndex = sourceModel()->index(sr, 1, sp);
    QString fieldDataString = sourceModel()->data(fieldDataModelIndex).toString();
    QString itemTypeString = sourceModel()->data(itemTypeModelIndex).toString();
    QString DetailsToSearchTemp = detailsToSearch;
    QRegExp itemToSearch;
    if(itemType!="Tutti"){
        itemToSearch = QRegExp(itemType, Qt::CaseInsensitive, QRegExp::Wildcard);
    }else{
        itemToSearch = QRegExp();
    }
    return (fieldDataString.contains(QRegExp(DetailsToSearchTemp, Qt::CaseInsensitive, QRegExp::Wildcard)) && itemTypeString.contains(itemToSearch));
}

void filterProxyModel::setDetailsToSearch(const QString &value) { detailsToSearch = value; }
