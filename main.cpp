#include "mainInstruction.h"
#include "chars/matem.h"
#include <memory>
#include <span>
#include <vector>
#include <any>
#include <algorithm>

void consoleClear()
{

    for (short i = 0; i < 10; i++)
    {
        cout << "\t\n"; 
    }
    
}


int main()
{
    consoleClear();

    debora deb;
    deb.say();
    deb.say();
    

    

    return 0;
}

