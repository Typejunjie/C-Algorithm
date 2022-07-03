#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct Lnode
{
    int data;
    struct Lnode *next;
}Lnode, *linkList;

// log方法
void log(linkList &L)
{
    linkList p;
    p = L->next;
    while (p)
    {
        cout << "[" << p->data << "]";
        p = p->next;
    }
    cout << "Log end" << endl;
}

// 头插法
void instertEleInFist(linkList &L, int* Array, int length)
{
    linkList p;
    for (int i = length - 1; i >= 0; i--)
    {
        p = new Lnode;
        p->data = Array[i];
        p->next = L->next;
        L->next = p;
    }
}
// 尾插法
void insterEleInLast(linkList &L, int* Array, int length)
{
    linkList p, lastN;
    lastN = L;
    for (int i = 0; i < length; i++)
    {
        p = new Lnode;
        p->next = NULL;
        p->data = Array[i];
        lastN->next = p;
        lastN = p;
    }
}

void creatLinkList(linkList &L, int* Array, int length)
{
    L = new Lnode;
    L->next = NULL;
    insterEleInLast(L, Array, length);
}