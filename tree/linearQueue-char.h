#include <stdio.h>
#include <iostream>
#include <math.h>
#include "interfere-char.h"

using namespace std;

struct Queue
{
    Tree *data[20];
    int front, rear;
    int tag, volume = 20;
};

// 获取队列当前长度
int getLength(Queue Q)
{
    int cache;
    if (Q.front <= Q.rear)
        cache = Q.rear - Q.front;
    else
        cache = Q.volume - (Q.rear - Q.front);
    return cache;
}

// 初始化队列
void initalQueue(Queue &Q)
{
    Q.front = 0;
    Q.rear = 0;
    Q.tag = 0;
}

void pushQueue(Queue &Q, linkT &T)
{
    if (Q.rear == Q.front && Q.tag == 1)
    {
        // cout << "队列发生了溢出" << endl;
        return;
    }
    Q.data[Q.rear] = T;
    Q.rear = ++Q.rear % Q.volume;
    if (Q.rear == Q.front)
        Q.tag = 1;
}

linkT popQueue(Queue &Q)
{
    if (Q.front == Q.rear && Q.tag == 0)
    {
        // cout << "队空，无法取出元素" << endl;
        return 0;
    }
    linkT value = Q.data[Q.front];
    Q.front = ++Q.front % Q.volume;
    if (Q.tag == 1)
        Q.tag = 0;
    return value;
}

void logQueue(Queue &Q)
{
    int cache = Q.front;
    cout << "front->";
    if (cache != Q.rear || Q.tag == 1)
    {
        do
        {
            if (Q.data[cache] == NULL)
            {
                cout << '|' << "NULL" << '|';
            }
            else
            {
                cout << '|' << Q.data[cache]->data << '|';
            }
            cache = ++cache % Q.volume;
        } while (cache != Q.rear);
    }
    cout << "<-rear" << endl;
}

linkT createT(char str)
{
    linkT cache = new Tree;
    cache->data[0] = str;
    cache->rChild = NULL;
    cache->lChild = NULL;
    return cache;
}

void clearNull(linkT &T)
{
    if (T == NULL)
        return;
    if (T->lChild->data[0] == '\\')
        T->lChild = NULL;
    else
        clearNull(T->lChild);
    if (T->rChild->data[0] == '\\')
        T->rChild = NULL;
    else
        clearNull(T->rChild);
}

// 由层次遍历数组创建二叉树
void createTree(linkT &T, char *Array, int length)
{
    Queue Q;
    initalQueue(Q);
    linkT cache;
    T = createT(0);
    pushQueue(Q, T);
    int i = 0;
    while (true)
    {
        cache = popQueue(Q);
        if (cache == 0) // 队列下溢返回0
            break;
        else if (Array[i] == '\\' || i >= length)
        {
            cache = NULL;
        }
        else
        {
            cache->data[0] = Array[i];
            cache->lChild = createT('\\');
            cache->rChild = createT('\\');
            pushQueue(Q, cache->lChild);
            pushQueue(Q, cache->rChild);
        }
        i++;
    }
    clearNull(T);
}

bool queueIsEmpty(Queue &Q)
{
    if (Q.front == Q.rear && Q.tag == 0)
    {
        // cout << "队空，无法取出元素" << endl;
        return true;
    }
    return false;
}

// 层次遍历
void arrangementLog(linkT &T)
{
    Queue Q;
    initalQueue(Q);
    linkT cache = T;
    pushQueue(Q, T);
    while (!queueIsEmpty(Q))
    {
        cache = popQueue(Q);
        cout << cache->data[0];
        if (cache->lChild)
        {
            pushQueue(Q, cache->lChild);
        }
        if (cache->rChild)
        {
            pushQueue(Q, cache->rChild);
        }
    }
    cout << "Log end" << endl;
}

