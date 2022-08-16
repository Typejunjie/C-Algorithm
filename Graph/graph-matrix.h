#include <stdio.h>
#include <iostream>
#include "../Stack/linearStack.h"

using namespace std;

#define maxSize 50

struct Gmatrix
{
    int pointArr[maxSize];
    int data[maxSize][maxSize];
    int countPoint;
};

void logMatrix(Gmatrix G)
{
    for (int i = 0; i < G.countPoint; i++)
    {
        for (int j = 0; j < G.countPoint; j++)
        {
            cout << "[" << G.data[i][j] << "]";
        }
        cout << endl;
    }
    cout << "Log end" << endl;
}

void initalMatrix(Gmatrix &G)
{
    G.countPoint = 0;
}

void createMatrix(Gmatrix &G, int *pointArr, int plength, int (*edgeArr)[2], int elength)
{
    int fromPoint, toPoint;
    for (int i = 0; i < plength; i++)
    {
        G.pointArr[i] = pointArr[i];
    }
    G.countPoint = plength;
    for (int i = 0; i < elength; i++)
    {
        for (fromPoint = 0; fromPoint < G.countPoint; fromPoint++)
        {
            if (edgeArr[i][0] == G.pointArr[fromPoint])
                break;
        }
        for (toPoint = 0; toPoint < G.countPoint; toPoint++)
        {
            if (edgeArr[i][1] == G.pointArr[toPoint])
                break;
        }
        G.data[toPoint][fromPoint] = 1;
        G.data[fromPoint][toPoint] = 1;
    }
}

// DFS //////////////////

void DFS_matrix(Gmatrix &G)
{
    Stack S;
    initalStack(S);
    int visArr[100];
    for (int i = 0; i < G.countPoint; i++)
    {
        visArr[i] = 0;
    }
    int cache = 0;
    int line = 0;
    while (true)
    {
        if (G.data[line][cache] != 0 && visArr[line] == 0)
        {
            pushStack(S, cache);
            cout << G.pointArr[cache];
            visArr[cache] = 1;
            cache = line;
            line = 0;
        }
        else if (line >= G.countPoint)
        {
            if (visArr[cache] == 0)
            {
                cout << G.pointArr[cache];
                visArr[cache] = 1;
            }
            cache = popStack(S);
            if (cache == 0)
                break;
            line = 0;
        }
        else
        {
            line++;
        }
    }
}

// DFS //////////////////

// BFS //////////////////

void BFS_M_vis(Gmatrix &G, int localP, int *visArr)
{
    int cache;
    if (visArr[localP] == 0)
    {
        cout << G.pointArr[localP];
        visArr[localP] = 1;
    }
    for (cache = 0; cache < G.countPoint; cache++)
    {
        if (G.data[cache][localP] != 0 && visArr[cache] == 0)
            cout << G.pointArr[cache];
    }
    for (cache = 0; cache < G.countPoint; cache++)
    {
        if (G.data[cache][localP] != 0 && visArr[cache] == 0)
        {
            visArr[cache] = 1;
            BFS_M_vis(G, cache, visArr);
        }
    }
}

void BFS_matrix(Gmatrix &G)
{
    int visArr[100];
    for (int i = 0; i < G.countPoint; i++)
        visArr[i] = 0;
    BFS_M_vis(G, 0, visArr);
}

// BFS //////////////////
