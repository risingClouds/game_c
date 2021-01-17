#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
void InitBoard(char board[ROWS][COLS], int rows, int cols,char ch);
void display(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col,int counts);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int get_mine_counts(char mine[ROWS][COLS], int x, int y);