#include "covered.h"

//Costruttore, costruttore di copia
Covered::Covered(const std::string &id, u_int c, u_int w, double p, u_int dis, u_int s, u_int h, u_int d, const std::string& tst) : ConeBox(id, c, w, p, dis, s, h, d), taste(tst) {}
Covered::Covered(const Covered& c): ConeBox(c.getID(), c.getCapacity(), c.getWeight(), c.getPrice(), c.getDiscount(), c.getStockAvailability(), c.getHeight(), c.getExtDiameter()), taste(c.getTaste()){}

//Getter
std::string Covered::getTaste() const{return taste;}

//Setter
void Covered::setTaste(const std::string& ts){taste=ts;}

//Operatori
bool Covered::operator ==(const Covered&c) {return ConeBox::operator ==(c) && taste == c.taste;}
bool Covered::operator !=(const Covered&c) {return ConeBox::operator !=(c) || taste != c.taste;}

//Clone
Covered* Covered::clone() const {return new Covered(*this);}

std::string Covered::getItemType() const{return "CoveredBox";}
