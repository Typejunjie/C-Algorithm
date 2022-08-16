#include <stdio.h>
#include "../linkList.h"

/*
算法：使链表递增有序
时间复杂度O(n^2)
空间复杂度O(1)
 */

/* 
算法实现方案：
使用冒泡算法将大的元素后移
 */
void orderList(linkList &L)
{
    linkList last, nowNode;
    last = L->next;
    int p;
    while (last->next != NULL)
    {
        last = last->next;
    }
    while (last != L->next)
    {
        nowNode = L->next;
        while (nowNode->next != last)
        {
            if (nowNode->data > nowNode->next->data)
            {
                p = nowNode->data;
                nowNode->data = nowNode->next->data;
                nowNode->next->data = p;
            }
            nowNode = nowNode->next;
        }
        last = nowNode;
    }
}
