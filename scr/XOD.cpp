#include <cstdio>
#include <iostream>
#include <locale.h>

using namespace std;

void XOD(char chess[9][9], int m[][2])
{
    char temp;
    if (m[0][0] == m[1][0])
        if (((chess[m[0][1]][m[0][0]] == 'P')
             && ((m[1][1] == m[0][1] - 1) || (m[1][1] == m[0][1] - 2)))
            || ((chess[m[0][1]][m[0][0]] == 'p')
                && ((m[1][1] == m[0][1] + 1) || (m[1][1] == (m[0][1] + 2))))) {
            temp = chess[m[0][1]][m[0][0]];
            chess[m[0][1]][m[0][0]] = chess[m[1][1]][m[1][0]];
            chess[m[1][1]][m[1][0]] = temp;
        }
}
