#include "../linearQueue-char.h"

/*
算法：由表达式二叉树构造适当括号的中缀表达式
根部和叶子结点不需要套括号
 */

// 初始count等于0
void inLOgMinSUffic(linkT &T, int count)
{
    if (T == NULL)
        return;
    if (T->lChild == NULL && T->rChild == NULL)
    {
        cout << T->data[0];
    }
    else
    {
        if (count > 0)
            cout << '(';
        inLOgMinSUffic(T->lChild, count + 1);
        cout << T->data[0];
        inLOgMinSUffic(T->rChild, count + 1);
        if (count > 0)
            cout << ')';
    }
}