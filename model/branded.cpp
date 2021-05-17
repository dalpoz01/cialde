#include "branded.h"

//Costruttore, costruttore di copia
Branded::Branded(const std::string& nome, const std::string &id, const std::string &foto, u_int c, u_int w, double p, u_int dis, u_int s, u_int h, u_int d, const std::string& princ, const std::string& sec) : ConeBox(nome, id, foto, c, w, p, dis, s, h, d), principal_color(princ), secondary_color(sec) {}
Branded::Branded(const Branded& b): ConeBox(b.getName(), b.getID(), b.getPhoto(), b.getCapacity(), b.getWeight(), b.getPrice(), b.getDiscount(), b.getStockAvailability(), b.getHeight(), b.getExtDiameter()), principal_color(b.getPrincipalColor()), secondary_color(b.getSecundaryColor()) {}

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

std::string Branded::getItemType() const{return "BrandedBox";}

std::string Branded::printItem() const{
    std::stringstream stream;
    stream <<
              ConeBox::printItem() << std::endl
             << "Colore principale: " << principal_color << std::endl
             << "Colore secondario: " << principal_color << std::endl;
    return stream.str();
}
