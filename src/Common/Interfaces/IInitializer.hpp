#ifndef _IINITIALIZER_HPP_
#define _IINITIALIZER_HPP_

#include "XMLParser/tinyxml.h"

typedef TiXmlElement xmlElement_t;

class IInitializer {
protected:
    xmlElement_t* element;
public:
    IInitializer() {}
    virtual ~IInitializer() {}

    virtual int load() const = 0;

    inline void setXmlElement(xmlElement_t& element)
    {
        this->element = &element;
    }
};


#endif /* end of include guard: _IINITIALIZER_HPP_ */
