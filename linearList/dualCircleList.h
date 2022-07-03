#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct Lnode
{
    int data;
    struct Lnode *next;
    struct Lnode *prior;
} Lnode, *circleList;

// 打印循环双链表
void log(circleList &L)
{
    circleList p;
    p = L->next;
    while (p != L)
    {
        cout << "[" << p->data << "]";
        p = p->next;
    }
    cout << "Log end" << endl;
}

// 尾插法创建循环双链表
void createCircleList(circleList &L, int *Array, int length)
{
    L = new Lnode;
    L->prior = NULL;
    L->next = NULL;
    circleList nowNode, newNode;
    nowNode = L;
    for (int i = 0; i < length; i++)
    {
        newNode = new Lnode;
        newNode->data = Array[i];
        newNode->next = NULL;
        newNode->prior = nowNode;
        nowNode->next = newNode;
        nowNode = nowNode->next;
    }
    nowNode->next = L;
    L->prior = nowNode;
}
