#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void menu(void)
{
	printf("---欢迎来到井字棋游戏!---\n");
	printf("输入1开始游戏，输入0退出。\n");
}
void InitBoard(char board[ROW][COL],int row,int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void test(char board[ROW][COL], int row, int col)
{
	int input;
	scanf("%d", &input);
	srand((unsigned int)time(NULL));
	while (input==1)
	{
		display_board(board, ROW, COL);
		game(board, ROW, COL);
		menu();
		scanf("%d", &input);
	}
}
int main(void)
{
	char board[ROW][COL] = { '0' };
	menu();
	InitBoard(board,ROW,COL);
	test(board,ROW,COL);
	return 0;
}