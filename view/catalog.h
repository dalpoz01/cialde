#ifndef CATALOG_H
#define CATALOG_H

#include <QComboBox>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <QLineEdit>
#include <QRadioButton>
#include "view/table.h"
#include "model/tablemodel.h"
#include "model/filterproxymodel.h"

class catalog : public QWidget{
    Q_OBJECT
private:
    Table *table;
    QPushButton *btnModify;
    QPushButton *btnViewItem;
    QPushButton *btnRemove;
    QPushButton* btnBuy;
    QLineEdit *searchEdit;
    QComboBox *typeCombobox;
    QComboBox *detailsCombobox;
    TableModel *Tm;
    filterProxyModel *fpm;
    bool ord;
public:
    explicit catalog(QWidget * = nullptr, TableModel * = nullptr, filterProxyModel * = nullptr);
    QPushButton *getBtnModifiy() const;
    QPushButton *getBtnViewItem() const;
    QPushButton *getBtnRemove() const;
    Table *getTable() const;
    QComboBox *getTypeCombobox() const;
    QComboBox *getDetailsCombobox() const;
    QLineEdit *getSearchEdit() const;
    TableModel *getTm() const;
    filterProxyModel *getFpm() const;
    /*QRadioButton *getOrdAsc() const;
    QRadioButton *getOrdDesc() const;*/
    void sortHeaderClicked(int);
/*public slots:
    void setOrder();*/
    QPushButton *getBtnBuy() const;
};

#endif // CATALOG_H
