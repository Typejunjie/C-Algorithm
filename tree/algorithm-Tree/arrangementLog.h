#include "../linearQueue.h"

/* 
算法：树的层次遍历
 */

void arrangementLog(linkT &T)
{
    Queue Q;
    initalQueue(Q);
    linkT cache = T;
    pushQueue(Q, T);
    while (!queueIsEmpty(Q))
    {
        cache = popQueue(Q);
        cout << cache->data;
        if (cache->lChild)
        {
            pushQueue(Q, cache->lChild);
        }
        if (cache->rChild)
        {
            pushQueue(Q, cache->rChild);
        }
    }
}