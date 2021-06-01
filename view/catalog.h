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

class Catalog : public QWidget{
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
    FilterProxyModel *fpm;
    bool ord;  //Variabile booleana per gestire l'ordinamento della tabella. Se falsa ordina in modo crescente, altrimenti in ordine decrescente
public:
    explicit Catalog(QWidget * = nullptr, TableModel * = nullptr, FilterProxyModel * = nullptr);
    QPushButton *getBtnModifiy() const;
    QPushButton *getBtnViewItem() const;
    QPushButton *getBtnRemove() const;
    Table *getTable() const;
    QComboBox *getTypeCombobox() const;
    QComboBox *getDetailsCombobox() const;
    QLineEdit *getSearchEdit() const;
    TableModel *getTm() const;
    FilterProxyModel *getFpm() const;
    /*QRadioButton *getOrdAsc() const;
    QRadioButton *getOrdDesc() const;*/
/*public slots:
    void setOrder();*/
    QPushButton *getBtnBuy() const;
    void sortHeaderClicked(int); //Metodo per gestire l'ordinamento della tabella in base alla colonna cliccata
};

#endif // CATALOG_H
