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

    QComboBox *itemComboBox;
    QLabel *imgLabel,*tipoLabel,*nomeLabel,*idLabel,*nPezziLabel,*prezzoLabel;
    QPushButton *addPhoto,*addButton,*cancelButton;
    QLineEdit *nomeLine,*idLine,*npezziLine,*prezzoLine;
public:
    explicit addproduct(QWidget * = nullptr);
    QPushButton* getAdd();
};

#endif // ADDPRODUCT_H
