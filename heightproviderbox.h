#ifndef HEIGHTPROVIDERBOX_H
#define HEIGHTPROVIDERBOX_H
#include "wafflebox.h"

class HeightProviderBox : public WaffleBox {
private:
    u_int height;
public:
    HeightProviderBox(const std::string& id=" ", u_int = 0, u_int = 0, double = 0, u_int = 0, u_int = 0);
    HeightProviderBox(const HeightProviderBox&);
    virtual ~HeightProviderBox() = default;

    //GETTER
    u_int getHeight() const;

    //SETTER
    void setHeight(u_int) const;

    //OPERATORI
    virtual bool operator ==(const HeightProviderBox&) const;
    virtual bool operator !=(const HeightProviderBox&) const;
    //CLONE
    virtual HeightProviderBox* clone() const = 0;
};

#endif // HEIGHTPROVIDERBOX_H
