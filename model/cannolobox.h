#ifndef CANNOLOBOX_H
#define CANNOLOBOX_H
#include "heightproviderbox.h"

//Classe concreta polimorfa
class CannoloBox : public HeightProviderBox {
private:
    u_int int_diameter;
public:
    //Costruttore, costruttore di copia, distruttore
    CannoloBox(const std::string& nome=" ", const std::string& id=" ", u_int = 0, u_int = 0, double = 0, u_int = 0, u_int = 0, u_int = 0, u_int = 0);
    CannoloBox(const CannoloBox&);
    virtual ~CannoloBox() = default;

    u_int getIntDiameter() const;
    void setIntDiameter(u_int);

    //OPERATORI
    bool operator ==(const CannoloBox&) const;
    bool operator !=(const CannoloBox&) const;

    //CLONE
    virtual CannoloBox *clone() const;

    std::string getItemType() const;

    virtual std::string printItem() const;
};

#endif // CANNOLOBOX_H
