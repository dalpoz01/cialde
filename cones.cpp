#include "cones.h"
//Costruttore
Cones::Cones(const std::string& id, unsigned int dia_est, unsigned int alt, const std::string& br):
    Waffle(id),diametro_esterno(dia_est),altezza(alt),brand(br){}

//Costruttore di copia
Cones::Cones(const Cones& c):
    Waffle(c.getID(),diametro_esterno(c.getDiametroEsterno(),altezza(c.getAltezza(),brand(c.getBrand())))){}

//Getter
unsigned int Cones::getDiametroEsterno() const{return diametro_esterno;}
unsigned int Cones::getAltezza() const{return altezza;}
std::string Cones::getBrand() const{return brand;}

//Setter
void Cones::setDiametroEsterno(unsigned int diam){diametro_esterno=diam;}
void Cones::setAltezza(unsigned int alt){altezza=alt;}
void Cones::getBrand(const std::string &br){brand=br;}

//Operatori
bool Cones::operator ==(const Cones&c) {return Waffle::operator ==(c)&&diametro_esterno==c.diametro_esterno&&altezza==c.altezza&&brand==c.brand;}
bool Cones::operator !=(const Cones&c) {return Waffle::operator !=(c)||diametro_esterno!=c.diametro_esterno||altezza==c.altezza||brand==c.brand;}

//Clone
Cones* Cones::clone() const {return new Cones(*this);}
