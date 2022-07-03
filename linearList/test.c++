#include <stdio.h>
#include <iostream>
#include "algorithm-Link/jadgeCenterSymmetry.h"

using namespace std;

int main()
{
    int Array[] = {2, 3, -2, -15, -15, -2, 3, 2};
    linkList L;
    creatLinkList(L, Array, 8);
    bool jadge = jadgeCenterSymmetry(L);
    cout << jadge;
}
/* // Initialize a linked list
    linkList L;
    int LArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    InitList(L);
    // createList_H(L);
    createList_L(L, LArray);
    log(L); */

// algorithm_1(L, 7);
// log(L);
// int index = halfSearch(L, 9);
// cout << index << endl;

/* int LArray_1[] = {-1, 0, 9};
    int LArray_2[] = {-25, -10, 10, 11};
    int LArray_3[] = {2, 9, 17, 30, 41};
    list L;
    list S;
    list T;
    creatLinearList(L, LArray_1, 3);
    creatLinearList(S, LArray_2, 4);
    creatLinearList(T, LArray_3, 5);
    int count = findMinD(L, S, T);
    cout << count << endl; */