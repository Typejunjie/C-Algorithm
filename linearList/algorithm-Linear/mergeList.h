#include <stdio.h>
#include <iostream>
#include <cmath>
#include "../linearList.h"
/*
算法：计算所有可能三元组中距离最小值
三元组：三个元素组成的线性集合且
距离：设三元组为（a，b，c），距离D = |a - b| + |b - c| + |c - a|
给定三个升序数组集合，a属于S1，b属于S2，c属于S3
求其可能组合中距离最小
S1.length = n, S2.length = m, S3.length = l.
时间复杂度O(nml)
空间复杂度O(n + m + l)
 */
/*
算法实现方案：
先将三个有序序列合并为一个有序序列
遍历该有序序列，计算对应三个值的距离，存储，i++，
再找下一个三元组的距离，依次遍历
 */
// 合并两个有序序列
void mergeList(linearList &L, linearList &S, linearList &newList)
{
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < L.length && j < S.length)
    {
        if (L.data[i] < S.data[j])
        {
            newList.data[count] = L.data[i];
            i++;
        }
        else
        {
            newList.data[count] = S.data[j];
            j++;
        }
        count++;
    }
    if (i < L.length)
    {
        while (i < L.length)
        {
            newList.data[count] = L.data[i];
            i++;
            count++;
        }
    }
    else
    {
        while (j < S.length)
        {
            newList.data[count] = S.data[j];
            j++;
            count++;
        }
    }
    newList.length = count;
}
int findMinD(linearList &L, linearList &S, linearList &T)
{
    list K;
    mergeList(L, S, K);
    list A;
    mergeList(K, T, A);
    int i = 0;
    int minD = 328;
    int nowD;
    while (i < A.length - 3)
    {
        nowD = abs(A.data[i] - A.data[i + 1]) + abs(A.data[i + 1] - A.data[i + 2]) + abs(A.data[i] - A.data[i + 2]);
        if(nowD < minD)
        {
            minD = nowD;
        }
        i++;
    }
    return minD;
}
