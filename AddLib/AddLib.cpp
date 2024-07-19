#include "AddLib.h"

#include <iostream>

using namespace std;

AddLib::~AddLib()
{
    cout << "释放内存" << endl;

    m_xfthreadStop = true;
    m_conditionFull.notify_all();
    if(m_xfThread.joinable())
    {
        m_xfThread.join();
    }

    m_scthreadStop = true;
    m_conditionNotFull.notify_all();
    if(m_scThread.joinable())
    {
        m_scThread.join();
    }

    cout << "释放内存完毕" << endl;
}

void AddLib::TestOut()
{
    cout << "hello" << endl;
    cout << "你好" << endl;
    cout << "hello" << endl;
    cout << "hello" << endl;
    cout << "hello" << endl;
}

void AddLib::InitData()
{
    m_scthreadStop = false;
    m_xfthreadStop = false;
    m_dataStart = 0;
}

void AddLib::Start()
{
    m_scThread = thread(&AddLib::ScThreadFunction, this);
    m_xfThread = thread(&AddLib::XfThreadFunction, this);
}

void AddLib::ScThreadFunction()
{
    while (!m_scthreadStop)
    {
        unique_lock<mutex> lock(m_mutexNotFull);
        m_conditionNotFull.wait(lock, [this]{return m_scthreadStop || m_queueData.size() < 60;});
        if(m_queueData.size() < 60)
        {
            m_queueData.push(++m_dataStart);
            m_conditionFull.notify_one();
        }
    }
}

void AddLib::XfThreadFunction()
{
    while (!m_xfthreadStop)
    {
        unique_lock<mutex> lock(m_mutexFull);
        m_conditionFull.wait(lock, [this]{return m_xfthreadStop || !m_queueData.empty();});
        if(!m_queueData.empty())
        {
            cout << "s: " << m_queueData.front() << endl;
            m_queueData.pop();
            m_conditionNotFull.notify_one();
            lock.unlock();
        }

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

///工厂函数声明（备注：函数在其子类中实现，返回子类实例）
AddLibInterface *CreateMyClassInstance()
{
    return new AddLib();
}
