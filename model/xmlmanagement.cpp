#include "xmlmanagement.h"

XmlManagement::XmlManagement(const std::string& p, const std::string& fn) : path(p), fileName(fn) {}

Container<DeepPtr<WaffleBox>> XmlManagement::read() const {

    Container<DeepPtr<WaffleBox>> temp;
    QFile xFile(QString::fromStdString(path+fileName));

    //Prendo il file XML
    if(xFile.open(QIODevice::ReadOnly | QIODevice::Text)==false){ //Se il file non si può aprire in lettura
        QMessageBox openMsg(QMessageBox::Warning, "ERRORE DI APERTURA", "Errore! Impossibile aprire il file in lettura", QMessageBox::Ok);
        openMsg.exec();
        xFile.close();
    }else{
        QXmlStreamReader reader(&xFile);
        if(reader.readNextStartElement()==true && reader.name() == "element"){
           //Reads until the next start element within the current element.
            while(reader.readNextStartElement()==true){ //Inizio a leggere i WaffleBox
                try{
                    if(reader.name() != "WaffleBox") throw std::string("Xml not valid.");
                    //Attributi comuni
                    std::string itemType = reader.attributes().value("type").toString().toStdString();
                    std::string name = "";
                    std::string ID = "";
                    std::string photo = "";
                    unsigned int capacity = 0;
                    unsigned int weight = 0;
                    double price = 0;
                    unsigned int discount = 0;
                    unsigned int stockAva = 0;

                    //Leggo gli attributi comuni con readElementText()

                    if(reader.readNextStartElement()==true && reader.name() == "Nome")
                        name = reader.readElementText().toStdString();
                    if(reader.readNextStartElement()==true && reader.name() == "ID")
                        ID = reader.readElementText().toStdString();
                    if(reader.readNextStartElement()==true && reader.name() == "Foto")
                        photo = reader.readElementText().toStdString();
                    if(reader.readNextStartElement()==true && reader.name() == "capacity")
                        capacity = reader.readElementText().toUInt();
                    if(reader.readNextStartElement()==true && reader.name() == "weight")
                        weight = reader.readElementText().toUInt();
                    if(reader.readNextStartElement()==true && reader.name() == "price")
                        price = reader.readElementText().toDouble();
                    if(reader.readNextStartElement()==true && reader.name() == "discount")
                        discount = reader.readElementText().toUInt();
                    if(reader.readNextStartElement()==true && reader.name() == "stockavailability")
                        stockAva = reader.readElementText().toUInt();

                    //Leggo gli attributi degli oggetti concreti.
                    if(itemType == "Circle Box"){
                        unsigned int radius = 0;
                        if(reader.readNextStartElement()==true && reader.name() == "radius")
                            radius = reader.readElementText().toUInt();
                        reader.skipCurrentElement();    //Skippo all'elemento successivo perchè ho finito quello corrente e devo continuare il ciclo
                        CircleBox* cb = new CircleBox(name,ID,photo,capacity,weight,price,discount,stockAva,radius);
                        temp.push_back(DeepPtr<WaffleBox>(cb));
                        delete cb;
                    }else if(itemType == "Ventaglio Box"){
                        unsigned int height = 0;
                        unsigned int width = 0;
                        if(reader.readNextStartElement()==true && reader.name() == "height")
                            height = reader.readElementText().toUInt();
                        if(reader.readNextStartElement()==true && reader.name() == "width")
                            width = reader.readElementText().toUInt();
                        reader.skipCurrentElement();
                        VentaglioBox* vb = new VentaglioBox(name,ID,photo,capacity,weight,price,discount,stockAva,height,width);
                        temp.push_back(DeepPtr<WaffleBox>(vb));
                        delete vb;
                    }else if(itemType == "Cannolo Box"){
                        unsigned int height = 0;
                        unsigned int int_diam = 0;
                        if(reader.readNextStartElement()==true && reader.name() == "height")
                            height = reader.readElementText().toUInt();
                        if(reader.readNextStartElement()==true && reader.name() == "int_diameter")
                            int_diam = reader.readElementText().toUInt();
                        reader.skipCurrentElement();
                        CannoloBox* c = new CannoloBox(name,ID,photo,capacity,weight,price,discount,stockAva,height,int_diam);
                        temp.push_back(DeepPtr<WaffleBox>(c));
                        delete c;
                    }else if(itemType == "Cone Box"){
                        unsigned int height = 0;
                        unsigned int ext_diam = 0;
                        if(reader.readNextStartElement()==true && reader.name() == "height")
                            height = reader.readElementText().toUInt();
                        if(reader.readNextStartElement()==true && reader.name() == "ext_diameter")
                            ext_diam = reader.readElementText().toUInt();
                        reader.skipCurrentElement();
                        ConeBox* co = new ConeBox(name,ID,photo,capacity,weight,price,discount,stockAva,height,ext_diam);
                        temp.push_back(DeepPtr<WaffleBox>(co));
                        delete co;
                    }else if(itemType == "Branded Box"){
                        unsigned int height = 0;
                        unsigned int ext_diam = 0;
                        std::string princ = "";
                        std::string seco = "";
                        if(reader.readNextStartElement()==true && reader.name() == "height")
                            height = reader.readElementText().toUInt();
                        if(reader.readNextStartElement()==true && reader.name() == "ext_diameter")
                            ext_diam = reader.readElementText().toUInt();
                        if(reader.readNextStartElement()==true && reader.name() == "principal_color")
                            princ = reader.readElementText().toStdString();
                        if(reader.readNextStartElement()==true && reader.name() == "secondary_color")
                            seco = reader.readElementText().toStdString();
                        reader.skipCurrentElement();
                        Branded* b = new Branded(name,ID,photo,capacity,weight,price,discount,stockAva,height,ext_diam,princ,seco);
                        temp.push_back(DeepPtr<WaffleBox>(b));
                        delete b;
                    }else if(itemType == "Covered Box"){
                        unsigned int height = 0;
                        unsigned int ext_diam = 0;
                        std::string taste = "";
                        if(reader.readNextStartElement()==true && reader.name() == "height")
                            height = reader.readElementText().toUInt();
                        if(reader.readNextStartElement()==true && reader.name() == "ext_diameter")
                            ext_diam = reader.readElementText().toUInt();
                        if(reader.readNextStartElement()==true && reader.name() == "taste")
                            taste = reader.readElementText().toStdString();
                        reader.skipCurrentElement();
                        Covered* c = new Covered(name,ID,photo,capacity,weight,price,discount,stockAva,height,ext_diam,taste);
                        temp.push_back(DeepPtr<WaffleBox>(c));
                        delete c;
                    }

               }catch(string exc){
               //Exception
                QMessageBox readXmlExc(QMessageBox::Warning, "Errore lettura Xml.", "il file potrebbe esser stato letto male" , QMessageBox::Ok);
                readXmlExc.exec();
               }

            }
            xFile.close();
         }
    }
    return temp;
}

