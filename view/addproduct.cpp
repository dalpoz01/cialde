#include "addproduct.h"

addproduct::addproduct(QWidget(*parent)):QWidget(parent),

    itemComboBox(new QComboBox(this)),
    capacityBox(new QComboBox(this)),
    imgLabel(new QLabel(this)),
    tipoLabel(new QLabel("TIPO",this)),
    nomeLabel(new QLabel("NOME",this)),
    idLabel(new QLabel("ID",this)),
    nPezziLabel(new QLabel("NUMERO PEZZI",this)),
    prezzoLabel(new QLabel("PREZZO",this)),
    discountLabel(new QLabel("SCONTO", this)),
    stockLabel(new QLabel("STOCK",this)),
    addPhoto(new QPushButton("Aggiungi foto")),
    addButton(new QPushButton("Aggiungi")),
    cancelButton(new QPushButton("Annulla")),
    nomeLine(new QLineEdit(this)),
    idLine(new QLineEdit(this)),
    prezzoLine(new QLineEdit(this)),
    discountBox(new QSpinBox(this)),
    dim1Radio(new QRadioButton("50",this)),
    dim2Radio(new QRadioButton("100",this)),
    dim3Radio(new QRadioButton("150",this)),
    dim4Radio(new QRadioButton("200",this)),
    radiusLabel(new QLabel("Raggio (mm)",this)),
    radiusSpin(new QSpinBox(this)),
    heightLabel(new QLabel("Altezza",this)),
    heightLine(new QLineEdit(this)),
    widthLabel(new QLabel("Larghezza",this)),
    widthLine(new QLineEdit(this)),
    intdiamLabel(new QLabel("Diametro interno",this)),
    intdiamLine(new QLineEdit(this)),
    extdiamLabel(new QLabel("Diametro esterno",this)),
    extdiamLine(new QLineEdit(this)),
    prncolorLabel(new QLabel("Principale",this)),
    seccolorLabel(new QLabel("Secondario",this)),
    prncolorLine(new QLineEdit(this)),
    seccolorLine(new QLineEdit(this)),
    colorLabel(new QLabel("Colore",this)),
    tasteLabel(new QLabel("Gusto",this)),
    tasteLine(new QLineEdit(this))
{

    QHBoxLayout* base = new QHBoxLayout(this);
    QVBoxLayout* left = new QVBoxLayout();
    QVBoxLayout* right = new QVBoxLayout();
    QHBoxLayout* bottom_right = new QHBoxLayout();
    QHBoxLayout* radioLayoutUp = new QHBoxLayout();
    QHBoxLayout* radioLayoutDown = new QHBoxLayout();
    QVBoxLayout* radioLayout = new QVBoxLayout();
    QVBoxLayout* color1Layout = new QVBoxLayout();
    QVBoxLayout* color2Layout = new QVBoxLayout();
    QHBoxLayout* colorLayout = new QHBoxLayout();
    QFormLayout* form = new QFormLayout();

    createRadioLayout(radioLayoutDown, radioLayout, radioLayoutUp);

    color1Layout->addWidget(prncolorLabel);
    color1Layout->addWidget(prncolorLine);
    color2Layout->addWidget(seccolorLabel);
    color2Layout->addWidget(seccolorLine);
    colorLayout->addLayout(color1Layout);
    colorLayout->addLayout(color2Layout);

    itemComboBox->addItem(" - ");
    itemComboBox->addItem("Circle Box");
    itemComboBox->addItem("Ventaglio Box");
    itemComboBox->addItem("Cannolo Box");
    itemComboBox->addItem("Cone Box");
    itemComboBox->addItem("Covered Box");
    itemComboBox->addItem("Branded Box");

    for(u_int i = 0; i <= 300; i += 50) capacityBox->addItem(QString::number(i));

    prezzoLine->setValidator(new QDoubleValidator(0.00, 9999.00, 2, this));
    heightLine->setValidator((new QIntValidator(0, 200, this)));
    intdiamLine->setValidator(new QIntValidator(0, 10, this));
    intdiamLine->setValidator(new QIntValidator(0, 90, this));

    radiusSpin->setMaximum(10);

    form->addRow(tipoLabel,itemComboBox);
    form->addRow(nomeLabel,nomeLine);
    form->addRow(idLabel,idLine);
    form->addRow(nPezziLabel,capacityBox);
    form->addRow(prezzoLabel,prezzoLine);
    form->addRow(discountLabel,discountBox);
    form->addRow(stockLabel,radioLayout);
    form->addRow(radiusLabel,radiusSpin);
    form->addRow(heightLabel,heightLine);
    form->addRow(widthLabel,widthLine);
    form->addRow(intdiamLabel,intdiamLine);
    form->addRow(extdiamLabel,extdiamLine);
    form->addRow(colorLabel,colorLayout);
    form->addRow(tasteLabel,tasteLine);


    imgLabel->setPixmap(QPixmap(QString::fromStdString(":/MyRes/Photo/image-not-found.jpg")).scaled(QSize(400, 400)));
    left->addWidget(imgLabel);
    left->addWidget(addPhoto);
    right->addLayout(form);
    bottom_right->addWidget(addButton);
    bottom_right->addWidget(cancelButton);
    right->addLayout(bottom_right);

    base->addLayout(left);
    base->addLayout(right);

    showCommon();

    //Listener
    connect(itemComboBox,SIGNAL(currentIndexChanged(const QString&)),this,SLOT(showItemTypeField(const QString&)));
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(resetFields()));

}

