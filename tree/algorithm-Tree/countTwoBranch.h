#include "../linearQueue.h"

/* 
算法：计算双分支结点个数
 */

int countTwoBranch(linkT &T)
{
    Queue Q;
    initalQueue(Q);
    pushQueue(Q, T);
    linkT cache;
    int count = 0;
    while (!queueIsEmpty(Q))
    {
        cache = popQueue(Q);
        if (cache->lChild && cache->rChild)
            count++;
        if (cache->lChild)
            pushQueue(Q, cache->lChild);
        if (cache->rChild)
            pushQueue(Q, cache->rChild);
    }
    return count;
}