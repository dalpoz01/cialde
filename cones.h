#ifndef CONES_H
#define CONES_H

#include "waffle.h"

class Cones : public Waffle{
    private:
        u_int ext_diameter;
        u_int height;
    public:
        //Costruttore, costruttore di copia e distruttore
        Cones(const std::string& = "", u_int = 0, u_int = 0);
        Cones(const Cones&);
        virtual ~Cones() = default;
        //GETTER
        u_int getExtDiameter() const;
        u_int getHeight() const;
        //SETTER
        void setExtDiameter(u_int);
        void setHeight(u_int);
        //OPERATORI
        virtual bool operator ==(const Cones&);
        virtual bool operator !=(const Cones&);
        //CLONE
        virtual Cones *clone() const;
};

#endif // CONES_H