void XmlManagement::write(const Container<DeepPtr<WaffleBox>> &cont) const {
    QDir directory;
    //verifico che esista la directory, altrimento la creo
    if(!directory.exists(QString::fromStdString(path))) directory.mkdir(QString::fromStdString(path));
    QSaveFile savedFile(QString::fromStdString(path+fileName));
        if(savedFile.open(QIODevice::WriteOnly) == false){
            std::cerr << path;
            throw std::exception();
        }
    QFile xmlFile(QString::fromStdString(path+fileName)); //Prendo il file XML
    //verifico che sia presente anche il file dove scrivere
    if(xmlFile.open(QIODevice::WriteOnly)){
         QXmlStreamWriter writer(&xmlFile);
         writer.setAutoFormatting(true);
         writer.writeStartDocument();
         writer.writeStartElement("element");
         for(Container<DeepPtr<WaffleBox>>::const_iterator it = cont.begin(); it != cont.end(); ++it){
             const WaffleBox* wb = it->operator ->();
            // wb ; //Ottengo l'oggetto puntato dall'iteratore costante
             writer.writeStartElement("WaffleBox");
             writer.writeAttribute("type", QString::fromStdString(wb->getItemType()));

             writer.writeStartElement("Nome");
             writer.writeCharacters(QString::fromStdString(wb->getName()));
             writer.writeEndElement();

             writer.writeStartElement("ID");
             writer.writeCharacters(QString::fromStdString(wb->getID()));
             writer.writeEndElement();

             writer.writeStartElement("Foto");
             writer.writeCharacters(QString::fromStdString(wb->getPhoto()));
             writer.writeEndElement();

             writer.writeStartElement("capacity");
             writer.writeCharacters(QString::fromStdString(UIntToString(wb->getCapacity())));
             writer.writeEndElement();

             writer.writeStartElement("weight");
             writer.writeCharacters(QString::fromStdString(UIntToString(wb->getWeight())));
             writer.writeEndElement();

             writer.writeStartElement("price");
             writer.writeCharacters(QString::fromStdString(DoubleToString(wb->getPrice())));
             writer.writeEndElement();

             writer.writeStartElement("discount");
             writer.writeCharacters(QString::fromStdString(UIntToString(wb->getDiscount())));
             writer.writeEndElement();

             writer.writeStartElement("stockavailability");
             writer.writeCharacters(QString::fromStdString(UIntToString(wb->getStockAvailability())));
             writer.writeEndElement();

             if(wb->getItemType() == "Circle Box"){
                 writer.writeStartElement("radius");
                 writer.writeCharacters(QString::fromStdString(UIntToString(static_cast<const CircleBox*>(wb)->getRadius())));
                 writer.writeEndElement();
             }else if(wb->getItemType() == "Ventaglio Box"){
                 writer.writeStartElement("height");
                 writer.writeCharacters(QString::fromStdString(UIntToString(static_cast<const VentaglioBox*>(wb)->getHeight())));
                 writer.writeEndElement();
                 writer.writeStartElement("width");
                 writer.writeCharacters(QString::fromStdString(UIntToString(static_cast<const VentaglioBox*>(wb)->getWidth())));
                 writer.writeEndElement();
             }else if(wb->getItemType() == "Cannolo Box"){
                 writer.writeStartElement("height");
                 writer.writeCharacters(QString::fromStdString(UIntToString(static_cast<const CannoloBox*>(wb)->getHeight())));
                 writer.writeEndElement();
                 writer.writeStartElement("int_diameter");
                 writer.writeCharacters(QString::fromStdString(UIntToString(static_cast<const CannoloBox*>(wb)->getIntDiameter())));
                 writer.writeEndElement();
             }else if(wb->getItemType() == "Cone Box"){
                 writer.writeStartElement("height");
                 writer.writeCharacters(QString::fromStdString(UIntToString(static_cast<const ConeBox*>(wb)->getHeight())));
                 writer.writeEndElement();
                 writer.writeStartElement("ext_diameter");
                 writer.writeCharacters(QString::fromStdString(UIntToString(static_cast<const ConeBox*>(wb)->getExtDiameter())));
                 writer.writeEndElement();
             }else if(wb->getItemType() == "Covered Box"){
                 writer.writeStartElement("height");
                 writer.writeCharacters(QString::fromStdString(UIntToString(static_cast<const Covered*>(wb)->getHeight())));
                 writer.writeEndElement();
                 writer.writeStartElement("taste");
                 writer.writeCharacters(QString::fromStdString(static_cast<const Covered*>(wb)->getTaste()));
                 writer.writeEndElement();
             }else if(wb->getItemType() == "Branded Box"){
                 writer.writeStartElement("height");
                 writer.writeCharacters(QString::fromStdString(UIntToString(static_cast<const Branded*>(wb)->getHeight())));
                 writer.writeEndElement();
                 writer.writeStartElement("ext_diameter");
                 writer.writeCharacters(QString::fromStdString(UIntToString(static_cast<const Branded*>(wb)->getExtDiameter())));
                 writer.writeEndElement();
                 writer.writeStartElement("principal_color");
                 writer.writeCharacters(QString::fromStdString(static_cast<const Branded*>(wb)->getPrincipalColor()));
                 writer.writeEndElement();
                 writer.writeStartElement("secondary_color");
                 writer.writeCharacters(QString::fromStdString(static_cast<const Branded*>(wb)->getSecundaryColor()));
                 writer.writeEndElement();
             }
             writer.writeEndElement();  //</WaffleBox>
         }
         writer.writeEndElement();  //</element>
         writer.writeEndDocument();
         xmlFile.close();
    }else{
        QMessageBox readXmlExc(QMessageBox::Warning, "Errore lettura XML", "File non esistente per scrivere" , QMessageBox::Ok);
        readXmlExc.exec();
    }
}

std::string XmlManagement::DoubleToString(double d) { std::stringstream stream; stream << d; return stream.str(); }

std::string XmlManagement::UIntToString(unsigned int i) { std::stringstream stream; stream << i; return stream.str(); }

std::string XmlManagement::getXmlPath() const { return path; }

std::string XmlManagement::getXmlFileName() const { return fileName; }
