#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
#define ElemType int
#define MaxSize 25
// 定义串的相关算法
// 顺序存储定义
struct SString
{
    string ch;
    int length;
};

// BF算法匹配模式串
int Bf(SString &S, SString &T)
{
    int i = 0, j = 0;
    while (i < S.length && j < T.length)
    {
        if (S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
        if (!T.ch[j])
        {
            return i - T.length + 1;
        }
    }
    return 0;
}

// 链式存储定义
/* typedef struct StringNode
{
    char ch[MaxSize];
    StringNode *next;
} StringNode;
typedef struct Lstring
{
    StringNode *head, *tail;
    int StringLen;
}; */
// 初始化一个串