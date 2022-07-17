#include <stdio.h>
#include <iostream>
#include "graph-matrix.h"

using namespace std;

int main()
{
    Gmatrix G;
    initalMatrix(G);
    int pointArr[] = {1, 2, 3, 4, 5};
    int edgeArr[][2] = {1, 2, 1, 3, 1, 4, 2, 3, 2, 4, 2, 5, 3, 4, 4, 5};
    createMatrix(G, pointArr, 5, edgeArr, 8);
    logMatrix(G);
    // DFS_matrix(G);
}
/* Gmatrix G;
    initalMatrix(G);
    int pointArr[] = {1, 2, 3, 4};
    int edgeArr[][2] = {1, 2, 3, 4, 3, 2};
    createMatrix(G, pointArr, 4, edgeArr, 3);
    log(G); */

/* Glist G;
Gmatrix H;
initalLinkGraph(G);
int pointArr[] = {1, 2, 3, 4};
int edgeArr[][2] = {1, 2, 3, 4, 3, 2};
createGraph(G, pointArr, 4, edgeArr, 3);
transLinkGraph(G, H);
logMatrix(H); */