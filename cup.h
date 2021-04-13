#ifndef CUP_H
#define CUP_H

#include "cones.h"

class Cup: public Cones{
private:
    u_int int_diameter;
public:
    //Costruttore, costruttore di copia e distruttore
    Cup(const std::string& = "", u_int = 0, u_int = 0, const std::string& ="", u_int = 0);
    Cup(const Cup&);
    virtual ~Cup() = default;
    //GETTER
    u_int getIntDiameter() const;
    //SETTER
    void setIntDiameter(u_int);
    //OPERATORI
    virtual bool operator ==(const Cup&);
    virtual bool operator !=(const Cup&);
    //CLONE
    virtual Cup *clone() const;
};

#endif // CUP_H
