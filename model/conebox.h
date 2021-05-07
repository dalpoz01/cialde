#ifndef CONEBOX_H
#define CONEBOX_H

#include "heightproviderbox.h"

//Classe concreta polimorfa
class ConeBox : public HeightProviderBox {
    private:
        u_int ext_diameter;
    public:
        //Costruttore, costruttore di copia e distruttore
        ConeBox(const std::string& = "", u_int = 0, u_int = 0, double = 0, u_int = 0,  u_int = 0, u_int = 0, u_int = 0);
        ConeBox(const ConeBox&);
        virtual ~ConeBox() = default;

        //Getter
        u_int getExtDiameter() const;

        //Setter
        void setExtDiameter(u_int);

        //Operatori
        virtual bool operator ==(const ConeBox&);
        virtual bool operator !=(const ConeBox&);

        //Clone
        virtual ConeBox *clone() const;

        std::string getItemType() const;
};

#endif // CONEBOX_H
