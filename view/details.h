#ifndef DETAILS_H
#define DETAILS_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QDesktopWidget>
#include <QApplication>
#include <QSize>

#include "model/wafflebox.h"
#include "model/branded.h"
#include "model/cannolobox.h"
#include "model/circlebox.h"
#include "model/conebox.h"
#include "model/covered.h"
#include "model/heightproviderbox.h"
#include "model/ventagliobox.h"

class details: public QWidget{
private:
    WaffleBox  *w;
    //Etichetta valori comuni
    QLabel *imgLabel;
    QLabel *tipoLabel;
    QLabel *nomeLabel;
    QLabel *idLabel;
    QLabel *nPezziLabel;
    QLabel *prezzoLabel;
    QLabel *discountLabel;
    QLabel *stockLabel;
    //Valori comuni
    QLabel *tipoValueLabel;
    QLabel *nomeValueLabel;
    QLabel *idValueLabel;
    QLabel *nPezziValueLabel;
    QLabel *prezzoValueLabel;
    QLabel *discountValueLabel;
    QLabel *stockValueLabel;
    //Branded
    QLabel *principalColorLabel;
    QLabel *secondaryColorLabel;
    QLabel *principalColorValueLabel;
    QLabel *secondaryColorValueLabel;
    //CannoloBox
    QLabel *intDiameterLabel;
    QLabel *intDiameterValueLabel;
    //CircleBox
    QLabel *radiusLabel;
    QLabel *radiusValueLabel;
    //Conebox
    QLabel *externalRadiusLabel;
    QLabel *externalRadiusValueLabel;
    //Covered
    QLabel *tasteLabel;
    QLabel *tasteValueLabel;
    //VentaglioBox
    QLabel *widthLabel;
    QLabel *widthValueLabel;

    QPushButton *cancelButton;

    static std::string doubleToString(double); //Metodo per convertire double in stringa con precisione prefissata
public:

    explicit details(QWidget * = nullptr, WaffleBox * = nullptr);
    virtual QSize sizeHint() const override;

};

#endif // DETAILS_H
