#include "../linkList.h"

/* 
算法：找出两个单链表中相同的结点
两个单链表可以是无序的
L1.length = n, L2.length = m
时间复杂度O(nm)
空间复杂度O(min(n,m))
*/

void finSimNode(linkList &L, linkList &S, linkList &emptyList)
{
    emptyList = new Lnode;
    emptyList->next = NULL;
    linkList firstList, lastList, simNode;
    firstList = L->next;
    lastList = S->next;
    while (firstList)
    {
        while (lastList)
        {
            if (lastList->data == firstList->data)
            {
                simNode = new Lnode;
                simNode->data = lastList->data;
                simNode->next = emptyList->next;
                emptyList->next = simNode;
            }
            lastList = lastList->next;
        }
        lastList = S->next;
        firstList = firstList->next;
    }
}

