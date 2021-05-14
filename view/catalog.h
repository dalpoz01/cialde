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

class catalog : public QWidget{
    Q_OBJECT
private:
    QComboBox *itemTypeCombobox;
    QPushButton *search;
    QLabel *imgLabel;
    QLabel *nome;
    QLabel *disponibilita;
    QVBoxLayout *mainLayout;
    QComboBox *itemCombobox;
    QPushButton *btnSearch;
    QPushButton *btnSee;
    QPushButton *btnGo;
    QLabel *tipoLabel;
    QLabel *nomeLabel;
    QLineEdit *editNome;
    QFormLayout *formLayout;

public:
    explicit catalog(QWidget * = nullptr);
    void showSearch() const;
    QPushButton* getBtnSearch();
    virtual QSize sizeHint() const override;
};

#endif // CATALOG_H
