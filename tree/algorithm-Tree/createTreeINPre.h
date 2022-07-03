#include "../linearQueue.h"

/* 
算法：根据先序和中序构建二叉链表存储的二叉树
 */

int localRoot(int key, int *Array, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (Array[i] == key)
        {
            return i;
        }
    }
    return 0;
}

linkT createTreeINPre(int *pre, int *in, int ileft, int iright, int num)
{
    linkT cache;
    int minPre[] = {0, 100}, local;
    for (int i = ileft; i <= iright; i++)
    {
        local = localRoot(in[i], pre, num);
        if (local < minPre[1])
        {
            minPre[1] = local;
            minPre[0] = i;
        }
    }
    cache = createT(in[minPre[0]]);
    int root = minPre[0];
    if (ileft != root)
        cache->lChild = createTreeINPre(pre, in, ileft, root - 1, num);
    if (iright != root)
        cache->rChild = createTreeINPre(pre, in, root + 1, iright, num);
    return cache;
}