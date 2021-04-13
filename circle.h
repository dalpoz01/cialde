#ifndef CIRCLE_H
#define CIRCLE_H

#include "waffle.h"
class Circle : public Waffle{
    private:
        unsigned int diametro;
    public:
        //Costruttore, costruttore di copia e distruttore
        Circle(const std::string& = "", unsigned int = 0);
        Circle(const Circle&);
        virtual ~Circle() = default;
        //GETTER
        unsigned int getDiametro() const;
        //SETTER
        void setDiametro(unsigned int);
        //OPERATORI
        virtual bool operator ==(const Circle&);
        virtual bool operator !=(const Circle&);
        //CLONE
        virtual Circle *clone() const;
};

#endif // CIRCLE_H
