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
    connect(addButton,SIGNAL(clicked()),this,SLOT(insert()));
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

void addproduct::insert(){
    WaffleBox* temp = nullptr;
    int typeIndex = itemComboBox->currentIndex();
    if(itemComboBox->currentText().toStdString() != " - " && nomeLine->text().toStdString() != " " && capacityBox->currentText().toUInt() != 0){
        //Creo attributi e assegno loro il valore presente nei campi

        std::string id = idLine->text().toStdString();
        u_int capa = capacityBox->currentText().toUInt();
        u_int peso = (capa)*(0.8);
        double prezzo = prezzoLine->text().toDouble();
        u_int disc = discountBox->text().toUInt();
        u_int stockAva;

        if(dim1Radio->isChecked())
            stockAva = dim1Radio->text().toUInt();
        else if(dim2Radio->isChecked())
            stockAva = dim2Radio->text().toUInt();
        else if(dim3Radio->isChecked())
            stockAva = dim3Radio->text().toUInt();
        else if(dim4Radio->isChecked())
            stockAva = dim4Radio->text().toUInt();

        u_int radius = 0;
        u_int height = 0;
        u_int width = 0;
        u_int intDiam = 0;
        u_int extDiam = 0;
        std::string princ = " ";
        std::string seco = " ";
        std::string taste = " ";

        switch(typeIndex){
        case 0: QMessageBox::critical(this,"Impossibile inserire!","Tipo Box mancante.", QMessageBox::Ok, QMessageBox::Close);  //Tipo item = " - ".
                break;
        case 1: radius = radiusSpin->text().toUInt(); //Tipo "Circle Box"
                temp = new CircleBox(id,capa,peso,prezzo,disc,stockAva,radius);
        case 2: height = heightLine->text().toUInt();
                width = widthLine->text().toUInt();   //Tipo "Ventaglio Box"
                temp = new VentaglioBox(id,capa,peso,prezzo,disc,stockAva,height,width);
        case 3: height = heightLine->text().toUInt();
                intDiam = intdiamLine->text().toUInt();   //Tipo "Cannolo Box"
                temp = new CannoloBox(id,capa,peso,prezzo,disc,stockAva,height,intDiam);
        case 4: height = heightLine->text().toUInt();
                extDiam = extdiamLine->text().toUInt();   //Tipo "Cone Box"
                temp = new ConeBox(id,capa,peso,prezzo,disc,stockAva,height,extDiam);
        case 5: if(tasteLine->text().toStdString() == " "){
                    if(QMessageBox::question(this,"Ops","Hai dimenticato il gusto! \nIntendevi un ConeBox senza gusto?", QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes){
                        height = heightLine->text().toUInt();
                        extDiam = extdiamLine->text().toUInt();   //Tipo "Cone Box"
                        temp = new ConeBox(id,capa,peso,prezzo,disc,stockAva,height,extDiam);
                    }
                }
                height = heightLine->text().toUInt();
                extDiam = extdiamLine->text().toUInt();
                taste = tasteLine->text().toStdString(); //Tipo "Covered Box"
                temp = new Covered(id,capa,peso,prezzo,disc,stockAva,height,extDiam,taste);
        case 6: height = heightLine->text().toUInt();
                extDiam = extdiamLine->text().toUInt();
                if((prncolorLine->text().toStdString() == " " || seccolorLine->text().toStdString() == " ") ||
                   (prncolorLine->text().toStdString() == " " && seccolorLine->text().toStdString() == " ")){
                    QMessageBox::warning(this,"Ops","Hai dimenticato uno o più colori! \nSe non inserisci un colore, verrà settato 'White' di default.", QMessageBox::Yes, QMessageBox::Close);
                }

                princ = (prncolorLine->text().toStdString() == " " ? "White" : prncolorLine->text().toStdString());
                seco = (seccolorLine->text().toStdString() == " " ? "White" : seccolorLine->text().toStdString());  //Tipo "Branded Box"
                temp = new Branded(id,capa,peso,prezzo,disc,stockAva,height,extDiam,princ,seco);

            }

    }else{
          QMessageBox::critical(this,"Errore","Campi essenziali errati o vuoti",QMessageBox::Ok);
    }

    if(temp)
        emit insertItemView(temp);  //Emetto segnale che indica al controller che ho l'oggetto pronto per essere inserito nel model
        delete temp;    //ELimino l'oggetto, non serve più.

}
