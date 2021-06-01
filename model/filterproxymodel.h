#ifndef FILTERPROXYMODEL_H
#define FILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QString>
#include <iostream>
using namespace std;

class FilterProxyModel : public QSortFilterProxyModel{
private:
    QString itemType;
    QString detailsToSearch;
    int columnCount;
public:
    FilterProxyModel(QObject* = nullptr);
    void setColumnCount(int);
    void setItemType(const QString &);
    unsigned int getIndexByQIndex(const QModelIndex &) const;
    bool filterAcceptsRow(int sr, const QModelIndex &sp) const;
    void setDetailsToSearch(const QString &);
};

#endif // FILTERPROXYMODEL_H
