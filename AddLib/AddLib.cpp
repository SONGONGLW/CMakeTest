#include "AddLib.h"

#include <iostream>

using namespace std;

AddLib::~AddLib()
{
    m_threadStop = true;
    if(m_scThread.joinable())
    {
        m_scThread.join();
    }

    if(m_xfThread.joinable())
    {
        m_xfThread.join();
    }
}

void AddLib::InitData()
{
    m_threadStop = false;
}

void AddLib::Start()
{
    m_scThread = thread(&AddLib::ScThreadFunction, this);
    m_xfThread = thread(&AddLib::XfThreadFunction, this);
}

void AddLib::ScThreadFunction()
{
    int data = 0;
    while (!m_threadStop)
    {
        unique_lock<mutex> lock(m_mutexNotFull);
        m_conditionNotFull.wait(lock, [this]{return m_queueData.size() < 60;});
        m_queueData.push(++data);
        m_conditionFull.notify_one();
    }
}

void AddLib::XfThreadFunction()
{
    while (!m_threadStop)
    {
        unique_lock<mutex> lock(m_mutexFull);
        m_conditionFull.wait(lock, [this]{return !m_queueData.empty();});
        cout << m_queueData.front() << endl;
        m_queueData.pop();
        m_conditionNotFull.notify_one();
        lock.unlock();

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}
