#include "details.h"

Details::Details(QWidget *parent, WaffleBox *wf): QWidget(parent),
    w(wf)
{
    setWindowTitle("Wafflebox - Dettagli prodotto");
    setWindowIcon(QIcon(QPixmap(":/MyRes/Photo/icon.png")));

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
    nomeLabel=new QLabel("Nome: ",this);
    idLabel=new QLabel("ID: ",this);
    nPezziLabel=new QLabel("Capacità Box: ",this);
    prezzoLabel=new QLabel("Prezzo: ",this);
    discountLabel=new QLabel("Sconto: ",this);
    stockLabel=new QLabel("Disponibilità: ",this);

    imgLabel=new QLabel(this);
    QPixmap qpm = QPixmap(QString::fromStdString(w->getPhoto()));
    if(!qpm.isNull()){
        imgLabel->setPixmap(qpm.scaled(QSize(400, 400)));
    }else{
        imgLabel->setText("IMMAGINE NON TROVATA");
        imgLabel->setMinimumSize(400,400);
    }
    imgLabel->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);

    tipoValueLabel=new QLabel(QString::fromStdString(w->getItemType()), this);
    nomeValueLabel=new QLabel(QString::fromStdString(w->getName()), this);
    idValueLabel=new QLabel(QString::fromStdString(w->getID()), this);
    nPezziValueLabel=new QLabel(QString::number((w->getCapacity())), this);
    prezzoValueLabel=new QLabel(QString::number((w->getRealPrice()))+QString("€"), this);
    discountValueLabel=new QLabel(QString::number((w->getDiscount()))+QString("%"), this);
    stockValueLabel=new QLabel(QString::number((w->getStockAvailability())), this);

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
        radiusValueLabel=new QLabel(QString::number((ci->getRadius()))+QString("mm"), this);
        formLayout->addRow(radiusLabel,radiusValueLabel);
    }else{
        VentaglioBox *v=dynamic_cast<VentaglioBox*>(w);
        if (v) {
            heightLabel=new QLabel("Altezza: ",this);
            heightValueLabel=new QLabel(QString::number((v->getHeight()))+QString("mm"), this);
            widthLabel=new QLabel("Larghezza: ",this);
            widthValueLabel=new QLabel(QString::number((v->getWidth()))+QString("mm"), this);
            formLayout->addRow(heightLabel,heightValueLabel);
            formLayout->addRow(widthLabel,widthValueLabel);
        } else {
            CannoloBox *ca=dynamic_cast<CannoloBox*>(w);
            if (ca) {
                heightLabel=new QLabel("Altezza: ",this);
                heightValueLabel=new QLabel(QString::number((ca->getHeight()))+QString("mm"), this);
                intDiameterLabel=new QLabel("Diamentro interno: ",this);
                intDiameterValueLabel=new QLabel(QString::number((ca->getIntDiameter()))+QString("mm"), this);
                formLayout->addRow(heightLabel,heightValueLabel);
                formLayout->addRow(intDiameterLabel,intDiameterValueLabel);
            } else {
                Covered *cv=dynamic_cast<Covered*>(w);
                if(cv){
                    heightLabel=new QLabel("Altezza: ",this);
                    heightValueLabel=new QLabel(QString::number((cv->getHeight()))+QString("mm"), this);
                    externalRadiusLabel=new QLabel("Diametro esterno: ",this);
                    externalRadiusValueLabel=new QLabel(QString::number((cv->getExtDiameter()))+QString("mm"), this);
                    tasteLabel=new QLabel("Gusto",this);
                    tasteValueLabel=new QLabel(QString::fromStdString(cv->getTaste()), this);
                    formLayout->addRow(heightLabel,heightValueLabel);
                    formLayout->addRow(externalRadiusLabel,externalRadiusValueLabel);
                    formLayout->addRow(tasteLabel,tasteValueLabel);
                }else{
                   Branded *br=dynamic_cast<Branded*>(w);
                   if (br) {
                       heightLabel=new QLabel("Altezza: ",this);
                       heightValueLabel=new QLabel(QString::number((br->getHeight()))+QString("mm"), this);
                       externalRadiusLabel=new QLabel("Diametro esterno: ",this);
                       externalRadiusValueLabel=new QLabel(QString::number((br->getExtDiameter()))+QString("mm"), this);
                       principalColorLabel=new QLabel("Colore principale: ",this);
                       principalColorValueLabel=new QLabel(QString::fromStdString(br->getPrincipalColor()), this);
                       secondaryColorLabel=new QLabel("Colore secondario: ",this);
                       secondaryColorValueLabel=new QLabel(QString::fromStdString(br->getSecundaryColor()), this);
                       formLayout->addRow(heightLabel,heightValueLabel);
                       formLayout->addRow(externalRadiusLabel,externalRadiusValueLabel);
                       formLayout->addRow(principalColorLabel,principalColorValueLabel);
                       formLayout->addRow(secondaryColorLabel,secondaryColorValueLabel);
                   }else{
                       ConeBox *co=dynamic_cast<ConeBox*>(w);
                       if(co){
                           heightLabel=new QLabel("Altezza: ",this);
                           heightValueLabel=new QLabel(QString::number((co->getHeight()))+QString("mm"), this);
                           externalRadiusLabel=new QLabel("Diametro esterno: ",this);
                           externalRadiusValueLabel=new QLabel(QString::number((co->getExtDiameter()))+QString("mm"), this);
                           formLayout->addRow(heightLabel,heightValueLabel);
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

std::string Details::doubleToString(double d) {
    std::stringstream s;
    s << std::fixed <<std::setprecision(2) << d;
    return s.str();
}

QSize Details::sizeHint() const {
    return QSize(800,500);
}

