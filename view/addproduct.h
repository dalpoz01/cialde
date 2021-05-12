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

class addproduct : public QWidget{
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

    //Circle Field
    QLabel *radiusLabel;
    QSpinBox *radiusSpin;

    //Height Field
    QLabel *heightLabel;
    QLineEdit *heightLine;

    //Ventaglio Field
    QLabel *widthLabel;
    QLineEdit *widthLine;


    //Cannolo Field
    QLabel *intdiamLabel;
    QLineEdit *intdiamLine;

    //Cone Field
    QLabel *extdiamLabel;
    QLineEdit *extdiamLine;

    //Branded Field
    QLabel *prncolorLabel;
    QLabel *seccolorLabel;
    QLineEdit *prncolorLine;
    QLineEdit *seccolorLine;
    QLabel *colorLabel;

    //Covered Field
    QLabel *tasteLabel;
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
    explicit addproduct(QWidget * = nullptr);
    QPushButton* getAdd();

private slots:
    void resetFields();    //Metodo per resettare a " " tutti i campi.
    void showItemTypeField(const QString&) const;
    void insert();
};

#endif // ADDPRODUCT_H
