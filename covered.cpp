#include "covered.h"

//Costruttore
Covered::Covered(const std::string& id, u_int dia_est, u_int alt, const std::string& ts):
    Cones(id,dia_est,alt), taste(ts){}

//Costruttore di copia
Covered::Covered(const Covered& c):
    Cones(c.getID(),c.getExtDiameter(),c.getHeight()),taste(c.getTaste()){}

//Getter
std::string Covered::getTaste() const{return taste;}

//Setter
void Covered::setTaste(const std::string& ts){taste=ts;}

//Operatori
bool Covered::operator ==(const Covered&c) {return Cones::operator ==(c) && taste == c.taste;}
bool Covered::operator !=(const Covered&c) {return Cones::operator !=(c) || taste != c.taste;}

//Clone
Covered* Covered::clone() const {return new Covered(*this);}
