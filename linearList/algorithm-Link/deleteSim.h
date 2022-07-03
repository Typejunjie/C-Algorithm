#include "../linkList.h"

/* 
算法：去重
原表为有序单链表
时间复杂度O(n)
空间复杂度O(1)
 */

void deleteSim(linkList &L)
{
    linkList nowNode, free;
    nowNode = L;
    while (nowNode->next)
    {
        if (nowNode->data == nowNode->next->data)
        {
            free = nowNode->next;
            nowNode->next = free->next;
            delete free;
            continue;
        }
        nowNode = nowNode->next;
    }
}