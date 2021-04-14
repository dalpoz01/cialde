#ifndef COVERED_H
#define COVERED_H

#include "conebox.h"

class Covered: public Cones{
private:
    std::string taste;
public:
    //Costruttore, costruttore di copia e distruttore
    Covered(const std::string& = "", u_int = 0, u_int = 0, const std::string& ="");
    Covered(const Covered&);
    virtual ~Covered() = default;
    //GETTER
    std::string getTaste() const;
    //SETTER
    void setTaste(const std::string&);
    //OPERATORI
    virtual bool operator ==(const Covered&);
    virtual bool operator !=(const Covered&);
    //CLONE
    virtual Covered *clone() const;
};

#endif // COVERED_H
