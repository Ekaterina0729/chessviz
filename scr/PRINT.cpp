#include <cstdio>
#include <iostream>
#include <locale.h>

using namespace std;

void Print(char chess[][9])
{
    cout << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
}
