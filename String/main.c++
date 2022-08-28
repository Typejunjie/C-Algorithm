#include <stdio.h>
#include <iostream>
#include "algorithm-kmp/KMP.h"

using namespace std;

int main()
{
    SString S;
    SString T;
    char str[] = "ababa\0";
    char str_T[] = "aababbaaa\0";
    initalString(S, str);
    initalString(T, str_T);
    bool judge = KPM(T, S);
    cout << judge;
}