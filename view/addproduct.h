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
#include <QSpinBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QMessageBox>

#include "model/wafflebox.h"
#include "model/circlebox.h"
#include "model/ventagliobox.h"
#include "model/heightproviderbox.h"
#include "model/cannolobox.h"
#include "model/conebox.h"
#include "model/branded.h"
#include "model/covered.h"
#include "controller.h"

class AddProduct : public QWidget{
    Q_OBJECT
private:
    //Common Field
    QComboBox *itemComboBox, *capacityBox;
    QLabel *imgLabel;
    QLabel *tipoLabel;
    QLabel *nomeLabel;
    QLabel *idLabel;
    QLabel *nPezziLabel;
    QLabel *prezzoLabel;
    QLabel *discountLabel;
    QLabel *stockLabel;
    QPushButton *addPhoto;
    QPushButton *addButton;
    QPushButton*cancelButton;
    QLineEdit *nomeLine;
    QLineEdit *idLine;
    QLineEdit *prezzoLine;
    QSpinBox *discountBox;
    QRadioButton *dim1Radio;
    QRadioButton *dim2Radio;
    QRadioButton *dim3Radio;
    QRadioButton *dim4Radio;
    QLabel *radiusLabel; //Circle Field
    QSpinBox *radiusSpin;
    QLabel *heightLabel; //Height Field
    QLineEdit *heightLine;
    QLabel *widthLabel; //Ventaglio Field
    QLineEdit *widthLine;
    QLabel *intdiamLabel; //Cannolo Field
    QLineEdit *intdiamLine; 
    QLabel *extdiamLabel; //Cone Field
    QLineEdit *extdiamLine;
    QLabel *prncolorLabel;  //Branded Field
    QLabel *seccolorLabel;
    QLineEdit *prncolorLine;
    QLineEdit *seccolorLine;
    QLabel *colorLabel;
    QLabel *tasteLabel; //Covered Field
    QLineEdit *tasteLine;

    void showCircle(bool) const; //Metodo per mostrare o meno i campi per determinato tipo
    void showHeight(bool) const;
    void showVentaglio(bool) const;
    void showCannolo(bool) const;
    void showCone(bool) const;
    void showBranded(bool) const;
    void showCovered(bool) const;
    void showCommon() const;
    void createRadioLayout(QHBoxLayout* radioLayoutDown, QVBoxLayout* radioLayout, QHBoxLayout* radioLayoutUp);

    void resetCommon() const;
    void resetCircle() const;
    void resetHeight() const;
    void resetVentaglio() const;
    void resetCannolo() const;
    void resetCone() const;
    void resetBranded() const;
    void resetCovered() const;
public:
    explicit AddProduct(QWidget * = nullptr);
    QPushButton* getAdd();
    void enableFields(bool) const;
    
private slots:
    void resetFields();    //Metodo per resettare a " " tutti i campi.
    void showItemTypeField(const QString&) const;
    void insert();    //Metodo che crea un oggetto in base ai campi inseriti

signals:
    void signalToInsert(WaffleBox*) const;

};

#endif // ADDPRODUCT_H
