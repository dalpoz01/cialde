#include "cones.h"
//Costruttore
Cones::Cones(const std::string& id, u_int dia_est, u_int alt):
    Waffle(id), ext_diameter(dia_est), height(alt){}

//Costruttore di copia
Cones::Cones(const Cones& c):
    Waffle(c.getID()),ext_diameter(c.getExtDiameter()),height(c.getHeight()){}

//Getter
u_int Cones::getExtDiameter() const{return ext_diameter;}
u_int Cones::getHeight() const{return height;}

//Setter
void Cones::setExtDiameter(u_int diam){ext_diameter=diam;}
void Cones::setHeight(u_int alt){height=alt;}

//Operatori
bool Cones::operator ==(const Cones&c) {return Waffle::operator ==(c) && ext_diameter == c.ext_diameter && height == c.height;}
bool Cones::operator !=(const Cones&c) {return Waffle::operator !=(c) || ext_diameter != c.ext_diameter || height == c.height;}

//Clone
Cones* Cones::clone() const {return new Cones(*this);}
