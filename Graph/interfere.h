#include <stdio.h>
#include <iostream>
using namespace std;
#define MaxSize 100
// 边结点
typedef struct Edge
{
    int toPoint;
    Edge *nextEdge;
}*linkEdge;
// 头节点
typedef struct Gnode
{
    char data;
    Edge *next;
} Glist[MaxSize];
// 图的定义
typedef struct Graph_L
{
    Glist list;
    int point, edge;
};
// 
int locateData_L(Graph_L G, char data)
{
    for (int i = 0; i < G.point; i++)
    {
        if(data == G.list[i].data)
        {
            return i;
        }
    }
    return -1;    
}
// 邻接表存储网
void createGraph_L(Graph_L &G)
{
    cout << "input point and Edge" << endl;
    cin >> G.point >> G.edge;
    for (int i = 0; i < G.point; i++)
    {
        cin >> G.list[i].data;
        G.list[i].next = NULL;
    }
    cout << "头节点构造完成" << endl;
    for (int k = 0; k < G.edge; k++)
    {
        char v1, v2;
        int i, j;
        cin >> v1 >> v2;
        i = locateData_L(G, v1);
        j = locateData_L(G, v2);
        // 头插法插入结点
        linkEdge p1 = new Edge;
        p1->toPoint = j;
        p1->nextEdge = G.list[i].next;
        G.list[i].next = p1;
        linkEdge p2 = new Edge;
        p2->toPoint = i;
        p2->nextEdge = G.list[j].next;
        G.list[j].next = p2;
    }
    cout << "OK" << endl;
}

// 线性存储图
struct Graph
{
    char data[MaxSize];         // 顶点表
    int arcs[MaxSize][MaxSize]; // 邻接矩阵
    int point, edge;            // 点和边数
};

// 查找输入结点的位置
int locatePoint(Graph G, char data)
{
    for (int i = 0; i < G.point; i++)
    {
        if (data == G.data[i])
        {
            return i;
        }
    }
    return -1;
}
// 初始化一个网
void createGraph(Graph &G)
{
    cout << "输入点和边的个数" << endl;
    cin >> G.point >> G.edge;
    for (int i = 0; i < G.point; i++)
    {
        cin >> G.data[i];
    }
    cout << "顶点表构建完成" << endl;
    for (int i = 0; i < G.point; i++)
    {
        for (int j = 0; j < G.point; j++)
        {
            G.arcs[i][j] = 32314;
        }
    }
    cout << "邻接矩阵初始化完成" << endl;
    for (int k = 0; k < G.edge; k++)
    {
        char v1, v2;
        int i, j, w;
        cout << "输入两个元素和对应边的权值" << endl;
        cin >> v1 >> v2 >> w;
        i = locatePoint(G, v1);
        j = locatePoint(G, v2);
        if (i == -1 || j == -1)
        {
            cout << "找不到对应顶点" << endl;
            k--;
            continue; // 找不到对应元素跳过该次循环
        }
        G.arcs[i][j] = w;
        G.arcs[j][i] = w;
    }
    cout << "OK" << endl;
}
