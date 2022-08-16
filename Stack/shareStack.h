#include <iostream>
#include <stdio.h>

using namespace std;

// 共享栈
struct shareStack
{
    int data[20];
    int S1top, S2top, volume = 20;
};

void initalShareStack(shareStack &S)
{
    S.S1top = 0;
    S.S2top = S.volume - 1;
}

void pushShareStack(shareStack &S, int diraction, int key)
{
    if (S.S1top > S.S2top)
        return;
    if (diraction == 0)
    {
        S.data[S.S1top] = key;
        S.S1top++;
    }
    else
    {
        S.data[S.S2top] = key;
        S.S2top--;
    }
}

int popShareStack(shareStack &S, int diraction)
{
    if (diraction == 0)
    {
        if (S.S1top == 0)
            return 0;
        S.S1top--;
        return S.data[S.S1top];
    }
    else
    {
        if (S.S2top == S.volume - 1)
            return 0;
        S.S2top++;
        return S.data[S.S2top];
    }
}

void log(shareStack &S)
{
    cout << "|L|" << " |R|" << endl;
    int leftCache, rightCache;
    leftCache = S.S1top;
    rightCache = S.S2top;
    while (leftCache > 0 || rightCache < S.volume - 1)
    {
        if (leftCache > (S.volume - 1) - rightCache)
        {
            cout << '|' << S.data[leftCache - 1] << '|' << endl;
            leftCache--;
        }
        else if (leftCache < (S.volume - 1) - rightCache)
        {
            cout << '|' << S.data[rightCache + 1] << '|' << endl;
            rightCache++;
        }
        else
        {
            cout << '|' << S.data[leftCache - 1] << '|' << '|' << S.data[rightCache + 1] << '|' << endl;
            rightCache++;
            leftCache--;
        }
    }
}