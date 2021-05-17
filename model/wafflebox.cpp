#include "wafflebox.h"

WaffleBox::WaffleBox(const std::string &nome, const std::string &id, const std::string &foto, u_int c, u_int w, double p, u_int d, u_int s) : Name(nome), ID(id), photo(foto), capacity(c), weight(w), price(p), discount(d), stockavailability(s) {}
WaffleBox::WaffleBox(const WaffleBox &w) : Name(w.getName()), ID(w.getID()), photo(w.getPhoto()), capacity(w.getCapacity()), weight(w.getWeight()), price(w.getPrice()), discount(w.getDiscount()), stockavailability(w.getStockAvailability()) {}

//GETTER
std::string WaffleBox::getName() const{return Name;}
std::string WaffleBox::getID() const {return ID;}
std::string WaffleBox::getPhoto() const{return photo;}
u_int WaffleBox::getCapacity() const {return capacity;}
u_int WaffleBox::getWeight() const {return weight;}
double WaffleBox::getPrice() const {return price;}
u_int WaffleBox::getStockAvailability() const {return stockavailability;}
u_int WaffleBox::getDiscount() const{return discount;}

//SETTER
void WaffleBox::setName(const std::string &value){Name = value;}
void WaffleBox::setID(const std::string &id) {ID = id;}
void WaffleBox::setPhoto(const std::string &value){photo = value;}
void WaffleBox::setCapacity(u_int c) {capacity = c;}
void WaffleBox::setWeight(u_int w) {weight = w;}
void WaffleBox::setPrice(double p) {price = p;}
void WaffleBox::setStockAvailability(u_int s) {stockavailability = s;}
void WaffleBox::setDiscount(u_int dis) {discount = dis;}

//OPERATORI ==, !=
bool WaffleBox::operator ==(const WaffleBox &w) const {return ID == w.ID && capacity == w.capacity && weight == w.weight && price == w.price && discount == w.discount && stockavailability == w.stockavailability;}
bool WaffleBox::operator !=(const WaffleBox &w) const {return ID != w.ID || capacity != w.capacity || weight != w.weight || price != w.price || discount != w.discount || stockavailability != w.stockavailability;;}

//STAMPA INFO
std::string WaffleBox::printItem() const{
    std::stringstream stream;
    stream <<
              "------------------------------------" << std::endl
             << "Nome: " << Name <<std::endl
             << "ID: " << ID << std::endl
             << "Capacità: " << capacity << std::endl
             << "Peso: " << weight << std::endl
             << "Prezzo: " << price << std::endl
             << "Sconto: " << discount << std::endl
             << "Stock: " << stockavailability << std::endl;
    return stream.str();
}
