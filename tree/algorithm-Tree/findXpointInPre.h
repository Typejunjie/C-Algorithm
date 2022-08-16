#include "../linearQueue.h"

using namespace std;

/*
算法：找到先序遍历中第k个元素
 */

int i = 1;

void findXpointInPre(linkT &T, int goal)
{
    if (!T)
        return;
    if (i == goal)
        cout << T->data;
    i++;
    findXpointInPre(T->lChild, goal);
    findXpointInPre(T->rChild, goal);
}