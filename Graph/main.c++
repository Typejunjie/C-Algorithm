#include <stdio.h>
#include <iostream>
#include "algorithm-graph/jadgeElRoute.h"

using namespace std;

int main()
{
    Gmatrix G;
    initalMatrix(G);
    int pointArr[] = {1, 2, 3, 4};
    int edgeArr[][2] = {1, 3, 1, 2};
    createMatrix(G, pointArr, 4, edgeArr, 2);
    bool jadge = jadgeElroute(G);
    cout << jadge;
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