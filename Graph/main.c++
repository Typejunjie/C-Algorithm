#include <stdio.h>
#include <iostream>
#include "graph-linklist.h"

using namespace std;

int main()
{
    Glist G;
    int pointArr[] = {1, 2, 3, 4, 5};
    int edgeArr[][2] = {1, 2, 1, 3, 3, 4, 3, 5, 1, 5};
    createGraph(G, pointArr, 5, edgeArr, 5);
    logLinkGraph(G);
    BFS_linkGraph(G);
}
/* Gmatrix G;
    initalMatrix(G);
    int pointArr[] = {1, 2, 3, 4};
    int edgeArr[][2] = {1, 2, 3, 4, 3, 2};
    createMatrix(G, pointArr, 4, edgeArr, 3);
    log(G); */

/*  Gmatrix G;
    initalMatrix(G);
    int pointArr[] = {1, 2, 3, 4, 5};
    int edgeArr[][2] = {1, 2, 1, 3, 1, 4, 2, 3, 2, 4, 2, 5, 3, 4, 4, 5};
    createMatrix(G, pointArr, 5, edgeArr, 8);
    logMatrix(G);
    DFS_matrix(G); */

/* Glist G;
    initalLinkGraph(G);
    int pointArr[] = {1, 2, 3, 4, 5, 6};
    int edgeArr[][2] = {1, 4, 1, 3, 1, 2, 4, 5, 5, 1};
    createGraph(G, pointArr, 6, edgeArr, 5);
    // logLinkGraph(G);
    bool judge = judgementPath(G, 1, 6);
    cout << judge; */