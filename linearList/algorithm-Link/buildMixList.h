#include "../linkList.h"

/* 
算法：将后面一半的元素倒置插入到前一半结点中间位置
要求空间复杂度为O(1)
时间复杂度O(n)
空间复杂度O(1)
 */
/* 
实现方案：先将单链表截为两半
再加后一半逆置
将逆置后的链表对应插入前一半的元素间隔中
 */
void bulidMixList(linkList &L)
{
    linkList slow, fast;
    slow = fast = L->next;
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast->next != NULL)
            fast = fast->next;
    }
    linkList last, mid, next;
    last = slow;
    mid = last->next;
    last->next = NULL;
    while (mid != NULL)
    {
        next = mid->next;
        mid->next = last;
        last = mid;
        mid = next;
    }
    mid = L->next;
    while (mid->next != slow)
    {
        mid = mid->next;
    }
    mid->next = NULL;
    linkList S, Lcache;
    Lcache = L->next;
    linkList Scache = last;
    while (Scache)
    {
        S = Scache->next;
        Scache->next = Lcache->next;
        Lcache->next = Scache;
        Scache = S;
        Lcache = Lcache->next->next;
    }
}