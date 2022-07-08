#include <stdio.h>
#include <iostream>
#include "graph-linklist.h"

using namespace std;

int main()
{
    Glist G;
    initalGraph(G);
    int pointArr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int edgeArr[][2] = {1, 2, 3, 4, 3, 2, 5, 6, 7, 8};
    createGraph(G, pointArr, 8, edgeArr, 5);
    log(G);
}
