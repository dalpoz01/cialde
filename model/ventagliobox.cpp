#include "ventagliobox.h"

//Costruttore, costruttore di copia
VentaglioBox::VentaglioBox(const std::string& nome, const std::string &id, const std::string &foto, u_int c, u_int w, double p, u_int d, u_int s, u_int h, u_int wd) : HeightProviderBox(nome, id, foto, c, w, p, d, s, h), width(wd) {}
VentaglioBox::VentaglioBox(const VentaglioBox &v) : HeightProviderBox(v.getName(), v.getID(), v.getPhoto(), v.getCapacity(), v.getWeight(), v.getPrice(), v.getDiscount(), v.getStockAvailability(), v.getHeight()), width(v.getWidth()) {}

//GETTER, SETTER
u_int VentaglioBox::getWidth() const { return width; }
void VentaglioBox::setWidth(u_int w) { width = w; }

//OPERATORI
bool VentaglioBox::operator !=(const VentaglioBox& v) const { return HeightProviderBox::operator !=(v) || width != v.width; }
bool VentaglioBox::operator ==(const VentaglioBox& v) const { return HeightProviderBox::operator ==(v) && width == v.width; }

//CLONE
VentaglioBox* VentaglioBox::clone() const { return new VentaglioBox(*this); }

std::string VentaglioBox::getItemType() const { return "Ventaglio Box"; }

//STAMPA INFO
std::string VentaglioBox::printItem() const {
    std::stringstream stream;
    stream <<
              HeightProviderBox::printItem() << std::endl
             << "Larghezza: " << width << std::endl;
    return stream.str();
}

