#include "details.h"

details::details(QWidget *parent, WaffleBox *wf): QWidget(parent),
    w(wf)
{
    setWindowTitle("Wafflebox - Dettagli prodotto");

    tipoLabel=new QLabel("Tipo: ",this);
    nomeLabel=new QLabel("Nome: ",this);
    idLabel=new QLabel("ID: ",this);
    nPezziLabel=new QLabel("Numero Pezzi: ",this);
    prezzoLabel=new QLabel("Prezzo: ",this);
    discountLabel=new QLabel("Sconto: ",this);
    stockLabel=new QLabel("Disponibilità: ",this);

    imgLabel=new QLabel(this);
    QPixmap qpm = QPixmap(QString::fromStdString(w->getPhoto()));

    if(!qpm.isNull()){
        if(qpm.width()>700||qpm.height()>500){
            int width= qpm.width(), height = qpm.height();
            while(width>700||height>500){
                width /=1.01;
                height /= 1.01;
            }
            imgLabel->setPixmap(qpm.scaled(QSize(width, height)));
        }else{
            imgLabel->setPixmap(qpm.scaled(QSize(qpm.width(), qpm.height())));
        }
    }else{
        imgLabel->setText("Immagine non trovata");
        //imgLabel->setPixmap(QPixmap(QString::fromStdString("../cialde-test/Data/Photo/image-not-found.jpg")).scaled(QSize(400, 400)));
    }
    imgLabel->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);

    tipoValueLabel=new QLabel(QString::fromStdString(w->getItemType()), this);
    nomeValueLabel=new QLabel(QString::fromStdString(w->getName()), this);
    idValueLabel=new QLabel(QString::fromStdString(w->getID()), this);
    nPezziValueLabel=new QLabel(QString::fromStdString(std::to_string(w->getCapacity())), this);
    prezzoValueLabel=new QLabel(QString::fromStdString(doubleToString(w->getPrice())), this);
    discountValueLabel=new QLabel(QString::fromStdString(std::to_string(w->getDiscount())), this);
    stockValueLabel=new QLabel(QString::fromStdString(std::to_string(w->getStockAvailability())), this);

    QHBoxLayout *main=new QHBoxLayout(this);
    QHBoxLayout *left=new QHBoxLayout();
    QHBoxLayout *right=new QHBoxLayout();
    QFormLayout *formLayout= new QFormLayout();

    formLayout->addRow(tipoLabel,tipoValueLabel);
    formLayout->addRow(nomeLabel,nomeValueLabel);
    formLayout->addRow(idLabel,idValueLabel);
    formLayout->addRow(nPezziLabel,nPezziValueLabel);
    formLayout->addRow(prezzoLabel,prezzoValueLabel);
    formLayout->addRow(discountLabel,discountValueLabel);
    formLayout->addRow(stockLabel,stockValueLabel);

    //Distinzione in base ai vari prodotti

    CircleBox *ci=dynamic_cast<CircleBox*>(w);
    if(ci){
        radiusLabel=new QLabel("Raggio: ",this);
        radiusValueLabel=new QLabel(QString::fromStdString(std::to_string(ci->getRadius())), this);
        formLayout->addRow(radiusLabel,radiusValueLabel);
    }else{
        VentaglioBox *v=dynamic_cast<VentaglioBox*>(w);
        if (v) {
            widthLabel=new QLabel("Larghezza: ",this);
            widthValueLabel=new QLabel(QString::fromStdString(std::to_string(v->getWidth())), this);
            formLayout->addRow(widthLabel,widthValueLabel);
        } else {
            CannoloBox *ca=dynamic_cast<CannoloBox*>(w);
            if (ca) {
                intDiameterLabel=new QLabel("Diamentro interno: ",this);
                intDiameterValueLabel=new QLabel(QString::fromStdString(std::to_string(ca->getIntDiameter())), this);
                formLayout->addRow(intDiameterLabel,intDiameterValueLabel);
            } else {
                ConeBox *co=dynamic_cast<ConeBox*>(w);
                if(co){
                    Covered *cv=dynamic_cast<Covered*>(w);
                    if(cv){
                        tasteLabel=new QLabel("Gusto",this);
                        tasteValueLabel=new QLabel(QString::fromStdString(cv->getTaste()), this);
                        formLayout->addRow(tasteLabel,tasteValueLabel);
                    }else{
                       Branded *br=dynamic_cast<Branded*>(w);
                       if (br) {
                           principalColorLabel=new QLabel("Colore principale: ",this);
                           principalColorValueLabel=new QLabel(QString::fromStdString(br->getPrincipalColor()), this);
                           secondaryColorLabel=new QLabel("Colore secondario: ",this);
                           secondaryColorValueLabel=new QLabel(QString::fromStdString(br->getSecundaryColor()), this);
                           formLayout->addRow(principalColorLabel,principalColorValueLabel);
                           formLayout->addRow(secondaryColorLabel,secondaryColorValueLabel);
                       } else {
                           externalRadiusLabel=new QLabel("Diametro esterno: ",this);
                           externalRadiusValueLabel=new QLabel(QString::fromStdString(std::to_string(co->getExtDiameter())), this);
                           formLayout->addRow(externalRadiusLabel,externalRadiusValueLabel);
                       }
                    }
                }
            }
        }
    }

    left->addWidget(imgLabel);
    right->addLayout(formLayout);
    main->addLayout(left);
    main->addLayout(right);
    setLayout(main);
}

std::string details::doubleToString(double d){
    std::stringstream s;
    s << std::fixed <<std::setprecision(2) << d;
    return s.str();
}

QSize details::sizeHint() const{
    return QSize(800,500);
}

