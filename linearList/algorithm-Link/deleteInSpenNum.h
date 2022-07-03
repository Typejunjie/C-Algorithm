#include "../linkList.h"

/* 
算法：删除给定范围内的值结点
给定链表为无序
时间复杂度O(n)
空间复杂度O(1)
 */

void deleteInSpenNum(linkList &L, int min, int max)
{
    linkList nowNode = L;
    linkList free;
    while (nowNode->next != NULL)
    {
        if (nowNode->next->data < max && nowNode->next->data > min)
        {
            free = nowNode->next;
            nowNode->next = free->next;
            delete free;
        }
        nowNode = nowNode->next;
    }
}

