#include "model.h"

Model::Model(const std::string& p, const std::string& fn, u_int n) : path(p), fileName(fn), container(n) {

    cout << "FILENAME Model: " << fileName << endl;
    cout << "PATH Model: " << path << endl;
    cout << "N Model: " << n << endl;
}

void Model::addBox(WaffleBox* waffleb){container.push_back(DeepPtr<WaffleBox>(waffleb));}

void Model::removeBox(u_int index){container.erase(index);}

void Model::removeBox(DeepPtr<WaffleBox>& ptr){container.erase(ptr);}

void Model::loadXMl(){ XmlManagement loader(path,fileName); container = loader.read();}

void Model::writeXml() const {XmlManagement writer(path,fileName); writer.write(container);}

int Model::getSize() const{return container.getSize();}

WaffleBox* Model::getItem(unsigned int i) const{return container[i].operator ->();}
