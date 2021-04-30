#include "model.h"

Model::Model(u_int n) : container(n) {}

void Model::addBox(WaffleBox* waffleb){container.push_back(DeepPtr<WaffleBox>(waffleb));}

void Model::removeBox(u_int index){container.erase(i);}

