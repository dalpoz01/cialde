#ifndef CIRCLEBOX_H
#define CIRCLEBOX_H
#include "wafflebox.h"

//Classe concreta
class CircleBox : public WaffleBox {
private:
    u_int radius;
public:
    //Costruttore, costruttore di copia e distruttore
    CircleBox(const std::string& nome=" ",const std::string& id=" ", const std::string &foto=" ", u_int = 0, u_int = 0, double = 0, u_int = 0, u_int = 0, u_int = 0);
    CircleBox(const CircleBox&);
    virtual ~CircleBox() = default;

    //Getter
    u_int getRadius() const;

    //Setter
    void setRadius(u_int);

    //Operatori
    virtual bool operator ==(const CircleBox&);
    virtual bool operator !=(const CircleBox&);

    //Clone
    virtual CircleBox *clone() const;

    std::string getItemType() const;

    virtual std::string printItem() const;
};

#endif // CIRCLEBOX_H
