#include "chess.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

int main(int argc, char* argv[])
{
    char** board = make();
    print(board);
    for (int i = 0; i < 10; ++i) {
        cout << "Make your move!" << endl;
        string str;
        getline(cin, str);
        if (chess_move(board, str)) {
            print(board);
        } else {
            cout << "Incorrect input! Repeat please! " << endl;
        }
    }
