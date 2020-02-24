#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
     char chess[9][9]={{'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
					 {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                     {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                     {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                     {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                     {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
 					 {'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                     {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                     {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    int i, j;
    for( int i = 0; i < 9; i++) {
        for( int j = 0; j < 9; j++) {
 			cout << chess[i][j]; 
        }
         cout << endl;
    }
    return 0;
}
