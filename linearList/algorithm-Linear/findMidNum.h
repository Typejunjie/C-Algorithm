#include <stdio.h>
#include <iostream>
#include "../linearList.h"
/* 
算法：求两个有序序列的中位数
将两个有序序列合并，再求L/2
时间复杂度O(mn)
空间复杂度O(n + m)
 */
int findMidNum(linearList &L, linearList &S)
{
    int i = 0;
    int j = 0;
    int index = 0;
    list newArray;
    newArray.length = L.length + S.length;
    while (i < L.length && j < S.length)
    {
        if(L.data[i] < S.data[j])
        {
            newArray.data[index] = L.data[i];
            i++;
        } 
        else
        {
            newArray.data[index] = S.data[j];
            j++;
        }
        index++;
    }
    if(i < L.length)
    {
        while (i < L.length)
        {
            newArray.data[index] = L.data[i];
            i++;
            index++;
        }
    }
    else 
    {
        while (j < S.length)
        {
            newArray.data[index] = S.data[j];
            j++;
            index++;
        }
    }
    log(newArray);
    return newArray.data[(L.length + S.length) / 2];
}
