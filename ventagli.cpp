#include "ventagli.h"

Ventagli::Ventagli(const std::string &id, u_int h, u_int w) : Decoration(id,h), width(w) {}
Ventagli::Ventagli(const Ventagli &v) : Decoration(v.getID(),v.getHeight()), width(v.getWidth()) {}

//GETTER, SETTER
u_int Ventagli::getWidth() const {return width;}
void Ventagli::setWidth(u_int w) {width = w;}

//OPERATORI
bool Ventagli::operator !=(const Ventagli& v) const {return Decoration::operator !=(v) || width != v.getWidth();}
bool Ventagli::operator ==(const Ventagli& v) const {return Decoration::operator ==(v) && width == v.getWidth();}

//CLONE
Ventagli* Ventagli::clone() const {return new Ventagli(*this);}
