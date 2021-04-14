#include "ventagliobox.h"

Ventagli(const std::string &id, u_int c, u_int w, double p, u_int s, u_int h, u_int wd) : HeightProviderBox(id, c, w, p, s, h), width(wd) {}
Ventagli(const VentaglioBox &v) : HeightProviderBox(v.getID(), v.getCapacity(), v.getWeight(), v.getPrice(), v.getStockAvailability(), v.getHeight()), width(v.getWidth()) {}

//GETTER, SETTER
u_int getWidth() const {return width;}
void setWidth(u_int w) {width = w;}

//OPERATORI
bool VentaglioBox::operator !=(const VentaglioBox& v) const {return HeightProviderBox::operator !=(v) || width != v.getWidth();}
bool VentaglioBox::operator ==(const VentaglioBox& v) const {return HeightProviderBox::operator ==(v) && width == v.getWidth();}

//CLONE
VentaglioBox* VentaglioBox::clone() const {return new VentaglioBox(*this);}
