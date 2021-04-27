#ifndef CONTAINER_H
#define CONTAINER_H
using namespace std;
typedef unsigned int u_int;
/*
*    METODI
*    Distruttore -> viene deallocata la memoria di ogni cosa contenuta dal contenitore
*    Size_type size()
*/
template<class T>
class Container {
private:
    u_int size; //Quanti elementi sono memorizzati
    u_int capacity; //Quanti elementi posso memorizzare
    T *p;

    void resize();
public:
    //Costruttore standard
    Container(u_int = 1, u_int = 0);
    //Fill constructor, cioè crea il contenitore avente n copie di t.
    Container(const T&, u_int);
    //costruttore di copia
    Container(const Container&);
    //distruttore
    ~Container();

    //OPERATORI
    Container& operator =(const Container&);
    T& operator[](u_int);
    const T& operator[](u_int) const;
    bool operator ==(const Container&) const;
    bool operator !=(const Container&) const;
    bool operator <(const Container&) const;
    bool operator >(const Container&) const;
    bool operator <=(const Container&) const;
    bool operator >=(const Container&) const;

    //METODI
    bool empty() const;
    void clear();
    void push_back(const T&);
    void pop_back();
    u_int getSize() const;
    u_int getCapacity() const;
    void erase(u_int,u_int); //toglie elementi tra due indici
    void erase(u_int);  //toglie elemento in quell'indice

};

//Costruttore standard
template<class T>
Container<T>::Container(u_int s, u_int c) : size(s), capacity(c), p(new T[c]) {}

//Costruttore di copia
template<class T>
Container<T>::Container(const Container<T> &c) : size(c.size), capacity(c.capacity), p(new T[c.capacity])
    {for(u_int = 0; i<size; ++i) p[i] = c.p[i];}

//FIll constructor
template<class T>
Container<T>::Container(const T &t, u_int n) : size(n), capacity(n), p(new T[n])
    {for(u_int i = 0; i<n; ++i) p[i] = t;}

//Distruttore
template<class T>
Container<T>::~Container<T>() {if(p) delete[] p;}

//Resize, necessaria nel caso si volesse aggiungere un elemento nel container e size==capacity
template<class T>
void Container<T>::resize(){
    capacity=capacity*2;
    T* temp = new T[capacity];  //Creo temp con capacità doppia.
    for(u_int = 0; i<size; ++i)
        temp[i] = p[i];
    delete[] p;s
    p = temp;
}

/**** METODI *****/

template<class T>
bool Container<T>::empty() const{return size==0;}

template<class T>
void Container<T>::clear(){if(p) delete[] p; p = new T[1]; size=0;}

template<class T>
void Container<T>::push_back(const T& t){if(size == capacity) resize(); p[size] = t; size++;} //size è l'ultimo elemento

template<class T>
void Container<T>::pop_back(){if(size > 0) size--;};

template<class T>
u_int Container<T>::getSize() const {return size;}

template<class T>
u_int Container<T>::getCapacity() const {return capacity;}

template<class T>
void Container<T>::erase(u_int first, u_int last){  //DA COMPLETARE
    if(first>last) throw std::out_of_range("Errore.");
    u_int k = last;
    for(u_int i = first; k<size; ++i, k++) p[i] = p[k]; //scorro dal primo elemento dopo il range di elementi [first-last], e assegno partendo da first gli elementi successivi all'indice last.

    size -= (last-first)+1; //dimensione effettiva diventa la dimensione precedente MENO gli elementi di cui si è fatto l'erase.

}

template<class T>
void Container<T>::erase(u_int position){
    if(position >= size || position < 0) throw std::out_of_range("Index not valid.");
    for(u_int i = position; i<size; ++i)
        p[i] = p[i+1];
    size--;
}
/**** OPERATORI *****/

//operator=
template<class T>
Container<T>& Container<T>::operator =(const Container<T>& ctr){
    if(this != &ctr){
        size = ctr.size;
        capacity = ctr.capacity;
        //Devo eliminare il puntatore corrente
        delete [] p;
        //Creo il puntatore ad array con CAPACITA'(effettiva memoria occupata) del container passato per parametro, non la size!
        p = new T[ctr.capacity];
        for(u_int = 0; i<ctr.size; ++i) {p[i] = ctr.p[i];}
    }
}

//operator[]
template<class T>
T& Container<T>::operator [](u_int index) {if(index > size) throw std::out_of_range("Index out of range."); return *(p+i);}

//const operator[]
template<class T>
const T& Container<T>::operator [](u_int index) const {if(index > size) throw std::out_of_range("Index out of range."); return *(p+i);}

//operator==
template<class T>
bool Container<T>::operator ==(const Container& c){
    if(size != c.size)
        return false;
    else{
        for(u_int = 0; i<size; ++i)
            if(p[i] != c.p[i])
                return false;
    }
    return true;
}

//operator!=
template<class T>
bool Container<T>::operator !=(const Container& c) const {
    if(size == c.size)
        return false;
    else{
        for(u_int = 0; i<size; ++i)
            if(p[i] == c.p[i])
                return false;
    }
    return true;
}

//operator<
template<class T>
bool Container<T>::operator <(const Container& c) const{
    u_int j = 0;
    while(j<size && j<c.size){
        if(p[j] != c.p[j])
            return p[j]<c.p[j];
        j++;
    }

    if(size < c.size)
        return true;
    return false;
}

//operator>
template<class T>
bool Container<T>::operator >(const Container& c) const{
    u_int j = 0;
    while(j<size && j<c.size){
        if(p[j] != c.p[j])
            return p[j]>c.p[j];
        j++;
    }

    if(size > c.size)
        return true;
    return false;
}

//operator<=
template<class T>
bool Container<T>::operator <=(const Container& c) const{return *this == c || *this < c;}//Sfrutta la definizione di operator < e ==

//operator>=
template<class T>
bool Container<T>::operator >=(const Container& c) const{return *this == c || *this > c;}//Sfrutta la definizione di operator > e ==

#endif // CONTAINER_H
