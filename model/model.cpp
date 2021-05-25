#include "model.h"

Model::Model(const std::string& p, const std::string& fn, u_int n) : path(p), fileName(fn), xmlManager(p,fn), container(n) {

    /*cout << "FILENAME Model: " << fileName << endl;
    cout << "PATH Model: " << path << endl;
    cout << "FILENAME Xml: " << xmlManager.getXmlFileName() << endl;
    cout << "PATH Xml: " << xmlManager.getXmlPath() << endl;
    cout << "N Model: " << n << endl;*/

}

Model::Model(const Model& m) : Model(m.getPath(), m.getFileName(), m.getSize()) {

    for(u_int i = 0; i < m.container.getSize(); ++i){
        container[i] = m.container[i];
    }
}

//bool Model::findItem(WaffleBox* obj) const{return container.find(DeepPtr<WaffleBox>(obj));}

void Model::addBox(WaffleBox* waffleb){container.push_back(DeepPtr<WaffleBox>(waffleb));}

void Model::removeBox(u_int index){container.erase(index);}

void Model::removeBox(DeepPtr<WaffleBox>& ptr){container.erase(ptr);}

void Model::loadXml(){container = xmlManager.read();}

void Model::writeXml() const { if(container.getSize()>0){xmlManager.write(container);}else{std::cout<<"Container vuoto"<<endl;}}

u_int Model::getSize() const{return container.getSize();}

WaffleBox* Model::getItem(unsigned int i) const{return container[i].operator ->();}

void Model::printAll() const{ for(u_int i=0; i < container.getSize(); ++i){ cout << container[i]->printItem() << endl; } }

std::string Model::getPath() const{ return path; }

std::string Model::getFileName() const{ return fileName; }

Container<DeepPtr<WaffleBox>> Model::getContainer() const{ return container; }

void Model::updateItem(u_int index, WaffleBox* wb){
    for(u_int i = 0; i < container.getSize(); ++i){
        if(i == index){ //Ho trovato l'oggettor
            container[i] = DeepPtr<WaffleBox>(wb);
        }
    }
}
