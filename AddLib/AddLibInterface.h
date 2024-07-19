#ifndef ADDLIBINTERFACE_H
#define ADDLIBINTERFACE_H

#include "AddLib_global.h"

///纯虚函数接口类
class AddLibInterface
{
public:

    //虚析构函数，在delete基类后，自动调用其子类的析构函数
    virtual ~AddLibInterface(){};

    //初始化数据接口
    virtual void InitData() = 0;

    //启动数据输出
    virtual void Start() = 0;

};

#endif // ADDLIBINTERFACE_H

///工厂函数声明（备注：函数在其子类中实现，返回子类实例）
extern "C" SCHEDULERSHARED_EXPORT AddLibInterface* CreateMyClassInstance();
