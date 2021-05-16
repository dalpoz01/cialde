#ifndef COVERED_H
#define COVERED_H

#include "conebox.h"

//Classe concreta polimorfa
class Covered: public ConeBox {
private:
    std::string taste;
public:
    //Costruttore, costruttore di copia e distruttore
    Covered(const std::string& ="",const std::string& = "", u_int = 0, u_int = 0, double = 0, u_int = 0, u_int = 0, u_int = 0, u_int = 0, const std::string& = "");
    Covered(const Covered&);
    virtual ~Covered() = default;

    //Getter
    std::string getTaste() const;

    //Setter
    void setTaste(const std::string&);

    //Operatori
    virtual bool operator ==(const Covered&);
    virtual bool operator !=(const Covered&);

    //Clone
    virtual Covered *clone() const;

    std::string getItemType() const;

    virtual std::string printItem() const;
};

#endif // COVERED_H
