#ifndef ADDLIB_H
#define ADDLIB_H

#include "AddLibInterface.h"
#include <thread>
#include <condition_variable>
#include <mutex>
#include <queue>

using namespace std;

class SCHEDULERSHARED_EXPORT AddLib : public AddLibInterface
{
public:
    ~AddLib() override;
    void InitData() override;
    void Start() override;

    void ScThreadFunction() override;
    void XfThreadFunction() override;

private:
    thread m_scThread;
    thread m_xfThread;

    bool m_threadStop;
    condition_variable m_conditionNotFull;
    condition_variable m_conditionFull;
    mutex m_mutexNotFull;
    mutex m_mutexFull;
    queue<int> m_queueData;

};

#endif // ADDLIB_H

// 工厂函数声明
extern "C" SCHEDULERSHARED_EXPORT AddLibInterface* CreateMyClassInstance();
