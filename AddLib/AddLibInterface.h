#ifndef ADDLIBINTERFACE_H
#define ADDLIBINTERFACE_H

#include "AddLib_global.h"

///纯虚函数接口类
class SCHEDULERSHARED_EXPORT AddLibInterface
{
public:
    virtual ~AddLibInterface(){};

    virtual void InitData() = 0;
    virtual void Start() = 0;

private:
    virtual void ScThreadFunction() = 0;
    virtual void XfThreadFunction() = 0;
};

#endif // ADDLIBINTERFACE_H

///工厂函数声明（备注：函数在其子类中实现，返回子类实例）
extern "C" SCHEDULERSHARED_EXPORT AddLibInterface* CreateMyClassInstance();
