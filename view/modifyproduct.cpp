#include "modifyproduct.h"
#include <iostream>
using namespace std;

ModifyProduct::ModifyProduct(QWidget *parent, WaffleBox *wf) : QWidget(parent),
    w(wf)
{
    setWindowTitle("Wafflebox - Modifica prodotto");
    setWindowIcon(QIcon(QPixmap("../cialde-test/Data/Photo/icon.png")));

    //Centro la finestra sullo schermo
    QSize size = sizeHint();
    QDesktopWidget* desktop = QApplication::desktop();
    int width = desktop->width();
    int height = desktop->height();
    int mw = size.width();
    int mh = size.height();
    int centerW = (width/2) - (mw/2);
    int centerH = (height/2) - (mh/2);
    move(centerW, centerH);

    tipoLabel=new QLabel("Tipo: ",this);
    tipoValueEdit=new QLabel(QString::fromStdString(w->getItemType()));
    nomeLabel=new QLabel("Nome: ",this);
    idLabel=new QLabel("ID: ",this);
    nPezziLabel=new QLabel("Numero Pezzi: ",this);
    weightLabel=new QLabel("Weight: ",this);
    prezzoLabel=new QLabel("Prezzo: ",this);
    discountLabel=new QLabel("Sconto: ",this);
    stockLabel=new QLabel("Disponibilità: ",this);
    imgLabel=new QLabel(this);
    imgpath=w->getPhoto();
    //recupero l'immagine del prodotto e la visualizzo
    QPixmap qpm = QPixmap(QString::fromStdString(imgpath));
    if(!qpm.isNull()){
        imgLabel->setPixmap(qpm.scaled(QSize(400, 400)));
    }else{
        imgLabel->setText("IMMAGINE NON TROVATA");
        imgLabel->setMinimumSize(400,400);
        //imgLabel->setPixmap(QPixmap(QString::fromStdString("../cialde-test/Data/Photo/image-not-found.jpg")).scaled(QSize(400, 400)));
    }
    imgLabel->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);

    int maxSizeEdit=400;

    nomeValueEdit=new QLineEdit(QString::fromStdString(w->getName()),this);
    nomeValueEdit->setMaximumWidth(maxSizeEdit);
    idValueEdit=new QLineEdit(QString::fromStdString(w->getID()),this);
    idValueEdit->setMaximumWidth(maxSizeEdit);
    nPezziValueEdit=new QLineEdit(QString::fromStdString(std::to_string(w->getCapacity())), this);
    nPezziValueEdit->setMaximumWidth(maxSizeEdit);
    nPezziValueEdit->setValidator(new QIntValidator(50,500,this));
    weightEdit=new QLineEdit(QString::fromStdString(std::to_string(w->getWeight())), this);
    weightEdit->setMaximumWidth(maxSizeEdit);
    prezzoValueEdit=new QLineEdit(QString::fromStdString(doubleToString(w->getPrice())), this);
    prezzoValueEdit->setMaximumWidth(maxSizeEdit);
    prezzoValueEdit->setValidator(new QDoubleValidator(0.00, 9999.00, 2, this));
    discountValueEdit=new QLineEdit(QString::fromStdString(std::to_string(w->getDiscount())), this);
    discountValueEdit->setMaximumWidth(maxSizeEdit);
    stockValueEdit=new QLineEdit(QString::fromStdString(std::to_string(w->getStockAvailability())), this);
    stockValueEdit->setMaximumWidth(maxSizeEdit);

    QHBoxLayout *main=new QHBoxLayout(this);
    QVBoxLayout *left=new QVBoxLayout();
    QVBoxLayout *right=new QVBoxLayout();
    QHBoxLayout *button=new QHBoxLayout();
    QFormLayout *formLayout= new QFormLayout();

    formLayout->addRow(tipoLabel,tipoValueEdit);
    formLayout->addRow(nomeLabel,nomeValueEdit);
    formLayout->addRow(idLabel,idValueEdit);
    formLayout->addRow(nPezziLabel,nPezziValueEdit);
    formLayout->addRow(weightLabel,weightEdit);
    formLayout->addRow(prezzoLabel,prezzoValueEdit);
    formLayout->addRow(discountLabel,discountValueEdit);
    formLayout->addRow(stockLabel,stockValueEdit);

    //Aggiungo e riempio i campi in base al tipo di prodotto
    if (w->getItemType()=="Circle Box") {
        CircleBox *ci=dynamic_cast<CircleBox*>(w);
        radiusLabel=new QLabel("Raggio: ",this);
        radiusValueEdit=new QLineEdit(QString::fromStdString(std::to_string(ci->getRadius())), this);
        radiusValueEdit->setMaximumWidth(maxSizeEdit);
        formLayout->addRow(radiusLabel,radiusValueEdit);
    } else {
        if (w->getItemType()=="Ventaglio Box"){
            VentaglioBox *v=dynamic_cast<VentaglioBox*>(w);
            heightLabel=new QLabel("Altezza: ",this);
            heightValueEdit=new QLineEdit(QString::fromStdString(std::to_string(v->getHeight())), this);
            widthLabel=new QLabel("Larghezza: ",this);
            widthValueEdit=new QLineEdit(QString::fromStdString(std::to_string(v->getWidth())), this);
            widthValueEdit->setMaximumWidth(maxSizeEdit);
            formLayout->addRow(heightLabel,heightValueEdit);
            formLayout->addRow(widthLabel,widthValueEdit);
        } else {
            if (w->getItemType()=="Cannolo Box") {
                CannoloBox *ca=dynamic_cast<CannoloBox*>(w);
                heightLabel=new QLabel("Altezza: ",this);
                heightValueEdit=new QLineEdit(QString::fromStdString(std::to_string(ca->getHeight())), this);
                intDiameterLabel=new QLabel("Diamentro interno: ",this);
                intDiameterValueEdit=new QLineEdit(QString::fromStdString(std::to_string(ca->getIntDiameter())), this);
                intDiameterValueEdit->setMaximumWidth(maxSizeEdit);
                formLayout->addRow(heightLabel,heightValueEdit);
                formLayout->addRow(intDiameterLabel,intDiameterValueEdit);
            } else {
                if (w->getItemType()=="Cone Box") {
                    ConeBox *co=dynamic_cast<ConeBox*>(w);
                    heightLabel=new QLabel("Altezza: ",this);
                    heightValueEdit=new QLineEdit(QString::fromStdString(std::to_string(co->getHeight())), this);
                    externalRadiusLabel=new QLabel("Diametro esterno: ",this);
                    externalRadiusValueEdit=new QLineEdit(QString::fromStdString(std::to_string(co->getExtDiameter())), this);
                    externalRadiusValueEdit->setMaximumWidth(maxSizeEdit);
                    formLayout->addRow(heightLabel,heightValueEdit);
                    formLayout->addRow(externalRadiusLabel,externalRadiusValueEdit);
                } else {
                    if (w->getItemType()=="Covered Box") {
                        Covered *cv=dynamic_cast<Covered*>(w);
                        heightLabel=new QLabel("Altezza: ",this);
                        heightValueEdit=new QLineEdit(QString::fromStdString(std::to_string(cv->getHeight())), this);
                        externalRadiusLabel=new QLabel("Diametro esterno: ",this);
                        externalRadiusValueEdit=new QLineEdit(QString::fromStdString(std::to_string(cv->getExtDiameter())), this);
                        externalRadiusValueEdit->setMaximumWidth(maxSizeEdit);
                        tasteLabel=new QLabel("Gusto",this);
                        tasteValueEdit=new QLineEdit(QString::fromStdString(cv->getTaste()), this);
                        tasteValueEdit->setMaximumWidth(maxSizeEdit);
                        formLayout->addRow(heightLabel,heightValueEdit);
                        formLayout->addRow(externalRadiusLabel,externalRadiusValueEdit);
                        formLayout->addRow(tasteLabel,tasteValueEdit);
                    } else {
                        Branded *br=dynamic_cast<Branded*>(w);
                        heightLabel=new QLabel("Altezza: ",this);
                        heightValueEdit=new QLineEdit(QString::fromStdString(std::to_string(br->getHeight())), this);
                        externalRadiusLabel=new QLabel("Diametro esterno: ",this);
                        externalRadiusValueEdit=new QLineEdit(QString::fromStdString(std::to_string(br->getExtDiameter())), this);
                        externalRadiusValueEdit->setMaximumWidth(maxSizeEdit);
                        principalColorLabel=new QLabel("Colore principale: ",this);
                        principalColorValueEdit=new QLineEdit(QString::fromStdString(br->getPrincipalColor()), this);
                        principalColorValueEdit->setMaximumWidth(maxSizeEdit);
                        secondaryColorLabel=new QLabel("Colore secondario: ",this);
                        secondaryColorValueEdit=new QLineEdit(QString::fromStdString(br->getSecundaryColor()), this);
                        secondaryColorValueEdit->setMaximumWidth(maxSizeEdit);
                        formLayout->addRow(heightLabel,heightValueEdit);
                        formLayout->addRow(externalRadiusLabel,externalRadiusValueEdit);
                        formLayout->addRow(principalColorLabel,principalColorValueEdit);
                        formLayout->addRow(secondaryColorLabel,secondaryColorValueEdit);
                    }
                }
            }
        }
    }

    cancelButton=new QPushButton("Annulla",this);
    modifyPhotoButton=new QPushButton("Cambia immangine",this);
    okButton=new QPushButton("Applica modifiche",this);
    button->addWidget(okButton);
    button->addWidget(cancelButton);

    left->addWidget(imgLabel);
    left->addWidget(modifyPhotoButton);
    right->addLayout(formLayout);
    right->addLayout(button);
    main->addLayout(left);
    main->addLayout(right);
    setLayout(main);
}

