#include <stdio.h>
#include <iostream>
#define MaxSize 10

using namespace std;

struct Queue
{
    int data[MaxSize];
    int front, rear;
    int volume = MaxSize;
    int tag = 0;
};

void initalQueue(Queue &Q)
{
    Q.front = 0;
    Q.rear = 0;
}

void pushQueue(Queue &Q, int key)
{
    if (Q.rear == Q.front && Q.tag == 1)
    {
        //cout << "队列发生了溢出" << endl;
        return;
    }
    Q.data[Q.rear] = key;
    Q.rear = ++Q.rear % Q.volume;
    if (Q.rear == Q.front)
        Q.tag = 1;
}

int popQueue(Queue &Q)
{
    if (Q.front == Q.rear && Q.tag == 0)
    {
        //cout << "队空，无法取出元素" << endl;
        return 0;
    }
    int value = Q.data[Q.front];
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
            cout << '|' << Q.data[cache] << '|';
            cache = ++cache % Q.volume;
        } while (cache != Q.rear);
    }
    cout << "<-rear" << endl;
}