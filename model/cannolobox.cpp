#include "cannolobox.h"

//Costruttore, costruttore di copia
CannoloBox::CannoloBox(const std::string &id, u_int c, u_int w, double p, u_int d, u_int s, u_int h, u_int int_d) : HeightProviderBox(id, c, w, p, d, s, h), int_diameter(int_d) {}
CannoloBox::CannoloBox(const CannoloBox& c) : HeightProviderBox(c.getID(), c.getCapacity(), c.getWeight(), c.getPrice(), c.getDiscount(), c.getStockAvailability(), c.getHeight()), int_diameter(c.getIntDiameter()) {}

//Getter, Setter
u_int CannoloBox::getIntDiameter() const {return int_diameter;}
void CannoloBox::setIntDiameter(u_int value){int_diameter = value;}

//Operatori
bool CannoloBox::operator ==(const CannoloBox& c) const {return HeightProviderBox::operator ==(c) && int_diameter == c.int_diameter;}
bool CannoloBox::operator !=(const CannoloBox& c) const {return HeightProviderBox::operator !=(c) || int_diameter != c.int_diameter;}

//Clone
CannoloBox* CannoloBox::clone() const{return new CannoloBox(*this);}

std::string CannoloBox::getItemType() const{return "CannoloBox";}
