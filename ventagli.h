#ifndef VENTAGLI_H
#define VENTAGLI_H
#include "decoration.h"
typedef unsigned int u_int;

class Ventagli : public Decoration {
private:
     u_int width;
public:
    Ventagli(u_int = 0, const std::string& = "", u_int = 0);
    Ventagli(const Ventagli&);
    virtual ~Ventagli() = default;

    //GETTER, SETTER
    u_int getWidth() const;
    void setWidth(u_int);

    //OPERATORI
    bool operator ==(const Ventagli&) const;
    bool operator !=(const Ventagli&) const;

    //CLONE
    virtual Ventagli *clone() const;
};

#endif // VENTAGLI_H
