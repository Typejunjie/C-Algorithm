#include "../linkList.h"

/* 
算法：从两个链表中抽取相同结点
要求不破坏原链表，且原链表为有序
时间复杂度O(n)
空间复杂度O(1)
 */

void findSimNodeFromOrder(linkList &L, linkList &S, linkList &empty)
{
    linkList Lcache, Scache, cache;
    empty = new Lnode;
    empty->next = NULL;
    Lcache = L->next;
    Scache = S->next;
    while (Lcache && Scache)
    {
        if (Lcache->data == Scache->data)
        {
            cache = new Lnode;
            cache->data = Lcache->data;
            cache->next = empty->next;
            empty->next = cache;
            Lcache = Lcache->next;
            Scache = Scache->next;
        }
        else if (Lcache->data < Scache->data)
        {
            Lcache = Lcache->next;
        }
        else
        {
            Scache = Scache->next;
        }        
    }
}