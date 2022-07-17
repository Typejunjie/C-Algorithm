#include "../graph-linklist.h"

/* 
算法：判断一个图是否为树
时间复杂度O()
空间复杂度O()
 */

void vis(Glist G, int localP, int *visArr)
{
    cout << G.data[localP]->data;
    visArr[localP] = 1;
    if (G.data[localP]->Edge == NULL)
        return;
    linkEdge cache;
    cache = G.data[localP]->Edge;
    while (cache != NULL)
    {
        if (visArr[cache->toPoint] == 0)
            vis(G, cache->toPoint, visArr);
        cache = cache->nextEdge;
    }
}

void jadgeTree(Glist &G)
{
    int visitedPoint[50];
    for (int i = 0; i < G.countPoint; i++)
    {
        visitedPoint[i] = 0;
    }
    vis(G, 0, visitedPoint);
}


