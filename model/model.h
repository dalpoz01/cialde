#ifndef MODEL_H
#define MODEL_H
#include "xmlmanagement.h"
#include "container.h"
#include "wafflebox.h"
#include "deepptr.h"

class Model{
private:
    std::string path;
    std::string fileName;
    XmlManagement xmlManager;
    Container<DeepPtr<WaffleBox>> container;
public:

    Model(const std::string& = "../cialde-test/Data/Xml/", const std::string& = "products.xml", u_int = 10);
    //bool findItem(WaffleBox*) const;
    void addBox(WaffleBox*);
    void removeBox(u_int);
    void removeBox(DeepPtr<WaffleBox>&);
    void loadXMl(); //Carico i dati dal file
    void writeXml() const;
    u_int getSize() const;
    WaffleBox* getItem(unsigned int i) const; //Metodo per ottenere l'obj nel container

    void printAll() const;


};

#endif // MODEL_H
