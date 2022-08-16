#include <stdio.h>
#include <iostream>
#include "algorithm-Tree/fromArrangeAndDegreeToTree.h"

using namespace std;

int main()
{
    int Array[6][2] = {1, 3, 2, 2, 3, 0, 4, 0, 5, 0, 6, 0};
    linkT T;
    createTreeInArrangeAndDegree(T, Array, 6);
    inLogTree(T);
}

/* linkT p = T->lChild->lChild->lChild;
    linkT q = T->lChild->lChild->rChild;
    linkT r;
    findAncestor(T, p, q, r);
    cout << r->data; */

/* int Array[] = {1, 2, 3, 4, 5, 6, 7};
    linkT T;
    createTree(T, Array, 7);
    int count = countTreeDepth(T);
    cout << count; */

/* char str[] = "*+*abc-\\\\\\\\\\\\\\d";
linkT T;
createTree(T, str, 15);
inLOgMinSUffic(T, 0);
// createTree(T, Array, 16); */