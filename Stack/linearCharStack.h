#include <iostream>
#include <stdio.h>

using namespace std;

struct Stack
{
    char data[10];
    int top, volume = 10;
};

void initalStack(Stack &S)
{
    S.top = 0;
}

void pushStack(Stack &S, char value)
{
    if (S.top >= S.volume)
    {
        //cout << "栈发生了溢出，丢失了:" << value << endl;
        return;
    }
    S.data[S.top] = value;
    S.top++;
}

char popStack(Stack &S)
{
    if (S.top <= 0)
    {
        //cout << "栈空，无法弹出元素" << endl;
        return 0;
    }
    S.top--;
    return S.data[S.top];
}

void logStack(Stack &S)
{
    int cache = S.top;
    while (cache > 0)
    {
        cache--;
        cout << '|' << S.data[cache] << '|' << endl;
    }
    cout << "Log end" << endl;
}