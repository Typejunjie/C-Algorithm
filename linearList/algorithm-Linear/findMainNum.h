#include <stdio.h>
#include <iostream>
#include "../linearList.h"
/*
算法：查找主元素
主元素：一半以上元素值相同，该值称为主元素
存在则返回该元素，否则返回-1.
时间复杂度O(n^2)
空间复杂度O(n)
 */
// 查找函数，未找到则存入
int findACount(int arr[][2], int length, int &count, int key)
{
    int i = 0;
    while (i < count)
    {
        if (key == arr[i][0])
        {
            arr[i][1]++;
            return i;
        }
        i++;
    }
    if (count > length)
    {
        return -2;
    }
    arr[count][0] = key;
    return -1;
}

int findMainNum(linearList &L)
{
    int arr[L.length / 2 + 1][2];
    int count = 0;
    int i = 0;
    int state;
    while (i < L.length)
    {
        state = findACount(arr, L.length / 2 + 1, count, L.data[i]);
        if (state == -1)
        {
            count++;
        }
        else if (state == -2)
        {
            return -1;
        }
        i++;
    }

    int j = 0;
    while (j < count)
    {
        if (arr[j][1] >= L.length / 2)
        {
            return arr[j][0];
        }
    }
    return 0;
}
