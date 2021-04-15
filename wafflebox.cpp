#include "wafflebox.h"

WaffleBox::WaffleBox(const std::string &id, u_int c, u_int w, double p, u_int s) : ID(id), capacity(c), weight(w), price(p), stockavailability(s) {}
WaffleBox::WaffleBox(const WaffleBox &w) : ID(w.getID()), capacity(w.getCapacity()), weight(w.getWeight()), price(w.getPrice()), stockavailability(w.getStockAvailability()) {}

//GETTER
std::string WaffleBox::getID() const {return ID;}
u_int WaffleBox::getCapacity() const {return capacity;}
u_int WaffleBox::getWeight() const {return weight;}
double WaffleBox::getPrice() const {return price;}
u_int WaffleBox::getStockAvailability() const {return stockavailability;}

//SETTER
void WaffleBox::setID(const std::string &id) {ID = id;}
void WaffleBox::setCapacity(u_int c) {capacity = c;}
void WaffleBox::setWeight(u_int w) {weight = w;}
void WaffleBox::setPrice(double p) {price = p;}
void WaffleBox::setStockAvailability(u_int s) {stockavailability = s;}

//OPERATORI ==, !=
bool WaffleBox::operator ==(const WaffleBox &w) const {return ID == w.ID && capacity == w.capacity && weight == w.weight && price == w.price && stockavailability == w.stockavailability;}
bool WaffleBox::operator !=(const WaffleBox &w) const {return ID != w.ID || capacity != w.capacity || weight != w.weight || price != w.price || stockavailability != w.stockavailability;;}

