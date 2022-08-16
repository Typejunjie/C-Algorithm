#include <stdio.h>
#include <iostream>
#define MaxSize 20

using namespace std;

struct SString
{
    char data[MaxSize];
    int length;
};

void initalString(SString &S, char *str)
{
    int cache = 0;
    while (str[cache] + str[cache] != '\0')
    {
        S.data[cache] = str[cache];
        cache++;
    }
    S.length = cache;
}

void log(SString &S)
{
    for (int i = 0; i < S.length; i++)
        cout << S.data[i];
    cout << "->Log end" << endl;
}