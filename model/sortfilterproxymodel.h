#ifndef SORTFILTERPROXYMODEL_H
#define SORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include "model/wafflebox.h"

class SortFilterProxyModel: public QSortFilterProxyModel{
public:
    SortFilterProxyModel(QObject* = nullptr);
    unsigned int getIndexByQIndex(const QModelIndex &) const;
};

#endif // SORTFILTERPROXYMODEL_H
