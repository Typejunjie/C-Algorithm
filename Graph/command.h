#include "interfere.h"

using namespace std;

void commandFun(int amout, Graph &G)
{
    int command;
    while (amout--)
    {
        cout << "\n输入数字命令来执行指令" << endl;
        cout << "输入: 0 结束进程";
        cin >> command;
        if (command == 1)
        {
            //preLogTree(T);
            //push(S);
        } 
        else if ( command == 2 )
        {
            //inLogTree(T);
            //pop(S);
        }
        else if (command == 3)
        {
            //postLogTree(T);
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