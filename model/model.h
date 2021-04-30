#ifndef MODEL_H
#define MODEL_H
#include "container.h"
#include "deepptr.h"
#include "wafflebox.h"

class Model{
private:
    Container<DeepPtr<WaffleBox>> container;
public:

    Model(u_int);
    void addBox(WaffleBox*);
    void removeBox(u_int);
    void removeBox(DeepPtr<WaffleBox>&);



};

#endif // MODEL_H
