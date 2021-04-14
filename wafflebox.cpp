#include "wafflebox.h"

WaffleBox(const std::string &id, u_int c, u_int w, double p, u_int s) : ID(id), capacity(c), weight(w), price(p), stockavailability(s) {}
WaffleBox(const WaffleBox &w) : ID(w.getID()), capacity(w.getCapacity()), weight(w.getWeight()), price(w.getPrice()), stockavailability(w.getStockAvailability()) {}

//GETTER
std::string getID() const {return ID;}
u_int getCapacity() const {return capacity;}
u_int getWeight() const {return weight;}
double getPrice() const {return price;}
u_int getStockAvailability() const {return stockavailability;}

//SETTER
void setID(const std::string &id) {ID = id;}
void setCapacity(u_int c) {capacity = c;}
void setWeight(u_int w) {weight = w;}
void setPrice(double p) {price = p;}
void setStockAvailability(u_int s) {stockavailability = s;}

//OPERATORI ==, !=
bool WaffleBox::operator ==(const WaffleBox &w) const {return ID == w.ID && capacity == w.capacity && weight == w.weight && price == w.price && stockavailability == w.stockavailability;}
bool WaffleBox::operator !=(const WaffleBox &w) const {return ID != w.ID || capacity != w.capacity || weight != w.weight || price != w.price || stockavailability != w.stockavailability;;}

