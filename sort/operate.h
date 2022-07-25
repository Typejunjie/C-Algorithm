#include <stdio.h>
#include <iostream>

using namespace std;
// 打印数组
void logArr(int q[])
{
    for (int i = 1; i < 15; i++)
    {
        cout << q[i] << ",";
    }
}
// 简单选择排序
void selectSort(int q[])
{
    for (int i = 1; i < 14; i++)
    {
        int k = i;
        for (int j = i + 1; j <= 14; j++)
        {
            if (q[j] < q[k])
            {
                k = j;
            }
        }
        if (i != k)
        {
            int s = q[i];
            q[i] = q[k];
            q[k] = s;
        }
    }
}
// 快速排序
int partiton(int q[], int low, int high)
{
    q[0] = q[low];
    int piv = q[low];
    while (low < high)
    {
        while (low < high && q[high] >= piv)
        {
            --high;
        }
        q[low] = q[high];
        while (low < high && q[low] <= piv)
        {
            ++low;
        }
        q[high] = q[low];
    }
    q[low] = q[0];
    return low;
}
void fastSort(int q[], int low, int high)
{
    if (low < high)
    {
        int piv = partiton(q, low, high);
        fastSort(q, low, piv - 1);
        fastSort(q, piv + 1, high);
    }
}
void mainFastSort(int q[])
{
    fastSort(q, 1, 14);
}
// 冒泡排序
void bubbleSort(int q[])
{
    int m, j, x;
    for (m = 1; m < 14; m++)
    {
        for (j = 1; j < 15 - m; j++)
        {
            if (q[j] > q[j + 1])
            {
                x = q[j];
                q[j] = q[j + 1];
                q[j + 1] = x;
            }
        }
    }
}
// 希尔排序
void shellInsert(int q[], int dlta)
{
    for (int i = dlta + 1; i < 15; i++)
    {
        if (q[i] < q[i - dlta])
        {
            q[0] = q[i];
            int j;
            for (j = i - dlta; j > 0 && (q[0] < q[j]); j = j - dlta)
            {
                q[j + dlta] = q[j];
            }
            q[j + dlta] = q[0];
        }
    }
}
void shellSort(int q[])
{
    int dlta[] = {5, 3, 1};
    int t = 3;
    for (int i = 0; i < t; i++)
    {
        shellInsert(q, dlta[i]);
    }
}
// 折半插入排序
void BinsertSort(int q[])
{
    for (int i = 2; i < 15; i++)
    {
        q[0] = q[i];
        int low = 1, high = i - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (q[0] < q[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        for (int j = i - 1; j >= high + 1; j--)
        {
            q[j + 1] = q[j];
        }
        q[high + 1] = q[0];
    }
    cout << "OK" << endl;
}
// 直接插入排序
void insertSort(int q[])
{
    int i, j;
    for (i = 1; i < 15; i++)
    {
        if (q[i] >= q[i - 1])
        {
            continue;
        }
        else
        {
            q[0] = q[i];
            for (j = i - 1; q[0] < q[j]; j--)
            {
                q[j + 1] = q[j];
            }
            q[j + 1] = q[0];
        }
    }
    cout << "OK" << endl;
}