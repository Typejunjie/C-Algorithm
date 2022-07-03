#include "../linkList.h"

/* 
算法：递增次序输出单链表的结点
单链表可以是无序的
时间复杂度O(n^2)
空间复杂度O(1)
 */

void outputInOrder(linkList &L)
{
    if (L->next == NULL) return;
    linkList nowNode, minNode, free;
    nowNode = L;
    minNode = L;
    while (nowNode->next)
    {
        if (nowNode->next->data < minNode->next->data)
        {
            minNode = nowNode;
        }
        nowNode = nowNode->next;
    }
    free = minNode->next;
    cout << '[' << free->data << ']';
    minNode->next = minNode->next->next;
    delete free;
    outputInOrder(L);
}
