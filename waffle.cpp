#include "waffle.h"

Waffle::Waffle(const std::string& id) : ID(id) {} //Costruttore

Waffle::Waffle(const Waffle &w) :  ID(w.ID) {} // Costruttore di copia

//GETTER
std::string getID() const {return ID;}

//SETTER
void setID(const std::string id) {ID=id;}

//OPERATORI VARI
bool Waffle::operator==(const Waffle& w) const {return ID == w.ID}

bool Waffle::operator!=(const Waffle& w) const {return ID != w.ID}

//CLONE
