#include "../graph-linklist.h"
#include "../graph-matrix.h"

/* 
算法：将邻接表转为邻接矩阵
时间复杂度O(max(n, e))
空间复杂度O(1)
 */

void transLinkGraph(Glist &G, Gmatrix &H)
{
    linkEdge cache;
    initalMatrix(H);
    for (int i = 0; i < G.countPoint; i++)
    {
        H.pointArr[i] = G.data[i]->data;
    }
    H.countPoint = G.countPoint;
    for (int i = 0; i < H.countPoint; i++)
    {
        cache = G.data[i]->Edge;
        while (cache)
        {
            H.data[cache->toPoint][i] = 1;
            cache = cache->nextEdge;
        }
    }
}


