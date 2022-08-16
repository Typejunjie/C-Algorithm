#include "../linearQueue.h"

/*
算法：找到两个结点的最近公共祖先
 */

int findAncestor(linkT &T, linkT p, linkT q, linkT &r)
{
    if (T == NULL)
        return 0;
    if (T == p || T == q)
        return 1;
    else
    {
        int cache_1 = findAncestor(T->lChild, p, q, r);
        int cache_2 = findAncestor(T->rChild, p, q, r);
        if (cache_1 == 1 && cache_2 == 1)
        {
            r = T;
            return 0;
        }
        else if (cache_1 == 1 || cache_2 == 1)
            return 1;
        else
            return 0;
    }
}