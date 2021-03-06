#ifndef VENTAGLIOBOX_H
#define VENTAGLIOBOX_H
#include "heightproviderbox.h"

//Classe concreta polimorfa
class VentaglioBox : public HeightProviderBox {
private:
     u_int width;
public:
    VentaglioBox(const std::string& nome=" ", const std::string& id=" ", const std::string& foto=" ", u_int = 0, u_int = 0, double = 0, u_int = 0, u_int = 0, u_int = 0, u_int = 0);
    VentaglioBox(const VentaglioBox&);
    virtual ~VentaglioBox() = default;

    //GETTER, SETTER
    u_int getWidth() const;
    void setWidth(u_int);

    //OPERATORI
    bool operator ==(const VentaglioBox&) const;
    bool operator !=(const VentaglioBox&) const;

    //CLONE
    virtual VentaglioBox *clone() const;
    std::string getItemType() const;

    virtual std::string printItem() const;
};

#endif // VENTAGLIOBOX_H
