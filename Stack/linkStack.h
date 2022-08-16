#include <iostream>
#include <stdio.h>

#define ElemType int
using namespace std;

// 链式存储栈表
typedef struct StackNode
{
    ElemType data;
    StackNode *next;
} StackNode, *linkStack;

// 初始化链栈
void initStack(linkStack &S)
{
    S = NULL;
    cout << "OK" << endl;
    return;
}
// 入栈
void push(linkStack &S) 
{
    linkStack p = new StackNode;
    p ->next = S;
    cout << "输入元素入栈" << endl;
    cin >> p ->data;
    S = p;
    cout << "OK" << endl;
    return;
}
// 出栈
void pop(linkStack &S)
{
    if (S == NULL)
    {
        cout << "当前栈空" << endl;
        return;
    }
    cout << S ->data << endl;
    S = S ->next;
    return;
}


