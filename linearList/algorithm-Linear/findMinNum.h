#include <stdio.h>
#include <iostream>
#include "../linearList.h"
/* 
算法：求未出现的最小正整数(不包括0)
时间复杂度O(n)
空间复杂度O(n)
 */
int findMinNum(linearList &L)
{
    int countArray[L.length];
    for (int i = 0; i < L.length; i++)
    {
        countArray[i] = 0;
    }
    int j = 0;
    while (j < L.length)
    {
        if(L.data[j] < L.length)
        {
            countArray[L.data[j]]++;
        }
        j++;
    }
    for (int k = 1; k < L.length; k++)
    {
        if (countArray[k] == 0)
        {
            return k;
        }
    }
    return L.length;
}


