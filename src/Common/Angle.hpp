#ifndef _ANGLE_HPP_
#define _ANGLE_HPP_

#include <cmath>
#define _USE_MATH_DEFINES 

class Angle {
private:
    typedef float angle_t;
    angle_t piRadAngle;
public:
    Angle normalize()
    {
        while(piRadAngle >= 2.0) {
            piRadAngle -= 2.0;
        } 
        while(piRadAngle < 0.0) {
            piRadAngle += 2.0;
        }
        return *this;
    }

    Angle() : piRadAngle(0.0)
    {
    }
    Angle(const Angle& second) : piRadAngle(second.piRadAngle)
    {
    }
    Angle(angle_t piRadAngle) : piRadAngle(piRadAngle)
    {
    }
    ~Angle() 
    {
    }
    inline void setRadAngle(float newAngle) 
    {
        piRadAngle = newAngle / M_PI;
    }
    inline void setPiRadAngle(float newAngle) 
    {
        piRadAngle = newAngle;
    }
    inline void setGradAngle(float newAngle) 
    {
        piRadAngle = newAngle / 180;
    }
    inline float inGrad() const 
    {
        return round(piRadAngle*180 );
    }
    inline float inRad() const
    {
        return piRadAngle * M_PI;
    }
    inline angle_t inPiRad() const
    {
        return piRadAngle;
    }
    inline Angle& operator = (const Angle& second) 
    {
        this->piRadAngle = second.piRadAngle; 
        return  *this;
    }
    inline Angle operator * (float factor) const
    {
        Angle tmp;
        tmp.piRadAngle = piRadAngle * factor;
        return  tmp;
    }
    inline Angle operator / (float divider)  const
    {
        return  this->operator*(1/divider);
    }
    inline Angle operator - (const Angle& second) const
    {
        Angle tmp;
        tmp.piRadAngle = this->piRadAngle - second.piRadAngle; 
        return  tmp;
    }
    inline Angle operator + (const Angle& second)  const
    {
        Angle tmp;
        tmp.piRadAngle = this->piRadAngle + second.piRadAngle; 
        return  tmp;
    }
    inline Angle& operator -= (const Angle& second) 
    {
        this->piRadAngle -= second.piRadAngle; 
        return  *this;
    }
    inline Angle& operator += (const Angle& second) 
    {
        this->piRadAngle += second.piRadAngle; 
        return  *this;
    }
    inline bool operator == (const Angle& second) const
    {
        return  piRadAngle == second.piRadAngle;
    }
    inline bool operator != (const Angle& second) const
    {
        return  piRadAngle != second.piRadAngle;
    }
    inline bool operator > (const Angle& second)  const
    {
        return  piRadAngle > second.piRadAngle;
    }
    inline bool operator < (const Angle& second) const
    {
        return  piRadAngle < second.piRadAngle;
    }
    inline bool operator <= (const Angle& second) const
    {
        return  piRadAngle <= second.piRadAngle;
    }
    inline bool operator >= (const Angle& second) const
    {
        return  piRadAngle >= second.piRadAngle;
    }
};

#endif /* end of include guard: _ANGLE_HPP_ */
