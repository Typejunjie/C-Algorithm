#include <stdio.h>
#include <iostream>
#include "List.h"

using namespace std;

void commandFun(int amout, linkList &L)
{
    int command;
    while (amout--)
    {
        cout << "Input a digital command" << endl;
        cin >> command;
        if (command == 1)
        {
            log(L);
        } 
        else if ( command == 2 )
        {
            addElem(L);
        }
        else if (command == 3)
        {
            deleteData(L);
        }
        else if (command == 0)
        {
            cout << "Stop the process" << endl;
            break;
        }
        else
        {
            cout << "Place input a valied value" << endl;
        }
    }
}
