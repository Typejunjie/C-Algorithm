#include <stdio.h>
#include <iostream>
#include "linkStack.h"
using namespace std;

void commandFun(int amout, linkStack &S)
{
    int command;
    while (amout--)
    {
        cout << "输入数字命令来执行指令" << endl;
        cin >> command;
        if (command == 1)
        {
            push(S);
        } 
        else if ( command == 2 )
        {
            pop(S);
        }
        else if (command == 3)
        {
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
