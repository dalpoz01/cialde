#include "heightproviderbox.h"

HeightProviderBox::HeightProviderBox(const std::string& nome,const std::string &id, u_int c, u_int w, double p, u_int d, u_int s, u_int h) : WaffleBox(nome,id, c, w, p, d, s), height(h) {}
HeightProviderBox::HeightProviderBox(const HeightProviderBox &hp) : WaffleBox(hp.getName(),hp.getID(), hp.getCapacity(), hp.getWeight(), hp.getPrice(), hp.getDiscount(), hp.getStockAvailability()), height(hp.getHeight()) {}

//Getter
u_int HeightProviderBox::getHeight() const { return height;}

//Setter
void HeightProviderBox::setHeight(u_int h) {height = h;}

//Operatori
bool HeightProviderBox::operator ==(const HeightProviderBox& hp) const { return WaffleBox::operator ==(hp) && height == hp.height;}
bool HeightProviderBox::operator !=(const HeightProviderBox& hp) const { return WaffleBox::operator !=(hp) || height != hp.height;}

//STAMPA INFO
std::string HeightProviderBox::printItem() const{
    std::stringstream stream;
    stream <<
              WaffleBox::printItem() << std::endl
             << "Altezza: " << height << std::endl;
    return stream.str();
}
