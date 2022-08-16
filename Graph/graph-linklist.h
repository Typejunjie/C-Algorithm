#include <stdio.h>
#include <iostream>

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

void BFSvis_linkGraph(Glist &G, int localP, int *visArr)
{
    if (visArr[localP] == 0)
    {
        cout << G.data[localP]->data;
        visArr[localP] = 1;
    }
    linkEdge cache = G.data[localP]->Edge;
    while (cache)
    {
        if (visArr[cache->toPoint] == 0)
        {
            cout << G.data[cache->toPoint]->data;
        }
        cache = cache->nextEdge;
    }
    cache = G.data[localP]->Edge;
    while (cache)
    {
        if (visArr[cache->toPoint] == 0)
        {
            visArr[cache->toPoint] = 1;
            BFSvis_linkGraph(G, cache->toPoint, visArr);
        }
        cache = cache->nextEdge;
    }
}

void BFS_linkList(Glist &G)
{
    int visitedPoint[50];
    for (int i = 0; i < G.countPoint; i++)
        visitedPoint[i] = 0;
    BFSvis_linkGraph(G, 0, visitedPoint);
}

// BFS //////////////////
