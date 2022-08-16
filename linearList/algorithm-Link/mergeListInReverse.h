#include "../linkList.h"

/*
算法：合并两个有序链表
要求将升序转为降序，且原地执行
L1.length = n, L2.length = m
时间复杂度O(min(n, m))
空间复杂度O(1)
 */

void mergeListInReverse(linkList &L, linkList &S, linkList &mergeList)
{
    linkList Lcache, Scache, cache;
    mergeList = new Lnode;
    mergeList->next = NULL;
    Lcache = L->next;
    Scache = S->next;
    while (Lcache && Scache)
    {
        if (Lcache->data < Scache->data)
        {
            cache = Lcache;
            Lcache = Lcache->next;
        }
        else
        {
            cache = Scache;
            Scache = Scache->next;
        }
        cache->next = mergeList->next;
        mergeList->next = cache;
    }
    while (Lcache)
    {
        cache = Lcache;
        Lcache = Lcache->next;
        cache->next = mergeList->next;
        mergeList->next = cache;
    }
    while (Scache)
    {
        cache = Scache;
        Scache = Scache->next;
        cache->next = mergeList->next;
        mergeList->next = cache;
    }
}