#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char ch)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = ch;
		}
	}
}
void display(char board[ROWS][COLS], int row, int col)
{
	for (int i = 1; i <= col; i++)
	{
		if (i == 1)
		{
			printf("    ");
		}
		printf("%d ", i);
	}
	printf("\n\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d   ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char board[ROWS][COLS], int row, int col,int counts)
{
	while (counts > 0)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			counts--;
		}
	}
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int win = 0;
	while (win<row*col-10)
	{
		printf("请输入排查雷的坐标:>");
		scanf("%d%d", &x, &y);
		if ((x >= 1 && x <= row) && y >= 1 && y <= row)
		{
			if (mine[x][y] == '1')
			{
				printf("炸死!!!图中1代表有雷\n");
				display(mine, row, col);
				break; 
			}
			else
			{
				int counts=get_mine_counts(mine, x, y);
				show[x][y] = (char)counts + '0';
				display(show, row, col);
				win++;
			}
		}
		else
		{
			printf("输入非法，请重新输入/n");
		}
	}
	if (win == row*col - 10)
	{
		printf("恭喜你，胜利！！！");
		display(mine, row, col);
	}
}
int get_mine_counts(char mine[ROWS][COLS], int x, int y)
{
	return
	mine[x - 1][y] +
	mine[x - 1][y - 1] +
	mine[x][y - 1] +
	mine[x + 1][y - 1] +
	mine[x + 1][y + 1] +
	mine[x + 1][y]+
	mine[x][y + 1] +
	mine[x - 1][y + 1] - 8 * (int)'0';
}