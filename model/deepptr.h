#ifndef DEEPPTR_H
#define DEEPPTR_H

template<class T>
class DeepPtr{
private:
    T* p;
public:
    DeepPtr(const T* = nullptr);
    DeepPtr(const DeepPtr&);
    ~DeepPtr();

    DeepPtr<T>& operator =(const DeepPtr&);
    T& operator *() const;
    T* operator ->() const;
    bool operator==(const DeepPtr&) const;
};

template<class T>
DeepPtr<T>::DeepPtr(const T* punt){
    if(punt == nullptr)
        p = nullptr;
    else
        p = punt->clone();
}

template<class T>
DeepPtr<T>::DeepPtr(const DeepPtr& ptr){
    if(ptr.p == nullptr)
        p = nullptr;
    else
        p = (ptr.p)->clone();
}

template<class T>
DeepPtr<T>::~DeepPtr(){if(p) delete p;}

template<class T>
DeepPtr<T>& DeepPtr<T>::operator =(const DeepPtr& ptr){
    if(&ptr != this){
        if(p) delete p;
        if(ptr.p == nullptr)
            p = nullptr;
        else
            p = (ptr.p)->clone();
    }
    return *this;
}

template<class T>
T& DeepPtr<T>::operator *() const{ if(p != nullptr) return *p;}

template<class T>
T* DeepPtr<T>::operator ->() const{ if(p != nullptr) return p;}

template<class T>
bool DeepPtr<T>::operator ==(const DeepPtr& ptr) const{ return p == ptr.p ? true : false; }
#endif // DEEPPTR_H
