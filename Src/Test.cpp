#include "AddLib.h"
#include "AddLibInterface.h"

int main()
{
    AddLibInterface *add = new AddLib;
    add->InitData();
    add->Start();

    delete add;
    while (true) {}
    return -1;
}