QPushButton* addproduct::getAdd(){
    return addButton;
}

void addproduct::showCircle(bool flag) const{
    radiusLabel->setVisible(flag);
    radiusSpin->setVisible(flag);
}

void addproduct::showHeight(bool flag) const{
    heightLabel->setVisible(flag);
    heightLine->setVisible(flag);
}

void addproduct::showVentaglio(bool flag) const{
    widthLabel->setVisible(flag);
    widthLine->setVisible(flag);
}

void addproduct::showCannolo(bool flag) const{
    intdiamLabel->setVisible(flag);
    intdiamLine->setVisible(flag);
}

void addproduct::showCone(bool flag) const{
    extdiamLabel->setVisible(flag);
    extdiamLine->setVisible(flag);
}

void addproduct::showBranded(bool flag) const{
    prncolorLabel->setVisible(flag);
    seccolorLabel->setVisible(flag);
    prncolorLine->setVisible(flag);
    seccolorLine->setVisible(flag);
    colorLabel->setVisible(flag);
}

void addproduct::showCovered(bool flag) const{
    tasteLabel->setVisible(flag);
    tasteLine->setVisible(flag);
}

void addproduct::showCommon() const{
    showCircle(false);
    showHeight(false);
    showVentaglio(false);
    showCannolo(false);
    showCone(false);
    showCovered(false);
    showBranded(false);
}


void addproduct::createRadioLayout(QHBoxLayout* radioLayoutDown, QVBoxLayout* radioLayout, QHBoxLayout* radioLayoutUp)
{
    radioLayoutUp->addWidget(dim1Radio);
    radioLayoutUp->addWidget(dim2Radio);
    radioLayoutDown->addWidget(dim3Radio);
    radioLayoutDown->addWidget(dim4Radio);
    radioLayout->addLayout(radioLayoutUp);
    radioLayout->addLayout(radioLayoutDown);
}

void addproduct::resetCommon() const{
    itemComboBox->setCurrentIndex(0);
    capacityBox->setCurrentIndex(0);
    nomeLine->setText(" ");
    idLine->setText(" ");
    prezzoLine->setText(" ");
    dim1Radio->setChecked(false);
    dim2Radio->setChecked(false);
    dim3Radio->setCheckable(false);
    dim3Radio->setChecked(false);
}


void addproduct::resetCircle() const{
    radiusSpin->setValue(0);
}

void addproduct::resetHeight() const{
    heightLine->setText(" ");
}

void addproduct::resetVentaglio() const{
    widthLine->setText(" ");
}

void addproduct::resetCannolo() const{

    intdiamLine->setText(" ");
}

void addproduct::resetCone() const{

    extdiamLine->setText(" ");
}

void addproduct::resetBranded() const{

    prncolorLine->setText(" ");
    seccolorLine->setText(" ");
}

void addproduct::resetCovered() const{

    tasteLine->setText(" ");
}

void addproduct::resetFields(){

    if(QMessageBox::question(this, "Attenzione" ,"Vuoi annullare l'inserimento e resettare i campi?", QMessageBox::Ok, QMessageBox::Close) == QMessageBox::Ok){
            resetCommon();
            resetCircle();
            resetHeight();
            resetVentaglio();
            resetCannolo();
            resetCone();
            resetBranded();
            resetCovered();
            showCommon();
     }
}

void addproduct::showItemTypeField(const QString& selection) const{

    if(selection == " - "){

        showCircle(false);
        showHeight(false);
        showVentaglio(false);
        showCannolo(false);
        showCone(false);
        showCovered(false);
        showBranded(false);

    }else if(selection == "Circle Box"){

        showCircle(true);
        showVentaglio(false);
        showCannolo(false);
        showCone(false);
        showCovered(false);
        showBranded(false);

    }else if(selection =="Ventaglio Box"){

        showCircle(false);
        showHeight(false);
        showVentaglio(true);
        showCannolo(false);
        showCone(false);
        showCovered(false);
        showBranded(false);

    }else if(selection == "Cannolo Box"){

        showCircle(false);
        showHeight(false);
        showVentaglio(false);
        showCannolo(true);
        showCone(false);
        showCovered(false);
        showBranded(false);

    }else if(selection  == "Cone Box"){

        showCircle(true);
        showHeight(false);
        showVentaglio(false);
        showCannolo(false);
        showCone(true);
        showCovered(false);
        showBranded(false);

    }else if(selection == "Covered Box"){

        showCircle(true);
        showHeight(false);
        showVentaglio(false);
        showCannolo(false);
        showCone(true);
        showCovered(true);
        showBranded(false);

    }else if(selection == "Branded Box"){

        showCircle(true);
        showVentaglio(false);
        showCannolo(false);
        showCone(true);
        showCovered(false);
        showBranded(true);
    }
}
