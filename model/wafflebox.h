#ifndef WAFFLEBOX_H
#define WAFFLEBOX_H
#include<string>
#include <sstream>

typedef unsigned int u_int;

//Classe BASE ASTRATTA POLIMORFA
class WaffleBox {
private:
    std::string name;
    std::string ID;
    std::string photo;
    u_int capacity;
    u_int weight;
    double price;
    u_int discount;
    u_int stockavailability;
public:
    WaffleBox(const std::string& nome=" ", const std::string& id=" ", const std::string& foto=" ", u_int = 0, u_int = 0, double = 0, u_int = 0, u_int = 0);
    WaffleBox(const WaffleBox& w);
    virtual ~WaffleBox() = default;

    //GETTER
    std::string getName() const;
    std::string getID() const;
    std::string getPhoto() const;
    u_int getCapacity() const;
    u_int getWeight() const;
    double getPrice() const;
    u_int getStockAvailability() const;
    u_int getDiscount() const;

    //SETTER
    void setName(const std::string &);
    void setID(const std::string&);
    void setPhoto(const std::string &);
    void setCapacity(u_int);
    void setWeight(u_int);
    void setPrice(double);
    void setStockAvailability(u_int);
    void setDiscount(u_int);

    //OPERATORI VARI
    virtual bool operator==(const WaffleBox&) const;
    virtual bool operator!=(const WaffleBox&) const;

    //CLONE
    virtual WaffleBox *clone() const = 0;
    virtual std::string getItemType() const = 0;

    //STAMPA INFO
    virtual std::string printItem() const;


};

#endif // WAFFLEBOX_H
