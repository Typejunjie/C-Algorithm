#include <stdio.h>
#include <iostream>

using namespace std;
#define maxSize 100

typedef struct Edge
{
    int toPoint;
    Edge *nextEdge;
} *linkEdge;


typedef struct Gnode
{
    int data;
    Edge *Edge;
} *linkGnode;

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
    
    linkEdge e;
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
        e->nextEdge = G.data[fromPoint]->Edge;
        G.data[fromPoint]->Edge = e;
    }
}/* if (edgeArr[i][0] == G.data[j]->data)
            {
                e = new Edge;
                e->nextEdge = NULL;
                e->nextEdge = G.data[j]->Edge;
                G.data[j]->Edge = e;
                e->toPoint = edgeArr[i][1];
                break;
            } */