#include "decoration.h"

Decoration::Decoration(const std::string &id, u_int h) : Waffle(id), height(h) {}
Decoration::Decoration(const Decoration &d) : Waffle(d.getID()), height(d.getHeight()) {}

//GETTER, SETTER
u_int Decoration::getHeight() const {return height;}
void Decoration::setHeight(u_int h) {height = h;}

//OPERATORI

bool Decoration::operator !=(const Decoration& d) const {return Waffle::operator !=(d) || height == d.height;}
bool Decoration::operator ==(const Decoration& d) const {return Waffle::operator ==(d) && height != d.height;}