std::string ModifyProduct::doubleToString(double d){
    std::stringstream s;
    s << std::fixed <<std::setprecision(2) << d;
    return s.str();
}

QSize ModifyProduct::sizeHint() const{
    return QSize(900,500);
}

QPushButton *ModifyProduct::getCancelButton() const{ return cancelButton; }

QPushButton *ModifyProduct::getModifyPhotoButton() const { return modifyPhotoButton; }

QPushButton *ModifyProduct::getOkButton() const { return okButton; }

WaffleBox* ModifyProduct::getWaffleBox() const{ return w; }

void ModifyProduct::changePhoto(){
    QString path(QFileDialog::getOpenFileName(this, "Seleziona file", "../", "Immagine (*.png *.jpg *.jpeg)"));
    if (path.isNull()==false){
        if(!QFile::exists("../cialde-test/Data/Photo/" + path.section("/", -1, -1))){
            if(QFile::copy(path, QString("../cialde-test/Data/Photo/" + path.section("/", -1, -1)))) {
                QPixmap qpm(QString("../cialde-test/Data/Photo/" + path.section("/", -1, -1)));
                imgLabel->setPixmap(qpm.scaled(QSize(400, 400)));
                imgpath = QString("../cialde-test/Data/Photo/" + path.section("/", -1, -1)).toStdString();
            }
        } else {
            QPixmap qpm(QString("../cialde-test/Data/Photo/" + path.section("/", -1, -1)));
            imgLabel->setPixmap(qpm.scaled(QSize(400, 400)));
            imgpath = QString("../cialde-test/Data/Photo/" + path.section("/", -1, -1)).toStdString();
        }
    }
}

