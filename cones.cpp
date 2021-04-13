#include "cones.h"
//Costruttore
Cones::Cones(const std::string& id, u_int dia_est, u_int alt, const std::string& br):
    Waffle(id), ext_diameter(dia_est), height(alt), brand(br){}

//Costruttore di copia
Cones::Cones(const Cones& c):
    Waffle(c.getID()),ext_diameter(c.getExtDiameter()),height(c.getHeight()),brand(c.getBrand()){}

//Getter
u_int Cones::getExtDiameter() const{return ext_diameter;}
u_int Cones::getHeight() const{return height;}
std::string Cones::getBrand() const{return brand;}

//Setter
void Cones::setExtDiameter(u_int diam){ext_diameter=diam;}
void Cones::setHeight(u_int alt){height=alt;}
void Cones::setBrand(const std::string &br){brand=br;}

//Operatori
bool Cones::operator ==(const Cones&c) {return Waffle::operator ==(c) && ext_diameter == c.ext_diameter && height == c.height && brand == c.brand;}
bool Cones::operator !=(const Cones&c) {return Waffle::operator !=(c) || ext_diameter != c.ext_diameter || height == c.height || brand == c.brand;}

//Clone
Cones* Cones::clone() const {return new Cones(*this);}
