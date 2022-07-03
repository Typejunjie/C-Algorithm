#include "../linkList.h"

/*
算法：将链表分为偶数与奇数两个链表
需要保持表中元素相对位置不变
时间复杂度O(n)
空间复杂度O(1)
 */

void splitList(linkList &L, linkList &emptyL, linkList &emptyS)
{
    emptyL = new Lnode;
    emptyS = new Lnode;
    emptyL->next = NULL;
    emptyS->next = NULL;
    linkList El, Es, cache; // 需使用尾插法构建奇偶表
    El = emptyL;
    Es = emptyS;
    linkList nowNode;
    nowNode = L->next;
    while (nowNode)
    {
        cache = new Lnode;
        cache->data = nowNode->data;
        cache->next = NULL;
        if (nowNode->data % 2 == 1)
        {
            El->next = cache;
            El = cache;
        }
        else
        {
            Es->next = cache;
            Es = cache;
        }
        nowNode = nowNode->next;
    }
}
