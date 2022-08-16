#include "../linkList.h"

/* 
算法：判断是否为子序列
给与两个有序链表判断其中一个是否为另一个的连续子序列
时间复杂度O(n^2)
空间复杂度O(1)
 */
// 模式串匹配幼稚算法
bool jadgeSubsequence(linkList &L, linkList &S)
{
    linkList Lcache, Scache, Lnow;
    Lcache = L->next;
    Lnow = L->next;
    Scache = S->next;
    int count = 0;
    while (Lcache && Scache)
    {
        if (Lcache->data == Scache->data)
        {
            if (count == 0)
                Lnow = Lcache;
            count++;
            Lcache = Lcache->next;
            Scache = Scache->next;
        }
        else
        {
            count = 0;
            Lcache = Lnow->next;
            Lnow = Lcache;
            Scache = S->next;
        }
    }
    if (Scache)
        return false;
    else
        return true;
}