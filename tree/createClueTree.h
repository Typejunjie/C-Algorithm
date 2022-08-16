#include <stdio.h>
#include <iostream>
#include "linearQueue.h"

/*
在已经建成的二叉树条件下线索化
 */

void createInClueTree(linkT &T, linkT &cache)
{
    if (T == NULL)
        return;
    createInClueTree(T->lChild, cache);
    if (!cache)
        cache = T;
    if (T->lChild == NULL && cache != T)
    {
        T->lChild = cache;
        T->ltag = 1;
    }
    if (cache->rChild == NULL && cache != T)
    {
        cache->rChild = T;
        cache->rtag = 1;
    }
    cache = T;
    createInClueTree(T->rChild, cache);
}

void createPreClueTree(linkT &T, linkT &cache)
{
    if (T == NULL)
        return;
    bool lChildIsNull = false;
    if (T->lChild == NULL && cache != NULL)
    {
        T->lChild = cache;
        T->ltag = 1;
        lChildIsNull = true;
    }
    if (cache != NULL && cache->rChild == NULL)
    {
        cache->rChild = T;
        cache->rtag = 1;
    }
    cache = T;
    if (!lChildIsNull) // 没有该if语句将无线循环stackoverflow
        createPreClueTree(T->lChild, cache);
    createPreClueTree(T->rChild, cache);
    /* 
    在将左子树为空的结点左子树赋值为先序前驱后
    再对左子树递归遍历将无限循环导致stackoverflow
     */
}

void createPostClueTree(linkT &T, linkT &cache)
{
    if (T == NULL)
        return;
    createPostClueTree(T->lChild, cache);
    createPostClueTree(T->rChild, cache);
    if (!cache)
        cache = T;
    if (T->lChild == NULL && cache != T)
    {
        T->lChild = cache;
        T->ltag = 1;
    }
    if (cache->rChild == NULL && cache != T)
    {
        cache->rChild = T;
        cache->rtag = 1;
    }
    cache = T;
}