#ifndef _Vec2_HPP_
#define _Vec2_HPP_

#include <cstdlib>
#include <cmath>

#include <Common/Angle.hpp>

template<typename T = size_t> 
class Vec2 {
public:
    T x;
    T y;

    Vec2();
    Vec2(T, T);

    Vec2(T, const Angle& );

    Vec2(const Vec2<T>&);
    ~Vec2();

    Vec2<T>& operator = (const Vec2<T>&);
    Vec2<T>& operator += (const Vec2<T>&);
    
    Vec2<T> operator - (const Vec2<T>&);
    Vec2<T> operator - (const Vec2<T>&) const;
    Vec2<T> operator + (const Vec2<T>&);
    Vec2<T> operator + (const Vec2<T>&) const;

    void setComponents(T , T );

    Vec2<T> operator / (const int&);

    bool operator == (const Vec2<T>&);
    bool operator >= (const Vec2<T>&);
    bool operator <= (const Vec2<T>&);
    bool operator >  (const Vec2<T>&);
    bool operator <  (const Vec2<T>&);

    inline T getAbs();
    const inline T getAbs() const;
};

template<class T> 
Vec2<T> Vec2<T>::operator / (const int& divider)
{
    Vec2<T> resultVec;

    resultVec.x = this->x / divider; 
    resultVec.y = this->y / divider; 

    return resultVec;
}

template<class T> 
void Vec2<T>::setComponents(T x, T y)
{
    this->x = x;
    this->y = y;
}


template<class T> 
bool Vec2<T>::operator >= (const Vec2<T>& right)
{
    return this->getAbs() >= right.getAbs();
}

template<class T> 
bool Vec2<T>::operator <= (const Vec2<T>& right)
{
    return this->getAbs() <= right.getAbs();
}

template<class T> 
bool Vec2<T>::operator == (const Vec2<T>& right)
{
    return this->getAbs() == right.getAbs();
}

template<class T> 
bool Vec2<T>::operator > (const Vec2<T>& right)
{
    return this->getAbs() > right.getAbs();
}

template<class T> 
bool Vec2<T>::operator < (const Vec2<T>& right)
{
    return this->x < right.x && this->y < right.y;
}

template<class T> 
Vec2<T> Vec2<T>::operator - (const Vec2<T>& right)
{
    Vec2<T> resultVec;

    resultVec.x = this->x - right.x; 
    resultVec.y = this->y  - right.y;

    return resultVec;
}

template<class T> 
Vec2<T> Vec2<T>::operator - (const Vec2<T>& right) const
{
    Vec2<T> resultVec;

    resultVec.x = this->x - right.x; 
    resultVec.y = this->y  - right.y;

    return resultVec;
}

template<class T> 
Vec2<T> Vec2<T>::operator + (const Vec2<T>& right)
{
    Vec2<T> resultVec;

    resultVec.x = this->x + right.x; 
    resultVec.y = this->y  + right.y;

    return resultVec;
}

template<class T> 
Vec2<T> Vec2<T>::operator + (const Vec2<T>& right) const
{
    Vec2<T> resultVec;

    resultVec.x = this->x + right.x; 
    resultVec.y = this->y  + right.y;

    return resultVec;
}

template<class T> 
Vec2<T>& Vec2<T>::operator += (const Vec2<T>& right)
{
    this->x += right.x; 
    this->y += right.y;

    return *this;
}

template<class T> 
Vec2<T>& Vec2<T>::operator=(const Vec2<T>& right)
{
    this->x = right.x;
    this->y = right.y; 

    return *this;
}

template<class T> 
Vec2<T>::Vec2()
{
    this->x = 0;
    this->y = 0; 
}

template<class T> 
Vec2<T>::Vec2(T x, T y)
{
    this->x = x;
    this->y = y; 
}

template<class T> 
Vec2<T>::Vec2(T modulo, const Angle& angle) 
{
    this->x = modulo * cos(angle.inRad());
    this->y = modulo * sin(angle.inRad());
}

template<class T> 
Vec2<T>::~Vec2()
{
}

template<class T> 
Vec2<T>::Vec2(const Vec2<T>& second)
{
    this->x = second.x;
    this->y = second.y; 
}


template<class T> 
T Vec2<T>::getAbs() 
{
    return std::sqrt(x*x + y*y);
}

template<class T> 
const T Vec2<T>::getAbs() const 
{
    return std::sqrt(x*x + y*y);
}

#endif /* end of include guard: _Vec2_HPP_ */
