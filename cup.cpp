#include "cup.h"

//Costruttore
Cup::Cup(const std::string& id, u_int dia_est, u_int alt, const std::string& br, u_int dia_int):
    Cones(id,dia_est,alt,br), int_diameter(dia_int){}

//Costruttore di copia
Cup::Cup(const Cup& c):
    Cones(c.getID(),c.getExtDiameter(),c.getHeight(),c.getBrand()),int_diameter(c.getIntDiameter()){}

//Getter
u_int Cup::getIntDiameter() const{return int_diameter;}

//Setter
void Cup::setIntDiameter(u_int dia_int){int_diameter=dia_int;}

//Operatori
bool Cup::operator ==(const Cup&c) {return Cones::operator ==(c) && int_diameter == c.int_diameter;}
bool Cup::operator !=(const Cup&c) {return Cones::operator !=(c) || int_diameter != c.int_diameter;}

//Clone
Cup* Cup::clone() const {return new Cup(*this);}
