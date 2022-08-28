#include "../char.h"

void logArr(int *Arr, int length)
{
    for (int i = 0; i < length + 1; i++)
    {
        cout << '[' << Arr[i] << ']';
    }
    cout << "Log end" << endl;
}

// 求next数组
void nextArr(SString &S, int *next)
{
    int i = 0, j = -1;
    next[0] = -1;
    while (i < S.length)
    {
        if (j == -1 || S.data[i] == S.data[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

// KMP算法
bool KPM(SString &S, SString &T)
{
    int i = 0, j = 0;
    int next[50];
    nextArr(T, next);
    logArr(next, 5);
    while (i < S.length && j < T.length)
    {
        if (j == 0 || S.data[i] == T.data[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if (j >= T.length)
        return true;
    return false;
}

