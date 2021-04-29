#include "conebox.h"
//Costruttore
ConeBox::ConeBox(const std::string &id, u_int c, u_int w, double p, u_int s, u_int h, u_int d): HeightProviderBox(id, c, w, p, s, h), ext_diameter(d) {}

//Costruttore di copia
ConeBox::ConeBox(const ConeBox& c): HeightProviderBox(c.getID(), c.getCapacity(), c.getWeight(), c.getPrice(), c.getStockAvailability(), c.getHeight()), ext_diameter(c.getExtDiameter()) {}

//Getter
u_int ConeBox::getExtDiameter() const{return ext_diameter;}

//Setter
void ConeBox::setExtDiameter(u_int diam){ext_diameter = diam;}


//Operatori
bool ConeBox::operator ==(const ConeBox& c) {return HeightProviderBox::operator ==(c) && ext_diameter == c.ext_diameter;}
bool ConeBox::operator !=(const ConeBox& c) {return HeightProviderBox::operator !=(c) || ext_diameter != c.ext_diameter;}

//Clone
ConeBox* ConeBox::clone() const {return new ConeBox(*this);}