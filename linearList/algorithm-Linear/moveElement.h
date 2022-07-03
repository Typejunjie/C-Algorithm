#include <stdio.h>
#include <iostream>
#include "../linearList.h"
/* 
算法：
将一个整数数组的所有元素一致右移p个单位
时间复杂度：O(n)
空间复杂度：O(n)
 */
void moveElement(linearList &L, int p)
{
    int newArray[L.length];
    int distance;
    for (int i = 0; i < L.length; i++)
    {
        distance = i + p;
        if (distance >= L.length)
        {
            distance = (i + p) % L.length;
        }
        newArray[distance] = L.data[i];
    }
    for (int j = 0; j < L.length; j++)
    {
        L.data[j] = newArray[j];
    }
}
