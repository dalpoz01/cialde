#include "xmlmanagement.h"

XmlManagement::XmlManagement(const std::string& p, const std::string& fn) : path(p), fileName(fn) {}

Container<DeepPtr<WaffleBox>> XmlManagement::read() const{
    Container<DeepPtr<WaffleBox>> temp;

    QFile xmlFile(QString::fromStdString(path+fileName)); //Prendo il file XML

    if(!xmlFile.open(QFile::ReadOnly | QFile::Text)){
           //ERRORE
    }else{
        QXmlStreamReader reader(&xmlFile);
        if(reader.readNextStartElement()){ //Reads until the next start element within the current element.
            if(reader.name() == "elemento"){
                while(reader.readNextStartElement()){ //Inizio a leggere i WaffleBox

                    try{
                        if(reader.name() != "WaffleBox") throw std::string("Xml not valid.");
                        //Attributi comuni
                        std::string itemType = reader.attributes().value("type").toString().toStdString();
                        std::string ID = "";
                        unsigned int capacity;
                        unsigned int weight;
                        double price;
                        unsigned int discount;
                        unsigned int stockAva;

                        //Leggo gli attributi comuni con readElementText()

                        if(reader.name() == "ID")
                            ID = reader.readElementText().toStdString();
                        if(reader.name() == "capacity")
                            capacity = reader.readElementText().toUInt();
                        if(reader.name() == "weight")
                            weight = reader.readElementText().toUInt();
                        if(reader.name() == "price")
                            price = reader.readElementText().toDouble();
                        if(reader.name() == "discount")
                            discount = reader.readElementText().toUInt();
                        if(reader.name() == "stockAvailability")
                            stockAva = reader.readElementText().toUInt();

                        //Leggo gli attributi degli oggetti concreti.
                        if(itemType == "CircleBox"){
                            unsigned int radius;
                            if(reader.name() == "radius")
                                radius = reader.readElementText().toUInt();
                            reader.skipCurrentElement();    //Skippo all'elemento successivo perchè ho finito quello corrente e devo continuare il ciclo
                            CircleBox* cb = new CircleBox(ID,capacity,weight,price,discount,stockAva,radius);
                            temp.push_back(DeepPtr<WaffleBox>(cb));
                            delete cb;
                        }else if(itemType == "VentaglioBox"){
                            unsigned int height;
                            unsigned int width;
                            if(reader.name() == "height")
                                height = reader.readElementText().toUInt();
                            if(reader.name() == "width")
                                width = reader.readElementText().toUInt();
                            reader.skipCurrentElement();
                            VentaglioBox* vb = new VentaglioBox(ID,capacity,weight,price,discount,stockAva,height,width);
                            temp.push_back(DeepPtr<WaffleBox>(vb));
                            delete vb;
                        }else if(itemType == "CannoloBox"){
                            unsigned int height;
                            unsigned int int_diam;
                            if(reader.name() == "height")
                                height = reader.readElementText().toUInt();
                            if(reader.name() == "int_diameter")
                                int_diam = reader.readElementText().toUInt();
                            reader.skipCurrentElement();
                            CannoloBox* c = new CannoloBox(ID,capacity,weight,price,discount,stockAva,height,int_diam);
                            temp.push_back(DeepPtr<WaffleBox>(c));
                            delete c;
                        }else if(itemType == "ConeBox"){
                            unsigned int height;
                            unsigned int ext_diam;
                            if(reader.name() == "height")
                                height = reader.readElementText().toUInt();
                            if(reader.name() == "ext_diameter")
                                ext_diam = reader.readElementText().toUInt();
                            reader.skipCurrentElement();
                            ConeBox* co = new ConeBox(ID,capacity,weight,price,discount,stockAva,height,ext_diam);
                            temp.push_back(DeepPtr<WaffleBox>(co));
                            delete co;
                        }else if(itemType == "Branded"){
                            unsigned int height;
                            unsigned int ext_diam;
                            std::string princ;
                            std::string seco;
                            if(reader.name() == "height")
                                height = reader.readElementText().toUInt();
                            if(reader.name() == "ext_diameter")
                                ext_diam = reader.readElementText().toUInt();
                            if(reader.name() == "principal_color")
                                princ = reader.readElementText().toStdString();
                            if(reader.name() == "secondary_color")
                                seco = reader.readElementText().toStdString();
                            reader.skipCurrentElement();
                            Branded* b = new Branded(ID,capacity,weight,price,discount,stockAva,height,ext_diam,princ,seco);
                            temp.push_back(DeepPtr<WaffleBox>(b));
                            delete b;
                        }else if(itemType == "Covered"){
                            unsigned int height;
                            unsigned int ext_diam;
                            std::string taste;
                            if(reader.name() == "height")
                                height = reader.readElementText().toUInt();
                            if(reader.name() == "ext_diameter")
                                ext_diam = reader.readElementText().toUInt();
                            if(reader.name() == "taste")
                                taste = reader.readElementText().toStdString();
                            reader.skipCurrentElement();
                            Covered* c = new Covered(ID,capacity,weight,price,discount,stockAva,height,ext_diam,taste);
                            temp.push_back(DeepPtr<WaffleBox>(c));
                            delete c;
                        }

                   }catch(string e){
                   //Exception
                    QMessageBox readXmlExc(QMessageBox::Warning, "Errore lettura Xml.", "il file potrebbe esser stato letto male" , QMessageBox::Ok);
                    readXmlExc.exec();
                   }

                }
                xmlFile.close();
            }
        }
    }
    return temp;
}
