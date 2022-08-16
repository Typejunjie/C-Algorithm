#include "../linkList.h"

/* 
算法：反向打印链表
时间复杂度O(n)
空间复杂度O(n)
 */

void reverseLog(linkList L)
{
    L = L->next;
    if (L == NULL)
    {
        return;
    }
    else
    {
        reverseLog(L);
        cout << "[" << L->data << "]";
    }
}
