#ifndef MODIFYPRODUCT_H
#define MODIFYPRODUCT_H

#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QWidget>
#include <QDesktopWidget>
#include <QSize>
#include <QPixmap>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <sstream>
#include <iomanip>
#include <iostream>

#include "model/wafflebox.h"
#include "model/branded.h"
#include "model/cannolobox.h"
#include "model/circlebox.h"
#include "model/conebox.h"
#include "model/covered.h"
#include "model/heightproviderbox.h"
#include "model/ventagliobox.h"

class modifyProduct : public QWidget{
    Q_OBJECT
private:
    std::string imgpath;
    WaffleBox  *w;
    //Etichetta valori comuni
    QLabel *imgLabel;
    QLabel *tipoLabel;
    QLabel *tipoValueEdit;
    QLabel *nomeLabel;
    QLabel *idLabel;
    QLabel *nPezziLabel;
    QLabel *weightLabel;
    QLabel *prezzoLabel;
    QLabel *discountLabel;
    QLabel *stockLabel;
    //Valori comuni
    QLineEdit *nomeValueEdit;
    QLineEdit *idValueEdit;
    QLineEdit *nPezziValueEdit;
    QLineEdit *weightEdit;
    QLineEdit *prezzoValueEdit;
    QLineEdit *discountValueEdit;
    QLineEdit *stockValueEdit;
    //Branded
    QLabel *principalColorLabel;
    QLabel *secondaryColorLabel;
    QLineEdit *principalColorValueEdit;
    QLineEdit *secondaryColorValueEdit;
    //CannoloBox
    QLabel *intDiameterLabel;
    QLineEdit *intDiameterValueEdit;
    //CircleBox
    QLabel *radiusLabel;
    QLineEdit *radiusValueEdit;
    //Conebox
    QLabel *externalRadiusLabel;
    QLineEdit *externalRadiusValueEdit;
    //Covered
    QLabel *tasteLabel;
    QLineEdit *tasteValueEdit;
    //VentaglioBox
    QLabel *widthLabel;
    QLineEdit *widthValueEdit;

    QPushButton *cancelButton;
    QPushButton *modifyPhotoButton;
    QPushButton *okButton;

    static std::string doubleToString(double); //Metodo per convertire double in stringa con precisione prefissata
public:
    explicit modifyProduct(QWidget * = nullptr, WaffleBox * = nullptr);
    virtual QSize sizeHint() const override;

    QPushButton *getCancelButton() const;
    QPushButton *getModifyPhotoButton() const;
    QPushButton *getOkButton() const;
    WaffleBox* getWaffleBox() const;

public slots:
    void modifica();    //slot per modificare un oggetto, avvisa
    void changePhoto();
    void noModify();
signals:
    void signalToModify(WaffleBox*) const;
};

#endif // MODIFYPRODUCT_H
