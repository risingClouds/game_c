#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
#include<stdlib.h>

void game(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		char ret;
		//玩家下棋
		player_move(board, ROW, COL);
		display_board(board, row, col);
		//判定
		ret=isWin(board, ROW, COL);
		if (ret == '*')
		{
			printf("玩家获胜\n");
			break;
		}
		else if (ret == '#')
		{
			printf("电脑获胜\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("平局\n");
			break;
		}
		//电脑下棋
		computer_move(board, ROW, COL);
		display_board(board, row, col);
		//判定
		ret = isWin(board, ROW, COL);
		if (ret == '*')
		{
			printf("玩家获胜\n");
			break;
		}
		else if (ret == '#')
		{
			printf("电脑获胜\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("平局\n");
			break;
		}
	}
}
void display_board(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		for (int j = 0; j < col; j++)
		{
			if (i < row - 1)
			{
				printf("---");

				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}
void player_move(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("请输入你想落子的行和列：");
	scanf("%d%d", &x, &y);
	while ((x > row||x < 1) || (y > col||y < 1))
	{
		printf("输入非法\n");
		printf("请重新输入你想落字的行和列：");
		scanf("%d%d", &x, &y);
	}
	while (board[x-1][y-1] != ' ')
	{
		printf("此处已落子\n");
		printf("请重新输入你想落字的行和列：");
		scanf("%d%d", &x, &y);
	}
	
	x--;
	y--;
	board[x][y] = '*';
}
void computer_move(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = (int)rand() % row;
		int y = (int)rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
char isWin(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row ; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2]&&board[i][1]!=' ')
		{
			return board[i][1];
		}
	}
	for (int j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[0][j] == board[2][j]&&board[0][j]!=' ')
		{
			return board[1][j];
		}
	}
	if ((board[1][1] == board[2][2] && board[1][1] == board[0][0]) || board[1][1] == board[0][2] && board[1][1] == board[2][0])
	{
		return board[1][1];
	}
	if (isFull(board, ROW, COL) == 1)
	{
		return 'Q';
	}
	return 'C';
}
int isFull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}