void ModifyProduct::noModify(){
    QMessageBox::warning(nullptr, "Attenzione", "Operazione annullata", QMessageBox::Ok);
    close();
}

void ModifyProduct::modifica() {
    bool isEdited=true;
    if(nomeValueEdit->text().toStdString() != "" && idValueEdit->text().toStdString() != "" && nPezziValueEdit->text().toUInt() != 0 && weightEdit->text().toUInt() !=0 &&prezzoValueEdit->text().toDouble() != 0){
        if (w->getItemType()=="Circle Box") {
            if (radiusValueEdit->text().toUInt() == 0) {
                isEdited=false;
            }
        } else {
            if (w->getItemType()=="Ventaglio Box"){
                if (widthValueEdit->text().toUInt() == 0 || heightValueEdit->text().toUInt() == 0) {
                    isEdited=false;
                }
            } else {
                if (w->getItemType()=="Cannolo Box") {
                    if(intDiameterValueEdit->text().toUInt() == 0 || heightValueEdit->text().toUInt() == 0){
                        isEdited=false;
                    }
                } else {
                    if (w->getItemType()=="Cone Box") {
                        if(externalRadiusValueEdit->text().toUInt() == 0 || heightValueEdit->text().toUInt() == 0){
                            isEdited=false;
                        }
                    } else {
                        if (w->getItemType()=="Covered Box") {
                            if(externalRadiusValueEdit->text().toUInt() == 0 || tasteValueEdit->text().toStdString() == " " || heightValueEdit->text().toUInt() == 0){
                                isEdited=false;
                            }
                        } else {
                            if(externalRadiusValueEdit->text().toUInt() == 0 || principalColorValueEdit->text().toStdString() == " " || secondaryColorValueEdit->text().toStdString() == " " || heightValueEdit->text().toUInt() == 0){
                                isEdited=false;
                            }
                        }
                    }
                }
            }
        }
    }else{
        isEdited=false;
    }
    if(isEdited){
        w->setID(idValueEdit->text().toStdString());
        w->setName(nomeValueEdit->text().toStdString());
        w->setPhoto(imgpath);
        w->setCapacity(nPezziValueEdit->text().toUInt());
        w->setWeight(weightEdit->text().toUInt());
        w->setPrice(prezzoValueEdit->text().toDouble());
        w->setDiscount(discountValueEdit->text().toUInt());
        w->setStockAvailability(stockValueEdit->text().toUInt());
        //Valuto i vari tipi e aggiorno il wafflebox corrispondente
        if (w->getItemType()=="Circle Box") {
            CircleBox *tmp=static_cast<CircleBox*>(w);
            tmp->setRadius(radiusValueEdit->text().toUInt());
        } else {
            if (w->getItemType()=="Ventaglio Box"){
                VentaglioBox *tmp=static_cast<VentaglioBox*>(w);
                tmp->setWidth(widthValueEdit->text().toUInt());
            } else {
                if (w->getItemType()=="Cannolo Box") {
                    CannoloBox *tmp=static_cast<CannoloBox*>(w);
                    tmp->setIntDiameter(intDiameterValueEdit->text().toUInt());
                } else {
                    if (w->getItemType()=="Cone Box") {
                        ConeBox *tmp=static_cast<ConeBox*>(w);
                        tmp->setExtDiameter(externalRadiusValueEdit->text().toUInt());
                    } else {
                        if (w->getItemType()=="Covered Box") {
                            Covered *tmp=static_cast<Covered*>(w);
                            tmp->setExtDiameter(externalRadiusValueEdit->text().toUInt());
                            tmp->setTaste(tasteValueEdit->text().toStdString());
                        } else {
                            Branded *tmp=static_cast<Branded*>(w);
                            tmp->setExtDiameter(externalRadiusValueEdit->text().toUInt());
                            tmp->setPrincipalColor(principalColorValueEdit->text().toStdString());
                            tmp->setSecundaryColor(secondaryColorValueEdit->text().toStdString());
                        }
                    }
                }
            }
        }
        QMessageBox::information(nullptr, "Modifica", "Operazione avvenuta con successo", QMessageBox::Ok);
        close();
    } else {
        QMessageBox::critical(this,"Errore","Campi essenziali errati o non compilati o vuoti",QMessageBox::Ok);
    }
}
