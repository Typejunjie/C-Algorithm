#include "../linearQueue.h"

/* 
算法：交换所有左右子树的值
 */

void exchangeLRnode(linkT &T)
{
    Queue Q;
    initalQueue(Q);
    pushQueue(Q, T);
    linkT cache;
    int value;
    while (!queueIsEmpty(Q))
    {
        cache = popQueue(Q);
        if (cache->lChild && cache->rChild)
        {
            value = cache->lChild->data;
            cache->lChild->data = cache->rChild->data;
            cache->rChild->data = value;
        }
        if (cache->lChild)
            pushQueue(Q, cache->lChild);
        if (cache->rChild)
            pushQueue(Q, cache->rChild);
    }
}