#ifndef _VECTOR2D_HPP_
#define _VECTOR2D_HPP_

#include <cstdlib>
#include <cmath>

#include <Common/Angle.hpp>

template<typename T = size_t> class Vector2D {
public:
    T x;
    T y;

    Vector2D();
    Vector2D(T, T);

    Vector2D(T, const Angle& );

    Vector2D(const Vector2D<T>&);
    ~Vector2D();

    Vector2D<T>& operator = (const Vector2D<T>&);
    Vector2D<T>& operator += (const Vector2D<T>&);
    
    Vector2D<T> operator - (const Vector2D<T>&);
    Vector2D<T> operator - (const Vector2D<T>&) const;
    Vector2D<T> operator + (const Vector2D<T>&);
    Vector2D<T> operator + (const Vector2D<T>&) const;

    void setCoordinates(T , T );

    Vector2D<T> operator / (const int&);

    bool operator == (const Vector2D<T>&);
    bool operator >= (const Vector2D<T>&);
    bool operator <= (const Vector2D<T>&);
    bool operator >  (const Vector2D<T>&);
    bool operator <  (const Vector2D<T>&);

    inline T getAbs();
    const inline T getAbs() const;
};

template<class T> 
Vector2D<T> Vector2D<T>::operator / (const int& divider)
{
    Vector2D<T> resultVec;

    resultVec.x = this->x / divider; 
    resultVec.y = this->y / divider; 

    return resultVec;
}

template<class T> 
void Vector2D<T>::setCoordinates(T x, T y)
{
    this->x = x;
    this->y = y;
}


template<class T> 
bool Vector2D<T>::operator >= (const Vector2D<T>& right)
{
    return this->getAbs() >= right.getAbs();
}

template<class T> 
bool Vector2D<T>::operator <= (const Vector2D<T>& right)
{
    return this->getAbs() <= right.getAbs();
}

template<class T> 
bool Vector2D<T>::operator == (const Vector2D<T>& right)
{
    return this->getAbs() == right.getAbs();
}

template<class T> 
bool Vector2D<T>::operator > (const Vector2D<T>& right)
{
    return this->getAbs() > right.getAbs();
}

template<class T> 
bool Vector2D<T>::operator < (const Vector2D<T>& right)
{
    return this->x < right.x && this->y < right.y;
}

template<class T> 
Vector2D<T> Vector2D<T>::operator - (const Vector2D<T>& right)
{
    Vector2D<T> resultVec;

    resultVec.x = this->x - right.x; 
    resultVec.y = this->y  - right.y;

    return resultVec;
}

template<class T> 
Vector2D<T> Vector2D<T>::operator - (const Vector2D<T>& right) const
{
    Vector2D<T> resultVec;

    resultVec.x = this->x - right.x; 
    resultVec.y = this->y  - right.y;

    return resultVec;
}

template<class T> 
Vector2D<T> Vector2D<T>::operator + (const Vector2D<T>& right)
{
    Vector2D<T> resultVec;

    resultVec.x = this->x + right.x; 
    resultVec.y = this->y  + right.y;

    return resultVec;
}

template<class T> 
Vector2D<T> Vector2D<T>::operator + (const Vector2D<T>& right) const
{
    Vector2D<T> resultVec;

    resultVec.x = this->x + right.x; 
    resultVec.y = this->y  + right.y;

    return resultVec;
}

template<class T> 
Vector2D<T>& Vector2D<T>::operator += (const Vector2D<T>& right)
{
    this->x += right.x; 
    this->y += right.y;

    return *this;
}

template<class T> 
Vector2D<T>& Vector2D<T>::operator=(const Vector2D<T>& right)
{
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
Vector2D<T>::Vector2D(T modulo, const Angle& angle) 
{
    this->x = modulo * cos(angle.inRad());
    this->y = modulo * sin(angle.inRad());
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


template<class T> 
T Vector2D<T>::getAbs() 
{
    return std::sqrt(x*x + y*y);
}

template<class T> 
const T Vector2D<T>::getAbs() const 
{
    return std::sqrt(x*x + y*y);
}

#endif /* end of include guard: _VECTOR2D_HPP_ */
