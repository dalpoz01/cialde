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
    Model(const Model&);

    //bool findItem(WaffleBox*) const;
    void addBox(WaffleBox*);
    void removeBox(u_int);
    void removeBox(DeepPtr<WaffleBox>&);
    void loadXml(); //Carico i dati dal file
    void writeXml() const;
    u_int getSize() const;
    WaffleBox* getItem(unsigned int i) const; //Metodo per ottenere l'obj nel container
    void printAll() const;

    void updateItem(u_int, WaffleBox*);
    bool findItem(std::string); //Metodo per veificare la presenza dell'ID di un wafflebox data una stringa, ritorna true se trovato

    std::string getPath() const;
    std::string getFileName() const;
    void setPath(const std::string&);
    void setFileName(const std::string&);
    Container<DeepPtr<WaffleBox>> getContainer() const;
};

#endif // MODEL_H
