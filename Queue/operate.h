#include <stdio.h>
#include <iostream>
#define ElemType int
using namespace std;
// 队列的链式存储
typedef struct Qnode
{
    ElemType data;
    Qnode *next;
} Qnode, *QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} linkQueue;

// 初始化
void initQueue(linkQueue &Q)
{
    Q.front = new Qnode;
    Q.rear = Q.front;
    Q.front ->next = NULL;
    cout << "OK" << endl;
    return;
}
// 入队
void push(linkQueue &Q) 
{
    QueuePtr p = new Qnode;
    p ->next = NULL;
    cout << "输入入队元素" << endl;
    cin >> p ->data;
    Q.rear ->next = p;
    Q.rear = p;
    return;
}
// 出队
void pop(linkQueue &Q) 
{
    if (Q.front == Q.rear)
    {
        cout << "当前队空" <<endl;
        return;
    }else if(Q.front ->next == Q.rear) {
        Q.rear = Q.front;
    }
    cout << Q.front ->next ->data << endl;
    Q.front ->next = Q.front ->next ->next;
    return;
}