#ifndef _ALGORITHMS_HPP_
#define _ALGORITHMS_HPP_

#include <iostream>
#include <cmath>

#include <string>
#include <vector>

#include "XMLParser/tinyxml.h"

#include "Common/BaseShape.hpp"
#include "Common/Vector2D.hpp"
#include "Common/Angle.hpp"
#include "Common/Delegate.hpp"


namespace alg {

    inline bool isCrossing(const BaseShape& first, const BaseShape& second)
    {
        Vector2D<float> currentDist;
        currentDist.x = ::abs(first.pos.y - second.pos.y);
        currentDist.y = ::abs(first.pos.x - second.pos.x);

        Vector2D<float> minPossibleDist;
        minPossibleDist.x = (first.width + second.width) / 2;
        minPossibleDist.y = (first.heigth + second.heigth) / 2;
        
        return currentDist < minPossibleDist;
    }

    inline float getDistance(const BaseShape& first, const BaseShape& second)
    {
        return ::abs( first.pos.getAbs() - second.pos.getAbs() );
    }

    inline Angle getAvarage(Angle& first, Angle& second)
    {
        Angle temp;
        if(abs( (first-second).inPiRad() ) >= 1.0 ) {
            temp = (first + Angle(2.0) + second) / 2 ;
        } else {
            temp = (first + second) / 2 ;
        }
        temp.correctAngle();
        return temp;
    }
    template<class T, class U> 
    Delegate* createSignal(T* connectableClass, U connectableMethod)
    {
        Delegate* delegate = new Delegate;
        delegate->bind(connectableClass, connectableMethod);
        return delegate;
    }

    inline TiXmlDocument * openXmlFile(const std::string& filename)
    {
        TiXmlDocument * xmlFile = new TiXmlDocument;
        if(! xmlFile->LoadFile(filename.c_str()) ) {
            throw std::ios_base::failure( filename + ": ERROR while opening file" );
        }
        return xmlFile;
    }

    inline TiXmlElement * getXmlElement(TiXmlDocument* xmlFile, std::vector<std::string> pathNodes)
    {
        std::vector<std::string>::iterator node = pathNodes.begin();
        TiXmlElement *xmlElement = xmlFile->FirstChildElement((*node).c_str());
        node++;
        for(; node != pathNodes.end(); node++) {
            xmlElement = xmlElement->FirstChildElement((*node).c_str());
        }
        return xmlElement;
    }

}

#endif /* end of include guard: _ALGORITHMS_HPP_ */
