#ifndef _VECTOR2D_HPP_
#define _VECTOR2D_HPP_

template<class T> class Vector2D {
public:
    T x;
    T y;

    Vector2D();
    Vector2D(T, T);
    Vector2D(const Vector2D<T>&);
    ~Vector2D();

    Vector2D<T>& operator = (const Vector2D<T>&);
};

template<class T> 
Vector2D<T>& Vector2D<T>::operator=(const Vector2D<T>& right)
{
    if(this == &right) {
        return *this;
    }
    this->x = right.x;
    this->y = right.y; 

    return *this;
}

template<class T> 
Vector2D<T>::Vector2D()
{
    this->x = 0;
    this->y = 0; 
}

template<class T> 
Vector2D<T>::Vector2D(T x, T y)
{
    this->x = x;
    this->y = y; 
}

template<class T> 
Vector2D<T>::~Vector2D()
{
}

template<class T> 
Vector2D<T>::Vector2D(const Vector2D<T>& second)
{
    this->x = second.x;
    this->y = second.y; 
}

#endif /* end of include guard: _VECTOR2D_HPP_ */
