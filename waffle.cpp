#include <waffle.h>
#include <string>

Waffle::Waffle(const std::string &id) : ID(id) {}
Waffle::Waffle(const Waffle &w) : ID(w.getID()) {}

//GETTER
std::string Waffle::getID() const {return ID;}

//SETTER
void Waffle::setID(const std::string &id) {ID = id;}

//OPERATORI ==, !=
bool Waffle::operator ==(const Waffle &w) const {return ID == w.ID;}
bool Waffle::operator !=(const Waffle &w) const {return ID != w.ID;}

