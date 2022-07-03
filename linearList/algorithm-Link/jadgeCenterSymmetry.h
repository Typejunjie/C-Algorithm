#include <stdio.h>
#include "../linkList.h"

/* 
算法：判断链表是否中心对称‘
时间复杂度O(n)
空间复杂度O(1)
 */

bool jadgeCenterSymmetry(linkList &L)
{
    linkList slow, fast;
    slow = fast = L;
    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast->next)
            fast = fast->next;
    }
    fast = slow->next;
    slow->next = NULL;
    linkList last, mid, prior;
    last = fast;
    mid = last->next;
    last->next = NULL;
    while (mid)
    {
        prior = mid->next;
        mid->next = last;
        last = mid;
        mid = prior;
    }
    linkList Laft, Right;
    Laft = L->next;
    Right = last;
    while (Laft && Right)
    {
        if (Laft->data != Right->data)
        {
            return false;
        }
        Laft = Laft->next;
        Right = Right->next;
    }
    return true;
}