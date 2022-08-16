#include "operate.h"
using namespace std;

void commandFun(int amout, linkQueue &Q)
{
    int command;
    while (amout--)
    {
        cout << "输入数字命令来执行指令" << endl;
        cin >> command;
        if (command == 1)
        {
            push(Q);
        } 
        else if ( command == 2 )
        {
            pop(Q);
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
