#ifndef MODEL_H
#define MODEL_H
#include "container.h"
#include "deepptr.h"
#include "wafflebox.h"
#include "xmlmanagement.h"

class Model{
private:
    std::string path;
    std::string fileName;
    Container<DeepPtr<WaffleBox>> container;
public:

    Model(const std::string& = "../cialde-test/Data/Xml/", const std::string& = "product.xml", u_int = 10);
    void addBox(WaffleBox*);
    void removeBox(u_int);
    void removeBox(DeepPtr<WaffleBox>&);
    void loadXMl(); //Carico i dati dal file

};

#endif // MODEL_H