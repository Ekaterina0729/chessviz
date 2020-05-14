#include "chess.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

char** make()
{
    char** board = new char*[n];
    for (int i = 0; i < 8; ++i) {
        board[i] = new char[n];
    }
    board[0][0] = 'r';
    board[0][1] = 'h';
    board[0][2] = 'b';
    board[0][3] = 'q';
    board[0][4] = 'k';
    board[0][5] = 'b';
    board[0][6] = 'h';
    board[0][7] = 'r';
    for (int i = 0; i < n; ++i) {
        board[1][i] = 'p';
        board[6][i] = 'P';
    }
    for (int i = 2; i < 6; ++i) {
        for (int j = 0; j < n; ++j) {
            board[i][j] = ' ';
        }
    }
    board[7][0] = 'R';
    board[7][1] = 'H';
    board[7][2] = 'B';
    board[7][3] = 'K';
    board[7][4] = 'Q';
    board[7][5] = 'B';
    board[7][6] = 'H';
    board[7][7] = 'R';
    return board;
}

void print(char** board)
{
    cout << " abcdefgh" << endl;
    string str;
    for (int i = 0; i < n; ++i) {
        str.clear();
        for (int j = 0; j < n; ++j) {
            str.push_back(board[i][j]);
        }
        cout << i + 1 << str << endl;
    }
    cout << endl;
}