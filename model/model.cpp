#include "model.h"

Model::Model(const std::string& p, const std::string& fn, u_int n) : path(p), fileName(fn), xmlManager(p,fn), container(n) {

    cout << "FILENAME Model: " << fileName << endl;
    cout << "PATH Model: " << path << endl;
    cout << "FILENAME Xml: " << xmlManager.getXmlFileName() << endl;
    cout << "PATH Xml: " << xmlManager.getXmlPath() << endl;
    cout << "N Model: " << n << endl;

}

//bool Model::findItem(WaffleBox* obj) const{return container.find(DeepPtr<WaffleBox>(obj));}

void Model::addBox(WaffleBox* waffleb){container.push_back(DeepPtr<WaffleBox>(waffleb));}

void Model::removeBox(u_int index){container.erase(index);}

void Model::removeBox(DeepPtr<WaffleBox>& ptr){container.erase(ptr);}

void Model::loadXml(){container = xmlManager.read();}

void Model::writeXml() const { xmlManager.write(container);}

u_int Model::getSize() const{return container.getSize();}

WaffleBox* Model::getItem(unsigned int i) const{return container[i].operator ->();}

void Model::printAll() const{ for(u_int i=0; i < container.getSize(); ++i){ cout << container[i]->printItem() << endl; } }
