#include <stdio.h>
#include <iostream>
#define sElemType int
#define maxSize 100

using namespace std;
// 顺序栈实现
typedef struct Stack
{
    sElemType *base;
    sElemType *top;
    int stackSize;
} Stack;

// 初始化一个栈
Stack initStack(int length)
{
    Stack S;
    S.base = new sElemType[length];
    if (!S.base)
    {
        cout << "fault! overflow" << endl;
        return S;
    }
    S.top = S.base;
    S.stackSize = length;
    cout << "初始化完成" << endl;
    return S;
}
// 入栈
void push(Stack &S)
{
    if(S.top - S.base == S.stackSize) {
        cout << "栈已满" << endl;
        return;
    }
    cout << "输入压入的数字" << endl;
    cin >> *S.top;
    S.top ++;
    cout << "OK" << endl;
}
// 出栈
void pop(Stack &S) {
    if(S.base == S.top) {
        cout << "栈已空" << endl;
        return;
    }
    cout << "取出：" << *--S.top << endl;
}

// 打印栈中元素
void log(Stack &S) {

}

// 判断栈是否为空
void stackEmpty(Stack &S)
{}

// 求顺序栈长度