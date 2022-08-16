#include "../char.h"

// KMP算法

void nextArr(SString &S, int *next)
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < S.length)
    {
        if (j == 0 || S.data[i] == S.data[j])
        {
            ++i;++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

void logArr(int *Arr, int length)
{
    for (int i = 1; i < length + 1; i++)
    {
        cout << '[' << Arr[i] << ']';
    }
    cout << "Log end" << endl;
}