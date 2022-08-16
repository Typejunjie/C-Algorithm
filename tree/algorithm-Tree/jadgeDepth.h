#include "../linearQueue.h"

/* 
算法：判断树的层数
 */

int jadgeDepth(linkT &T)
{
    Queue Q;
    initalQueue(Q);
    linkT cache = T;
    pushQueue(Q, T);
    int last = 1, level = 0;
    while (!queueIsEmpty(Q))
    {
        cache = popQueue(Q);
        if (cache->lChild)
            pushQueue(Q, cache->lChild);
        if (cache->rChild)
            pushQueue(Q, cache->rChild);
        if (Q.front == last)
        {
            level++;
            last = Q.rear;
        }
    }
    return level;
}
