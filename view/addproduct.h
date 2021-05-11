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
    QLabel *imgLabel,*tipoLabel,*nomeLabel,*idLabel,*nPezziLabel,*prezzoLabel;
    QPushButton *addPhoto,*add,*cancel;
    QLineEdit *editNome,*editID,*editNPezzi,*editPrezzo;
public:
    explicit addproduct(QWidget * = nullptr);
    QPushButton* getAdd();
};

#endif // ADDPRODUCT_H
