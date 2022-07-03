#include "../linearQueue.h"

/* 
算法：计算孩子兄弟表示法存储的森林的叶子结点数
 */

int countForestLeaf(linkT &T)
{
    if (T == NULL)
        return 0;
    int lLeaf = countForestLeaf(T->lChild);
    int rLeaf = countForestLeaf(T->rChild);
    int sum = lLeaf + rLeaf;
    if (T->rChild == NULL)
        sum++;
    return sum;
}