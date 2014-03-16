#ifndef _LWVECTOR_HPP_
#define _LWVECTOR_HPP_

template<class T>
class LWVector {
private:
    T* elements;
    size_t size; 
public:
    LWVector(size_t size = 0);
    virtual ~LWVector();
};

template<class T>
LWVector<T>::LWVector(size_t size)
{
    this->size = size;
    if (this->size != 0) {
        elements = new T [this->size];
    } else {
        elements = 0;
    }
}

template<class T>
LWVector<T>::~LWVector()
{
}
#endif /* end of include guard: _LWVECTOR_HPP_ */
