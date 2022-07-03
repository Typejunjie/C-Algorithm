#include "../createClueTree.h"

/* 
算法：给定在中序线索二叉树的结点，找其后序遍历前驱
 */

// count初始为零计数是否为首次传入
linkT inClueTreeXInPostPrior(linkT &T, int count)
{
    if (T->rChild != NULL && T->rtag == 0 && count < 1)
    {
        return T->rChild;
    }
    else if (T->lChild != NULL && T->ltag == 0)
    {
        return T->lChild;
    }
    else 
    {
        count++;
        return inClueTreeXInPostPrior(T->lChild, count);
    }
}