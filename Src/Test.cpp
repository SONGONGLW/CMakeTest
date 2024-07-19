#include "AddLib.h"
#include "AddLibInterface.h"

int main()
{
    AddLibInterface *add = new AddLib;
    add->InitData();
    add->Start();
    while (true) {}
    return -1;
}
