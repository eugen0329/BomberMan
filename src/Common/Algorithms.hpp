#ifndef _ALGORITHMS_HPP_
#define _ALGORITHMS_HPP_

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

#include "TinyXML/tinyxml.h"

#include "Common/BaseShape.hpp"
#include "Common/Vec2.hpp"
#include "Common/Angle.hpp"

namespace alg {
    inline int randInRange(int from, int to)
    {
        return std::rand() % (to - from) + from;
    }

    inline float randInRange(float from, float to)
    {
        return((float)rand()/(float)(RAND_MAX)) * (to - from) + from;
    }
    
    inline float parseFloat(const std::string source)
    {
        char* endptr;
        float retVal = strtof(source.c_str(), &endptr);
        if(*endptr != '\0') 
            throw std::invalid_argument(std::string("parseFloat: \"") + source + "\" is wrong arg to parse");
        return retVal;
    }

    template <typename I>
    I randElem(I&& begin, I&& end)
    {
        I retVal = begin;
        std::advance(retVal, randInRange(0, std::distance(begin, end)));
        return retVal;
    } 

    inline int parseInt(const std::string source)
    {
        char* endptr;
        int retVal = strtol(source.c_str(), &endptr, 10);
        if(*endptr != '\0') 
            throw std::invalid_argument(std::string("parseInt: ") + source + " is wrong arg to parse");
        return retVal;
    }

    inline bool isCrossing(const BaseShape& first, const BaseShape& second)
    {
        static Vec2<float> currentDist;
        currentDist.x = ::abs(first.pos.y - second.pos.y);
        currentDist.y = ::abs(first.pos.x - second.pos.x);

        static Vec2<float> minPossibleDist;
        minPossibleDist.x = (first.width + second.width) / 2;
        minPossibleDist.y = (first.heigth + second.heigth) / 2;
        
        return currentDist < minPossibleDist;
    }

    inline float getDistance(const BaseShape& first, const BaseShape& second)
    {
        return ::abs(first.pos.getAbs() - second.pos.getAbs());
    }

    inline Angle getAvarage(Angle& first, Angle& second)
    {
        Angle temp;
        if(abs( (first-second).inPiRad() ) >= 1.0 ) {
            temp = (first + Angle(2.0) + second) / 2 ;
        } else {
            temp = (first + second) / 2 ;
        }
        temp.normalize();
        return temp;
    }

    inline TiXmlDocument * openXmlFile(const std::string& filename)
    {
        TiXmlDocument * xmlFile = new TiXmlDocument;
        if(! xmlFile->LoadFile(filename.c_str()) ) 
            throw std::ios_base::failure( filename + ": ERROR while opening file" );

        return xmlFile;
    }

    inline TiXmlElement * getXmlElem(TiXmlDocument* xmlFile, std::vector<std::string> path)
    {
        std::vector<std::string>::iterator node = path.begin();
        TiXmlElement *xmlElement = xmlFile->FirstChildElement((*node).c_str());
        node++;
        for(; node != path.end(); node++) {
            xmlElement = xmlElement->FirstChildElement((*node).c_str());
        }
        return xmlElement;
    }

}

#endif /* end of include guard: _ALGORITHMS_HPP_ */
