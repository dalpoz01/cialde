#include "conebox.h"

//Costruttore
ConeBox::ConeBox(const std::string& nome, const std::string &id, const std::string &foto, u_int c, u_int w, double p, u_int dis, u_int s, u_int h, u_int d): HeightProviderBox(nome, id, foto, c, w, p, dis, s, h), ext_diameter(d) {}

//Costruttore di copia
ConeBox::ConeBox(const ConeBox& c): HeightProviderBox(c.getName(), c.getID(), c.getPhoto(), c.getCapacity(), c.getWeight(), c.getPrice(), c.getDiscount(), c.getStockAvailability(), c.getHeight()), ext_diameter(c.getExtDiameter()) {}

//Getter
u_int ConeBox::getExtDiameter() const { return ext_diameter; }

//Setter
void ConeBox::setExtDiameter(u_int diam) { ext_diameter = diam; }

//Operatori
bool ConeBox::operator ==(const ConeBox& c) { return HeightProviderBox::operator ==(c) && ext_diameter == c.ext_diameter; }
bool ConeBox::operator !=(const ConeBox& c) { return HeightProviderBox::operator !=(c) || ext_diameter != c.ext_diameter; }

//Clone
ConeBox* ConeBox::clone() const { return new ConeBox(*this); }

std::string ConeBox::getItemType() const { return "Cone Box"; }

std::string ConeBox::printItem() const {
    std::stringstream stream;
    stream <<
              HeightProviderBox::printItem() << std::endl
             << "Diametro esterno: " << ext_diameter << std::endl;
    return stream.str();
}
