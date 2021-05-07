#include "model.h"

Model::Model(const std::string& p, const std::string& fn, u_int n) : path(p), fileName(fn), container(n) {}

void Model::addBox(WaffleBox* waffleb){container.push_back(DeepPtr<WaffleBox>(waffleb));}

void Model::removeBox(u_int index){container.erase(index);}

void Model::removeBox(DeepPtr<WaffleBox>& ptr){container.erase(ptr);}

void Model::loadXMl(){XmlManagement loader(path,fileName); container = loader.read();}

int Model::getSize() const{return container.getSize();}
