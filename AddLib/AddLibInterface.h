#ifndef ADDLIBINTERFACE_H
#define ADDLIBINTERFACE_H

#include "AddLib_global.h"

class SCHEDULERSHARED_EXPORT AddLibInterface
{
public:
    virtual ~AddLibInterface(){};

    virtual void InitData() = 0;
    virtual void Start() = 0;

    virtual void ScThreadFunction() = 0;
    virtual void XfThreadFunction() = 0;
};

#endif // ADDLIBINTERFACE_H
