#include <stdio.h>
#include <iostream>

using namespace std;

#define ElemType char
// 二叉树结点结构定义
typedef struct Tree
{
    ElemType data[1];
    struct Tree *lChild, *rChild;
    int ltag = 0, rtag = 0;
} Tree, *linkT;

// 以先序遍历一个棵树
void preLogTree(linkT &T)
{
    if (T != NULL)
    {
        cout << T->data[0];
        preLogTree(T->lChild);
        preLogTree(T->rChild);
    }
}
// 中序遍历
void inLogTree(linkT &T)
{
    if(T != NULL)
    {
        inLogTree(T->lChild);
        cout << T->data[0];
        inLogTree(T->rChild);
    }
}
// 后序遍历
void postLogTree(linkT &T)
{
    if(T != NULL)
    {
        postLogTree(T->lChild);
        postLogTree(T->rChild);
        cout << T->data[0];
    }
}