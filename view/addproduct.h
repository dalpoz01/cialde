#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H

#include <QComboBox>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <QLineEdit>

class addproduct : public QWidget{
    Q_OBJECT
private:
    QHBoxLayout *base;
    QVBoxLayout *left,*right;
    QComboBox *item;
    QLabel *imgLabel,*tipo,*nome,*id,*nPezzi,*prezzo;
    QPushButton *addPhoto,*add,*cancel;
    QLineEdit *editNome,*editID,*editNPezzi,*editPrezzo;
public:
    explicit addproduct(QWidget * = nullptr);
};

#endif // ADDPRODUCT_H
