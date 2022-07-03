#include <stdio.h>
#include <iostream>

using namespace std;

typedef struct Lnode
{
    int data, freq;
    struct Lnode *next, *prior;
} Lnode, *dualFreqList;

//
void log(dualFreqList &L)
{
    dualFreqList cache;
    cache = L->next;
    while (cache)
    {
        cout << '[' << cache->data << "," << cache->freq << ']';
        cache = cache->next;
    }
    cout << "Log end";
}

//创建双链表
void createDualFreq(dualFreqList &L, int *Array, int length)
{
    dualFreqList pointL, cache;
    L = new Lnode;
    L->next = NULL;
    L->prior = NULL;
    pointL = L;
    for (int i = 0; i < length; i++)
    {
        cache = new Lnode;
        cache->next = NULL;
        cache->data = Array[i];
        cache->freq = 0;
        pointL->next = cache;
        cache->prior = pointL;
        pointL = cache;
    }
}

/*
算法：实现Locate函数
要求，传入链表L和参数X，找到X结点并将X结点的Freq++
最后使得结点的Freq呈非递增顺序排列
freq最大的元素放最前面，并且每次访问的结点排在同freq的最前面
时间复杂度O(n)
空间复杂度O(1)
 */

dualFreqList Locate(dualFreqList &L, int x)
{
    dualFreqList cache;
    int value;
    cache = L->next;
    while (cache)
    {
        if (cache->data == x)
        {
            break;
        }
        cache = cache->next;
    }
    if (cache->data == x)
    {
        cache->freq++;
        while (cache->prior != L)
        {
            if (cache->prior->freq > cache->freq)
            {
                break;
            }
            value = cache->data;
            cache->data = cache->prior->data;
            cache->prior->data = value;
            value = cache->freq;
            cache->freq = cache->prior->freq;
            cache->prior->freq = value;
            cache = cache->prior;
        }
        return cache;
    }
    else
    {
        return NULL;
    }
}