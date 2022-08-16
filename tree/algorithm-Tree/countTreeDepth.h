#include "../linearQueue.h"

/* 
算法：计算一颗以孩子兄弟存储法存储的树的深度
 */

int countTreeDepth(linkT &T)
{
    if (T == NULL)
        return 0;
    int lDepth = countTreeDepth(T->lChild);
    int rDepth = countTreeDepth(T->rChild) - 1;
    if (lDepth > rDepth)
        return lDepth + 1;
    else
        return rDepth + 1;
}