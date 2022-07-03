#include "../linearQueue.h"

/*
算法：判断二叉树是否为完全二叉树
实现方案：层次遍历树，将存在的结点左右子树都入队无论是否为空
         出队时遇到空指针推出循环，再将队列剩余元素出队查看
         是否有非空结点，有则非完全二叉树，没有则相反
 */

bool jadgeTreeComplete(linkT &T)
{
    Queue Q;
    initalQueue(Q);
    linkT cache = T;
    pushQueue(Q, T);
    while (!queueIsEmpty(Q))
    {
        cache = popQueue(Q);
        if (cache)
        {
            pushQueue(Q, cache->lChild);
            pushQueue(Q, cache->rChild);
        }
        else
            break;
    }
    while (!queueIsEmpty(Q))
    {
        cache = popQueue(Q);
        if (cache != NULL)
            return false;
    }
    return true;
}