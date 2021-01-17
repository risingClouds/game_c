#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 3
void game(char board[ROW][COL], int row, int col);
void display_board(char board[ROW][COL], int row, int col);
void player_move(char board[ROW][COL], int row, int col);
void computer_move(char board[ROW][COL], int row, int col);
char isWin(char board[ROW][COL], int row, int col);
int isFull(char board[ROW][COL], int row, int col);