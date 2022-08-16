#include <stdio.h>
#include <iostream>

using namespace std;
#define maxSize 50

typedef struct Edge // 边结点结构定义
{
    int endPoint;
    int power;
    Edge *nextEdge;
} * linkEdge;

typedef struct Gnode // 顶点结构定义
{
    int data;
    Edge *firstEdge;
} * linkGnode;

struct directionGraph // 有向带权网结构定义
{
    int countPoint;
    Gnode *data[maxSize];
};

void initalGraph(directionGraph &G)
{
    G.countPoint = 0;
}

void logDirectionGraph(directionGraph &G)
{
    linkEdge cache;
    for (int i = 0; i < G.countPoint; i++)
    {
        cout << G.data[i]->data;
        cache = G.data[i]->firstEdge;
        while (cache)
        {
            cout << "[->" << cache->endPoint << "|" << cache->power << "]";
            cache = cache->nextEdge;
        }
        cout << endl;
    }
    cout << "Log end" << endl;
}

/*
创建数据结构
参数：初始化后的图G, 顶点结点一维数组，数组长度，顶点结点二维数组 起点、终点、权值，数组长度
 */
void createDirectionGraph(directionGraph &G, int *pointArr, int pLength, int (*edgeArr)[3], int eLength)
{
    linkEdge newEdge, theLastEdge;
    linkGnode newGnode;
    int startPoint, endPoint;         // 存储起始终点结点在data数组的下标
    for (int i = 0; i < pLength; i++) // 初始化顶点
    {
        newGnode = new Gnode;
        newGnode->data = pointArr[i];
        G.data[i] = newGnode;
        G.data[i]->firstEdge = NULL;
    }
    G.countPoint = pLength;
    for (int i = 0; i < eLength; i++) // 创建边结点
    {
        for (startPoint = 0; startPoint < pLength; startPoint++) // 搜索起点结点下标
        {
            if (edgeArr[i][0] == G.data[startPoint]->data)
                break;
        }
        for (endPoint = 0; endPoint < pLength; endPoint++) // 搜索终点结点下标
        {
            if (edgeArr[i][1] == G.data[endPoint]->data)
                break;
        }
        newEdge = new Edge;                  // 声名一个新的边结点
        newEdge->endPoint = endPoint;
        newEdge->power = edgeArr[i][2];
        newEdge->nextEdge = NULL;
        theLastEdge = G.data[startPoint]->firstEdge;
        if (theLastEdge != NULL)
        {
            while (theLastEdge->nextEdge)
                theLastEdge = theLastEdge->nextEdge;
            theLastEdge->nextEdge = newEdge;
        }
        else
        {
            G.data[startPoint]->firstEdge = newEdge;
        }
    }
}