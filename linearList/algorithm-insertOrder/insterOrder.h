#include "../linearList.h"

/*
算法：直接插入排序
时间复杂度O(n^2)
空间复杂度O(1)
 */

void insertOrder(linearList &L)
{
    int i, j;
    for (i = 2; i < L.length + 1; i++)
    {
        if (L.data[i - 1] > L.data[i])
        {
            L.data[0] = L.data[i];
            for (j = i - 1; L.data[j] > L.data[0]; j--)
            {
                L.data[j + 1] = L.data[j];
            }
            L.data[j + 1] = L.data[0];
        }
    }
}

void createSentryList(linearList &L, int* LArray, int length)
{
    int i = 1;
    while (i < length + 1)
    {
        L.data[i] = LArray[i - 1];
        i++;
    }
    L.length = length;
}

void logSentryList(linearList &L)
{
    int i = 1;
    while (i < L.length + 1)
    {
        cout << "[" << L.data[i] << "]";
        i++;
    }
    cout << "log end" << endl;
}