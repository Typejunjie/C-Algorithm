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


void initalGraph(Glist &G)
{
    G.countPoint = 0;
}

void log(Glist &G)
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
        for (int j = 0; j < G.countPoint; j++)
        {
            if (edgeArr[i][0] == G.data[j]->data)
            {
                e = new Edge;
                e->nextEdge = NULL;
                e->nextEdge = G.data[j]->Edge;
                G.data[j]->Edge = e;
                e->toPoint = edgeArr[i][1];
                break;
            }
        }
    }
}