#ifndef CONES_H
#define CONES_H

#include "waffle.h"

class Cones : public Waffle{
    private:
        unsigned int diametro_esterno;
        unsigned int altezza;
        std::string brand;
    public:
        //Costruttore, costruttore di copia e distruttore
        Cones(const std::string& = "", unsigned int = 0, unsigned int = 0, std::string& ="");
        Cones(const Cones&);
        virtual ~Cones() = default;
        //GETTER
        unsigned int getDiametroEsterno() const;
        unsigned int getAltezza() const;
        std::string getBrand() const;
        //SETTER
        void setDiametroEsterno(unsigned int);
        unsigned int setAltezza() const;
        std::string setBrand() const;
        //OPERATORI
        virtual bool operator ==(const Cones&);
        virtual bool operator !=(const Cones&);
        //CLONE
        virtual Cones *clone() const;
};

#endif // CONES_H
