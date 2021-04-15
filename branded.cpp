#include "branded.h"

//Costruttore, costruttore di copia
Branded::Branded(const std::string &id, u_int c, u_int w, double p, u_int s, u_int h, u_int d, const std::string& princ, const std::string& sec) : ConeBox(id, c, w, p, s, h, d), principal_color(princ), secondary_color(sec) {}
Branded::Branded(const Branded& b): ConeBox(b.getID(), b.getCapacity(), b.getWeight(), b.getPrice(), b.getStockAvailability(), b.getHeight(), b.getExtDiameter()), principal_color(b.getPrincipalColor()), secondary_color(b.getSecundaryColor()) {}

//Getter
std::string Branded::getPrincipalColor() const{return principal_color;}
std::string Branded::getSecundaryColor() const{return secondary_color;}

//Setter
void Branded::setPrincipalColor(const std::string& col) {principal_color=col;}
void Branded::setSecundaryColor(const std::string& col) {secondary_color=col;}

//Operatori
bool Branded::operator ==(const Branded& b) {return ConeBox::operator ==(b) && principal_color == b.principal_color && secondary_color == b.secondary_color;}
bool Branded::operator !=(const Branded& b) {return ConeBox::operator !=(b) || principal_color != b.principal_color || secondary_color != b.secondary_color;}

//Clone
Branded* Branded::clone() const {return new Branded(*this);}
