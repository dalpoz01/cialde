#include "cup.h"

//Costruttore
Cup::Cup(const std::string& id, u_int dia_est, u_int alt, const std::string& br):
    Cones(id,dia_est,alt), brand(br){}

//Costruttore di copia
Cup::Cup(const Cup& c):
    Cones(c.getID(),c.getExtDiameter(),c.getHeight()),brand(c.getBrand()){}

//Getter
std::string Cup::getBrand() const{return brand;}

//Setter
void Cup::setBrand(const std::string& br){brand=br;}

//Operatori
bool Cup::operator ==(const Cup&c) {return Cones::operator ==(c) && brand == c.brand;}
bool Cup::operator !=(const Cup&c) {return Cones::operator !=(c) || brand != c.brand;}

//Clone
Cup* Cup::clone() const {return new Cup(*this);}
