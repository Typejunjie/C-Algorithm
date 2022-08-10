#include "../graph-linklist.h"

/* 
算法：判断两个结点间是否存在路径
实现方法：DFS深度遍历
先在结点数组中遍历出起始结点的标传入vis函数
vis：
先检查当前结点是否是目标结点
再递归已连接的结点是否传回查找成功的返回值
若递归传回查找成功则将自身下标push在L表末尾得到倒序下标路径（此处仅存储不处理）
然后返回对应结果给上一个递归
 */

struct linearList
{
    int pathArr[50];
    int length = 0;
};

bool pathVis(Glist &G, linearList &L, int *visArr, int nowPoint, int searchPoint)
{
    bool judge = false;
    visArr[nowPoint] = 1;
    if (G.data[nowPoint]->data == searchPoint)// 判断当前结点是否是目标结点
        judge = true;
    linkEdge cache = G.data[nowPoint]->Edge;
    while (cache)                             // 循环遍历其他已链接结点是否存在路径
    {
        if (judge)
            break;
        if (visArr[cache->toPoint] == 0)
            judge = pathVis(G, L, visArr, cache->toPoint, searchPoint);
        cache = cache->nextEdge;
    }
    if (judge)
    {
        L.pathArr[L.length] = nowPoint;
        L.length++;
        return true;
    }
    return false;
}

bool judgementPath(Glist &G, int fromPoint, int toPoint)
{
    linearList L;                 // 声名一个线性表存储路径
    int visitedPoint[50];         // 声名一个数组存储已访问结点
    int j;
    for (int i = 0; i < G.countPoint; i++)
    {
        visitedPoint[i] = 0;
    }
    for (j = 0; j < G.countPoint; j++)
    {
        if (G.data[j]->data == fromPoint)
            break;
    }
    
    return pathVis(G, L, visitedPoint, j, toPoint);
}