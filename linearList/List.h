#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
#define ElemType int

// 定义结点
typedef struct Lnode
{
    ElemType data;
    struct Lnode *next;
} Lnode, *linkList;

// 开辟一个带头节点的链表
bool InitList(linkList &L)
{
    L = new Lnode;
    if (!L)
    {
        return false;
    }
    L->next = NULL;
    return true;
};

// 打印链表
void log(linkList &L)
{
    linkList s;
    s = L->next;
    while (s)
    {
        cout << "[" << s->data << "]";
        s = s->next;
    }
    cout << "log end" << endl;
}

// 头插法将数据初始化到链表中
void createList_H(linkList &L)
{
    int n;
    linkList s;
    L = new Lnode;
    L->next = NULL;
    cout << "Enter element here" << endl;
    cin >> n;
    cout << "Create linked list in head insertion \n and you can insertion number in here" << endl;
    while (n--)
    {
        s = new Lnode;
        cin >> s->data;
        s->next = L->next;
        L->next = s;
    }
    cout << "OK" << endl;
}

// 根据传入数组存为链式存储顺序链表
void createList_L(linkList &L, int *LArray)
{
    int i = 0;
    linkList nowNode, newNode;
    nowNode = L;
    while (i < 9)
    {
        newNode = new Lnode;
        newNode->next = NULL;
        newNode->data = LArray[i];
        nowNode->next = newNode;
        nowNode = nowNode->next;
        i++;
    }
    cout << "OK" << endl;
}

// 在链表中加入一个数据
void addElem(linkList &L)
{
    cout << "Input a element into the node" << endl;
    int data;
    cin >> data;
    linkList p;
    p = L->next;
    while (p->next)
    {
        p = p->next;
    }
    p->next = new Lnode;
    p->next->data = data;
    p->next->next = NULL;
    cout << "success" << endl;
}

// 删除最后一个数据
void deleteData(linkList &L)
{
    linkList s;
    s = L;
    while (s->next->next)
    {
        s = s->next;
    }
    s->next = NULL;
    cout << "OK" << endl;
}

// 删除一个指定位置的元素
void deleteLocatData(linkList &L)
{
    cout << "Place insert a number to delete element" << endl;
    int num;
    linkList s;
    s = L;
    cin >> num;
    while (num--)
    {
        if (s->next)
        {
            cout << "This element is not exit" << endl;
            return;
        }
        else if (s->next->next)
        {
            break;
        }
        s = s->next;
    }
    s->next = s->next->next;
    cout << "OK" << endl;
}
