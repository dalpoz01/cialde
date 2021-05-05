#ifndef MODIFYPRODUCT_H
#define MODIFYPRODUCT_H

#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class modifyProduct : public QWidget{
    Q_OBJECT
private:
    QVBoxLayout *mainLayout;
    QLineEdit *editNameProduct;
    QComboBox *itemTypeCombobox;
    QPushButton *search;
    QLabel *imgLabel;
public:
    explicit modifyProduct(QWidget * = nullptr);
};

#endif // MODIFYPRODUCT_H
