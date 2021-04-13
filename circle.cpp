#include "circle.h"
//Costruttore
Circle::Circle(const std::string& id, u_int d): Waffle(id), diametro(d){}

//Costruttore di copia
Circle::Circle(const Circle& c): Waffle(c.getID()), diametro(c.getDiametro()){}

//Getter
u_int Circle::getDiametro() const{return diametro;}

//Setter
void Circle::setDiametro(u_int diam){diametro=diam;}

//Operatori
bool Circle::operator ==(const Circle&c) {return Waffle::operator ==(c)&&diametro==c.diametro;}
bool Circle::operator !=(const Circle&c) {return Waffle::operator !=(c)||diametro!=c.diametro;}

//Clone
Circle* Circle::clone() const {return new Circle(*this);}
