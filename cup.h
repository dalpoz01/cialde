#ifndef CUP_H
#define CUP_H

#include "conebox.h"

class Cup: public Cones{
private:
    std::string brand;
public:
    //Costruttore, costruttore di copia e distruttore
    Cup(const std::string& = "", u_int = 0, u_int = 0, const std::string& ="");
    Cup(const Cup&);
    virtual ~Cup() = default;
    //GETTER
    std::string getBrand() const;
    //SETTER
    void setBrand(const std::string&);
    //OPERATORI
    virtual bool operator ==(const Cup&);
    virtual bool operator !=(const Cup&);
    //CLONE
    virtual Cup *clone() const;
};

#endif // CUP_H
