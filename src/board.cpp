#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "chess.h"

int c_1 = 97;
int c_2 = 49;
int n = 8;

int min(int a, int b)
{
    if (a >= b) {
        return b;
    }
    return a;
}

int max(int a, int b)
{
    if (a >= b) {
        return a;
    }
    return b;
}
bool pawn_move(char** board, int i, int j, int k, int l)
{
    if (k != i) {
        return false;
    }
    if (board[j][i] == 'p') {
        if (j == 1) {
            if (l - j > 2) {
                return false;
            }
        } else {
            if (l - j != 1) {
                return false;
            }
        }
    }
    if (board[j][i] == 'P') {
        if (j == 6) {
            if (j - l > 2) {
                return false;
            }
        } else {
            if (j - l != 1) {
                return false;
            }
        }
    }
    for (int n = min(j, l); n <= max(j, l); n++) {
        if (n == j) {
            continue;
        }
        if (board[n][i] != ' ') {
            return false;
        }
    }
    return true;
}

bool bishop_move(char** board, int i, int j, int k, int l)
{
    int X_dir = -1;
    int Y_dir = -1;
    int a = i - k;
    int b = j - l;
    if (a < 0) {
        X_dir = 1;
        a *= -1;
    }
    if (b < 0) {
        Y_dir = 1;
        b *= -1;
    }
    if (a != b) {
        return false;
    }
    i += X_dir;
    j += Y_dir;
    while (i != k && k != l) {
        if (board[j][i] != ' ') {
            return false;
        }
        i += X_dir;
        j += Y_dir;
    }
    return true;
}

bool horse_move(char** board, int i, int j, int k, int l)
{
    if (board[l][k] != ' ') {
        return false;
    }
    int a = i - k;
    int b = j - l;
    if (a < 0) {
        a *= -1;
    }
    if (b < 0) {
        b *= -1;
    }
    if (a == 2 && b == 1) {
        return true;
    }
    if (a == 1 && b == 2) {
        return true;
    }
    return false;
}

bool rook_move(char** board, int i, int j, int k, int l)
{
    if (i != k && j != l) {
        return false;
    }
    if (i == k) {
        for (int n = min(j, l); n <= max(j, l); ++n) {
            if (n == j) {
                continue;
            }
            if (board[n][i] != ' ') {
                return false;
            }
        }
    }
    if (j == l) {
        for (int n = min(i, k); n <= max(i, k); ++n) {
            if (n == i) {
                continue;
            }
            if (board[j][n] != ' ') {
                return false;
            }
        }
    }
    return true;
}

bool queen_move(char** board, int i, int j, int k, int l)
{
    if (!bishop_move(board, i, j, k, l) && !rook_move(board, i, j, k, l)) {
        return false;
    }
    return true;
}

bool king_move(char** board, int i, int j, int k, int l)
{
    if (board[l][k] != ' ') {
        return false;
    }
    int a = i - k;
    int b = j - l;
    if (a < 0) {
        a *= -1;
    }
    if (b < 0) {
        b *= -1;
    }
    if (a > 1 || b > 1) {
        return false;
    }
    return true;
}

bool symbols(int i, int j, int k, int l)
{
    if (i < 0 || i > 7 || j < 0 || j > 7) {
        return false;
    }
    if (k < 0 || k > 7 || l < 0 || l > 7) {
        return false;
    }
    return true;
}

bool chess_move(char** board, string str)
{
    int i, j, k, l;
    if (str.size() != 5) {
        return false;
    }
    if (str[2] != '-') {
        return false;
    }
    i = str[0] - c_1;
    j = str[1] - c_2;
    k = str[3] - c_1;
    l = str[4] - c_2;
    if (!symbols(i, j, k, l) || board[l][k] != ' ') {
        return false;
    }
    if (i == j && k == l) {
        return false;
    }
    bool is_valid = false;
    switch (board[j][i]) {
    case 'P':
    case 'p':
        is_valid = pawn_move(board, i, j, k, l);
        break;

    case 'R':
    case 'r':
        is_valid = rook_move(board, i, j, k, l);
        break;

    case 'B':
    case 'b':
        is_valid = bishop_move(board, i, j, k, l);
        break;

    case 'H':
    case 'h':
        is_valid = horse_move(board, i, j, k, l);
        break;

    case 'K':
    case 'k':
        is_valid = king_move(board, i, j, k, l);
        break;

    case 'Q':
    case 'q':
        is_valid = queen_move(board, i, j, k, l);
        break;

    default:
        return false;
    }
    if (!is_valid) {
        return false;
    }
    board[l][k] = board[j][i];
    board[j][i] = ' ';
    return true;
}
