#ifndef CONTAINER_H
#define CONTAINER_H
using namespace std;
typedef unsigned int u_int;

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

    class const_iterator;

    class iterator{
        friend class Container<T>;
    private:
        T* p;
        iterator(T* = 0);
    public:
        iterator(const iterator&);
        bool operator ==(const const_iterator&) const;
        bool operator !=(const const_iterator&) const;
        bool operator <=(const const_iterator&) const;
        bool operator >=(const const_iterator&) const;
        bool operator <(const const_iterator&) const;
        bool operator >(const const_iterator&) const;

        T& operator *() const;
        T& operator [](u_int) const;

        iterator& operator ++();
        iterator operator ++(int);

        iterator& operator --();
        iterator operator --(int);

        iterator& operator +=(int);
        iterator& operator -=(int);

        iterator operator +(int) const;
        iterator operator -(int) const;

        iterator operator +(const const_iterator&) const;
        iterator operator -(const const_iterator&) const;

    };

    //Classe const_iterator
    class const_iterator{
        friend class Container<T>;
    private:
        T* p;
        const_iterator(T* = 0);
    public:
        const_iterator(const const_iterator&);
        bool operator ==(const const_iterator&) const;
        bool operator !=(const const_iterator&) const;
        bool operator <=(const const_iterator&) const;
        bool operator >=(const const_iterator&) const;
        bool operator <(const const_iterator&) const;
        bool operator >(const const_iterator&) const;

        T& operator *() const;
        T& operator [](u_int) const;

        const_iterator& operator ++();
        const_iterator operator ++(int);

        const_iterator& operator --();
        const_iterator operator --(int);

        const_iterator& operator +=(int);
        const_iterator& operator -=(int);

        const_iterator operator +(int) const;
        const_iterator operator -(int) const;

        const_iterator operator +(const const_iterator&) const;
        const_iterator operator -(const const_iterator&) const;

    };

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
    T& back();
    const T& back() const;
    T& front();
    const T& front() const;
    void clear();   //rimuove elementi dal container.
    bool empty() const; //true se container size è 0.
    void push_back(const T&);   //aggiunge un elemento alla fine del container, aumentando size di 1 (capacità permettendo altrimenti resize()).
    void pop_back();    //rimuove l'ultimo elemento dal container, riducendo size di 1.
    u_int getSize() const;
    u_int getCapacity() const;
    void erase(u_int,u_int); //rimuove elementi tra due indici
    void erase(u_int);  //rimuove elemento in quell'indice
    void erase(T);  //rimuove elemento T

    iterator begin();
    iterator end();
    iterator erase(iterator);
    iterator erase(iterator, iterator);
    iterator insert(iterator, const T&);


    /* DA IMPLEMENTARE
     *
     * iterator begin();    //ritorna iteratore che punta al primo elemento del container.
     * iterator end();  //ritorna iteratore past-the-end
     * iterator erase(iterator);
     * iterator erase(iterator, iterator);
     * iterator insert(iterator, const T&);
     */

    /*
     * const_iterator cbegin() const;   //ritorna iteratore costante che punta al primo elemento (non modificabile essendo const_iterator)
     * const_iterator cend() const; //ritorna const_iterator che punta past-the-end del container
     * const_iterator begin() const;    //ritorna iteratore costante al primo elemento del container
     * const_iterator end() const;  //ritorna const_iterator past-the-end
     */

};

/*********************** CLASSE Container ***************************/

//Costruttore standard
template<class T>
Container<T>::Container(u_int s, u_int c) : size(s), capacity(c), p(new T[c]) {}

//Costruttore di copia
template<class T>
Container<T>::Container(const Container<T> &c) : size(c.size), capacity(c.capacity), p(new T[c.capacity])
    {for(u_int i= 0; i<size; ++i) p[i] = c.p[i];}

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
    for(u_int i = 0; i<size; ++i)
        temp[i] = p[i];
    delete[] p;
    p = temp;
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
        for(u_int i = 0; i<ctr.size; ++i) {p[i] = ctr.p[i];}
    }
}

