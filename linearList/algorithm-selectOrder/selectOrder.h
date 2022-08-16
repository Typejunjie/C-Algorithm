#include "../linearList.h"

/* 
算法：选择排序
时间复杂度O(n^2)
空间复杂度O(1)
 */

void selectOrder(linearList &L)
{
    int i, j, cache, value;
    for (i = 0; i < L.length; i++)
    {
        cache = i;
        for (j = i + 1; j < L.length; j++)
        {
            if (L.data[j] < L.data[cache])
            {
                cache = j;
            }
        }
        value = L.data[i];
        L.data[i] = L.data[cache];
        L.data[cache] = value;
    }
}