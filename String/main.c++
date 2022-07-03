#include <stdio.h>
#include <iostream>
#include "algorithm-kmp/KMP.h"

using namespace std;

int main()
{
    SString S;
    int next[20];
    char str[] = "ababaaaa\0";
    initalString(S, str);
    nextArr(S, next);
    logArr(next, S.length);
}