//operator[]
template<class T>
T& Container<T>::operator [](u_int index) {if(index > size) throw std::out_of_range("Index out of range."); return *(p+index);}

//const operator[]
template<class T>
const T& Container<T>::operator [](u_int index) const {if(index > size) throw std::out_of_range("Index out of range."); return *(p+index);}

//operator==
template<class T>
bool Container<T>::operator ==(const Container& c) const{
    if(size != c.size)
        return false;
    else{
        for(u_int i = 0; i<size; ++i)
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
        for(u_int i = 0; i<size; ++i)
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
        if(p[j]>=c.p[j])
            return false;
        j++;
    }

    if(size > c.size)
        return false;
    return true;
}

//operator>
template<class T>
bool Container<T>::operator >(const Container& c) const{
    u_int j = 0;
    while(j<size && j<c.size){
        if(p[j]<=c.p[j])
            return false;
        j++;
    }

    if(size < c.size)
        return false;
    return true;
}

//operator<=
template<class T>
bool Container<T>::operator <=(const Container& c) const{return *this == c || *this < c;}//Sfrutta la definizione di operator < e ==

//operator>=
template<class T>
bool Container<T>::operator >=(const Container& c) const{return *this == c || *this > c;}//Sfrutta la definizione di operator > e ==

/**** METODI *****/

template<class T>
T& Container<T>::back(){return p[size-1];}

template<class T>
const T& Container<T>::back() const{return p[size-1];}

template<class T>
T& Container<T>::front(){return p[0];}

template<class T>
const T& Container<T>::front() const{return p[0];}

template<class T>
void Container<T>::clear(){if(p) delete[] p; p = new T[1]; size=0;}

template<class T>
bool Container<T>::empty() const{return size==0;}

template<class T>
void Container<T>::push_back(const T& t){if(size == capacity) resize(); p[size] = t; size++;} //size è l'ultimo elemento

template<class T>
void Container<T>::pop_back(){if(size > 0) size--;}

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

template<class T>
void Container<T>::erase(T obj){
    for(u_int i = 0; i<size; ++i)
        if(p[i] == obj)
            erase(i);
}

/*********************** CLASSE iterator ***************************/

template<class T>
Container<T>::iterator::iterator(T* t) : p(t) {}

template<class T>
Container<T>::iterator::iterator(const iterator& it) : p(it.p) {}

template<class T>
bool Container<T>::iterator::operator ==(const const_iterator& cit) const{return p == cit.p;}

template<class T>
bool Container<T>::iterator::operator !=(const const_iterator& cit) const{return p != cit.p;}

template<class T>
bool Container<T>::iterator::operator <=(const const_iterator& cit) const{return p <= cit.p;}

template<class T>
bool Container<T>::iterator::operator >=(const const_iterator& cit) const{return p >= cit.p;}

template<class T>
bool Container<T>::iterator::operator <(const const_iterator& cit) const{return p < cit.p;}

template<class T>
bool Container<T>::iterator::operator >(const const_iterator& cit) const{return p > cit.p;}

template<class T>
T& Container<T>::iterator::operator *() const{return *(p);}

template<class T>
T& Container<T>::iterator::operator [](u_int index) const{return *(p+index);}

template<class T>
iterator& Container<T>::iterator::operator ++(){if(p) ++p; return *(this);}

template<class T>
iterator Container<T>::iterator::operator ++(int i){iterator temp = iterator(*this); if(p) ++p; return temp;} //incremento postfisso, ritorno l'iteratore prima dell'incremento.

template<class T>
iterator& Container<T>::iterator::operator --(){if(p) --p; return *(this);}

template<class T>
iterator Container<T>::iterator::operator --(int i){iterator temp = iterator(*this); if(p) --p; return temp;}//decremento postifisso, analogo come l'incremento.

template<class T>
iterator& Container<T>::iterator::operator +=(int i){if(p) p += i; return *(this);}

template<class T>
iterator& Container<T>::iterator::operator -=(int i){if(p) p -= i; return *(this);}

template<class T>
iterator Container<T>::iterator::operator +(int i) const{if(p) return iterator(p+i); return iterator();}

