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
    int countpoint;
} Glist[maxSize];

void initalGraph(Glist &G)
{
    G->countpoint = 0;
}

void createGraph(Glist &G, int *pointArr, int plength, int (*edgeArr)[2], int elength)
{
    linkEdge e;
    for (int i = 0; i < plength; i++)
    {
        G[i].data = pointArr[i];
    }
    G->countpoint = plength;
    for (int i = 0; i < elength; i++)
    {
        for (int j = 0; j < plength; j++)
        {
            if (edgeArr[i][0] = G[j].data)
            {
                e = new Edge;
                e->nextEdge = G[j].Edge;
                G[j].Edge = e;
                break;
            }
        }
    }
}