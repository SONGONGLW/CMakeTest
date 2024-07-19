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

    void TestOut();
    void InitData() override;
    void Start() override;

    void ScThreadFunction();
    void XfThreadFunction();

private:
    thread m_scThread;
    thread m_xfThread;

    bool m_scthreadStop;
    bool m_xfthreadStop;
    condition_variable m_conditionNotFull;
    condition_variable m_conditionFull;
    mutex m_mutexNotFull;
    mutex m_mutexFull;
    queue<int> m_queueData;

    int m_dataStart;
};

#endif // ADDLIB_H
