#include "ventagli.h"

Ventagli::Ventagli(u_int h, const std::string &id, u_int w) : Decoration(h,id), width(w) {}
Ventagli::Ventagli(const Ventagli &v) : Decoration(v.getHeight(),v.getID()), width(v.getWidth()) {}

//GETTER, SETTER
u_int Ventagli::getWidth() const {return width;}
void Ventagli::setWidth(u_int w) {width = w;}

//OPERATORI
bool Ventagli::operator !=(const Ventagli& v) const {return Decoration::operator !=(v) || width != v.getWidth();}
bool Ventagli::operator ==(const Ventagli& v) const {return Decoration::operator ==(v) && width == v.getWidth();}

//CLONE
Ventagli* Ventagli::clone() const {return new Ventagli(*this);}
