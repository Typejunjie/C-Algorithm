#include "../linearQueue.h"

/* 
算法：非递归实现后续遍历、

 */

void postLogTreeInNoRecursion(linkT &T)
{
    Stack S;
    initalStack(S);
    linkT cache = T;
    linkT r;
    while (cache || S.top != 0)
    {
        if (cache)
        {
            pushStack(S, cache);
            cache = cache->lChild;
        }
        else
        {
            cache = S.data[S.top - 1];
            if (cache->rChild && cache != r)
            {
                cache = cache->rChild;
            }
            else
            {
                cache = popStack(S);
                cout << cache->data;
                r = cache;
                cache = NULL;
            }
        }
    }
}