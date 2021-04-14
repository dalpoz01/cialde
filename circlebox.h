#ifndef CIRCLEBOX_H
#define CIRCLEBOX_H
#include "wafflebox.h"

class CircleBox : public WaffleBox {
    private:
        u_int radius;
    public:
        CircleBox(const std::string& id=" ", u_int = 0, u_int = 0, double = 0, u_int = 0, u_int = 0);
        CircleBox(const CircleBox&);
        virtual ~CircleBox() = default;

        //GETTER
        u_int getRadius() const;

        //SETTER
        void setRadius(u_int);

        //OPERATORI
        virtual bool operator ==(const CircleBox&);
        virtual bool operator !=(const CircleBox&);

        //CLONE
        virtual CircleBox *clone() const;
};

#endif // CIRCLEBOX_H
