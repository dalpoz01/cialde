#include "heightproviderbox.h"

HeightProviderBox::HeightProviderBox(const std::string &id, u_int c, u_int w, double p, u_int s, u_int h) : WaffleBox(id, c, w, p, s), height(h) {}
HeightProviderBox::HeightProviderBox(const HeightProviderBox &hp) : WaffleBox(hp.getID(), hp.getCapacity(), hp.getWeight(), hp.getPrice(), hp.getStockAvailability()), height(hp.getHeight()) {}

//Getter
u_int HeightProviderBox::getHeight() const { return height;}

//Setter
void HeightProviderBox::setHeight(u_int h) {height = h;}

//Operatori
bool HeightProviderBox::operator ==(const HeightProviderBox& hp) const { return WaffleBox::operator ==(hp) && height == hp.height;}
bool HeightProviderBox::operator !=(const HeightProviderBox& hp) const { return WaffleBox::operator !=(hp) || height != hp.height;}
