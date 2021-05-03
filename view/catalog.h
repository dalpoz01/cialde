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
    QVBoxLayout *mainLayout;
    QComboBox *itemTypeCombobox;
    QPushButton *search;
    QLabel *imgLabel;
    QLabel *nome;
    QLabel *disponibilita;
    QLineEdit *editNome;
    QLineEdit *editDisponibilta;
    QPushButton *acquista;
    QPushButton *prec;
    QPushButton *succ;
    QFormLayout *formLayout;
public:
    explicit catalog(QWidget * = nullptr);
};

#endif // CATALOG_H
