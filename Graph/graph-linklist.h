#include <stdio.h>
#include <iostream>
#include "../Stack/linearStack.h"
#include "../Queue/linearQueue.h"

using namespace std;
#define maxSize 50

typedef struct Edge
{
    int toPoint;
    Edge *nextEdge;
} * linkEdge;

typedef struct Gnode
{
    int data;
    Edge *Edge;
} * linkGnode;

struct Glist
{
    Gnode *data[100];
    int countPoint;
};

void initalLinkGraph(Glist &G)
{
    G.countPoint = 0;
}

void logLinkGraph(Glist &G)
{
    linkEdge cache;
    for (int i = 0; i < G.countPoint; i++)
    {
        cout << G.data[i]->data;
        cache = G.data[i]->Edge;
        while (cache)
        {
            cout << "[" << cache->toPoint << "]";
            cache = cache->nextEdge;
        }
        cout << endl;
    }
    cout << "Log end" << endl;
}

void createGraph(Glist &G, int *pointArr, int plength, int (*edgeArr)[2], int elength)
{
    linkEdge e, lastE;
    linkGnode cache;
    int fromPoint, toPoint;
    for (int i = 0; i < plength; i++)
    {
        cache = new Gnode;
        cache->data = pointArr[i];
        G.data[i] = cache;
        cache->Edge = NULL;
    }
    G.countPoint = plength;
    for (int i = 0; i < elength; i++)
    {
        for (fromPoint = 0; fromPoint < G.countPoint; fromPoint++)
        {
            if (edgeArr[i][0] == G.data[fromPoint]->data)
                break;
        }
        for (toPoint = 0; toPoint < G.countPoint; toPoint++)
        {
            if (edgeArr[i][1] == G.data[toPoint]->data)
                break;
        }
        e = new Edge;
        e->toPoint = toPoint;
        e->nextEdge = NULL;
        lastE = G.data[fromPoint]->Edge;
        if (lastE != NULL)
        {
            while (lastE->nextEdge != NULL)
                lastE = lastE->nextEdge;
            lastE->nextEdge = e;
        }
        else
        {
            G.data[fromPoint]->Edge = e;
        }
        e = new Edge;
        e->toPoint = fromPoint;
        e->nextEdge = NULL;
        lastE = G.data[toPoint]->Edge;
        if (lastE != NULL)
        {
            while (lastE->nextEdge != NULL)
                lastE = lastE->nextEdge;
            lastE->nextEdge = e;
        }
        else
        {
            G.data[toPoint]->Edge = e;
        }
    }
}

// DFS //////////////////

void DFSvis_linkGraph(Glist G, int localP, int *visArr)
{
    linkEdge cache;
    visArr[localP] = 1;
    cout << G.data[localP]->data;
    if (G.data[localP]->Edge == NULL)
        return;
    cache = G.data[localP]->Edge;
    while (cache != NULL)
    {
        if (visArr[cache->toPoint] == 0)
            DFSvis_linkGraph(G, cache->toPoint, visArr);
        cache = cache->nextEdge;
    }
}

void DFS_linkList(Glist &G)
{
    int visitedPoint[50];
    for (int i = 0; i < G.countPoint; i++)
    {
        visitedPoint[i] = 0;
    }
    DFSvis_linkGraph(G, 0, visitedPoint);
}

// DFS //////////////////

// BFS //////////////////

void BFS_visited(int pointValue)
{
    cout << pointValue;
}

void BFS_linkGraph(Glist &G)
{
    bool visited[20];
    for (int i = 0; i < G.countPoint; i++)
        visited[i] = false;
    Queue Q;
    initalQueue(Q);
    pushQueue(Q, 0);
    visited[0] = true;
    int cache;
    linkEdge cacheEdge;
    while (judgeQueueEmpty(Q) == false)
    {
        cache = popQueue(Q);
        BFS_visited(G.data[cache]->data);
        cacheEdge = G.data[cache]->Edge;
        while (cacheEdge)
        {
            if (visited[cacheEdge->toPoint] == false)
            {
                pushQueue(Q, cacheEdge->toPoint);
                visited[cacheEdge->toPoint] = true;
            }
            cacheEdge = cacheEdge->nextEdge;
        }
    }
}

// BFS //////////////////
