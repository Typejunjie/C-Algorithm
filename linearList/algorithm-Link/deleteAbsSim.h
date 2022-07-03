#include <math.h>
#include <stdio.h>
#include "../linkList.h"

/*
算法：去掉绝对值相同的结点
时间复杂度O(n)
空间复杂度O(n)
 */
/*
实现方案：设立一个数组保存链表中的绝对值
扫描链表时对应为0则自加，否则删除该结点
 */
void deleteAbsSim(linkList &L, int n)
{
    linkList Lcache, point;
    point = L;
    int value;
    int Array[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        Array[i] = 0;
    }
    while (point->next)
    {
        value = abs(point->next->data);
        if (Array[value] == 0)
        {
            point = point->next;
            Array[value]++;
        }
        else
        {
            point->next = point->next->next;
        }
    }
}

/* 
特殊实现方法：
由每个元素开始遍历后面的元素是否绝对值相等，相等则删除
每轮遍历元素后移一位
时间复杂度O(n^2)
空间复杂度O(1)
 */
void deleteAbsSimSpacial(linkList &L)
{
    linkList cache, point;
    point = L->next;
    while (point)
    {
        cache = point;
        while (cache->next)
        {
            if (abs(point->data) == abs(cache->next->data))
            {
                cache->next = cache->next->next;
                continue;
            }
            cache = cache->next;
        }
        point = point->next;
    }
}