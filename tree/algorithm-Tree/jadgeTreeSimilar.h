#include "../linearQueue.h"

/*
算法：判断两颗树是否相似
相似是指结构相同
 */

bool jadgeTreeSimilar(linkT T, linkT P)
{
    if (T == NULL && P == NULL)
        return true;
    else if (T == NULL || P == NULL)
        return false;
    bool leftTree = jadgeTreeSimilar(T->lChild, P->lChild);
    bool rightTree = jadgeTreeSimilar(T->rChild, P->rChild);
    if (leftTree == false || rightTree == false)
        return false;
    return true;
}