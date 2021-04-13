#ifndef CONES_H
#define CONES_H

#include "waffle.h"

class Cones : public Waffle{
    private:
        u_int diametro_esterno;
        u_int altezza;
        std::string brand;
    public:
        //Costruttore, costruttore di copia e distruttore
        Cones(const std::string& = "", u_int = 0, u_int = 0, const std::string& ="");
        Cones(const Cones&);
        virtual ~Cones() = default;
        //GETTER
        u_int getDiametroEsterno() const;
        u_int getAltezza() const;
        std::string getBrand() const;
        //SETTER
        void setDiametroEsterno(u_int);
        void setAltezza(u_int);
        void setBrand(const std::string&);
        //OPERATORI
        virtual bool operator ==(const Cones&);
        virtual bool operator !=(const Cones&);
        //CLONE
        virtual Cones *clone() const;
};

#endif // CONES_H
