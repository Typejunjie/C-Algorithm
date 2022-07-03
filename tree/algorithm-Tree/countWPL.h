#include "../createClueTree.h"

using namespace std;

/* 
算法：计算WPL
 */

// 初始pathW为零，WPL为零
void countWPL(linkT &T, int pathW, int &WPL)
{
    if (T == NULL)
        return;
    if (T->lChild == NULL && T->rChild == NULL)
    {
        WPL = WPL + pathW + T->data;
        return;
    }
    countWPL(T->lChild, pathW + T->data, WPL);
    countWPL(T->rChild, pathW + T->data, WPL);
}