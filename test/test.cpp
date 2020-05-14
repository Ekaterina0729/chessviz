#include "chess.h"
#include <gtest/gtest.h>
#include <string>

TEST(board, make)
{
    char** board = make();
    ASSERT_TRUE(board != NULL);
}

TEST(board, chess_move)
{
    char** board = make_default();
    std::string str = "aaaaaaa";
    ASSERT_FALSE(chess_move(board, str));
    str = "a2-a2";
    ASSERT_FALSE(chess_move(board, str));
    str = "e1-e2";
    ASSERT_FALSE(chess_move(board, str));
    str = "e2 e3";
    ASSERT_FALSE(chess_move(board, str));
    str = "e2-e3-e4";
    ASSERT_FALSE(chess_move(board, str));
    str = "e4-e5";
    ASSERT_FALSE(chess_move(board, str));
    str = "e2-e4";
    ASSERT_TRUE(chess_move(board, str));
}

TEST(board, pawn_move)
{
    char** board = make();
    ASSERT_TRUE(pawn_move(board, 2, 1, 2, 3));
    ASSERT_TRUE(pawn_move(board, 2, 1, 2, 2));
    ASSERT_FALSE(pawn_move(board, 2, 1, 2, 4));
    std::string str = "b1-c3";
    chess_move(board, str);
    ASSERT_FALSE(pawn_move(board, 2, 1, 2, 2));
    ASSERT_FALSE(pawn_move(board, 2, 1, 2, 3));
}

TEST(board, bishop_move)
{
    char** board = make();
    ASSERT_FALSE(bishop_move(board, 2, 0, 5, 3));
    std::string str = "d2-d4";
    chess_move(board, str);
    ASSERT_TRUE(bishop_move(board, 2, 0, 5, 3));
    str = "c1-f4";
    chess_move(board, str);
    ASSERT_TRUE(bishop_move(board, 5, 3, 2, 0));
    ASSERT_TRUE(bishop_move(board, 5, 3, 6, 2));
    ASSERT_TRUE(bishop_move(board, 5, 3, 7, 5));
    ASSERT_TRUE(bishop_move(board, 5, 3, 3, 5));
    ASSERT_FALSE(bishop_move(board, 5, 3, 4, 3));
    str = "e2-e3";
    chess_move(board, str);
    ASSERT_FALSE(bishop_move(board, 5, 3, 2, 0));
}

TEST(board, rook_move)
{
    char** board = make();
    ASSERT_FALSE(rook_move(board, 0, 0, 0, 1));
    ASSERT_FALSE(rook_move(board, 0, 0, 0, 5));
    std::string str = "a2-a4";
    chess_move(board, str);
    ASSERT_FALSE(rook_move(board, 0, 0, 0, 5));
    ASSERT_TRUE(rook_move(board, 0, 0, 0, 2));
    str = "a1-a3";
    chess_move(board, str);
    ASSERT_TRUE(rook_move(board, 0, 2, 7, 2));
    str = "a3-h3";
    chess_move(board, str);
    ASSERT_TRUE(rook_move(board, 7, 2, 7, 5));
    str = "e2-e3";
    chess_move(board, str);
    ASSERT_FALSE(rook_move(board, 7, 2, 1, 2));
    // show(board);
}

TEST(board, horse_move)
{
    char** board = make();
    ASSERT_TRUE(horse_move(board, 1, 0, 2, 2));
    ASSERT_FALSE(horse_move(board, 1, 0, 2, 3));
    ASSERT_FALSE(horse_move(board, 1, 0, 3, 1));
    ASSERT_FALSE(horse_move(board, 1, 0, 3, 3));
    ASSERT_FALSE(horse_move(board, 1, 0, 1, 3));
    std::string str = "b1-c3";
    chess_move(board, str);
    // show(board);
    ASSERT_TRUE(horse_move(board, 2, 2, 0, 3));
    ASSERT_TRUE(horse_move(board, 2, 2, 3, 4));
    ASSERT_TRUE(horse_move(board, 2, 2, 1, 4));
    ASSERT_TRUE(horse_move(board, 2, 2, 4, 3));
    ASSERT_FALSE(horse_move(board, 2, 2, 0, 1));

}

TEST(board, queen_move)
{
    char** board = make();
    ASSERT_FALSE(queen_move(board, 4, 7, 6, 5));
    std::string str = "f7-f6";
    chess_move(board, str);
    ASSERT_TRUE(queen_move(board, 4, 7, 6, 5));
    ASSERT_FALSE(queen_move(board, 4, 7, 4, 4));
    board[6][4] = ' ';
    ASSERT_TRUE(queen_move(board, 4, 7, 4, 4));
    str = "e8-e4";
    chess_move(board, str);
    ASSERT_TRUE(queen_move(board, 4, 3, 4, 7));
    ASSERT_TRUE(queen_move(board, 4, 3, 4, 2));
    ASSERT_TRUE(queen_move(board, 4, 3, 7, 3));
    ASSERT_TRUE(queen_move(board, 4, 3, 0, 3));
    ASSERT_TRUE(queen_move(board, 4, 3, 6, 5));
    board[4][5] = 'P';
    board[6][4] = 'P';
    // show(board);
    ASSERT_FALSE(queen_move(board, 4, 3, 6, 5));
    ASSERT_FALSE(queen_move(board, 4, 3, 4, 7));
}

TEST(board, king_move)
{
    char** board = make_default();
    ASSERT_FALSE(king_move(board, 3, 7, 6, 5));
    ASSERT_FALSE(king_move(board, 3, 7, 3, 5));
    ASSERT_FALSE(king_move(board, 3, 7, 3, 6));
    std::string str = "d7-d5";
    chess_move(board, str);
    ASSERT_TRUE(king_move(board, 3, 7, 3, 6));
    str = "d8-d7";
    chess_move(board, str);
    // show(board);
    ASSERT_TRUE(king_move(board, 3, 6, 2, 5));
    ASSERT_TRUE(king_move(board, 3, 6, 3, 7));
    ASSERT_TRUE(king_move(board, 3, 6, 4, 5));
    ASSERT_FALSE(king_move(board, 3, 6, 1, 4));
}
