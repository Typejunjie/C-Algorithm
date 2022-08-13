#include "../graph-direction-weightedEdge.h"

/*
算法：拓扑排序
实现前提：逆邻接矩阵存储的有向带权网（在已实现的有向带权网中传入起点终点颠倒的边数组即可）
*/
void topologicalSorting(directionGraph &G)
{
    int visArr[50];
    int count = 0, visPointIndex;
    linkEdge cache, p;
    for (int i = 0; i < G.countPoint; i++) // 设置数组保存访问记录
        visArr[i] = 0;
    while (count < G.countPoint) // 遍历输出结点
    {
        for (visPointIndex = 0; visPointIndex < G.countPoint; visPointIndex++) // 找寻没有被指向的顶点
        {
            if (G.data[visPointIndex]->firstEdge == NULL && visArr[visPointIndex] == 0)
            {
                cout << G.data[visPointIndex]->data;
                visArr[visPointIndex] = 1;
                count++;
                break;
            }
        }
        for (int i = 0; i < G.countPoint; i++) // 遍历删除访问结点关联的边
        {
            cache = G.data[i]->firstEdge;
            if (cache != NULL)
            {
                if (cache->endPoint == visPointIndex)  // 判断第一条边是否关联
                {
                    G.data[i]->firstEdge = cache->nextEdge;
                    delete cache;
                    i--;
                    continue;
                }
                while (cache->nextEdge)
                {
                    if (cache->nextEdge->endPoint == visPointIndex)
                    {
                        p = cache->nextEdge;
                        cache->nextEdge = p->nextEdge;
                        delete p;
                    }
                    else
                    {
                        cache = cache->nextEdge;
                    }
                }
            }
        }
    }
}