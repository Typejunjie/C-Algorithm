#include "../linkList.h"

/* 
算法：将一个单链表中奇数位置与偶数位置元素拆分为两个单链表
需要就地执行，即空间复杂度为O(1)
时间复杂度O(n)
空间复杂度O(1)
 */

void splitListInHarf(linkList &L, linkList &emptyL, linkList &emptyS)
{
    emptyL = new Lnode;
    emptyS = new Lnode;
    emptyL->next = NULL;
    emptyS->next = NULL;
    linkList nowNode = L->next;
    linkList El, Es;
    El = emptyL;
    Es = emptyS;
    int count = 1;
    while (nowNode)
    {
        if (count % 2 == 1)
        {
            El->next = nowNode;
            nowNode = nowNode->next;
            El = El->next;
            El->next = NULL;
        }
        else
        {
            Es->next = nowNode;
            nowNode = nowNode->next;
            Es = Es->next;
            Es->next = NULL;
        }
        count++;
    }
}

