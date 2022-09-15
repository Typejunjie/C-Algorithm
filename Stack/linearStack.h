#include <iostream>
#include <stdio.h>

using namespace std;

struct Stack
{
    int data[10];
    int top, volume = 10;
};

void initalStack(Stack &S)
{
    S.top = 0;
}

bool judgeStackEmpty(Stack S)
{
    if (S.top <= 0)
        return true;
    return false;
}

void pushStack(Stack &S, int value)
{
    if (S.top >= S.volume)
    {
        //cout << "栈发生了溢出，丢失了:" << value << endl;
        return;
    }
    S.data[S.top] = value;
    S.top++;
}

int popStack(Stack &S)
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

// 栈的线性调用
void linearUse(Stack &S, int *Array, int length)
{
    int cache;
    for (int i = 0; i < length; i++)
    {
        if (Array[i] == 0)
        {
            cache = popStack(S);
            cout << '[' << cache << ']';
        }
        else
        {
            pushStack(S, Array[i]);
        }
    }
}