#ifndef BRANDED_H
#define BRANDED_H
#include "conebox.h"

class Branded : public ConeBox {
private:
    std::string principal_color;
    std::string secondary_color;
public:
    Branded(const std::string& = "", u_int = 0, u_int = 0, double = 0, u_int = 0, u_int = 0, u_int = 0, const std::string& = "", const std::string& = "");
    Branded(const Branded&);

    //Getter, setter
    std::string getPrincipalColor() const;
    std::string getSecundaryColor() const;

    void setPrincipalColor(const std::string&);
    void setSecundaryColor(const std::string&);

    //Operatori
    virtual bool operator ==(const Branded&);
    virtual bool operator !=(const Branded&);

    //Clone
    virtual Branded *clone() const;

};

#endif // BRANDED_H
