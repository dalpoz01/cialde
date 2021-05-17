#include "covered.h"

//Costruttore, costruttore di copia
Covered::Covered(const std::string &nome, const std::string &id, const std::string &foto, u_int c, u_int w, double p, u_int dis, u_int s, u_int h, u_int d, const std::string& tst) : ConeBox(nome, id, foto, c, w, p, dis, s, h, d), taste(tst) {}
Covered::Covered(const Covered& c): ConeBox(c.getName(), c.getID(), c.getPhoto(), c.getCapacity(), c.getWeight(), c.getPrice(), c.getDiscount(), c.getStockAvailability(), c.getHeight(), c.getExtDiameter()), taste(c.getTaste()){}

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

std::string Covered::printItem() const{
    std::stringstream stream;
    stream <<
              ConeBox::printItem() << std::endl
             << "Gusto: " << taste << std::endl;
    return stream.str();
}
