#include "../linearQueue.h"

/*
算法：将叶子结点从左到右链接为一个单链表
 */

void linkLeaf(linkT T, linkT &cache, linkT &head)
{
    if (T == NULL)
        return;
    linkLeaf(T->lChild, cache, head);
    linkLeaf(T->rChild, cache, head);
    if (T->lChild == NULL && T->rChild == NULL)
    {
        if (!cache)
        {
            cache = T;
            head = cache;
            return;
        }
        cache->rChild = T;
        cache = T;
    }
}