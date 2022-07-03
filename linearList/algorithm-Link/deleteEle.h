#include "../linkList.h"

/*
算法：删除值为x的结点
使用递归实现
时间复杂度O(n)
空间复杂度O(n)
 */

void deleteEleX(linkList L, int key)
{
    if (L->next == NULL)
    {
        return;
    }
    else if (L->next->data == key)
    {
        linkList nextNode = L->next;
        L->next = L->next->next;
        delete nextNode;
    }
    L = L->next;
    deleteEleX(L, key);
}
