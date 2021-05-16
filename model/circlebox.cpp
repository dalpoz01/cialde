#include "circlebox.h"

//Costruttore
CircleBox::CircleBox(const std::string &nome,const std::string &id, u_int c, u_int w, double p, u_int dis, u_int s, u_int d): WaffleBox(nome, id, c, w, p, dis, s), radius(d) {}

//Costruttore di copia
CircleBox::CircleBox(const CircleBox& c): WaffleBox(c.getName(),c.getID(), c.getCapacity(), c.getWeight(), c.getPrice(), c.getDiscount(), c.getStockAvailability()), radius(c.getRadius()){}

//Getter
u_int CircleBox::getRadius() const{return radius;}

//Setter
void CircleBox::setRadius(u_int r){radius=r;}

//Operatori
bool CircleBox::operator ==(const CircleBox &c) {return WaffleBox::operator ==(c) && radius==c.radius;}
bool CircleBox::operator !=(const CircleBox &c) {return WaffleBox::operator !=(c) || radius!=c.radius;}

//Clone
CircleBox* CircleBox::clone() const {return new CircleBox(*this);}

std::string CircleBox::getItemType() const{return "CircleBox";}

//STAMPA INFO
std::string CircleBox::printItem() const{
    std::stringstream stream;
    stream <<
              WaffleBox::printItem() << std::endl
             << "Raggio (mm): " << radius << std::endl;
    return stream.str();
}
