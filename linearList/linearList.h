#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct linearList
{
    int data[20];
    int length;
} list;

// 折半查找
int halfSearch(linearList &L, int key)
{
    int low = 0;
    int high = L.length - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (L.data[mid] == key)
        {
            return mid;
        }
        else if (key < L.data[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

// 创建顺序存储的线性表
void creatLinearList(linearList &L, int *LArray, int length)
{
    int i = 0;
    while (i < length)
    {
        L.data[i] = LArray[i];
        i++;
    }
    L.length = i;
}
// 打印
void log(linearList &L)
{
    int i = 0;
    while (i < L.length)
    {
        cout << "[" << L.data[i] << "]";
        i++;
    }
    cout << "log end" << endl;
}
