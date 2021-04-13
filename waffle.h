#ifndef WAFFLE_H
#define WAFFLE_H
#include<string>

//Classe BASE ASTRATTA POLIMORFA
class Waffle {
private:
    std::string ID;
public:
    Waffle(const std::string& id=" ");   //Costruttore
    Waffle(const Waffle& w);    //Costruttore di copia
    virtual ~Waffle() = default;    //Distruttore

    //GETTER
    std::string getID() const;

    //SETTER
    void setID(const std::string&);

    //OPERATORI VARI
    virtual bool operator==(const Waffle&) const;
    virtual bool operator!=(const Waffle&) const;

    //CLONE
    virtual Waffle *clone() const = 0;

};

#endif // WAFFLE_H
