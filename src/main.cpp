#include "chess.h"
#include <iostream>
using namespace std;

int main()
{
    char chess[9][9] = {{'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                        {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}};

    print(chess);
    int m[2][2];
    string xod;
    while (1) {
        proverka(xod, m);
        if ((chess[m[0][1]][m[0][0]] == 'P')
            || (chess[m[0][1]][m[0][0]] == 'p'))
            Move(chess, m);
        cout << endl << endl;
        print(chess);
    }
    return 0;
}