template<class T>
iterator Container<T>::iterator::operator -(int i) const{if(p) return iterator(p-i); return iterator();}

template<class T>
iterator Container<T>::iterator::operator +(const const_iterator& cit) const{return iterator(cit.p + p);}

template<class T>
iterator Container<T>::iterator::operator -(const const_iterator&) const{return iterator(cit-p - p);}

/*********************** CLASSE const_iterator ***************************/

template<class T>
Container<T>::const_iterator::const_iterator(T* t) : p(t) {}

template<class T>
Container<T>::const_iterator::const_iterator(const const_iterator& it) : p(it.p) {}

template<class T>
bool Container<T>::const_iterator::operator ==(const const_iterator& cit) const{return p == cit.p;}

template<class T>
bool Container<T>::const_iterator::operator !=(const const_iterator& cit) const{return p != cit.p;}

template<class T>
bool Container<T>::const_iterator::operator <=(const const_iterator& cit) const{return p <= cit.p;}

template<class T>
bool Container<T>::const_iterator::operator >=(const const_iterator& cit) const{return p >= cit.p;}

template<class T>
bool Container<T>::const_iterator::operator <(const const_iterator& cit) const{return p < cit.p;}

template<class T>
bool Container<T>::const_iterator::operator >(const const_iterator& cit) const{return p > cit.p;}

template<class T>
T& Container<T>::const_iterator::operator *() const{return *(p);}

template<class T>
T& Container<T>::const_iterator::operator [](u_int index) const{return *(p+index);}

template<class T>
const_iterator& Container<T>::const_iterator::operator ++(){if(p) ++p; return *(this);}

template<class T>
const_iterator Container<T>::const_iterator::operator ++(int i){iterator temp = iterator(*this); if(p) ++p; return temp;} //incremento postfisso, ritorno l'iteratore prima dell'incremento.

template<class T>
const_iterator& Container<T>::const_iterator::operator --(){if(p) --p; return *(this);}

template<class T>
const_iterator Container<T>::const_iterator::operator --(int i){iterator temp = iterator(*this); if(p) --p; return temp;}//decremento postifisso, analogo come l'incremento.

template<class T>
const_iterator& Container<T>::const_iterator::operator +=(int i){if(p) p += i; return *(this);}

template<class T>
const_iterator& Container<T>::const_iterator::operator -=(int i){if(p) p -= i; return *(this);}

template<class T>
const_iterator Container<T>::const_iterator::operator +(int i) const{if(p) return iterator(p+i); return iterator();}

template<class T>
const_iterator Container<T>::const_iterator::operator -(int i) const{if(p) return iterator(p-i); return iterator();}

template<class T>
const_iterator Container<T>::iterator::operator +(const const_iterator& cit) const{return const_iterator(cit.p + p);}

template<class T>
const_iterator Container<T>::iterator::operator -(const const_iterator&) const{return const_iterator(cit.p - p);}

//iterator begin
template <class C>
typename Container<C>::iterator Container<C>::begin() {return iterator(p);}

//iterator end
template <class C>
typename Container<C>::iterator Container<C>::end() {return iterator(p+size);}

//iterator erase
template <class C>
typename Container<C>::iterator Container<C>::erase(iterator i) {return erase(i, i);}

//iterator erase(iterator, iterator)
template <class C>
typename Container<C>::iterator Container<C>::erase(iterator i, iterator f){
    if(size == 0){
        return iterator(0);
    }else{
        if(i < begin()){
            i = begin();
        }
        if(f < end()){
            f = end();
        }
        for(iterator a = i, k(f+1); k<end(); ++a, ++k){
            *a = *k;
        }
        size-=static_cast<unsigned int>(last.p-i.p)+1;
        return i;
    }
}

//iterator insert
template <class C>
typename Container<C>::iterator Container<C>::insert(iterator it, const C &c){
    unsigned int position = it.p-p;
    if(size==capacity){
        resize();
    }
    for(unsigned int i = size; i>position; --i){
        p[i] = p[i-1];
    }
    p[position] = c;
    size++;
    return it;
}


#endif // CONTAINER_H
