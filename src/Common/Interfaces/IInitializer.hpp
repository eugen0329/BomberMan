#ifndef _IINITIALIZER_HPP_
#define _IINITIALIZER_HPP_

#include "TinyXML/tinyxml.h"

typedef TiXmlElement xmlElem_t;

class IInitializer {
protected:
    xmlElem_t* element;
public:
    IInitializer() {}
    virtual ~IInitializer() {}

    virtual int load() const = 0;

    inline void setXmlElement(xmlElem_t& element)
    {
        this->element = &element;
    }
};


#endif /* end of include guard: _IINITIALIZER_HPP_ */
