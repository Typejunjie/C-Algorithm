#include "../dualCircleList.h"

/* 
算法：循环找出最小结点并删除，直到为空链表再删除头结点
时间复杂度O(n^2)
空间复杂度O(n)
 */

void findMinNodeAndDele(circleList &L)
{
    if (L->next == L)
    {
        delete L;
        return;
    }
    circleList nowNode, minNode, free;
    nowNode = L;
    minNode = nowNode;
    while (nowNode->next != L)
    {
        if (nowNode->next->data < minNode->next->data)
        {
            minNode = nowNode;
        }
        nowNode = nowNode->next;
    }
    free = minNode->next;
    minNode->next = free->next;
    free->next->prior = minNode;
    cout << '[' << free->data << ']';
    delete free;
    findMinNodeAndDele(L);
}