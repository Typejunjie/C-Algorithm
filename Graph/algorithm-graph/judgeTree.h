#include "../graph-linklist.h"

/* 
算法：判断一个图是否为树
 */

bool vis(Glist G, int localP, int *visArr, int prevPoint)
{
    visArr[localP] = 1;
    if (G.data[localP]->Edge->nextEdge == NULL)
        return true;
    linkEdge cache;
    bool jadge = true;
    cache = G.data[localP]->Edge;
    while (cache != NULL)
    {
        if (visArr[cache->toPoint] != 0 && cache->toPoint != prevPoint)
        {
            return false;
        }
        cache = cache->nextEdge;
    }
    cache = G.data[localP]->Edge;
    while (cache != NULL)
    {
        if (visArr[cache->toPoint] == 0)
        {
            jadge = vis(G, cache->toPoint, visArr, localP);
        }
        if (jadge == false)
        {
            return false;
        }
        cache = cache->nextEdge;
    }
    return true;
}

bool judgeTree(Glist &G)
{
    int visitedPoint[50];
    for (int i = 0; i < G.countPoint; i++)
    {
        visitedPoint[i] = 0;
    }
    return vis(G, 0, visitedPoint, -1);
}