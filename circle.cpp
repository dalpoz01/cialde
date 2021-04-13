#include "circle.h"
//Costruttore
Circle::Circle(const std::string& id, unsigned int d):Waffle(id),Circle(d){}

//Costruttore di copia
Circle::Circle(const Circle& c):Waffle(c.getID(),diametro(c.getDiametro())){}

//Getter
unsigned int Circle::getDiametro() const{return diametro;}

//Setter
void Circle::setDiametro(unsigned int diam){diametro=diam;}

//Operatori
bool Circle::operator ==(const Circle&c) {return Waffle::operator ==(c)&&diametro==c.diametro;}
bool Circle::operator !=(const Circle&c) {return Waffle::operator !=(c)||diametro!=c.diametro;}

//Clone
Circle* Circle::clone() const {return new Circle(*this);}
