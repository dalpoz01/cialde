#ifndef CONEBOX_H
#define CONEBOX_H

#include "heightproviderbox.h"

class ConeBox : public HeightProviderBox {
    private:
        u_int ext_diameter;
    public:
        //Costruttore, costruttore di copia e distruttore
        ConeBox(const std::string& id=" ", u_int = 0, u_int = 0, double = 0, u_int = 0, u_int = 0);
        ConeBox(const ConeBox&);
        virtual ~ConeBox() = default;
        //GETTER
        u_int getExtDiameter() const;

        //SETTER
        void setExtDiameter(u_int);

        //OPERATORI
        virtual bool operator ==(const ConeBox&);
        virtual bool operator !=(const ConeBox&);
        //CLONE
        virtual ConeBox *clone() const;
};

#endif // CONEBOX_H
