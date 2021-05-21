#include "modifyproduct.h"

modifyProduct::modifyProduct(QWidget *parent, WaffleBox *wf) : QWidget(parent),
    w(wf)
{
    setWindowTitle("Wafflebox - Modifica prodotto");

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
        if(qpm.width()>600||qpm.height()>500){
            int width= qpm.width(), height = qpm.height();
            while(width>600||height>500){
                width /=1.01;
                height /= 1.01;
            }
            imgLabel->setPixmap(qpm.scaled(QSize(width, height)));
        }else{
            imgLabel->setPixmap(qpm.scaled(QSize(qpm.width(), qpm.height())));
        }
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
    if (w->getItemType()=="CircleBox") {
        CircleBox *ci=dynamic_cast<CircleBox*>(w);
        radiusLabel=new QLabel("Raggio: ",this);
        radiusValueEdit=new QLineEdit(QString::fromStdString(std::to_string(ci->getRadius())), this);
        radiusValueEdit->setMaximumWidth(maxSizeEdit);
        formLayout->addRow(radiusLabel,radiusValueEdit);
    } else {
        if (w->getItemType()=="VentaglioBox"){
            VentaglioBox *v=dynamic_cast<VentaglioBox*>(w);
            widthLabel=new QLabel("Larghezza: ",this);
            widthValueEdit=new QLineEdit(QString::fromStdString(std::to_string(v->getWidth())), this);
            widthValueEdit->setMaximumWidth(maxSizeEdit);
            formLayout->addRow(widthLabel,widthValueEdit);
        } else {
            if (w->getItemType()=="CannoloBox") {
                CannoloBox *ca=dynamic_cast<CannoloBox*>(w);
                intDiameterLabel=new QLabel("Diamentro interno: ",this);
                intDiameterValueEdit=new QLineEdit(QString::fromStdString(std::to_string(ca->getIntDiameter())), this);
                intDiameterValueEdit->setMaximumWidth(maxSizeEdit);
                formLayout->addRow(intDiameterLabel,intDiameterValueEdit);
            } else {
                if (w->getItemType()=="ConeBox") {
                    ConeBox *co=dynamic_cast<ConeBox*>(w);
                    externalRadiusLabel=new QLabel("Diametro esterno: ",this);
                    externalRadiusValueEdit=new QLineEdit(QString::fromStdString(std::to_string(co->getExtDiameter())), this);
                    externalRadiusValueEdit->setMaximumWidth(maxSizeEdit);
                    formLayout->addRow(externalRadiusLabel,externalRadiusValueEdit);
                } else {
                    if (w->getItemType()=="CoveredBox") {
                        Covered *cv=dynamic_cast<Covered*>(w);
                        tasteLabel=new QLabel("Gusto",this);
                        tasteValueEdit=new QLineEdit(QString::fromStdString(cv->getTaste()), this);
                        tasteValueEdit->setMaximumWidth(maxSizeEdit);
                        formLayout->addRow(tasteLabel,tasteValueEdit);
                    } else {
                        Branded *br=dynamic_cast<Branded*>(w);
                        principalColorLabel=new QLabel("Colore principale: ",this);
                        principalColorValueEdit=new QLineEdit(QString::fromStdString(br->getPrincipalColor()), this);
                        principalColorValueEdit->setMaximumWidth(maxSizeEdit);
                        secondaryColorLabel=new QLabel("Colore secondario: ",this);
                        secondaryColorValueEdit=new QLineEdit(QString::fromStdString(br->getSecundaryColor()), this);
                        secondaryColorValueEdit->setMaximumWidth(maxSizeEdit);
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

std::string modifyProduct::doubleToString(double d){
    std::stringstream s;
    s << std::fixed <<std::setprecision(2) << d;
    return s.str();
}

QSize modifyProduct::sizeHint() const{
    return QSize(900,500);
}

QPushButton *modifyProduct::getCancelButton() const{ return cancelButton; }

QPushButton *modifyProduct::getModifyPhotoButton() const { return modifyPhotoButton; }

QPushButton *modifyProduct::getOkButton() const { return okButton; }

void modifyProduct::changePhoto(){
    QString path(QFileDialog::getOpenFileName(this, "Seleziona file", "../", "Immagine (*.png *.jpg *.jpeg)"));
    if (path.isNull()==false){
        if(!QFile::exists("../cialde-test/Data/Photo/" + path.section("/", -1, -1))){
            if(QFile::copy(path, QString("../cialde-test/Data/Photo/" + path.section("/", -1, -1)))) {
                QPixmap qpm(QString("../cialde-test/Data/Photo/" + path.section("/", -1, -1)));
                if(qpm.width()>700||qpm.height()>500){
                    int width= qpm.width(), height = qpm.height();
                    while(width>700||height>500){
                        width /= 1.01;
                        height /= 1.01;
                    }
                    imgLabel->setPixmap(qpm.scaled(QSize(width, height)));
                    imgpath = QString("../cialde-test/Data/Photo/" + path.section("/", -1, -1)).toStdString();
                }else{
                    imgLabel->setPixmap(qpm.scaled(QSize(qpm.width(), qpm.height())));
                    imgpath = QString("../cialde-test/Data/Photo/" + path.section("/", -1, -1)).toStdString();
                }
            }
        } else {
            QPixmap qpm(QString("../cialde-test/Data/Photo/" + path.section("/", -1, -1)));
            imgpath = QString("../cialde-test/Data/Photo/" + path.section("/", -1, -1)).toStdString();
            if(qpm.width()>700||qpm.height()>500){
                int width= qpm.width(), height = qpm.height();
                while(width>700||height>500){
                    width /= 1.01;
                    height /= 1.01;
                }
                imgLabel->setPixmap(qpm.scaled(QSize(width, height)));
            }else{
                imgLabel->setPixmap(qpm.scaled(QSize(qpm.width(), qpm.height())));
            }
        }
    }
}

void modifyProduct::noModify(){
    QMessageBox::warning(nullptr, "Attenzione", "Operazione annullata", QMessageBox::Ok);
    close();
}

void modifyProduct::modifica() {
    w->setID(idValueEdit->text().toStdString());
    w->setName(nomeValueEdit->text().toStdString());
    w->setPhoto(imgpath);
    w->setCapacity(nPezziValueEdit->text().toUInt());
    w->setWeight(weightEdit->text().toUInt());
    w->setPrice(prezzoValueEdit->text().toDouble());
    w->setDiscount(discountValueEdit->text().toUInt());
    w->setStockAvailability(stockValueEdit->text().toUInt());
    if (w->getItemType()=="CircleBox") {
        CircleBox *tmp=static_cast<CircleBox*>(w);
        tmp->setRadius(radiusValueEdit->text().toUInt());
    } else {
        if (w->getItemType()=="VentaglioBox"){
            VentaglioBox *tmp=static_cast<VentaglioBox*>(w);
            tmp->setWidth(widthValueEdit->text().toUInt());
        } else {
            if (w->getItemType()=="CannoloBox") {
                CannoloBox *tmp=static_cast<CannoloBox*>(w);
                tmp->setIntDiameter(intDiameterValueEdit->text().toUInt());
            } else {
                if (w->getItemType()=="ConeBox") {
                    ConeBox *tmp=static_cast<ConeBox*>(w);
                    tmp->setExtDiameter(externalRadiusValueEdit->text().toUInt());
                } else {
                    if (w->getItemType()=="CoveredBox") {
                        Covered *tmp=static_cast<Covered*>(w);
                        tmp->setTaste(tasteValueEdit->text().toStdString());
                    } else {
                        Branded *tmp=static_cast<Branded*>(w);
                        tmp->setPrincipalColor(principalColorValueEdit->text().toStdString());
                        tmp->setSecundaryColor(secondaryColorValueEdit->text().toStdString());
                    }
                }
            }
        }
    }
    QMessageBox::information(nullptr, "Modifica", "Operazione avvenuta con successo", QMessageBox::Ok);
    close();
}
