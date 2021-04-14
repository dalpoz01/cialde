#ifndef WAFFLEBOX_H
#define WAFFLEBOX_H
#include<string>
typedef unsigned int u_int;

//Classe BASE ASTRATTA POLIMORFA
class WaffleBox {
private:
    std::string ID;
    u_int capacity;
    u_int weight;
    double price;
    u_int stockavailability;
public:
    WaffleBox(const std::string& id=" ", u_int = 0, u_int = 0, double = 0, u_int = 0);
    WaffleBox(const WaffleBox& w);
    virtual ~WaffleBox() = default;

    //GETTER
    std::string getID() const;
    u_int getCapacity() const;
    u_int getWeight() const;
    double getPrice() const;
    u_int getStockAvailability() const;

    //SETTER
    void setID(const std::string&);
    void setCapacity(u_int);
    void setWeight(u_int);
    void setPrice(double);
    void setStockAvailability(u_int);

    //OPERATORI VARI
    virtual bool operator==(const WaffleBox&) const;
    virtual bool operator!=(const WaffleBox&) const;

    //CLONE
    virtual WaffleBox *clone() const = 0;

};

#endif // WAFFLEBOX_H
