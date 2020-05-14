#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

char** make();
void print(char** board);
bool pawn_move(char** board, int i, int j, int k, int l);
bool bishop_move(char** board, int i, int j, int k, int l);
bool horse_move(char** board, int i, int j, int k, int l);
bool rook_move(char** board, int i, int j, int k, int l);
bool queen_move(char** board, int i, int j, int k, int l);
bool king_moved(char** board, int i, int j, int k, int l);
bool symbols(int i, int j, int k, int l);
bool chess_move(char** board, string str);
int min(int a, int b);
int max(int a, int b);

#endif
