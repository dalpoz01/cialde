#ifndef HEIGHTPROVIDERBOX_H
#define HEIGHTPROVIDERBOX_H
#include "wafflebox.h"

class HeightProviderBox : public WaffleBox {
private:
    u_int height;
public:
    HeightProviderBox(const std::string& nome=" ",const std::string& id=" ", const std::string &foto=" ", u_int = 0, u_int = 0, double = 0, u_int = 0, u_int = 0, u_int = 0);
    HeightProviderBox(const HeightProviderBox&);
    virtual ~HeightProviderBox() = default;

    //GETTER
    u_int getHeight() const;

    //SETTER
    void setHeight(u_int);

    //OPERATORI
    virtual bool operator ==(const HeightProviderBox&) const;
    virtual bool operator !=(const HeightProviderBox&) const;
    //CLONE
    virtual HeightProviderBox* clone() const = 0;

    virtual std::string printItem() const;
};

#endif // HEIGHTPROVIDERBOX_H
