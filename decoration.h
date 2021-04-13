#ifndef DECORATION_H
#define DECORATION_H
#include "waffle.h"
typedef unsigned int u_int;

//Classe polimorfa ASTRATTA
class Decoration : public Waffle {
private:
    u_int height;
public:
    Decoration(u_int = 0, const std::string& = "");
    Decoration(const Decoration&);
    virtual ~Decoration() = default;

    //GETTER, SETTER
    u_int getHeight() const;
    void setHeight(u_int);

    //OPERATORI
    bool operator !=(const Decoration&) const;
    bool operator ==(const Decoration&) const;
};

#endif // DECORATION_H
