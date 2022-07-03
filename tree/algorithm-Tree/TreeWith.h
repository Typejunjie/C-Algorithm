#include "../linearQueue.h"

/* 
算法：求树的宽度，即结点数最多的一层结点个数
 */

int TreeWith(linkT &T)
{
    Queue Q;
    initalQueue(Q);
    linkT cache;
    int line = 1;
    int with = 0;
    pushQueue(Q, T);
    while (!queueIsEmpty(Q))
    {
        cache = popQueue(Q);
        if (cache->lChild)
            pushQueue(Q, cache->lChild);
        if (cache->rChild)
            pushQueue(Q, cache->rChild);
        if (line == Q.front)
        {
            if (with < getLength(Q))
                with = getLength(Q);
            line = Q.rear;
        }
    }
    return with;
}